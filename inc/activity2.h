#ifndef ACTIVITY2_H_
#define ACTIVITY2_H_
#include<avr/io.h>
#include<avr/interrupt.h>
void initializeADC(uint8_t);
uint16_t read_from_ADC();

#endif // ACTIVITY2_H_
