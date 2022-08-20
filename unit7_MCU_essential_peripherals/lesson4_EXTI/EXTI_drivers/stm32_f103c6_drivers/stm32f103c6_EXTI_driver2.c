/*
 * stm32f103c6_EXTI_driver.c
 *
 *  Created on: Aug 2, 2022
 *      Author: ahmed shawki
 */
#include "stm32f103c6_EXTI_driver.h"
#include "stm32f103c6_gpio_driver.h"
/*==========================
/* GENERIC POINTERS TO FUNCTIONS
/===========================*/
void (*GP_IRQ_Callback[15])(void);

/*==========================
/* GENERIC MACROS
/===========================*/

#define GPIO_AFIO_MAPPING(X) ( (X==GPIOA)?0:   \
							   (X==GPIOB)?1:   \
							   (X==GPIOC)?2:   \
  							   (X==GPIOD)?3:0    )

void Enable_NVIC(uint16_t IRQ)
{
switch(IRQ)
{
case 0 :
	NVIC_IRQ6_EXTI0_Enable;
	break;
case 1 :
	NVIC_IRQ7_EXTI1_Enable;
	break;
case 2 :
	NVIC_IRQ8_EXTI2_Enable;
	break;
case 3 :
	NVIC_IRQ9_EXTI3_Enable;
	break;
case 4 :
	NVIC_IRQ10_EXTI4_Enable;
	break;
case 5 :
case 6 :
case 7 :
case 8 :
case 9 :
	NVIC_IRQ23_EXTI5_9_Enable;
		break;
case 10 :
case 11 :
case 12 :
case 13 :
case 14 :
case 15 :
	NVIC_IRQ40_EXTI10_15_Enable;
}
}
void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0 :
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1 :
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2 :
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3 :
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4 :
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	case 9 :
		NVIC_IRQ23_EXTI5_9_Disable;
			break;
	case 10 :
	case 11 :
	case 12 :
	case 13 :
	case 14 :
	case 15 :
		NVIC_IRQ40_EXTI10_15_Disable;
		}
}

