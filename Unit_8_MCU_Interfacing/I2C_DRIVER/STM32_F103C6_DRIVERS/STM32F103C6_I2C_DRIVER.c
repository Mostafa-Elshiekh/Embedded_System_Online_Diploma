/*
 * STM32F103C6_I2C_DRIVER.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Mostafa Elshiekh
 */


//include
#include "STM32F103C6_I2C_DRIVER.h"







/*==============================================================================
 *                                   Genaric Variables
 *==============================================================================*/
I2C_Config_t Global_I2C_Config[2] = {NULL,NULL};   //I will store Backup from I2C_Config_t for I2Cx










/*==============================================================================
 *                                   Genaric Macros
 *==============================================================================*/

#define I2C1_INDEX                          0
#define I2C2_INDEX                          1












/*==============================================================================
 *                                   I2C_APIs
 *==============================================================================*/

/**=================================================================
 * @Fn -                    -MCAL_I2C_Init
 * @brief -                 -Initialize the I2Cx  according specified parameters in I2C_config
 * @param [in] -            -I2Cx : where x can be (1,2 depending on device used)
 * @param [in] -            -I2C_config pointer to a I2C_Config_t structure that contains
 * @retval -                -None
 * note -                   -None
 */
/**================================================================= */

void MCAL_I2C_Init(I2C_TypeDef *I2Cx , I2C_Config_t *I2C_config)
{
	uint16_t TmReg=0;
	uint32_t Frequancy;
	uint32_t pclk1 = 8000000;
	uint32_t Result=0;

	//Enable RCC Clock
	if( I2Cx == I2C1 )
	{
		Global_I2C_Config[I2C1_INDEX]=*I2C_config;
		RCC_I2C1_CLOCK_EN();
	}
	else
	{
		Global_I2C_Config[I2C2_INDEX]=*I2C_config;
		RCC_I2C2_CLOCK_EN();
	}

	if(I2C_config->I2C_Mode == I2C_Mode_I2C)
	{

		/**************************** INIT Timing *********************************/
		//I2C_CR2.FREQ[5:0]: peripheral clock frequancy
		/*Get the I2Cx->CR2 val*/
		TmReg = I2Cx->I2C_CR2;
		//Clear frequancy FREQ[5:0] bits
		TmReg &=~(I2C_CR2_FREQ); //Clear the first 6bits in CR2 register(FREQ[5:0]
		/*Get pclk1 frequancy val*/
		pclk1 = MCAL_RCC_Get_PCLK1_Freq();
		/*Set Frequancy bits depending on pclk1 value */
		/*FREQ[5:0]: Peripheral clock frequency
		The FREQ bits must be configured with the APB clock frequency value (I2C peripheral
		connected to APB). The FREQ field is used by the peripheral to generate data setup and
		hold times compliant with the I2C specifications. The minimum allowed frequency is 2 MHz,
		the maximum frequency is limited by the maximum APB frequency and cannot exceed
		50 MHz (peripheral intrinsic maximum limit).
		0b000000: Not allowed
		0b000001: Not allowed
		0b000010: 2 MHz*/
		Frequancy = (uint16_t) (pclk1 / 1000000);

		TmReg |=Frequancy;
		//Write to I2C_CR2
		I2Cx->I2C_CR2 = TmReg;

		/*Configure the clock control registers*/
		//Disable I2C peripheral
		I2Cx->I2C_CR1 &=~(I2C_CR1_PE);

		TmReg = 0;

		//Set Mode (Stansard mode / Fast mode)
		if(I2C_config->I2C_CLOCK_SPEED == I2C_CLOCK_SPEED_SM_50K ||I2C_config->I2C_CLOCK_SPEED == I2C_CLOCK_SPEED_SM_100K )
		{
			//Stansard Mode
			//Standard Mode speed calculation
			/*Tclk/2 = CCR * Tpclk1
			 * CCR = Tclk /(Tpclk1 * 2)
			 * CCR = Fpclk1 /(I2C_ClockFrequancy * 2)
			 */
			Result = (uint16_t)(pclk1 /(I2C_config->I2C_CLOCK_SPEED *2 ));
			TmReg |=Result;
			//Write to I2C_CCR
			I2Cx->I2C_CCR = TmReg;

			/*For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
			If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
			therefore the TRISE[5:0] bits must be programmed with 09h.
			(1000 ns / 125 ns = 8 + 1)*/

			I2Cx->I2C_TRISE = Frequancy +1;

		}
		else if (I2C_CLOCK_SPEED_FM_200K || I2C_CLOCK_SPEED_FM_400K )
		{
			//Fast Mode ---Not Supported
		}

		/*Get the I2Cx CR1 val*/
		TmReg = I2Cx->I2C_CR1;
		TmReg |=(uint16_t)(I2C_config->I2C_ACK_Control)|(I2C_config->Stretching)|(I2C_config->_I2C_General_Call |I2C_config->I2C_Mode);
		//Write to I2C_CR1
		I2Cx->I2C_CR1 = TmReg;

		/**************************** I2CX OAR1 & OAR2 Configuration *********************************/
		TmReg=0;
		if(I2C_config->I2C_Slave_Address.Enable_Dual_ADD == 1)
		{
			TmReg |=(I2C_OAR2_ENDUAL); //Enable Dual Address
			/*Set Secondary Address*/
			TmReg |=(I2C_config->I2C_Slave_Address.Secondary_Slave_Address<<1);//bits 7:1 of address in dual addressing mode
			//Write to
			I2Cx->I2C_OAR2 = TmReg;
		}
		TmReg = 0;
		TmReg |=(I2C_config->I2C_Slave_Address.Primary_Slave_Address<<1);
		TmReg |=(I2C_config->I2C_Slave_Address.I2C_Addressing_Slave_Mode);
		//Write to I2C_OAR1
		I2Cx->I2C_OAR1 = TmReg;
	}//I2C_SMBUS_Mode
	else
	{
		//SMBUS Not Supported
	}

	//Interrupt mode in slave mode
	if(I2C_config->P_Slave_Event_CallBack !=NULL)
	{
		//Slave Mode
		//Bit 10 ITBUFEN: Buffer interrupt enable
		I2Cx->I2C_CR1 |=I2C_CR2_ITBUFEN;
		//Bit 8 ITERREN: Error interrupt enable
		I2Cx->I2C_CR1 |=I2C_CR2_ITERREN;
		//Bit 9 ITEVTEN: Event interrupt enable
		I2Cx->I2C_CR1 |=I2C_CR2_ITEVTEN;

		//Enable interrupt in NVIC
		if( I2Cx == I2C1 )
		{
			NVIC_IRQ31_I2C1_EV_IRQ_ENABLE();
			NVIC_IRQ32_I2C1_ER_IRQ_ENABLE();
		}
		else if(I2Cx == I2C2)
		{
			NVIC_IRQ33_I2C2_EV_IRQ_ENABLE();
			NVIC_IRQ34_I2C2_ER_IRQ_ENABLE();
		}
		I2Cx->I2C_SR1 = 0;
		I2Cx->I2C_SR2 = 0;
	}

	/*Enable I2C Peripheral Bit 0 PE: Peripheral enable*/
	I2Cx->I2C_CR1 |=I2C_CR1_PE;
}


