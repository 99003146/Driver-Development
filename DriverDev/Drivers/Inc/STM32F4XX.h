/*
 * STM32F4XX.h
 *
 *  Created on: Dec 27, 2020
 *      Author: 99003146
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_
#include <stdint.h>
#define __vo volatile


//Defining macros for Memories

#define FLASH_ADDR 	0x08000000U
#define SRAM1_ADDR 	0x20000000U
#define SRAM2_ADDR 	0x2001C000U
#define ROM_ADDR	0x1FFF0000
#define SRAM_ADDR   SRAM1ADDR


//Defining macros for Buses

#define AHB1_BASEADDR	0x40020000U
#define AHB2_BASEADDR	0x50000000U
#define AHB3_BASEADDR	0x60000000U
#define APB1_BASEADDR	0x40000000U
#define APB2_BASEADDR	0x40010000U
#define PERI_BASEADDR	APB1_BASEADDR

//Defining macros for peripherals hanging on AHB1 Bus

#define GPIOA_BASEADDR	(AHB1_BASEADDR + (0x0000U))
#define GPIOB_BASEADDR	(AHB1_BASEADDR + (0x0400U))
#define GPIOC_BASEADDR	(AHB1_BASEADDR + (0x0800U))
#define GPIOD_BASEADDR	(AHB1_BASEADDR + (0x0C00U))
#define GPIOE_BASEADDR	(AHB1_BASEADDR + (0x1000U))
#define GPIOF_BASEADDR	(AHB1_BASEADDR + (0x1400U))
#define GPIOG_BASEADDR	(AHB1_BASEADDR + (0x1800U))
#define GPIOH_BASEADDR	(AHB1_BASEADDR + (0x1C00U))
#define GPIOI_BASEADDR	(AHB1_BASEADDR + (0x2000U))
#define RCC_BASEADDR	(AHB1_BASEADDR + (0x3800U))

//Defining macros for peripherals hanging on APB1 BUS

#define SPI2_BASEADDR	(APB1_BASEADDR + (0x3800U))
#define SPI3_BASEADDR	(APB1_BASEADDR + (0x3C00U))
#define I2C1_BASEADDR	(APB1_BASEADDR + (0x5400U))
#define I2C2_BASEADDR	(APB1_BASEADDR + (0x5800U))
#define I2C3_BASEADDR	(APB1_BASEADDR + (0x5C00U))
#define UART4_BASEADDR	(APB1_BASEADDR + (0x4C00U))
#define UART5_BASEADDR	(APB1_BASEADDR + (0x5000U))
#define USART2_BASEADDR	(APB1_BASEADDR + (0x4400U))
#define USART3_BASEADDR	(APB1_BASEADDR + (0x4800U))

//Defining macros for peripherals hanging on APB2 BUS

#define SPI1_BASEADDR	(APB2_BASEADDR + (0x3000U))
#define USART1_BASEADDR	(APB1_BASEADDR + (0x1000U))
#define USART6_BASEADDR	(APB1_BASEADDR + (0x1400U))

//GPIO Peripheral Registers
typedef struct
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRRL;
	uint32_t BSRRH;
	uint32_t LCKR;
	uint32_t AFR[2]; //AFR[0]-Low Registers, AFR[1]-High Registers

}GPIO_Reg_Def_t;

//peripheral definition for GPIO

#define GPIOA (GPIO_Reg_Def_t*)(GPIOA_BASEADDR)
#define GPIOB (GPIO_Reg_Def_t*)(GPIOB_BASEADDR)
#define GPIOC (GPIO_Reg_Def_t*)(GPIOC_BASEADDR)
#define GPIOD (GPIO_Reg_Def_t*)(GPIOD_BASEADDR)
#define GPIOE (GPIO_Reg_Def_t*)(GPIOE_BASEADDR)
#define GPIOF (GPIO_Reg_Def_t*)(GPIOF_BASEADDR)
#define GPIOG (GPIO_Reg_Def_t*)(GPIOG_BASEADDR)
#define GPIOH (GPIO_Reg_Def_t*)(GPIOH_BASEADDR)
#define GPIOI (GPIO_Reg_Def_t*)(GPIOI_BASEADDR)





typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;

}RCC_Reg_Def_t;

#define RCC ((RCC_Reg_Def_t*)RCC_BASEADDR)
//GPIO Clock Enable
#define GPIOA_PCLK_EN()		RCC->AHB1ENR |= 1<<0;
#define GPIOB_PCLK_EN()		RCC->AHB1ENR |= 1<<1;
#define GPIOC_PCLK_EN()		RCC->AHB1ENR |= 1<<2;
#define GPIOD_PCLK_EN()		RCC->AHB1ENR |= 1<<3;
#define GPIOE_PCLK_EN()		RCC->AHB1ENR |= 1<<4;
#define GPIOF_PCLK_EN()		RCC->AHB1ENR |= 1<<5;
#define GPIOG_PCLK_EN()		RCC->AHB1ENR |= 1<<6;
#define GPIOH_PCLK_EN()		RCC->AHB1ENR |= 1<<7;
#define GPIOI_PCLK_EN()		RCC->AHB1ENR |= 1<<8;

//GPIO Clock Disable


#define GPIOA_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOC_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOD_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOE_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOF_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOG_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOH_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOI_PCLK_DI()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)


//Other important macros
#define ENABLE  1
#define DISABLE	0
#define GPIO_PIN_SET ENABLE
#define GPIO_PIN_RESET DISABLE

#include "STM32FXX_GPIO_Driver.h"

#endif /* INC_STM32F4XX_H_ */