void Update_EXTI(EXTI_Pin_Config_t* EXTI_CFG)
{
	//1-configure GPIO pin to be alternative function input (floating input)
	GPIO_Pin_config_t Pin_CFG;
	Pin_CFG.GPIO_Pin_number=EXTI_CFG->EXTI_Pin.GPIO_Pin;
	Pin_CFG.GPIO_mode_define=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(EXTI_CFG->EXTI_Pin.GPIO_Port,&Pin_CFG);
	//2-UPDATE AFIO TO ROUTE Between EXTI line with Port A,B,C,D
	uint8_t AFIO_EXTI_INDEX=(EXTI_CFG->EXTI_Pin.EXTI_input_line_number)/4;
	uint8_t AFIO_EXTI_Position=((EXTI_CFG->EXTI_Pin.EXTI_input_line_number)%4)*4;
	//3-clear the four bit first
	AFIO->EXT1_CR[AFIO_EXTI_INDEX]&=~(0XF<<AFIO_EXTI_Position);
	//These bits are written by software to select the source input for EXTIx external interrupt
	AFIO->EXT1_CR[AFIO_EXTI_INDEX]|=((GPIO_AFIO_MAPPING(EXTI_CFG->EXTI_Pin.GPIO_Port)&0xF)<<AFIO_EXTI_Position);
	//4-update rising or falling edge
	EXTI->RTSR&=~(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	EXTI->FTSR&=~(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	if(EXTI_CFG->trigger_case==EXTI_trigger_rising)
	{
		EXTI->RTSR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	}
	else if(EXTI_CFG->trigger_case==EXTI_trigger_falling)
	{
		EXTI->FTSR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	}
	else if(EXTI_CFG->trigger_case==EXTI_trigger_risingandfalling)
	{
		EXTI->RTSR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
		EXTI->FTSR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	}
	//5-update IRQ handler call back
	GP_IRQ_Callback[EXTI_CFG->EXTI_Pin.EXTI_input_line_number]=EXTI_CFG->P_IRQ_Callback;
	//6-enable or disable IRQ & NVIC
	if(EXTI_CFG->IRQ_EN==EXTI_IRQ_enable)
	{
		EXTI->IMR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
		Enable_NVIC(EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	}
	else
	{
		EXTI->IMR|=(1<<EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
		Disable_NVIC(EXTI_CFG->EXTI_Pin.EXTI_input_line_number);
	}
}

/**================================================================
 * @Fn			- MCAL_GPIO_EXTI_Deinit
 * @brief 		- reset the EXTI registers and corresponding IRQ mask
 * @retval 		- none
 * Note			- none
 */

 void MCAL_GPIO_EXTI_Deinit(void)
{
	EXTI->IMR=0x00000000;
	EXTI->EMR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0xffffffff;

//disable IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}
 /**================================================================
 * @Fn			- MCAL_GPIO_EXTI_init
 * @brief 		- initialize the EXTI GPIO and trigger the IRQ pin and NVIC pin
 * @param [in] 	- EXTI CONFIG SET based on  @ref EXTI define and @ref EXTI IRQ define and @ref EXTI trigger_case
 * @retval 		- none
 * Note			- the stm32f103c6 has ports A,B,C,D,E
 * 				  but if you use LFQP48 package it uses only A,B and part of C,D
 */

void MCAL_GPIO_EXTI_init(EXTI_Pin_Config_t *EXTI_CFG)
{
	Update_EXTI(EXTI_CFG);
}
void MCAL_GPIO_EXTI_update(EXTI_Pin_Config_t* EXTI_CFG)
{
	Update_EXTI(EXTI_CFG);
}

void EXTI0_IRQHandler(void)
{
//cleared by writing bit to pending register
EXTI->PR|=1<<0;
//call IRQ CALL
GP_IRQ_Callback[0]();
}
void EXTI1_IRQHandler(void)
{
	//cleared by writing bit to pending register
	EXTI->PR|=1<<1;
	//call IRQ CALL
	GP_IRQ_Callback[1]();
}
void EXTI2_IRQHandler(void)
{
	//cleared by writing bit to pending register
	EXTI->PR|=1<<2;
	//call IRQ CALL
	GP_IRQ_Callback[2]();
}
void EXTI3_IRQHandler(void)
{
	//cleared by writing bit to pending register
	EXTI->PR|=1<<3;
	//call IRQ CALL
	GP_IRQ_Callback[3]();
}
void EXTI4_IRQHandler(void)
{
	//cleared by writing bit to pending register
	EXTI->PR|=1<<4;
	//call IRQ CALL
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
if(EXTI->PR&(1<<5)) {EXTI->PR|=1<<5;   GP_IRQ_Callback[5](); }
if(EXTI->PR&(1<<6)) {EXTI->PR|=1<<6;   GP_IRQ_Callback[6](); }
if(EXTI->PR&(1<<7)) {EXTI->PR|=1<<7;   GP_IRQ_Callback[7](); }
if(EXTI->PR&(1<<8)) {EXTI->PR|=1<<8;   GP_IRQ_Callback[8](); }
if(EXTI->PR&(1<<9)) {EXTI->PR|=1<<9;   GP_IRQ_Callback[9](); }
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR&(1<<10)) {EXTI->PR|=1<<10;   GP_IRQ_Callback[10](); }
	if(EXTI->PR&(1<<11)) {EXTI->PR|=1<<11;   GP_IRQ_Callback[11](); }
	if(EXTI->PR&(1<<12)) {EXTI->PR|=1<<12;   GP_IRQ_Callback[12](); }
	if(EXTI->PR&(1<<13)) {EXTI->PR|=1<<13;   GP_IRQ_Callback[13](); }
	if(EXTI->PR&(1<<14)) {EXTI->PR|=1<<14;   GP_IRQ_Callback[14](); }
	if(EXTI->PR&(1<<15)) {EXTI->PR|=1<<15;   GP_IRQ_Callback[15](); }
}
