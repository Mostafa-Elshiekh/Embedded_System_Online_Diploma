/*
 * I2C_SLAVE_EEPROM.c
 *
 *  Created on: Sep 14, 2021
 *      Author: Mostafa Elshiekh
 */

#include "I2C_SLAVE_EEPROM.h"
void EEPROM_Init(void)
{

	/*================I2C init====================*/
	//PB6 : I2C1_SCL
	//PB7 : I2C1_I2C1_SDA
	I2C_Config_t I2C1CFG;

	//I2C controller act as master
	I2C1CFG.I2C_ACK_Control = I2C_ACK_Contro_Enable;
	I2C1CFG.I2C_CLOCK_SPEED = I2C_CLOCK_SPEED_SM_100K;
	I2C1CFG.I2C_Mode = I2C_Mode_I2C;
	I2C1CFG.P_Slave_Event_CallBack = NULL;
	//I2C1CFG._I2C_General_Call = I2C_General_Call_Enable;
	I2C1CFG.Stretching = Stretching_Enable;

	MCAL_I2C_Set_GPIO_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &I2C1CFG);
}


unsigned char EEPROM_Write_NBytes(unsigned int Memory_Address , unsigned char *Bytes , uint8_t Data_Lenght)
{
	uint8_t i=0;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_Address>>8); //upper byte memory address
	buffer[1] = (uint8_t)(Memory_Address); //lower byte memory address

	for(i=2 ; i<(Data_Lenght+2) ; i++)
	{
		buffer[i] = Bytes[i-2];
	}

	MCAL_I2C_Master_TX(I2C1, EEPROM_SLAVE_ADDRESS , buffer , (Data_Lenght+2), With_Stop, Start);
	return 0;
}


uint8_t   EEPROM_Read_Byte(unsigned int Memory_Address , uint8_t* DataOut , uint8_t Data_Lenght)
{

	uint8_t  buffer[2];
	buffer[0] = (uint8_t)(Memory_Address>>8); //upper byte memory address
	buffer[1] = (uint8_t)(Memory_Address); //lower byte memory address

	MCAL_I2C_Master_TX(I2C1, EEPROM_SLAVE_ADDRESS , &buffer , 2, Without_Stop, Start); //write address only

	MCAL_I2C_Master_RX(I2C1, EEPROM_SLAVE_ADDRESS , DataOut , Data_Lenght, With_Stop, Reapeated_Start_En); //Read

	return 0;



}
