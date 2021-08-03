/*
 * SPI As  Master.c
 *
 * Created: 7/29/2021 6:17:09 PM
 * Author : Mostafa Elshiekh
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#define  F_CPU  8000000UL


#define SS             4
#define MOSI        5
#define MISO        6
#define SCK           7


void SPI_Master_Init(void)
{
	      /*Make this pins as output in master*/
	     DDRB = (1<<SS) | (1<<MOSI) | (1<<SCK) ;
		 
		/* SPE bit is written to one, the SPI is enabled*/
		/*Master SPI mode when written to one*/
		SPCR =  (1<<SPE) |  (1<<MSTR)  | (1<<SPR0);
	
}


unsigned char  SPi_Master_Transmit(unsigned char   Data )
{
		SPDR = Data;
		while( ! ( SPSR &(1<<SPIF))  ); //while transmit not complete -->wait
		return Data;
	
}


int main(void)
{
	
    SPI_Master_Init();
	DDRA = 0xFF;
	unsigned char  i=0 ,  j=0;
	
	while(1)
	{
  
		for( i=0 ; i<10 ; i++)
		{
			PORTA = SPi_Master_Transmit(SevenSeg[i]);
			_delay_ms(500);			
		}

	}
		
		return 0;
		
 
}

