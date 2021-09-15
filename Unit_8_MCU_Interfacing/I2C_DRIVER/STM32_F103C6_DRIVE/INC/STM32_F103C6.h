/*
 * STM32_F103C6.h
 *
 *  Created on: Jul 17, 2021
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

/*2-Base Addresses For ABB1 PERIPHERALS*/

//USART2
#define USART2_BASE                              0x40004400

//USART3
#define USART3_BASE                              0x40004800

//SPI2
#define SPI2_BASE                                0X40003800


/*3-Base Addresses For ABB2 PERIPHERALS*/

//GPIO
// IN LQFP48 PACKAGE A,B GPIO FULLY INCLUDED & C,D PARTIAL INCLUDED & E NOT EXIST
#define GPIOA_BASE                               0x40010800
#define GPIOB_BASE                               0x40010C00
#define GPIOC_BASE                               0x40011000
#define GPIOD_BASE                               0x40011400
#define GPIOE_BASE                               0x40011800

//EXIT
#define EXTI_BASE                                0x40010400

//AFIO
#define AFIO_BASE                                0x40010000

//NVIC
#define NVIC_BASE                                0xE000E100

//USART1
#define USART1_BASE                              0x40013800

//SPI1
#define SPI1_BASE                                0X40013000


//NVIC REGISTERS MAP
#define NVIC_ISER0                              *( volatile uint32_t *)(NVIC_BASE+0x0000)
#define NVIC_ISER1                              *( volatile uint32_t *)(NVIC_BASE+0x0004)
#define NVIC_ISER2                              *( volatile uint32_t *)(NVIC_BASE+0x0008)
#define NVIC_ICER0                              *( volatile uint32_t *)(NVIC_BASE+0x0080)
#define NVIC_ICER1                              *( volatile uint32_t *)(NVIC_BASE+0x0084)
#define NVIC_ICER2                              *( volatile uint32_t *)(NVIC_BASE+0x0088)

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

	/*volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4; */  //0X14
	volatile uint32_t EXTICR[4];

	volatile uint32_t RESERVED0; //0X18
	volatile uint32_t MAPR2;     //0X1C
}AFIO_TypeDef;


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (USART)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}USART_TypeDef;


/*==========================================================*/
/*Base Addresses For PERIPHERALS REGISTERS (SPI)*/
/*==========================================================*/
typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;

}SPI_TypeDef;





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

#define USART1                        ((USART_TypeDef *)USART1_BASE)
#define USART2                        ((USART_TypeDef *)USART2_BASE)
#define USART3                        ((USART_TypeDef *)USART3_BASE)

#define SPI1                          ((SPI_TypeDef *)SPI1_BASE)
#define SPI2                          ((SPI_TypeDef *)SPI2_BASE)

/************************************************************************************/

/*==========================================================*/
/*CLOCK ENABLE MACROS*/
/*==========================================================*/
//GPIO
#define RCC_GPIOA_CLOCK_EN()             (RCC->APB2ENR |=(1<<2))
#define RCC_GPIOB_CLOCK_EN()             (RCC->APB2ENR |=(1<<3))
#define RCC_GPIOC_CLOCK_EN()             (RCC->APB2ENR |=(1<<4))
#define RCC_GPIOD_CLOCK_EN()             (RCC->APB2ENR |=(1<<5))
#define RCC_GPIOE_CLOCK_EN()             (RCC->APB2ENR |=(1<<6))
//AFIO
#define RCC_AFIO_CLOCK_EN()              (RCC->APB2ENR |=(1<<0))
//USART
#define RCC_USART1_CLOCK_EN()            (RCC->APB2ENR |=(1<<14))
#define RCC_USART2_CLOCK_EN()            (RCC->APB1ENR |=(1<<17))
#define RCC_USART3_CLOCK_EN()            (RCC->APB1ENR |=(1<<18))
//SPI
#define RCC_SPI1_CLOCK_EN()              (RCC->APB2ENR |=(1<<12))
#define RCC_SPI2_CLOCK_EN()              (RCC->APB1ENR |=(1<<14))


/*==========================================================*/
                     /*RESET MECHANISM*/
