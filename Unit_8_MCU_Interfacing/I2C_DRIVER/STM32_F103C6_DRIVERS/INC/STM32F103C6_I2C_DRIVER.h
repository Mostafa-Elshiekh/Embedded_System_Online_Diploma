/*
 * I2C_DRIVER.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Mostafa Elshiekh
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_

//include
#include "STM32_F103C6.h"
#include "STM32F103C6_GPIO_DRIVERS.h"
#include "STM32F103C6_RCC_DRIVERS.h"



struct I2C_Slave_Device_Address
{
	uint16_t   Enable_Dual_ADD; //1-Enable Or 0-Disable
	uint16_t   Primary_Slave_Address;
	uint16_t   Secondary_Slave_Address;
	uint16_t   I2C_Addressing_Slave_Mode; //@Ref I2C_Addressing_Slave_Mode_Define
};

typedef enum
{
	I2C_EV_STOP,
	I2C_EPROR_AF,
	I2C_EV_ADDR_MATCHED,
	I2C_EV_DATA_REQ, //APP layer should send the data (I2C_Slave_Send_Data) in this state
	I2C_EV_DATA_RCV  //APP layer read  the data (I2C_Slave_Send_Data) in this state
}Slave_State;


typedef struct
{
	uint32_t                          I2C_CLOCK_SPEED;  /*specifies the clock frequancy
	                                              This parameter must be set to @Ref_I2C_CLOCK_SPEED_define*/

    uint32_t                          Stretching; /*specifies the Stretching Enable or Disable
                                            This parameter must be set to @Ref_Stretching_define*/

    uint32_t                          I2C_Mode; /*specifies the I2C_Mode SMBus mode or I2C mode SMBus mode
                                          This parameter must be set to @Ref_I2C_Mode_define*/

    struct I2C_Slave_Device_Address   I2C_Slave_Address;

    uint32_t                          I2C_ACK_Control;/*specifies Enable or Disable ACK
                                          This parameter must be set to @Ref I2C_ACK_Control_define*/

    uint32_t                          _I2C_General_Call;/*specifies General call Enable or Disable
                                          This parameter must be set to @Ref _I2C_General_Call_define*/

    void(* P_Slave_Event_CallBack)(Slave_State state);




}I2C_Config_t;



/*==============================================================================
 * Refreence Macros
 *==============================================================================*/
/*@Ref_I2C_CLOCK_SPEED_define*/
//Standard Speed (up to 100 kHz)
//Fast Speed (up to 400 kHz)
//-To configure Clock before enable the peripheral
//----I2C_CR2.FREQ[5:0]: peripheral clock frequancy
//----Configure the clock control registers
//       Thigh = CCR * TPCLK1
//       SM OR FM
//----Configure the rise time register
#define I2C_CLOCK_SPEED_SM_50K                                    500000U
#define I2C_CLOCK_SPEED_SM_100K                                   100000
#define I2C_CLOCK_SPEED_FM_200K                                   200000U //Fast mode not supported
#define I2C_CLOCK_SPEED_FM_400K                                   400000U


/*@Ref_Stretching_define*/
/*Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
it is reset by software.
0: Clock stretching enabled
1: Clock stretching disabled*/
#define Stretching_Enable                                         0X00000000U
#define Stretching_Disable                                        I2C_CR1_NOSTRETCH

/*Bit 1 SMBUS: SMBus mode
  0: I2C mode
  1: SMBus mode*/
#define I2C_Mode_I2C                                              0
#define SMBus_Mode                                                I2C_CR1_SMBUS


/*Ref I2C_Addressing_Slave_Mode_Define*/
/*Bit 15 ADDMODE Addressing mode (slave mode)
0: 7-bit slave address (10-bit address not acknowledged)
1: 10-bit slave address (7-bit address not acknowledged)*/
#define I2C_Addressing_Slave_Mode_7Bit                            0
#define I2C_Addressing_Slave_Mode_10Bit                           (uint16_t)(1<<15)

/*@Ref I2C_ACK_Control_define*/
/*Bit 10 ACK: Acknowledge enable
This bit is set and cleared by software and cleared by hardware when PE=0.
0: No acknowledge returned
1: Acknowledge returned after a byte is received (matched address or data)*/
#define I2C_ACK_Contro_Enable                                     I2C_CR1_ACK_Msk
#define I2C_ACK_Contro_Disable                                     0

/*@Ref _I2C_General_Call_define*/
/*Bit 6 ENGC: General call enable
0: General call disabled. Address 00h is NACKed.
1: General call enabled. Address 00h is ACKed.*/
#define I2C_General_Call_Disable                                  0
#define I2C_General_Call_Enable                                   I2C_CR1_ENGC

/******************************************************************************************/




typedef enum
{
	With_Stop,
	Without_Stop
}Stop_Condition;

typedef enum
{
	Start,
	Reapeated_Start_En,
}Reapeated_Start;


typedef enum
{
	Disable,
	Enable,
}Functional_State;


typedef enum
{
	Reset,
	Set,
}Flag_Status;


typedef enum
{
	I2C_FLAG_BUSY,
	EV5, //EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6, //EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV8, //EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
	EV8_1,//EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
    EV7,   //RXNE=1 CLEARD BY READING DR REGISTER
	MASTER_BYTE_TRANSMITTING =((uint32_t) 0x00070080), /*TRA , BUSY , TXE , MSL , TXE flage*/

}Status;

typedef enum
{
	I2C_Direction_Transmitter,
	I2C_Direction_Recieve
}I2C_Direction;

/*==============================================================================
 *                                   I2C_APIs
 *==============================================================================*/
void MCAL_I2C_Init(I2C_TypeDef *I2Cx , I2C_Config_t *I2C_config);
void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx);
void MCAL_I2C_Set_GPIO_Pins(I2C_TypeDef *I2Cx);

//Master Polling Mechanism
void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx ,uint16_t DevAddr , uint8_t* DataOut , uint32_t DataLen , Stop_Condition Stop,Reapeated_Start Start);
void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx ,uint16_t DevAddr , uint8_t* DataOut , uint32_t DataLen , Stop_Condition Stop,Reapeated_Start Start);

//Slave interrupt mechanism
void MCAL_I2C_Slave_Send_Data(I2C_TypeDef *I2Cx , uint8_t Data);
uint8_t MCAL_I2C_Slave_Receive_Data(I2C_TypeDef *I2Cx);


//Genaric APIs
void I2C_Generate_Start(I2C_TypeDef *I2Cx , Functional_State NewState ,Reapeated_Start state );

Flag_Status I2C_Get_Flag_Status(I2C_TypeDef *I2Cx , Status Flag);

void I2C_Send_Address(I2C_TypeDef *I2Cx , uint16_t Address ,I2C_Direction Direction );

void I2C_Generate_STOP(I2C_TypeDef *I2Cx  , Functional_State NewState);

void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx  , Functional_State NewState);


#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
