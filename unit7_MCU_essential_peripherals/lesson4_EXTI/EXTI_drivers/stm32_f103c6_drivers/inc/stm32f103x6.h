/*
 * stm32f103x6.h
 *
 *  Created on: Aug 2, 2022
 *      Author: ahmed shawki
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

/* includes */
#include "stdlib.h"
#include "stdint.h"

/*base address for memories*/
#define flash_memory_base 			0x08000000UL
#define sram_memory_base  			0x20000000UL
#define system_memory_base 			0x1FFFF000UL
#define peripherals_base 			0x40000000UL
#define cortexm3_internal_base 		0xE0000000UL
//NVIC base
#define NVIC_base 					0xE000E100UL
//register
#define	NVIC_ISER0 					*((volatile uint32_t *)(NVIC_base+0x00))
#define	NVIC_ISER1					*((volatile uint32_t *)(NVIC_base+0x04))
#define	NVIC_ISER2 					*((volatile uint32_t *)(NVIC_base+0x08))
#define	NVIC_ICER0 					*((volatile uint32_t *)(NVIC_base+0x80))
#define	NVIC_ICER1 					*((volatile uint32_t *)(NVIC_base+0x84))
#define	NVIC_ICER2 					*((volatile uint32_t *)(NVIC_base+0x88))

/*******************************/
/* enable and disable IRQ*/
/*******************************/
#define NVIC_IRQ6_EXTI0_Enable 			NVIC_ISER0|=(1<<6)
#define NVIC_IRQ7_EXTI1_Enable 			NVIC_ISER0|=(1<<7)
#define NVIC_IRQ8_EXTI2_Enable 			NVIC_ISER0|=(1<<8)
#define NVIC_IRQ9_EXTI3_Enable 			NVIC_ISER0|=(1<<9)
#define NVIC_IRQ10_EXTI4_Enable 		NVIC_ISER0|=(1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable 		NVIC_ISER0|=(1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable 	NVIC_ISER1|=(1<<8) //index 40-32

#define NVIC_IRQ6_EXTI0_Disable 		NVIC_ICER0|=(1<<6)
#define NVIC_IRQ7_EXTI1_Disable 		NVIC_ICER0|=(1<<7)
#define NVIC_IRQ8_EXTI2_Disable 		NVIC_ICER0|=(1<<8)
#define NVIC_IRQ9_EXTI3_Disable 		NVIC_ICER0|=(1<<9)
#define NVIC_IRQ10_EXTI4_Disable 		NVIC_ICER0|=(1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable 		NVIC_ICER0|=(1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable 	NVIC_ICER1|=(1<<8) //index 40-32
/*base aisddresses for AHB peripherals*/
/******************/
//RCC
#define RCC_base  					0x40021000UL



/*base addresses for APB2 peripherals*/
/******************/
//GPIO
/*A,B fully included in LQFP48  */
#define GPIOA_base  				0x40010800UL
#define GPIOB_base  				0x40010C00UL


/*C,D partial included in LQFP48  */

#define GPIOC_base  				0x40011000UL
#define GPIOD_base  				0x40011400UL


/*E is not included in LQFP48  */
#define GPIOE_base  				0x40011800UL
/****************/
//EXTI
#define EXTI_base  					0x40010400UL


/**************/
//AFIO
#define AFIO_base  					0x40010000UL


/*base addresses for APB1 peripherals*/
/******************/

//========================================================//
/*peripherals registers*/

/*peripherals registers for GPIO*/
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_typedef;

/*peripherals registers for RCC*/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_typedef;

/*peripherals registers for EXTI*/
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_typedef;
/*peripherals registers for AFIO*/

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXT1_CR[4];
//	volatile uint32_t EXTI_CR2;
//	volatile uint32_t EXTI_CR3;
//	volatile uint32_t EXTI_CR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_typedef;

/***************************/
//***peripherals instants***//


#define GPIOA 			((GPIO_typedef*)(GPIOA_base))
#define GPIOB 			((GPIO_typedef*)(GPIOB_base))
#define GPIOC 			((GPIO_typedef*)(GPIOC_base))
#define GPIOD 			((GPIO_typedef*)(GPIOD_base))
#define GPIOE 			((GPIO_typedef*)(GPIOE_base))
#define RCC 			((RCC_typedef* )(RCC_base))
#define EXTI 			((EXTI_typedef*)(EXTI_base))
#define AFIO 			((AFIO_typedef*)(AFIO_base))

/***************************/
//***clock enable macros***//
#define RCC_GPIOA_CLK_EN() 		(RCC->APB2ENR|=1<<2);
#define RCC_GPIOB_CLK_EN() 		(RCC->APB2ENR|=1<<3);
#define RCC_GPIOC_CLK_EN() 		(RCC->APB2ENR|=1<<4);
#define RCC_GPIOD_CLK_EN() 		(RCC->APB2ENR|=1<<5);
#define RCC_GPIOE_CLK_EN() 		(RCC->APB2ENR|=1<<6);
#define RCC_AFIO_CLK_EN() 		(RCC->APB2ENR|=1<<0);

/*******************************/
/* IVT */
#define EXTI0_IRQ 6
#define EXTI1_IRQ 7
#define EXTI2_IRQ 8
#define EXTI3_IRQ 9
#define EXTI4_IRQ 10
#define EXTI5_IRQ 23
#define EXTI6_IRQ 23
#define EXTI7_IRQ 23
#define EXTI8_IRQ 23
#define EXTI9_IRQ 23
#define EXTI10_IRQ 40
#define EXTI11_IRQ 40
#define EXTI12_IRQ 40
#define EXTI13_IRQ 40
#define EXTI14_IRQ 40
#define EXTI15_IRQ 40


#endif /* INC_STM32F103X6_H_ */



