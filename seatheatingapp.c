#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"
int main(void)
{

    initializeLED();
    initializeADC(0);
    initializePWM();
    initializeUART(103);
    uint16_t temp_digital;
    while(1)
    {
    executeLED();
    temp_digital=read_from_ADC();
    if(temp_digital>0&&temp_digital<=200)
    {
        executePWM(51);
        writUART(20);

    }
    else if(temp_digital>=210&&temp_digital<=500)
    {

        executePWM(102);
        writUART(25);
    }
    else if(temp_digital>=510&&temp_digital<=700)
    {
        executePWM(179);
        writUART(29);
    }
    else if(temp_digital>=710&&temp_digital<=1023)
    {

        executePWM(243);
        writUART(33);
    }
    else{}
    }
    return 0;
}
