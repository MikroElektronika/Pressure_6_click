#line 1 "C:/Users/katarina.perendic/Desktop/Pressure 6 click/example/c/ARM/STM/STM_AppDemo/Click_Pressure6_STM.c"
#line 1 "c:/users/katarina.perendic/desktop/pressure 6 click/example/c/arm/stm/stm_appdemo/click_pressure6_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "c:/users/katarina.perendic/desktop/pressure 6 click/example/c/arm/stm/stm_appdemo/click_pressure6_config.h"
#line 1 "c:/users/katarina.perendic/desktop/pressure 6 click/example/c/arm/stm/stm_appdemo/click_pressure6_types.h"
#line 19 "c:/users/katarina.perendic/desktop/pressure 6 click/example/c/arm/stm/stm_appdemo/click_pressure6_config.h"
const uint32_t _PRESSURE6_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
extern const uint8_t _PRESSURE6_REG_MANUFACTURER_ID ;
extern const uint8_t _PRESSURE6_REG_PART_ID ;
extern const uint8_t _PRESSURE6_REG_POWER_DOWN ;
extern const uint8_t _PRESSURE6_REG_RESET ;
extern const uint8_t _PRESSURE6_REG_MODE_CONTROL ;
extern const uint8_t _PRESSURE6_REG_IIR_FIFO_CONTROL ;
extern const uint8_t _PRESSURE6_REG_FIFO_DATA ;
extern const uint8_t _PRESSURE6_REG_STATUS ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_MSB ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_LSB ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_XL ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_MSB ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_LSB ;


extern const uint8_t _PRESSURE6_DEF_SLAVE_ADDRESS ;
extern const uint8_t _PRESSURE6_DEF_MANUFACTURER_ID ;
extern const uint8_t _PRESSURE6_DEF_PART_ID ;


extern const uint8_t _PRESSURE6_DEVICE_POWER_DOWN;
extern const uint8_t _PRESSURE6_DEVICE_ACTIVE ;


extern const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_RESET ;
extern const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_ACTIVE ;


extern const uint8_t _PRESSURE6_MC_AVE_NUM_SINGLE ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_2_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_4_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_8_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_16_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_32_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_64_TIMES ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_PROHIBITED ;
extern const uint8_t _PRESSURE6_MC_DATA_READY_ENABLED ;
extern const uint8_t _PRESSURE6_MC_DATA_READY_DISABLED ;
extern const uint8_t _PRESSURE6_MC_FULL_DATA_ENABLED ;
extern const uint8_t _PRESSURE6_MC_FULL_DATA_DISABLED ;
extern const uint8_t _PRESSURE6_MC_WATER_MARK_ENABLED ;
extern const uint8_t _PRESSURE6_MC_WATER_MARK_DISABLED ;
extern const uint8_t _PRESSURE6_MC_MODE_STAND_BY ;
extern const uint8_t _PRESSURE6_MC_MODE_ONE_SHOT ;
extern const uint8_t _PRESSURE6_MC_MODE_CONTINUOUS ;


extern const uint8_t _PRESSURE6_FIFO_EN_MODE_BYPASS ;
extern const uint8_t _PRESSURE6_FIFO_EN_MODE_ENABLED ;
extern const uint8_t _PRESSURE6_WATER_MARK_LEVEL_24 ;
extern const uint8_t _PRESSURE6_WATER_MARK_LEVEL_28 ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_OFF ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_WEAK ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_MIDDLE ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_STRONG ;
#line 132 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 139 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_gpioDriverInit( const uint8_t*  gpioObj);
#line 149 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_writeByte(uint8_t reg, uint8_t _data);
#line 157 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
uint8_t pressure6_readByte(uint8_t reg);
#line 164 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
uint16_t pressure6_getPressure();
#line 171 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
uint8_t pressure6_getTemperatre();
#line 178 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
uint8_t pressure6_getInterrupt();
#line 185 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
uint8_t pressure6_getStatus();
#line 190 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_powerON();
#line 195 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_powerOFF();
#line 200 "c:/users/katarina.perendic/desktop/pressure 6 click/library/__pressure6_driver.h"
void pressure6_waitingForNewData();
#line 30 "C:/Users/katarina.perendic/Desktop/Pressure 6 click/example/c/ARM/STM/STM_AppDemo/Click_Pressure6_STM.c"
uint16_t Pressure;
uint8_t Temperature;
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
 pressure6_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _PRESSURE6_DEF_SLAVE_ADDRESS );
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
