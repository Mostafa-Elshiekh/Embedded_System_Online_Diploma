/*
 * USART.c
 *
 * Created: 7/23/2021 9:57:23 PM
 *  Author: Mostafa Elshiekh
 */ 
#include "USART.h"
#include "GPIOs_driver.h"

void USART_INIT(void)
{
  //BaudRate
	UBRRL =  51 ;
	
	//Frame
	/*Reset Bit 5:4 – UPM1:0: Parity Mode To No Parity*/
    RestBin(UCSRC,4);
	RestBin(UCSRC,5);

    //	RestBin(UCSRC,3);	//Bit 3 – USBS: Stop Bit Select One Stop
      UCSRC &=~(1<<3);
	//Set Bit 2:1 – UCSZ1:0: Character Size To 8bit & Reset UCSZ2 in UCSZ2
      SetBin(UCSRC,1);
	 SetBin(UCSRC,2);
	 RestBin(UCSRB,2);
	//Enable
	SetBin(UCSRB,3);//Bit 3 – TXEN: Transmitter Enable
	SetBin(UCSRB,4);//Bit 4 – RXEN: Receiver Enable
}

void USART_SEND(uint8_t data )
{
	while(  ! (UCSRA & (1<<5) ) );
	UDR = data;
}

uint8_t USART_RECEIVE(void)
{
		while(  ! (UCSRA & (1<<7) ));
		return UDR;
}

void USART_SEND_STRING(char *STR)
{
	unsigned char i=0;
	while(STR[i] !=0)
	{
		USART_SEND(STR[i]);
		i++;
	}
}

void  USART_RECEIVE_STRING(uint8_t  *Buff )
{
	uint8_t  i=;
	Buff[i] = USART_RECEIVE();
	while(   Buff[i]  != '\0'               )
	{
		i++;
		Buff[i] = USART_RECEIVE();
	}
}