/**=================================================================
 * @Fn -                    -MCAL_I2C_DeInit
 * @brief -                 -DeInit the I2Cx
 * @param [in] -            -I2Cx : where x can be (1,2 depending on device used)
 * @retval -                -None
 * note -                   -None
 */
/**================================================================= */
void MCAL_I2C_DeInit(I2C_TypeDef *I2Cx)
{

	if( I2Cx == I2C1 )
	{
		RCC_I2C1_RESET();
		NVIC_IRQ31_I2C1_EV_IRQ_DISABLE();
		NVIC_IRQ32_I2C1_ER_IRQ_DISABLE();
	}
	else if(I2Cx == I2C2)
	{
		RCC_I2C2_RESET();
		NVIC_IRQ33_I2C2_EV_IRQ_DISABLE() ;
		NVIC_IRQ34_I2C2_ER_IRQ_DISABLE();
	}

}


/**=================================================================
 * @Fn -                    -MCAL_I2C_Set_GPIO_Pins
 * @brief -                 -Set_GPIO_Pins according recommended in I2C
 * @param [in] -            -I2Cx : where x can be (1,2 depending on device used)
 * @retval -                -None
 * note -                   -None
 */
/**================================================================= */
void MCAL_I2C_Set_GPIO_Pins(I2C_TypeDef *I2Cx)
{
	GPIO_Pin_Configure_t PinCfg;

	if( I2Cx == I2C1 )
	{
		//I2C1_SCL-->PB6
		PinCfg.GPIO_Pin_Number = GPIO_PIN_6;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		//I2C1_SDA-->PB7
		PinCfg.GPIO_Pin_Number = GPIO_PIN_7;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

	}
	else if(I2Cx == I2C2)
	{
		//I2C_SCL2-->PB10
		PinCfg.GPIO_Pin_Number = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		//I2C2_SDA-->PB11
		PinCfg.GPIO_Pin_Number = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
	}

}