/*==========================================================*/
#define RCC_USART1_RESET()            (RCC->APB2RSTR |=(1<<14))
#define RCC_USART2_RESET()            (RCC->APB1RSTR |=(1<<17))
#define RCC_USART3_RESET()            (RCC->APB1RSTR |=(1<<18))
//SPI
#define RCC_SPI1_RESET()              (RCC->APB2RSTR |=(1<<12))
#define RCC_SPI2_RESET()              (RCC->APB1RSTR |=(1<<14))
/************************************************************************************/

/*==========================================================*/
/*EXTI_IRQ MACROS*/
/*==========================================================*/
#define EXTI0_IRQ                         6
#define EXTI1_IRQ                         7
#define EXTI2_IRQ                         8
#define EXTI3_IRQ                         9
#define EXTI4_IRQ                         10
#define EXTI5_IRQ                         23
#define EXTI6_IRQ                         23
#define EXTI7_IRQ                         23
#define EXTI8_IRQ                         23
#define EXTI9_IRQ                         23
#define EXTI10_IRQ                        40
#define EXTI11_IRQ                        40
#define EXTI12_IRQ                        40
#define EXTI13_IRQ                        40
#define EXTI14_IRQ                        40
#define EXTI15_IRQ                        40
/*==========================================================*/
/*USART_IRQ MACROS*/
/*==========================================================*/
#define USART1_IRQ                        37
#define USART2_IRQ                        38
#define USART3_IRQ                        39
/*==========================================================*/
/*SPI_IRQ MACROS*/
/*==========================================================*/
#define SPI1_IRQ	                      35
#define SPI2_IRQ                          36

/*==========================================================*/
/*NVIC IRQ ENABLE/DISABLE MACROS*/
/*==========================================================*/
//ENABLE
//EXTI
#define NVIC_IRQ6_EXTI0_ENABLE()             (NVIC_ISER0 |=(1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE()             (NVIC_ISER0 |=(1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE()             (NVIC_ISER0 |=(1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE()             (NVIC_ISER0 |=(1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE()            (NVIC_ISER0 |=(1<<10))
#define NVIC_IRQ23_EXTI5_9_ENABLE()          (NVIC_ISER0 |=(1<<23))
#define NVIC_IRQ40_EXTI0_15_ENABLE()         (NVIC_ISER1 |=(1<<8)) //40-32=8



//DISABLE
//EXTI
#define NVIC_IRQ6_EXTI0_DISABLE()             (NVIC_ICER0 |=(1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE()             (NVIC_ICER0 |=|(1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE()             (NVIC_ICER0 |=(1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE()             (NVIC_ICER0 |=(1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE()            (NVIC_ICER0 |=(1<<10))
#define NVIC_IRQ23_EXTI5_9_DISABLE()          (NVIC_ICER0 |=(1<<23))
#define NVIC_IRQ40_EXTI0_15_DISABLE()         (NVIC_ICER1 |=(1<<8)) //40-32=8
//UART

//ENABLE
//USART
#define NVIC_IRQ37_USART1_ENABLE()           (NVIC_ISER1 |=(1<<5)) //37-32=5
#define NVIC_IRQ38_USART2_ENABLE()           (NVIC_ISER1 |=(1<<6)) //38-32=6
#define NVIC_IRQ39_USART3_ENABLE()           (NVIC_ISER1 |=(1<<7)) //39-32=7

//DISABLE
//USART
#define NVIC_IRQ37_USART1_DISABLE()          (NVIC_ICER1 |=(1<<5)) //37-32=5
#define NVIC_IRQ38_USART2_DISABLE()          (NVIC_ICER1 |=(1<<6)) //38-32=6
#define NVIC_IRQ39_USART3_DISABLE()          (NVIC_ICER1 |=(1<<7)) //39-32=7

//ENABLE_SPI
#define NVIC_IRQ35_SPI1_ENABLE()             (NVIC_ISER1 |=(1<<3)) //35-32=3
#define NVIC_IRQ36_SPI2_ENABLE()             (NVIC_ISER1 |=(1<<4)) //36-32=4

//DISABLE_SPI
#define NVIC_IRQ35_SPI1_DISABLE()            (NVIC_ICER1 |=(1<<3)) //35-32=3
#define NVIC_IRQ36_SPI2_DISABLE()            (NVIC_ICER1 |=(1<<4)) //36-32=4












#endif /* INC_STM32_F103C6_H_ */
