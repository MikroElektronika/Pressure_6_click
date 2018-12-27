#include "Click_Pressure6_types.h"

//......................................................... Clikc config

const uint32_t _PRESSURE6_I2C_CFG[ 1 ] = 
{
	100000
};


//............................................................ Cloud config

const uint32_t _CLOUD_TIMER_LIMIT      = 5;        // 5 ticks
const uint16_t _CLOUD_BUF_WARNING      = 192;      // 192 bytes activate warning
const uint8_t  _CLOUD_POLL_ENABLE      = 1;        // poll enabled
const uint8_t  _CLOUD_CALLBACK_ENABLE  = 0;        // calback disabled
const uint8_t  _CLOUD_BOOTLOADER       = 0;        // wait bootloader sequence - 5 sec


const uint32_t _CLOUD_UART_CFG[ 4 ]   = 
{
    57600, 
    _UART_8_BIT_DATA, 
    _UART_NOPARITY, 
    _UART_ONE_STOPBIT
};