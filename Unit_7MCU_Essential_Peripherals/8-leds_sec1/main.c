/*
 * 8-leds.c
 *
 * Created: 6/16/2021 1:49:30 PM
 * Author : musta
 */ 
#define F_CPU  8000000UL
#include <MemoryMap.h>
#include <util/delay.h>

void init(void)
{
	DDRA = 0xff;
}

int main(void)
{
	
    /* Replace with your application code */
	init();
	  int NumPin;
    while (1) 
    {
	 
				 for(NumPin=0;NumPin<8;NumPin++)
				 {
					 SetBin(NumPin,PORTA);
					 _delay_ms(20);
				 }
				 
				 for(NumPin=7;NumPin>=0;NumPin--)
				 {
					 RestBin(NumPin,PORTA);
					 _delay_ms(20);
				 }
	 }
	return 0;
}

