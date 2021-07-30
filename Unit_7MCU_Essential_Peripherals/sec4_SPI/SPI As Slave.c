/*
 * SPI As Slave.c
 *
 * Created: 7/29/2021 7:11:41 PM
 * Author : Mostafa Elshiekh
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU       8000000UL


#define SS             4
#define MOSI        5
#define MISO        6
#define SCK           7

void SPI_Slave_Init(void)
{
	
	   /*Make this pins as input in slave*/
	   DDRB &= ~( (1<<SS) | (1<<MOSI) | (1<<SCK) );
	   
	   /* SPE bit is written to one, the SPI is enabled*/
	   SPCR = ( (1<<SPE)  | (1<<SPR0) );
	   
	  /*Slave SPI mode when written to zero*/
	   SPCR &=~(1<<MSTR);
   
}

uint8_t SPI_Slave_Receive(void )
{
	
	while( ! ( SPSR &(1<<SPIF))  ); //while Receive not complete -->wait
	return SPDR;
	
}


int main(void)
{
	SPI_Slave_Init();
	DDRA = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTA =SPI_Slave_Receive();
				_delay_ms(500);
    }
}

