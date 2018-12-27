/*
Example for Pressure6 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Inicializes I2C module and set INT pin as INPUT
- Application Initialization - Initialization driver init and start power ON procedure for wake up chip and sets  measurement mode.
- Application Task - (code snippet) - Read Pressure data and Temperature data and logs data to USBUART every 1 sec.

*/

#include "Click_Pressure6_types.h"
#include "Click_Pressure6_config.h"

uint16_t Pressure;
uint8_t  Temperature;
char demoText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_PRESSURE6_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 115200 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    pressure6_i2cDriverInit( (T_PRESSURE6_P)&_MIKROBUS1_GPIO, (T_PRESSURE6_P)&_MIKROBUS1_I2C, _PRESSURE6_DEF_SLAVE_ADDRESS );
    pressure6_powerON();
    Delay_1sec();
    pressure6_writeByte(_PRESSURE6_REG_MODE_CONTROL,
                        _PRESSURE6_MC_AVE_NUM_SINGLE |
                        _PRESSURE6_MC_DATA_READY_ENABLED |
                        _PRESSURE6_MC_FULL_DATA_ENABLED |
                        _PRESSURE6_MC_WATER_MARK_ENABLED |
                        _PRESSURE6_MC_MODE_CONTINUOUS);

    mikrobus_logWrite(" --- Start measurement --- ", _LOG_LINE);
}

void applicationTask()
{
    pressure6_waitingForNewData();
    Pressure = pressure6_getPressure();
    Temperature = pressure6_getTemperatre();

    // Logs Pressure and Temperature data
    IntToStr(Pressure, demoText);
    mikrobus_logWrite(" Pressure : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);

    IntToStr(Temperature, demoText);
    mikrobus_logWrite(" Temperature : ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);

    mikrobus_logWrite("  ", _LOG_LINE);
    Delay_ms( 1000 );
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