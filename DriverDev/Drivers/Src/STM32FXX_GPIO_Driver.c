/*
 * STM32FXX_GPIO_Driver.c
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003146
 */


#include "STM32FXX_GPIO_Driver.h"

//Peripheral clock setup
void GPIO_PeriClockControl(GPIO_Reg_Def_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}
}

////Init and Deinit
//
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. Configuring the Mode
		uint32_t temp=0;
		if(pGPIOHandle->pin_config.GPIO_PinMode <= GPIO_Mode_ANALOG) //Non interrupt Mode
			{	temp=0;
				temp= pGPIOHandle->pin_config.GPIO_PinMode <<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
				pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<(2*pGPIOHandle->pin_config.GPIO_PinNumber));
				pGPIOHandle->pGPIOx->MODER|=temp;
			}
	//2. Speed Control
		temp=0;
		temp= pGPIOHandle->pin_config.GPIO_PinSpeed <<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<(2*pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR|=temp;
 //3. Output Type
		temp=0;

	    temp= pGPIOHandle->pin_config.GPIO_PinOType <<(pGPIOHandle->pin_config.GPIO_PinNumber);
	    pGPIOHandle->pGPIOx->ODR &= ~(0x1 <<(2*pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->ODR |=temp;
		temp=0;
//4. PU-PD Control
		temp= pGPIOHandle->pin_config.GPIO_PinPuPdControl <<(2*pGPIOHandle->pin_config.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 <<(2*pGPIOHandle->pin_config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR|=temp;


	//5. Alternate Function
		if(pGPIOHandle->pin_config.GPIO_PinMode==GPIO_Mode_ALT )
		{
			uint32_t temp1=0,temp2=0;
		temp1= pGPIOHandle->pin_config.GPIO_PinNumber/8;
		temp2 =pGPIOHandle->pin_config.GPIO_PinNumber%8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<(4*temp2));
		pGPIOHandle->pGPIOx->AFR[temp1]|=pGPIOHandle->pin_config.GPIO_PinAltFuction << (4*temp2);
}
}
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
			{
				GPIOA_PCLK_DI();
			}
			if(pGPIOx == GPIOB)
			{
				GPIOB_PCLK_DI();
			}
			if(pGPIOx == GPIOC)
			{
				GPIOC_PCLK_DI();
			}
			if(pGPIOx == GPIOD)
			{
				GPIOD_PCLK_DI();
			}
			if(pGPIOx == GPIOE)
			{
				GPIOE_PCLK_DI();
			}
			if(pGPIOx == GPIOF)
			{
				GPIOF_PCLK_DI();
			}
			if(pGPIOx == GPIOG)
			{
				GPIOG_PCLK_DI();
			}
			if(pGPIOx == GPIOH)
			{
				GPIOH_PCLK_DI();
			}
			if(pGPIOx == GPIOI)
			{
				GPIOI_PCLK_DI();
			}
}
//
////Data Read and Write
//
uint8_t GPIO_ReadFromInputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value= (uint8_t)((pGPIOx->IDR >>PinNumber)*(0x00000001));
	return value;
}
uint16_t value1;
uint16_t GPIO_ReadFromInputPort(GPIO_Reg_Def_t *pGPIOx)
{
	value1=(uint16_t)(pGPIOx->IDR);
	return value1;
}
void GPIO_WriteToOutputPin(GPIO_Reg_Def_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value==GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1<<PinNumber);

	}
}
void GPIO_WriteToOutputPort(GPIO_Reg_Def_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;

}
void GPIO_ToggleOutputPin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR = pGPIOx->ODR ^ (1<<PinNumber);
}