void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx ,uint16_t DevAddr , uint8_t* DataOut , uint32_t DataLen , Stop_Condition Stop,Reapeated_Start Start)
{
	int i=0;
	//To do
	//Support timeout (configure timer working for specic duaration rise interrupt
	//in ISR rise flag=1 and any code exist in while (check flag || Any polling condion)
	//1. Set the start bit in the I2C_CR1 register to generate a Sart Condition
	I2C_Generate_Start(I2Cx , Enable, Start);

	//2. Wait for Ev5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(! I2C_Get_Flag_Status(I2Cx , EV5));

	//3. Send address
	I2C_Send_Address(I2Cx , DevAddr , I2C_Direction_Transmitter);

	//4.Wait for Ev6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(! I2C_Get_Flag_Status(I2Cx , EV6));

	//5. /*TRA , BUSY , TXE , MSL , TXE flage*/
	while(! I2C_Get_Flag_Status(I2Cx , MASTER_BYTE_TRANSMITTING));

	//6. Send Data
	for(i=0;i<DataLen;i++)
	{
		//6.EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
		while(!I2C_Get_Flag_Status(I2Cx, EV8_1));
		I2Cx->I2C_DR = DataOut[i];
		//Wait EV8
		//EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
		while(! I2C_Get_Flag_Status(I2Cx , EV8));
	}


	if(Stop == With_Stop)
	{
		//7. Send stop condition
		I2C_Generate_STOP(I2Cx , Enable);
	}
	else
	{
		I2C_Generate_STOP(I2Cx, Disable);
	}
}

void I2C_Generate_Start(I2C_TypeDef *I2Cx , Functional_State NewState ,Reapeated_Start state )
{

	if ( state != Reapeated_Start_En)
	{
		//Check if the bus is idle
		while(I2C_Get_Flag_Status(I2Cx , I2C_FLAG_BUSY));//While Bus is Busy Stuck
	}
	//if == reapeated i not need check the bus because i hold the bus
	/*Bit 8 START: Start generation
	This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
	In Master Mode:
	0: No Start generation
	1: Repeated start generation
	In Slave mode:
	0: No Start generation
	1: Start generation when the bus is free*/
	if(NewState != Disable)
	{
		I2Cx->I2C_CR1 |=(I2C_CR1_START); //Enable stat generation
	}
	else
	{
		I2Cx->I2C_CR1 &=~(I2C_CR1_START);//Disable start generation
	}

}

//supported only 7bit mode
void I2C_Send_Address(I2C_TypeDef *I2Cx , uint16_t Address ,I2C_Direction Direction )
{
	Address = (Address<<1); //7 Bit

	if(Direction != I2C_Direction_Transmitter)
	{
		//Set the address bin0 for read
		Address |=(1<<0);
	}
	else
	{
		//Reset the address bin0 for write
		Address &=~(1<<0);
	}

	/*Send the address */
	I2Cx->I2C_DR = Address;
}

void I2C_Generate_STOP(I2C_TypeDef *I2Cx  , Functional_State NewState)
{

	if(NewState != Disable)
	{
		/*Generate STOP condition*/
		/*Bit 9 STOP: Stop generation
		The bit is set and cleared by software, cleared by hardware when a Stop condition is
		detected, set by hardware when a timeout error is detected.
		In Master Mode:
		0: No Stop generation.
		1: Stop generation after the current byte transfer or after the current Start condition is sent*/
		I2Cx->I2C_CR1 |=I2C_CR1_STOP;
	}
	else
	{
		/*disable stop condition generate*/
		I2Cx->I2C_CR1 &=~I2C_CR1_STOP;
	}
}

