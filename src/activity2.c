#include "activity2.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#define ADC_FLAG (!(ADCSRA&(1<<ADIF)))
void initializeADC(uint8_t ch)
{

    ADMUX|=(1<<REFS0);
    ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
    ch&=0x07;
    ADMUX&=0xf8;
    ADMUX|=ch;
}
uint16_t read_from_ADC()
{
    ADCSRA|=(1<<ADSC);
    while(ADC_FLAG);
    ADCSRA|=(1<<ADIF);
    return ADC;
}
