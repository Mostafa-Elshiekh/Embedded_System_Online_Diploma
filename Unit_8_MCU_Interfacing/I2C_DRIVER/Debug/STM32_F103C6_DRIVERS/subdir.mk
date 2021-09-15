################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.c \
../STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.c \
../STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.c \
../STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.c 

OBJS += \
./STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.o \
./STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.o \
./STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.o \
./STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.o 

C_DEPS += \
./STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.d \
./STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.d \
./STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.d \
./STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.o: ../STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS/INC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_DRIVERS/I2C_SLAVE_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.o: ../STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS/INC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_DRIVERS/STM32F103C6_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.o: ../STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS/INC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_DRIVERS/STM32_F103C6_GPIO_DRIVERS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.o: ../STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS" -I"C:/Users/musta/STM32CubeIDE/workspace_1.4.0/I2C_DRIVER/STM32_F103C6_DRIVERS/INC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_DRIVERS/STM32_F103C6_RCC_DRIVERS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

