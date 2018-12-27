/*
Example for Pressure6 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes all necessary GPIO pins, UART used for
                          the communcation with Cloud click.
- Application Initialization - Initializes driver, power on module.
                               Commands are sent to prepare the module for communication with the cloud.
- Application Task - running in parallel core state machine and checks for the URC
                     message from ClickCloud.

Additional Functions :

All additional functions such as timer initialization and default handler. 

*/

#define __PRESSURE6__

#include "Click_Pressure6_types.h"
#include "Click_Pressure6_config.h"
#include "Click_Pressure6_timer.h"

static char pressure6_tempRef[ 30 ] = "PRESSURE6_T";
static char pressure6_presRef[ 30 ] = "PRESSURE6_P";

static char cloud_networkName     [ 20 ]  = "Network_Name";
static char cloud_networkPassword [ 20 ]  = "Network_Password";
static char cloud_devKey          [ 50 ]  = "Device_Key";
static char cloud_devPass         [ 100 ] = "Device_Password";

// static uint8_t state;
// static uint8_t oldstate;

// Commands
static char _ATE    [ 5 ] = "ATE1";
static char _AT     [ 3 ] = "AT";
static char _AT_CEN [ 9 ] = "AT+CEN=1";
static char _AT_NWCR[ 8 ] = "AT+NWCR";
static char _AT_NWC [ 9 ] = "AT+NWC=1";
static char _AT_BRCR[ 8 ] = "AT+BRCR";
static char _AT_BRC [ 9 ] = "AT+BRC=1";
static char _AT_DSET[ 8 ] = "AT+DSET";
static char _AT_PUB [ 7 ] = "AT+PUB";


void cloud_default_handler( uint8_t *rsp, uint8_t *evArgs )
{
    mikrobus_logWrite( rsp, _LOG_TEXT );
}

void cloud_packCmd(uint8_t *cmd, uint8_t *mid, uint8_t *_end)
{
    char cmd_param[ 10 ] = "=\"";
    char mid_param[ 10 ] = "\",\"";
    char end_param[ 10 ] = "\"";
    
    uint8_t tmpBuf[ 80 ];
    memset(&tmpBuf[ 0 ], 0, 50);
    
    strcat ( &tmpBuf[ 0 ], cmd );
    strcat ( &tmpBuf[ 0 ], &cmd_param[0] );
    strcat ( &tmpBuf[ 0 ], mid );
    strcat ( &tmpBuf[ 0 ], &mid_param[0] );
    strcat ( &tmpBuf[ 0 ], _end );
    strcat ( &tmpBuf[ 0 ], &end_param[0] );
    
    cloud_cmdSingle( &tmpBuf[ 0 ] );
}

void systemInit()
{
// Cloud
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_uartInit( _MIKROBUS1, &_CLOUD_UART_CFG[0] );
	
	mikrobus_gpioInit( _MIKROBUS2, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS2, &_PRESSURE6_I2C_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
// TIMER INIT
    cloud_configTimer();

// DRIVER INIT
    cloud_uartDriverInit((T_CLOUD_P)&_MIKROBUS1_GPIO, (T_CLOUD_P)&_MIKROBUS1_UART);
    cloud_coreInit( cloud_default_handler, 1500 );
    cloud_modulePower( true );

// CLICK INIT
    pressure6_i2cDriverInit( (T_PRESSURE6_P)&_MIKROBUS2_GPIO, (T_PRESSURE6_P)&_MIKROBUS2_I2C, _PRESSURE6_DEF_SLAVE_ADDRESS );
    pressure6_powerON();
    Delay_1sec();
    pressure6_writeByte(_PRESSURE6_REG_MODE_CONTROL,
                        _PRESSURE6_MC_AVE_NUM_SINGLE |
                        _PRESSURE6_MC_DATA_READY_ENABLED |
                        _PRESSURE6_MC_FULL_DATA_ENABLED |
                        _PRESSURE6_MC_WATER_MARK_ENABLED |
                        _PRESSURE6_MC_MODE_CONTINUOUS);

// MODULE INIT
    cloud_cmdSingle( &_ATE[0] );
    cloud_cmdSingle( &_AT[0] );
    cloud_cmdSingle( &_AT_CEN[0] );
    cloud_packCmd  ( &_AT_NWCR[0], &cloud_networkName[0], &cloud_networkPassword[0]);
    cloud_cmdSingle( &_AT_NWC[0] );
    cloud_packCmd  ( &_AT_BRCR[0], &cloud_devKey[0], &cloud_devPass[0]);
    cloud_cmdSingle( &_AT_BRC[0] );
    Delay_ms(3000);
    
    taskTime = 0;
}

void applicationTask()
{
    char demoBuffer[ 50 ];
    uint16_t Pressure;
    uint8_t  Temperature;
	
// CORE STATE MACHINE
    cloud_process();

// SENSOR - Remove if not used
   if( taskTime > 1500 )
   {
        taskTime = 0;
	    pressure6_waitingForNewData();
        Pressure = pressure6_getPressure();
        Temperature = pressure6_getTemperatre();
        
        IntToStr(Pressure, demoBuffer);
		Ltrim(demoBuffer);
		cloud_packCmd( &_AT_DSET[0], &pressure6_presRef[0], &demoBuffer[0]);
        
		IntToStr(Temperature, demoBuffer);
		Ltrim(demoBuffer);
        cloud_packCmd( &_AT_DSET[0], &pressure6_tempRef[0], &demoBuffer[0]);
        cloud_cmdSingle( &_AT_PUB[0] );
   }
}


void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}