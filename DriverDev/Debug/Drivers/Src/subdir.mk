################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/STM32FXX_GPIO_Driver.c 

OBJS += \
./Drivers/Src/STM32FXX_GPIO_Driver.o 

C_DEPS += \
./Drivers/Src/STM32FXX_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/STM32FXX_GPIO_Driver.o: ../Drivers/Src/STM32FXX_GPIO_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/99003146/STM32CubeIDE/workspace_1.5.0/DriverDev/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Src/STM32FXX_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

