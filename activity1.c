/*
 */
#include "activity1.h"
#include <avr/io.h>
#include<util/delay.h>
#define LED_FLAG ((PIND&(1<<PD0))&&(PIND&(1<<PD1)))
void  initializeLED()
{

    DDRD &=~(1<<PD0);// clear bit0 that configures PD0 for input of  button sensor
    DDRD &=~(1<<PD2);//clear bit2 that configures PD2 for input of heater
    DDRB|=(1<<PB0);//set bit0 that configures PB0 for output of LED

}
void executeLED()
{
        if(LED_FLAG) //when both PD0 and PD2 are HIGH the LED is given HIGH so that it glows
        {
            PORTB|=(1<<PB0);
            _delay_ms(2000);
        }
        else
        {

            PORTB&=~(1<<PB0);
            _delay_ms(2000);
    }

}
