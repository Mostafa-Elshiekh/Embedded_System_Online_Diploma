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
#include "LCD_ME.h"





void Clock_Init()
{

	/*Enable lock For GPIOA && GPIOB*/
	RCC_GPIOA_CLOCK_EN();
	RCC_GPIOB_CLOCK_EN();
}


void GPIO_Init()
{

	GPIO_Pin_Configure_t PinCinfg;

	//LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	PinCinfg.GPIO_Pin_Number=RS_SWITCH;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=RW_SWITCH;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=EN_SWITCH;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);





	//Data Lines A0>>A7
	PinCinfg.GPIO_Pin_Number=GPIO_PIN_0;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_1;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_2;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_3;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_4;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_5;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_6;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_7;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 0);
	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH, 0);

	//keypad
	/*DDRD=0x0F;

	PORTD= 0xFF;*/

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_0;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_1;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_3;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_4;
	PinCinfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_5;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_6;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_7;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);

	PinCinfg.GPIO_Pin_Number=GPIO_PIN_8;
	PinCinfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCinfg);


}



int main(void)
{
	Clock_Init();
	GPIO_Init();
	LCD_INIT();



	LCD_WRITE_STRING("Enter Number: ");
	LCD_WRITE_COMMAND(0xc);
	LCD_GOTO_XY(2, 1);
	while(1)
	{

		if(keypad() !='N' && keypad()!='c')
		{
			LCD_WRITE_CHAR(keypad());
			while(keypad()!='N');
		}
		if(keypad()=='c')
		{
			LCD_clear_screen();
			Wait();
			LCD_WRITE_STRING("Enter Number: ");

			LCD_WRITE_COMMAND(0xc);
			LCD_GOTO_XY(2, 1);
		}

	}
}

