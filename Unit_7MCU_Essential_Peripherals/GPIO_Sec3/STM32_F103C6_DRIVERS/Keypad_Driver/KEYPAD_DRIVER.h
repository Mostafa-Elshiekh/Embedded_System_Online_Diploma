/*
 *KEYPAD_DRIVER.h
 *
 * Created: 7/3/2021 2:04:20 PM
 *  Author: Mostafa Elshiekh
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_


#include <stdint.h>

#define KEYPAD_PORT  PORTD
#define DATA_DIR_PORT DDRD
#define KEYPAD_PIN  PIND

//KEYPAD RAWS
#define  R0      0
#define  R1        1
#define  R2       2
#define  R3       3

//KEYPAD COULMNS
#define  C0      4
#define  C1        5
#define  C2       6
#define  C3       7

//KEYPAD FUNCTIONS
void Keypad_init(void);
char  keypad(void);



#endif /* INCFILE1_H_ */
