/*
    __pressure6_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __pressure6_driver.h
@brief    Pressure6 Driver
@mainpage Pressure6 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   PRESSURE6
@brief      Pressure6 Click Driver
@{

| Global Library Prefix | **PRESSURE6** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **sep 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PRESSURE6_H_
#define _PRESSURE6_H_

/**
 * @macro T_PRESSURE6_P
 * @brief Driver Abstract type
 */
#define T_PRESSURE6_P    const uint8_t*

/** @defgroup PRESSURE6_COMPILE Compilation Config */              /** @{ */

//  #define   __PRESSURE6_DRV_SPI__                            /**<     @macro __PRESSURE6_DRV_SPI__  @brief SPI driver selector */
   #define   __PRESSURE6_DRV_I2C__                            /**<     @macro __PRESSURE6_DRV_I2C__  @brief I2C driver selector */
// #define   __PRESSURE6_DRV_UART__                           /**<     @macro __PRESSURE6_DRV_UART__ @brief UART driver selector */

                                                                       /** @} */
/** @defgroup PRESSURE6_VAR Variables */                           /** @{ */

/* Register */
extern const uint8_t _PRESSURE6_REG_MANUFACTURER_ID        ;
extern const uint8_t _PRESSURE6_REG_PART_ID                ;
extern const uint8_t _PRESSURE6_REG_POWER_DOWN             ;
extern const uint8_t _PRESSURE6_REG_RESET                  ;
extern const uint8_t _PRESSURE6_REG_MODE_CONTROL           ;
extern const uint8_t _PRESSURE6_REG_IIR_FIFO_CONTROL       ;
extern const uint8_t _PRESSURE6_REG_FIFO_DATA              ;
extern const uint8_t _PRESSURE6_REG_STATUS                 ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA          ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_MSB  ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_LSB  ;
extern const uint8_t _PRESSURE6_REG_PRESSURE_DATA_OUT_XL   ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA              ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_MSB      ;
extern const uint8_t _PRESSURE6_REG_TEMP_DATA_OUT_LSB      ;

/* Default  */
extern const uint8_t _PRESSURE6_DEF_SLAVE_ADDRESS   ;
extern const uint8_t _PRESSURE6_DEF_MANUFACTURER_ID ;
extern const uint8_t _PRESSURE6_DEF_PART_ID         ;

/* POWER DOWN */
extern const uint8_t _PRESSURE6_DEVICE_POWER_DOWN;
extern const uint8_t _PRESSURE6_DEVICE_ACTIVE    ;

/* RESET */
extern const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_RESET  ;
extern const uint8_t _PRESSURE6_MEASURE_CTRL_BLOCK_IS_ACTIVE ;

/* Mode control */
extern const uint8_t _PRESSURE6_MC_AVE_NUM_SINGLE      ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_2_TIMES     ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_4_TIMES     ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_8_TIMES     ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_16_TIMES    ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_32_TIMES    ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_64_TIMES    ;
extern const uint8_t _PRESSURE6_MC_AVE_NUM_PROHIBITED  ;
extern const uint8_t _PRESSURE6_MC_DATA_READY_ENABLED  ;
extern const uint8_t _PRESSURE6_MC_DATA_READY_DISABLED ;
extern const uint8_t _PRESSURE6_MC_FULL_DATA_ENABLED   ;
extern const uint8_t _PRESSURE6_MC_FULL_DATA_DISABLED  ;
extern const uint8_t _PRESSURE6_MC_WATER_MARK_ENABLED  ;
extern const uint8_t _PRESSURE6_MC_WATER_MARK_DISABLED ;
extern const uint8_t _PRESSURE6_MC_MODE_STAND_BY       ;
extern const uint8_t _PRESSURE6_MC_MODE_ONE_SHOT       ;
extern const uint8_t _PRESSURE6_MC_MODE_CONTINUOUS     ;

/* IIR, FIFO control */
extern const uint8_t _PRESSURE6_FIFO_EN_MODE_BYPASS    ;
extern const uint8_t _PRESSURE6_FIFO_EN_MODE_ENABLED   ;
extern const uint8_t _PRESSURE6_WATER_MARK_LEVEL_24    ;
extern const uint8_t _PRESSURE6_WATER_MARK_LEVEL_28    ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_OFF       ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_WEAK   ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_MIDDLE ;
extern const uint8_t _PRESSURE6_IIR_MODE_IIR_ON_STRONG ;

                                                                       /** @} */
/** @defgroup PRESSURE6_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PRESSURE6_INIT Driver Initialization */              /** @{ */

#ifdef   __PRESSURE6_DRV_SPI__
void pressure6_spiDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P spiObj);
#endif
#ifdef   __PRESSURE6_DRV_I2C__
void pressure6_i2cDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P i2cObj, uint8_t slave);
#endif
#ifdef   __PRESSURE6_DRV_UART__
void pressure6_uartDriverInit(T_PRESSURE6_P gpioObj, T_PRESSURE6_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void pressure6_gpioDriverInit(T_PRESSURE6_P gpioObj);
                                                                       /** @} */
/** @defgroup PRESSURE6_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] addr    Register in which the data will be written
 * @param[in] _data   Data which be written in the register
 */
void pressure6_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] reg    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t pressure6_readByte(uint8_t reg);

/**
 * @brief Functions for read Pressure data
 *
 * @retval Function return Pressure data in [hPa]
 */
uint16_t pressure6_getPressure();

/**
 * @brief Functions for read Temperature data
 *
 * @retval Function return Temperature data in [C]
 */
uint8_t pressure6_getTemperatre();

/**
 * @brief Function reads interrupt pin state
 *
 * @retval Interrupt pin state
 */
uint8_t pressure6_getInterrupt();

/**
 * @brief Function read device Status
 *
 * @retval device Status (read status register)
 */
uint8_t pressure6_getStatus();

/**
 * @brief Power ON procedure
 */
void pressure6_powerON();

/**
 * @brief Power OFF procedure
 */
void pressure6_powerOFF();

/**
 * @brief Waiting for new data
 */
void pressure6_waitingForNewData();







                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Pressure6_STM.c
    @example Click_Pressure6_TIVA.c
    @example Click_Pressure6_CEC.c
    @example Click_Pressure6_KINETIS.c
    @example Click_Pressure6_MSP.c
    @example Click_Pressure6_PIC.c
    @example Click_Pressure6_PIC32.c
    @example Click_Pressure6_DSPIC.c
    @example Click_Pressure6_AVR.c
    @example Click_Pressure6_FT90x.c
    @example Click_Pressure6_STM.mbas
    @example Click_Pressure6_TIVA.mbas
    @example Click_Pressure6_CEC.mbas
    @example Click_Pressure6_KINETIS.mbas
    @example Click_Pressure6_MSP.mbas
    @example Click_Pressure6_PIC.mbas
    @example Click_Pressure6_PIC32.mbas
    @example Click_Pressure6_DSPIC.mbas
    @example Click_Pressure6_AVR.mbas
    @example Click_Pressure6_FT90x.mbas
    @example Click_Pressure6_STM.mpas
    @example Click_Pressure6_TIVA.mpas
    @example Click_Pressure6_CEC.mpas
    @example Click_Pressure6_KINETIS.mpas
    @example Click_Pressure6_MSP.mpas
    @example Click_Pressure6_PIC.mpas
    @example Click_Pressure6_PIC32.mpas
    @example Click_Pressure6_DSPIC.mpas
    @example Click_Pressure6_AVR.mpas
    @example Click_Pressure6_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __pressure6_driver.h

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