Flag_Status I2C_Get_Flag_Status(I2C_TypeDef *I2Cx , Status Flag)
{
	//volatile uint32_t DumyRead;
	Flag_Status BitStatus = Reset;
	uint32_t flag1=0 , flag2=0;
	uint32_t LastEvent=0;


	switch (Flag)
	{
	case I2C_FLAG_BUSY:
		/*Bit 1 BUSY: Bus busy
				0: No communication on the bus
				1: Communication ongoing on the bus
				– Set by hardware on detection of SDA or SCL low
				– cleared by hardware on detection of a Stop condition.
				It indicates a communication in progress on the bus. This information is still updated when
				the interface is disabled (PE=0).*/

		if(I2Cx->I2C_SR2 & I2C_SR2_BUSY)
		{
			BitStatus = Set;
		}
		else
		{
			BitStatus = Reset;
		}
		break ;

	case EV5:
		//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
		/*Bit 0 SB: Start bit (Master mode)
			0: No Start condition
			1: Start condition generated.
			– Set when a Start condition generated.
			– Cleared by software by reading the SR1 register followed by writing the DR register, or by
			hardware when PE=0*/
		if( (I2Cx->I2C_SR1) & (I2C_SR1_SB) )
		{
			BitStatus = Set;
		}
		else
		{
			BitStatus = Reset;
		}
		break;


	case EV6:

		//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
		/*Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
				This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
				when PE=0.
				Address matched (Slave)
				0: Address mismatched or not received.
				1: Received address matched.*/
		if( I2Cx->I2C_SR1 & I2C_SR1_ADDR)
		{
			BitStatus = Set;
		}
		else
		{
			BitStatus = Reset;
		}
		/*//ADDR=1, cleared by reading SR1 register followed by reading SR2
		DumyRead = I2Cx->I2C_SR2;*/
		break;



	case MASTER_BYTE_TRANSMITTING:

		/*Read I2Cx status registers*/
		flag1 = I2Cx->I2C_SR1;
		flag2 = I2Cx->I2C_SR2;
		flag2 = flag2<<16;

		/* Get LastEvent value from I2C status register*/
		LastEvent = (flag1 | flag2) & ((uint32_t)0x00FFFFFF);
		/*Check whether the last event contains the I2C_EVENT */
		if( (LastEvent & Flag) == Flag )
		{
			/*last event is equal ti I2C_EVENT*/
			BitStatus = Set;
		}
		else
		{
			/*last event is not equal ti I2C_EVENT*/
			BitStatus = Reset;
		}
		break;


	case EV8_1://EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
	case EV8: //EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register

		/*Bit 7 TxE: Data register empty (transmitters)
			0: Data register not empty
			1: Data register empty
			– Set when DR is empty in transmission. TxE is not set during address phase.
			– Cleared by software writing to the DR register or by hardware after a start or a stop condition
			or when PE=0.*/
		if(I2Cx->I2C_SR1 & I2C_SR1_TXE)
		{
			//Data register empty
			BitStatus = Set;
		}
		else
		{
			//Data register not empty
			BitStatus = Reset;
		}
		break;

	case EV7:

		/*Bit 6 RxNE: Data register not empty (receivers)
		0: Data register empty
		1: Data register not empty*/
		if(I2Cx->I2C_SR1 & I2C_SR1_RXNE)
		{
			BitStatus = Set;
		}
		else
		{
			BitStatus = Reset;
		}


	}
	return BitStatus;
}

void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx  , Functional_State NewState)
{
	/*Bit 10 ACK: Acknowledge enable
	This bit is set and cleared by software and cleared by hardware when PE=0.
	0: No acknowledge returned
	1: Acknowledge returned after a byte is received (matched address or data)*/

	if(NewState == Enable)
	{
		I2Cx->I2C_CR1 |=(I2C_CR1_ACK);
	}
	else
	{
		I2Cx->I2C_CR1 &=~(I2C_CR1_ACK);
	}

}


void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx ,uint16_t DevAddr , uint8_t* DataOut , uint32_t DataLen , Stop_Condition Stop,Reapeated_Start Start)
{
	int i=0;
	uint8_t indix = I2Cx == I2C1 ? I2C1_INDEX : I2C2_INDEX;

	I2C_Generate_Start(I2Cx , Enable, Start);

	//2. Wait for Ev5
	//EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(! I2C_Get_Flag_Status(I2Cx , EV5));

	//3. Send address
	I2C_Send_Address(I2Cx , DevAddr , I2C_Direction_Recieve);

	//4.Wait for Ev6
	//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	while(! I2C_Get_Flag_Status(I2Cx , EV6));

	I2C_AcknowledgeConfig(I2Cx , Enable);



	if(DataLen)
	{
		//5.read data until len become zero
		for(i=DataLen ; i>1 ; i--)
		{
			//wait until RXNE BECOMES 1
			while(! I2C_Get_Flag_Status(I2Cx , EV7));
			//read data from data register
			*DataOut = I2Cx->I2C_DR;
			//increment the buffer address
			DataOut++;
		}
		//6.send not Ack
		I2C_AcknowledgeConfig(I2Cx , Disable); //To not receive
	}


	if(Stop == With_Stop)
	{
		//7. Send stop condition
		I2C_Generate_STOP(I2Cx, Enable);
	}

	//re-enable ack
	if(Global_I2C_Config[indix].I2C_ACK_Control == I2C_ACK_Contro_Enable)
	{
		I2C_AcknowledgeConfig(I2Cx , Enable);
	}

}

//Slave interrupt mechanism
void MCAL_I2C_Slave_Send_Data(I2C_TypeDef *I2Cx , uint8_t Data)
{
	I2Cx->I2C_DR = Data;
}


uint8_t MCAL_I2C_Slave_Receive_Data(I2C_TypeDef *I2Cx)
{
	uint8_t result;
	result =(uint8_t)(I2Cx->I2C_DR);
	return result;
}


void I2C1_EV_IRQHandler(void)
{

}

void I2C1_ER_IRQHandler(void)
{

}


void I2C2_EV_IRQHandler(void)
{

}

void I2C2_ER_IRQHandler(void)
{

}

