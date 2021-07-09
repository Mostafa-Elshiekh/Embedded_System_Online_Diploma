#include "LCD_ME.h"
#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"



#define mode 8



void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void Wait()
{
	int i=0;
	for(i=0;i<50000;i++);
}


void LCD_INIT()
{


	Wait();
	LCD_clear_screen();

	if(mode==8)
	{

		Wait();
		LCD_WRITE_COMMAND(0x38);
	}
	else if(mode==4)
	{

		LCD_WRITE_COMMAND(0x33);
		LCD_WRITE_COMMAND(0x32);
		LCD_WRITE_COMMAND(0x28);
	}
	LCD_WRITE_COMMAND(0x0e);
	LCD_WRITE_COMMAND(0x01);
	Wait();
	LCD_WRITE_COMMAND(0x06);
}
void LCD_WRITE_COMMAND(unsigned char command)//send commends to LCD
{
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 0);
	if(mode==8)
	{
		MCAL_GPIO_WritePort(LCD_CTRL, command);
	}
	/*else if(mode==4)
		{
			(*(volatile char*)(data+2))=cmd &0xf0;               //TAKE THE FIRST FOUR BIT  ON LEFT
			(*(volatile char*)(commmand+2))&=~(1<<RS);          // MAKE RS=0 BECAUSE I SEND COMMMANDS
			(*(volatile char*)(commmand+2))|=(1<<E);           //MAKE ENABLE AS HIGH PULSE
		Wait();
			(*(volatile char*)(commmand+2))&=~(1<<E);        //MAKE ENABLE AS LOW PULSE
		Wait();
			(*(volatile char*)(data+2))=cmd<<4;            //SHIFT THE LAST FOUR BITS
		}*/
	else if(mode==4)
	{

		unsigned char temp = command&0xf0;
		MCAL_GPIO_WritePort(LCD_CTRL, temp );
		MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 0);
		MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
		Wait();
		Wait();

		MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);
		Wait();
		temp= command<<4;
		MCAL_GPIO_WritePort(LCD_CTRL, temp);

	}

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
	Wait();
	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);
	Wait();
	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
	Wait();
	Wait();
	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);
}

void LCD_WRITE_CHAR(unsigned char character)  // send data to LCD as (char)
{

	if(mode==8)
	{
		MCAL_GPIO_WritePort(LCD_CTRL, character);                //TAKE THE ALL BYTE
	}
	/*else if(mode==4)
		{
			(*(volatile char*)(data+2))=value &0xf0;             //TAKE THE FIRST FOUR BIT ON LEFT
			(*(volatile char*)(commmand+2))|=(1<<E);           //MAKE ENABLE AS HIGH PULSE
		Wait();
			(*(volatile char*)(commmand+2))&=~(1<<E);        //MAKE ENABLE AS LOW PULSE
		Wait();
			(*(volatile char*)(data+2))=value<<4;          //SHIFT THE LAST FOUR BITS
		}*/
	else if(mode==4)
	{
		unsigned char temp = character&0xf0;

		MCAL_GPIO_WritePort(LCD_CTRL, temp);
		MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
		Wait();
		Wait();

		MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);
		Wait();
		temp=character<<4;
		MCAL_GPIO_WritePort(LCD_CTRL,temp );

	}
	MCAL_GPIO_WritePin(GPIOA, RS_SWITCH, 1);             // MAKE RS=1 BECAUSE I SEND DATA
	MCAL_GPIO_WritePin(GPIOA, RW_SWITCH, 0);
	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 1);
	Wait();
	Wait();

	MCAL_GPIO_WritePin(GPIOA, EN_SWITCH, 0);

}
void LCD_WRITE_STRING(char* string)
// print string
{
	unsigned char i=0;
	while(string[i]!=0)
	{
		if(i==15)
		{
			LCD_GOTO_XY(2, 1);
			LCD_WRITE_CHAR(string[i]);
			i++;
		}
		else
		{
			LCD_WRITE_CHAR(string[i]);
			i++;
		}

	}
}

void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	unsigned char first[]={0x80,0xC0,0x94,0xD4};
	LCD_WRITE_COMMAND(first [line-1]+position-1);
	Wait();
}

void LCD_INT_NUM(int value) // print integer value
{
	LCD_WRITE_CHAR(value+48); //val+48 as ASCLL code
}


void lcd_num(int n){
	/*lcd_out((n/1000)+48);
	n %= 1000;

	lcd_out((n/100)+48);
	n %= 100;*/

	LCD_WRITE_CHAR((n/10)+48);
	n %= 10;

	LCD_WRITE_CHAR(n+48);
}
