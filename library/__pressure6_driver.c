/*
    __pressure6_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__pressure6_driver.h"
#include "__pressure6_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */
const uint8_t _PRESSURE6_REG_MANUFACTURER_ID         = 0x0F;
const uint8_t _PRESSURE6_REG_PART_ID                 = 0x10;
const uint8_t _PRESSURE6_REG_POWER_DOWN              = 0x12;
const uint8_t _PRESSURE6_REG_RESET                   = 0x13;
const uint8_t _PRESSURE6_REG_MODE_CONTROL            = 0x14;
const uint8_t _PRESSURE6_REG_IIR_FIFO_CONTROL        = 0x15;
const uint8_t _PRESSURE6_REG_FIFO_DATA               = 0x18;
const uint8_t _PRESSURE6_REG_STATUS                  = 0x19;
const uint8_t _PRESSURE6_REG_PRESSURE_DATA           = 0x1A;
const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_MSB   = 0x1A;
const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_LSB   = 0x1B;
const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_XL    = 0x1C;
const uint8_t _PRESSURE6_REG_TEMP_DATA               = 0x1D;
const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_MSB       = 0x1D;
const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_LSB       = 0x1E;

/* Default  */
const uint8_t _PRESSURE6_DEF_SLAVE_ADDRESS         = 0x5D;
const uint8_t _PRESSURE6_DEF_MANUFACTURER_ID       = 0xE0;
const uint8_t _PRESSURE6_DEF_PART_ID               = 0x33;

/* POWER DOWN */
const uint8_t _PRESSURE6_DEVICE_POWER_DOWN = 0x00;
const uint8_t _PRESSURE6_DEVICE_ACTIVE     = 0x01;

/* RESET */
const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_RESET  = 0x00;
const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_ACTIVE = 0x01;

/* Mode control */
const uint8_t _PRESSURE6_MC_AVE_NUM_SINGLE      = 0x00;
const uint8_t _PRESSURE6_MC_AVE_NUM_2_TIMES     = 0x20;
const uint8_t _PRESSURE6_MC_AVE_NUM_4_TIMES     = 0x40;
const uint8_t _PRESSURE6_MC_AVE_NUM_8_TIMES     = 0x60;
const uint8_t _PRESSURE6_MC_AVE_NUM_16_TIMES    = 0x80;
const uint8_t _PRESSURE6_MC_AVE_NUM_32_TIMES    = 0xA0;
const uint8_t _PRESSURE6_MC_AVE_NUM_64_TIMES    = 0xC0;
const uint8_t _PRESSURE6_MC_AVE_NUM_PROHIBITED  = 0xE0;
const uint8_t _PRESSURE6_MC_DATA_READY_ENABLED  = 0x10;
const uint8_t _PRESSURE6_MC_DATA_READY_DISABLED = 0x00;
const uint8_t _PRESSURE6_MC_FULL_DATA_ENABLED   = 0x08;
const uint8_t _PRESSURE6_MC_FULL_DATA_DISABLED  = 0x00;
const uint8_t _PRESSURE6_MC_WATER_MARK_ENABLED  = 0x04;
const uint8_t _PRESSURE6_MC_WATER_MARK_DISABLED = 0x00;
const uint8_t _PRESSURE6_MC_MODE_STAND_BY       = 0x00;
const uint8_t _PRESSURE6_MC_MODE_ONE_SHOT       = 0x01;
const uint8_t _PRESSURE6_MC_MODE_CONTINUOUS     = 0x02;

/* IIR, FIFO control */
const uint8_t _PRESSURE6_FIFO_EN_MODE_BYPASS      = 0x00;
const uint8_t _PRESSURE6_FIFO_EN_MODE_ENABLED     = 0x80;
const uint8_t _PRESSURE6_WATER_MARK_LEVEL_24      = 0x00;
const uint8_t _PRESSURE6_WATER_MARK_LEVEL_28      = 0x40;
const uint8_t _PRESSURE6_IIR_MODE_IIR_OFF         = 0x00;
const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_WEAK     = 0x01;
const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_MIDDLE   = 0x02;
const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_STRONG   = 0x03;



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __PRESSURE6_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PRESSURE6_DRV_SPI__

void pressure6_spiDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __PRESSURE6_DRV_I2C__

void pressure6_i2cDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __PRESSURE6_DRV_UART__

void pressure6_uartDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void pressure6_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t pressure6_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];

    writeReg[ 0 ] = reg;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);

    return readReg[ 0 ];
}

uint16_t pressure6_getPressure()
{
    uint32_t pressure_counts = 0;
    uint32_t pressure_value = 0;

    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 3 ];

    writeReg[ 0 ] = 0x1A;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 3, END_MODE_STOP);

    pressure_counts = readReg[ 0 ];
    pressure_counts = pressure_counts << 8;
    pressure_counts |= readReg[ 1 ];
    pressure_counts = pressure_counts << 8;
    pressure_counts |= readReg[ 2 ];
    pressure_counts >>= 2;

    pressure_value = pressure_counts / 2048;

    return pressure_value;
}

uint8_t pressure6_getTemperatre()
{
    uint16_t temp_counts;
    uint8_t temp_value;

    temp_counts = pressure6_readByte(0x1D);
    temp_counts <<= 8;
    temp_counts |= pressure6_readByte(0x1E);

    temp_value = temp_counts / 32;

    return temp_value;
}


uint8_t pressure6_getInterrupt()
{
    return hal_gpio_intGet();
}

uint8_t pressure6_getStatus()
{
    uint8_t status;

    status = pressure6_readByte(0x19);
    return status;
}

void pressure6_powerON()
{
    Delay_1ms();
    pressure6_writeByte(_PRESSURE6_REG_POWER_DOWN, _PRESSURE6_DEVICE_ACTIVE);
    Delay_1ms();
    pressure6_writeByte(_PRESSURE6_REG_RESET, _PRESSURE6_MEASURE_CTRL_BLOCK_IS_ACTIVE);
    pressure6_writeByte(_PRESSURE6_REG_MODE_CONTROL, _PRESSURE6_MC_MODE_STAND_BY);
    Delay_100ms();
}

void pressure6_powerOFF()
{
    pressure6_writeByte(_PRESSURE6_REG_RESET, _PRESSURE6_MEASURE_CTRL_BLOCK_IS_RESET);
    pressure6_writeByte(_PRESSURE6_REG_POWER_DOWN, _PRESSURE6_DEVICE_POWER_DOWN);
    Delay_100ms();
}

void pressure6_waitingForNewData()
{
    uint8_t status;
    uint16_t cnt = 0;

    do{
        cnt++;
        if(cnt > 1000)
        {
            return;
        }
        status = pressure6_getStatus();
        Delay_10ms();

    }while((status & 0x01) == 0);
}

/* -------------------------------------------------------------------------- */
/*
  __pressure6_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */