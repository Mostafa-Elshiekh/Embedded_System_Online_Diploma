/*
 * STM32_F103C6.h
 *
 *  Created on: Jul 4, 2021
 *      Author: Mostafa Elshiekh
 */

#ifndef INC_STM32_F103C6_H_
#define INC_STM32_F103C6_H_


/*==========================================================*/
//includes
/*==========================================================*/
#include <stdlib.h>
#include <stdint.h>

/************************************************************************************/

/*==========================================================*/
//Base Addresses For Memory
/*==========================================================*/
#define FLASH_MEMOY_BASE                          0x08000000
#define SYSTEM_MEMORY_BASE                        0x1FFFF000
#define SRAM_MEMORY_BASE                          0x20000000
#define PERIPHERALS_BASE                          0x20000000
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE       0xE0000000


/************************************************************************************/

/*==========================================================*/
/*Base Addresses For BUS PERIPHERALS*/
/*==========================================================*/

/*1-Base Addresses For AHB PERIPHERALS*/
#define RCC_BASE                                  0x40021000

/*2-Base Addresses For AHB PERIPHERALS*/


/*3-Base Addresses For ABB2 PERIPHERALS*/

//GPIO
// IN LQFP48 PACKAGE A,B GPIO FULLY INCLUDED & C,D PARTIAL INCLUDED & E NOT EXIST
#define GPIOA_BASE                               0x40010800
#define GPIOB_BASE                               0x40010C00
#define GPIOC_BASE                               0x40011000
#define GPIOD_BASE                               0x40011400
#define GPIOE_BASE                               0x40011800

//EXIT
#define EXIT_BASE                                0x40010400

//AFIO
#define AFIO_BASE                                0x40010000

/************************************************************************************/

/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS*/
/*==========================================================*/


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (RCC)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_TypeDef;


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (GPIO)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (EXTI)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (AFIO)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;   //0X14
	volatile uint32_t RESERVED0; //0X18
	volatile uint32_t MAPR2;     //0X1C
}AFIO_TypeDef;

/************************************************************************************/

/*==========================================================*/
/*PERIPHERALS INSTANCE*/
/*==========================================================*/
#define GPIOA                        ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                        ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                        ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                        ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                        ((GPIO_TypeDef *)GPIOE_BASE)

#define RCC                          ((RCC_TypeDef *)RCC_BASE)

#define EXTI                         ((EXTI_TypeDef *)EXTI_BASE)

#define AFIO                        ((AFIO_TypeDef *)AFIO_BASE)

/************************************************************************************/

/*==========================================================*/
/*CLOCK ENABLE MACROS*/
/*==========================================================*/
#define RCC_GPIOA_CLOCK_EN()             (RCC->APB2ENR |=(1<<2))
#define RCC_GPIOB_CLOCK_EN()             (RCC->APB2ENR |=(1<<3))
#define RCC_GPIOC_CLOCK_EN()             (RCC->APB2ENR |=(1<<4))
#define RCC_GPIOD_CLOCK_EN()             (RCC->APB2ENR |=(1<<5))
#define RCC_GPIOE_CLOCK_EN()             (RCC->APB2ENR |=(1<<6))

#define RCC_EXTI_CLOCK_EN()              (RCC->APB2ENR |=(1<<0))

/************************************************************************************/



#endif /* INC_STM32_F103C6_H_ */
