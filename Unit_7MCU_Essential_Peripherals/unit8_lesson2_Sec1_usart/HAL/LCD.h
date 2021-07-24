/*
 * LCD.h
 *
 * Created: 7/24/2021 1:55:24 PM
 *  Author:  Mostafa Elshiekh
 */ 


#ifndef LCD_H_
#define LCD_H_

#define A  0x39
#define B  0x36
#define C  0x33
#define D  0x30

#define data B
#define commmand A
#define RS 6
#define E  7
#define mode 8

void lcd_init();
void lcd_command(char cmd) ;//send commends to LCD
void lcd_out(unsigned char value) ; // send data to LCD as (char)
void lcd_print(char *str);// print string
void lcd_go_to(unsigned char x,unsigned char y) ;// determine position
void lcd_int(int value) ;// print integer value
void lcd_num(int n);


#endif /* LCD_H_ */