/*
 * 00LED.c
 *
 *  Created on: 29-Dec-2020
 *      Author: 99003146
 */
#include "STM32F4XX.h"
void delay(void)
{
	for(uint32_t i=0;i<500000;i++);
}
int main()
{
GPIO_Handle_t GPIOLED;
GPIOLED.pGPIOx = GPIOD;
GPIOLED.pin_config.GPIO_PinNumber = GPIO_Pin_Number_15;
GPIOLED.pin_config.GPIO_PinMode = GPIO_Mode_OUT;
GPIOLED.pin_config.GPIO_PinSpeed=GPIO_SPEED_FAST;
GPIOLED.pin_config.GPIO_PinOType=GPIO_OType0;
GPIOLED.pin_config.GPIO_PinPuPdControl=GPIO_PIN_PU;
GPIO_PeriClockControl(GPIOD, ENABLE);
GPIO_Init(&GPIOLED);
while(1)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_Pin_Number_15);
	delay();
}
}
