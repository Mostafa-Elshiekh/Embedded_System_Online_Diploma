
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#define RCC_base 0x40021000
#define GPIOA_base 0x40010800
#define GPIOB_base 0x40010C00

#define RCC_APB2ENR *(( volatile uint32_t *)(RCC_base+0x18))

#define GPIOA_CRL *(( volatile uint32_t *)(GPIOA_base+0x00))
#define GPIOA_CRH *(( volatile uint32_t *)(GPIOA_base+0x04))
#define GPIOA_IDR *(( volatile uint32_t *)(GPIOA_base+0x08))
#define GPIOA_ODR *(( volatile uint32_t *)(GPIOA_base+0x0C))

#define GPIOB_CRL *(( volatile uint32_t *)(GPIOB_base+0x00))
#define GPIOB_CRH *(( volatile uint32_t *)(GPIOB_base+0x04))
#define GPIOB_IDR *(( volatile uint32_t *)(GPIOB_base+0x08))
#define GPIOB_ODR *(( volatile uint32_t *)(GPIOB_base+0x0C))

void clock_init(void)
{
	RCC_APB2ENR |=(1<<2); // enable clock for GPIOA
	RCC_APB2ENR |=(1<<3); // enable clock for GPIOB
}
void GPIO_init(void)
{   GPIOA_ODR=0;
GPIOA_CRL &=0xffffff0f;  // clear bits of PA1
GPIOA_CRL |=(1<<6);  // PA1 in input floating
GPIOA_CRH &=0xff0fffff; // clear bits of PA13
GPIOA_CRH |=(1<<22); // PA13 in input flaoting

GPIOB_CRL &=0xffffff0f;  // clear bits of PB1
GPIOB_CRL |=(1<<4);  // PB1 output pull-push and 10MHZ max Speed
GPIOB_CRH &=0xff0fffff; // clear bits of PB13
GPIOB_CRH |=(1<<20); // PB13 output pull-push  10MHZ max Speed


}
void my_wait(uint32_t x)
{
	uint32_t y,z;
	for(y=0;y<x;y++)
		for(z=0;z<255;z++);

}
int main(void)
{
	clock_init();
	GPIO_init();
	unsigned int flag=0;
	while(1)
	{
		//PA1 >>> is connected to PUR
		if(((GPIOA_IDR & (1<<1)) >>1 ) == 0 && flag==1) // button pressed
		{
			GPIOB_ODR ^=(1<<1); // toggle led on PB1
			flag=0;

		}
		if(((GPIOA_IDR & (1<<1)) >>1 ) == 1)
		{
			flag=1;
		}


			//PA13 >>> is connected to PDR
			if(((GPIOA_IDR & (1<<13)) >>13 ) ==1 ) // button pressed
			{
				GPIOB_ODR ^=(1<<13); // toggle led on PB13 multipressing

			}
		my_wait(300);
	}


}
