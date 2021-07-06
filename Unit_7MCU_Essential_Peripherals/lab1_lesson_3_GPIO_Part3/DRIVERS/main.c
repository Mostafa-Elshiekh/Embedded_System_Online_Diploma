/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Elshiekh
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"

void Clock_Init()
{

	/*Enable lock For GPIOA && GPIOB*/
	RCC_GPIOA_CLOCK_EN();
	RCC_GPIOB_CLOCK_EN();
}

void GPIO_Init()
{

	GPIO_Pin_Configure_t PinCinfg;


	//make GPIOA Pin 1 as Input Mode && Floating input
	PinCinfg.GPIO_Pin_Number=GPIO_PIN_1;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	//make GPIOB Pin 1 as 10:Output Mode with max speed 10 MHz.
	PinCinfg.GPIO_Pin_Number=GPIO_PIN_1;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	//make GPIOA Pin 13 as Input Mode && Floating input
	PinCinfg.GPIO_Pin_Number=GPIO_PIN_13;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	//make GPIOB Pin 13 as 10:Output Mode with max speed 10 MHz.
	PinCinfg.GPIO_Pin_Number=GPIO_PIN_13;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);


}

void Wait()
{
	int i=0;
	for(i=0;i<20000;i++);
}


int main(void)
{
	Clock_Init();
	GPIO_Init();
	int flag=0;



	while(1)
	{
		//PA1 >>> is connected to PUR
		if( (MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_1) == 0  && flag==1)) //  button pressed == 1 bcs the button is BUR
			//the right shift to compare with one or zero
		{
			// toggle led on PB1
			MCAL_GPIO_Toggle_pin(GPIOB, GPIO_PIN_1);
			flag=0;

		}
		//if( ((GPIOA_IDR & (1<<1)) >>1 ) == 1)
		if( MCAL_GPIO_Read_Pin(GPIOA,GPIO_PIN_1) == 1)
		{
			flag=1;
		}


		//PA13 >>> is connected to PDR
		if( MCAL_GPIO_Read_Pin(GPIOA,GPIO_PIN_13)==1) // button pressed
		{
			// toggle led on PB13 multipressing

			MCAL_GPIO_Toggle_pin(GPIOB, GPIO_PIN_13);

		}

		Wait();
	}
}

