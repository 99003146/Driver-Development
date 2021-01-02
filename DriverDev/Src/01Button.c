/*
 * 01Button.c
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

GPIO_Handle_t Button;
Button.pGPIOx=GPIOA;
Button.pin_config.GPIO_PinNumber = GPIO_Pin_Number_0;
Button.pin_config.GPIO_PinMode = GPIO_Mode_IN;
Button.pin_config.GPIO_PinSpeed=GPIO_SPEED_FAST;
Button.pin_config.GPIO_PinPuPdControl=GPIO_NO_PUPD;
GPIO_PeriClockControl(GPIOA, ENABLE);
GPIO_Init(&Button);

while(1)
{
	if( Button.pGPIOx->IDR== ENABLE)
	{
		delay();
	GPIO_ToggleOutputPin(GPIOD, GPIO_Pin_Number_15);
	delay();

	}
}
}
