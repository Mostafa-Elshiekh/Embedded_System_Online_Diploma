/*
 * USART.h
 *
 * Created: 7/23/2021 9:57:37 PM
 *  Author:  Mostafa Elshiekh
 */ 

#ifndef USART_H_
#define USART_H_

/*include*/
#include <avr/io.h>
#include "AVR_MEMORY_MAP.h"
#include <stdint.h>


/*MCAL USART APIs*/
void USART_INIT(void);
void USART_SEND(uint8_t data );
uint8_t USART_RECEIVE(void);
void USART_SEND_STRING(char *STR);
uint8_t  *USART_RECEIVE_STRING(char arr[] );
#endif /* USART_H_ */