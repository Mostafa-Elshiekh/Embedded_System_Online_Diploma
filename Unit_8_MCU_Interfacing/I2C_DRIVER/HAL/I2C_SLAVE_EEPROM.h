/*
 * I2C_SLAVE_EEPROM.h
 *
 *  Created on: Sep 14, 2021
 *      Author: Mostafa Elshiekh
 */

#ifndef INC_I2C_SLAVE_EEPROM_H_
#define INC_I2C_SLAVE_EEPROM_H_

#include "STM32F103C6_I2C_DRIVER.h"

//EEPROM is an I2C Slave
//Idel Mode : device is an high-impedance state and waits for data
//Master Transmiter Mode : the device transmits data to slave receiver
//Master Receviver Mode : the  device receive data from a slave transmitter

#define EEPROM_SLAVE_ADDRESS          0X2A

void EEPROM_Init(void);
unsigned char EEPROM_Write_NBytes(unsigned int Memory_Address , unsigned char *Bytes , uint8_t Data_Lenght);
unsigned char EEPROM_Read_Byte(unsigned int Address , uint8_t* DataOut , uint8_t Data_Lenght);





#endif /* INC_I2C_SLAVE_EEPROM_H_ */
