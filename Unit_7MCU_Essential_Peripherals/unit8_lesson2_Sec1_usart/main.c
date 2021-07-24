/*
 * unit 8_lesson2_Sec1_usart.c
 *
 * Created: 7/24/2021 1:50:49 PM
 * Author : Mostafa Elshiekh
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "GPIOs_driver.h"
#define F_CPU   8000000UL




int main(void)
{
	  char   Data;
	  char arr[100];
    /* Replace with your application code */
	Port_Direction(B,output);                    //make port B as output (LCD)
	Pin_Direction(A,6,output);                  //A6 as output (RS-LCD)
	Pin_Direction(A,7,output);                 //A7 as output (E-LCD)
	Pin_Direction(A,0,output);               //A6 as output (RS-LCD)
	
	USART_INIT();
	lcd_init();
	lcd_go_to(0,1);
	lcd_print("Uart TR");

	USART_SEND_STRING("Mostafa");
 
    while (1) 
    {
		Data =(char) USART_RECEIVE();
				if( Data)
				{
					lcd_go_to(2,8);
					lcd_out(Data);
				}
    }
	
}

