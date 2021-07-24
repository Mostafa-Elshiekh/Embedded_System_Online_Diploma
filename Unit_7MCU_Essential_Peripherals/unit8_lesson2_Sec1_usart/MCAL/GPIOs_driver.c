#include "GPIOs_driver.h"

void  Bin_Set(uint8_t  base , uint8_t  bit)
{
	( *(volatile uint8_t  *)(base+2)) |=(1<<bit);
}
void	 Bin_Rest (uint8_t  base , uint8_t  bit)
{
	( *(volatile uint8_t  *)(base+2))&=~(1<<bit);
}
void	 toggle_bit (uint8_t  reg , uint8_t  bit)
{
	reg^=(1<<bit);
	_delay_ms(100);
}

void Pin_Direction(uint8_t  base , uint8_t  bin , uint8_t  state )  //base is register bin
{
	if(state==output)
	{
		( *(volatile uint8_t  *)(base+1)) |=(1<<bin);	  //base+1 = DDR(BASE)
	}
	else{
		( *(volatile uint8_t  *)(base+1))&=~(1<<bin);    //DDRA = (*(volatile  uint8_t *)base+1
	}
}

void Port_Direction(uint8_t  base  , uint8_t  state )  //base is register bin
{
	if(state==output)
	{
		(*(volatile uint8_t  *)(base+1))=0xff;	  //base+1 = DDR(BASE)
	}
	else{
		(*(volatile  uint8_t  *)(base+1))=0x00;    //DDRA = (*(volatile  uint8_t *)base+1
	}
}
uint8_t  Port_Read(uint8_t  base)
{
	uint8_t  result;
	result = (*(volatile uint8_t *)(base));
	return result;
}

uint8_t  Port_Write(uint8_t  base , uint8_t  value)
{
	uint8_t   result;
	(*(volatile uint8_t *)(base+2))=value;
	return result;
}

uint8_t  Bin_Read(uint8_t  base , uint8_t   bin)
{
	uint8_t  result;
	result = (*(volatile uint8_t *)(base)) & (1<<bin);
	return result;
}

uint8_t  Bin_Write(uint8_t  base , uint8_t  bin, uint8_t  value)
{
	if(value==0)
	{
		(*(volatile uint8_t *)(base+2)) &=~(1<<bin);
	}
	else{
		(*(volatile uint8_t *)(base+2) )  |=(1<<bin);
	}
}


