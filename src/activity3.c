#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "activity3.h"
void initializePWM()
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    DDRD|=(1<<PD6);
}
void executePWM(uint8_t compare)
{

    OCR0A=compare;
    _delay_ms(2000);
}
