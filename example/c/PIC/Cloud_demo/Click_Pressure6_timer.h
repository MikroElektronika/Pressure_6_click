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
    T1CON	 = 0x01;
    TMR1IF_bit	 = 0;
    TMR1H	 = 0xC1;
    TMR1L	 = 0x80;
    TMR1IE_bit	 = 1;
    INTCON	 = 0xC0;
}

void Interrupt()
{
    if (TMR1IF_bit != 0)
    { 
    	cloud_tick();
        taskTime++;
        TMR1IF_bit = 0;
        TMR1H	 = 0xC1;
        TMR1L	 = 0x80;
    }
}
