
#include "lcd.h"
#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"



/*void Wait()
{
	int i=0;
	for(i=0;i<2000;i++);
}


void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
	Wait();
	Wait();

	Wait();

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);

	/*LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);*/

/*
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT(){
	Wait();
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}



void LCD_WRITE_COMMAND(unsigned char command)
{

	MCAL_GPIO_WritePort(LCD_CTRL, command);
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 0);
	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH, 0);
	Wait();
	LCD_lcd_kick();
}

void LCD_WRITE_CHAR(unsigned char character){

	MCAL_GPIO_WritePort(LCD_CTRL, character);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, 0);

	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, 1);

	Wait();
	LCD_lcd_kick();
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}*/
