/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/

#include "Click_Pressure6_types.h"

#define __Cloud_PRESSURE6__

uint16_t taskTime;

static void cloud_configTimer()
{
    SREG_I_bit = 1; 
    TCCR1A = 0x80;
    TCCR1B = 0x09;
    OCR1AH = 0x1F; 
    OCR1AL = 0x3F; 
    OCIE1A_bit = 1; 
}

void Timer_interrupt() org IVT_ADDR_TIMER1_COMPA
{
    cloud_tick();
    taskTime++;
}