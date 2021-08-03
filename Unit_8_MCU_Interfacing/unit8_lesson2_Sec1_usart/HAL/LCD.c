/*
 * LCD.c
 *
 * Created: 7/24/2021 1:51:41 PM
 *  Author: musta
 */ 


#include "LCD.h"
#include <avr/delay.h>
void lcd_init()
{
	(*(volatile char*)(commmand+2))&=~(1<<E);         //RESET E BIN TO EQUAL 0
	(*(volatile char*)(commmand+1))|=(1<<RS);        //DDRB=0XFF  -DEFINATION PORT B AS OUTPUT
	(*(volatile char*)(commmand+1))|=(1<<E);        //DDRB=0XFF  -DEFINATION PORT B AS OUTPUT
	(*(volatile char*)(data+2))=0x00;              //PORTD=0X00   -AS INIT VALUE-
	(*(volatile char*)(commmand+2))&=~(1<<E);     //RESET E BIN TO EQUAL 0
	
	if(mode==8)
	{
		(*(volatile char*)(data+1))=0xff;       //DDRD AS OUTPUT
		_delay_ms(2);
		lcd_command(0x38);
	}
	else if(mode==4)
	{
		(*(volatile char*)(data+1))&=0xf0;  //FIRST FOUR BITS AS OUTPUT AND SECOND FOUR BITS DONT CARE
		lcd_command(0x33);
		lcd_command(0x32);
		lcd_command(0x28);
	}
	lcd_command(0x0e);
	lcd_command(0x01);
	_delay_ms(2);
	lcd_command(0x06);
}
void lcd_command(char cmd) //send commends to LCD
{
	(*(volatile char*)(commmand+2))&=~(1<<RS);                    // MAKE RS=0 BECAUSE I SEND COMMMANDS
	if(mode==8)
	{
		(*(volatile char*)(data+2))=cmd;                       //TAKE THE ALL BYTE
	}
	else if(mode==4)
	{
		(*(volatile char*)(data+2))=cmd &0xf0;               //TAKE THE FIRST FOUR BIT  ON LEFT
		(*(volatile char*)(commmand+2))&=~(1<<RS);          // MAKE RS=0 BECAUSE I SEND COMMMANDS
		(*(volatile char*)(commmand+2))|=(1<<E);           //MAKE ENABLE AS HIGH PULSE
		_delay_ms(1);
		(*(volatile char*)(commmand+2))&=~(1<<E);        //MAKE ENABLE AS LOW PULSE
		_delay_ms(0.1);
		(*(volatile char*)(data+2))=cmd<<4;            //SHIFT THE LAST FOUR BITS
	}
	
	(*(volatile char*)(commmand+2 ))|=(1<<E);       //MAKE ENABLE AS HIGH PULSE
	_delay_ms(1);
	(*(volatile char*)(commmand+2))&=~(1<<E);     //MAKE ENABLE AS LOW PULSE
	_delay_ms(0.1);
}
void lcd_out(unsigned char value)  // send data to LCD as (char)
{
	(*(volatile char*)(commmand+2))|=(1<<RS);                // MAKE RS=1 BECAUSE I SEND DATA
	if(mode==8)
	{
		(*(volatile char*)(data+2))=value;                   //TAKE THE ALL BYTE
	}
	else if(mode==4)
	{
		(*(volatile char*)(data+2))=value &0xf0;             //TAKE THE FIRST FOUR BIT ON LEFT
		(*(volatile char*)(commmand+2))|=(1<<E);           //MAKE ENABLE AS HIGH PULSE
		_delay_ms(1);                                     //DELAY
		(*(volatile char*)(commmand+2))&=~(1<<E);        //MAKE ENABLE AS LOW PULSE
		_delay_ms(0.1);
		(*(volatile char*)(data+2))=value<<4;          //SHIFT THE LAST FOUR BITS
	}
	(*(volatile char*)(commmand+2))|=(1<<E);             //MAKE ENABLE AS HIGH PULSE
	_delay_ms(1);                                       //DELAY
	(*(volatile char*)(commmand+2))&=~(1<<E);          //MAKE ENABLE AS LOW PULSE
	_delay_ms(0.1);
}
void lcd_print(char *str)// print string
{
	unsigned char i=0;
	while(str[i]!=0) {lcd_out(str[i]);i++;}
}
void lcd_go_to(unsigned char x,unsigned char y) // determine position
{
	unsigned char first[]={0x80,0xC0,0x94,0xD4};
	lcd_command(first [x-1]+y-1);
	_delay_ms(100);
}
void lcd_int(int value) // print integer value
{
	lcd_out(value+48); //val+48 as ASCLL code
}


void lcd_num(int n){
	/*lcd_out((n/1000)+48);
	n %= 1000;
	lcd_out((n/100)+48);
	n %= 100;*/

	lcd_out((n/10)+48);
	n %= 10;

	lcd_out(n+48);
}

