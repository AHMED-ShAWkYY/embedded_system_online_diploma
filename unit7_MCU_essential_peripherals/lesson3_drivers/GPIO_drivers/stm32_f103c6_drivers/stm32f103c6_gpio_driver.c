/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Aug 2, 2022
 *      Author: ahmed shawki
 */
#include "inc/stm32f103c6_gpio_driver.h"
uint8_t Get_CRLH_Position(uint16_t pin_number)
{
switch(pin_number)
{
case GPIO_PIN_0:
	return 0 ;
	break;
case GPIO_PIN_1:
	return 4 ;
	break;
case GPIO_PIN_2:
	return 8 ;
	break;
case GPIO_PIN_3:
	return 12 ;
	break;
case GPIO_PIN_4:
	return 16 ;
	break;
case GPIO_PIN_5:
	return 20 ;
	break;
case GPIO_PIN_6:
	return 24 ;
	break;
case GPIO_PIN_7:
	return 28 ;
	break;
case GPIO_PIN_8:
	return 0 ;
	break;
case GPIO_PIN_9:
	return 4 ;
	break;
case GPIO_PIN_10:
	return 8 ;
	break;
case GPIO_PIN_11:
	return 12 ;
	break;
case GPIO_PIN_12:
	return 16 ;
	break;
case GPIO_PIN_13:
	return 20 ;
	break;
case GPIO_PIN_14:
	return 24 ;
	break;
case GPIO_PIN_15:
	return 28 ;
	break;

}
}
/**================================================================
* @Fn			- MCAL_GPIO_INIT
* @brief 		- initialize the GPIOX /PINY according to GPIO_Pin_config_t
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @param [out] 	- pin_config pointer to GPIO_Pin_config_t structure that contains
* 				  the configuration  for a specific pin
* @retval 		- none
* Note			- the stm32f103c6 has ports A,B,C,D,E
* 				  but if you use LFQP48 package it uses only A,B and part of C,D
*/
void   MCAL_GPIO_INIT(GPIO_typedef *GPIOX,GPIO_Pin_config_t* pin_config)
{
	volatile uint32_t *config_register=NULL;
	volatile uint8_t PIN_CONFIG=0;
	//determine the register CRL or CRH
	config_register =pin_config->GPIO_Pin_number <GPIO_PIN_8 ? &GPIOX->CRL:&GPIOX->CRH;
	//clear the CNFy MODEy at the beginning
	*(config_register)&=~(0xf<<Get_CRLH_Position(pin_config->GPIO_Pin_number));
	//if pin is output
	if((pin_config->GPIO_mode_define==GPIO_MODE_OUTPUT_PP)||(pin_config->GPIO_mode_define==GPIO_MODE_OUTPUT_OD)||(pin_config->GPIO_mode_define==GPIO_MODE_ALTF_OUTPUT_OD)||(pin_config->GPIO_mode_define==GPIO_MODE_ALTF_OUTPUT_PP))
	{
		PIN_CONFIG=((((pin_config->GPIO_mode_define-4)<<2)|(pin_config->GPIO_output_speed))&0x0f);
	}
	//if pin is input
	else
	{
		if((pin_config->GPIO_mode_define==GPIO_MODE_INPUT_FLO)||(pin_config->GPIO_mode_define==GPIO_MODE_Analog))
				{
			PIN_CONFIG=((((pin_config->GPIO_mode_define)<<2)|0x0)&0x0f);
				}
		else if(pin_config->GPIO_mode_define==GPIO_MODE_AF_input)
					{
				PIN_CONFIG=((((GPIO_MODE_INPUT_FLO)<<2)|0x0)&0xf);
					}
		else// PU or PD
		{
		if(pin_config->GPIO_mode_define==GPIO_MODE_INPUT_PU)
		{
			PIN_CONFIG=((((GPIO_MODE_INPUT_PU)<<2)|0x0)&0xf);
			GPIOX->ODR|=pin_config->GPIO_Pin_number;
		}
		else
		{
			PIN_CONFIG=((((GPIO_MODE_INPUT_PU)<<2)|0x0)&0xf);
			GPIOX->ODR&=~(pin_config->GPIO_Pin_number);
		}
		}
	}
	//write on CRL or CRH
	(*config_register)|=((PIN_CONFIG)<<Get_CRLH_Position(pin_config->GPIO_Pin_number));
}
/**================================================================
* @Fn			- MCAL_GPIO_DEINIT
* @brief 		- reset all the regissters of the GPIO pin
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_DEINIT(GPIO_typedef *GPIOX)
{
if(GPIOX==GPIOA)
{
RCC->APB2RSTR|=(1<<2);
RCC->APB2RSTR&=~(1<<2);
}
else if(GPIOX==GPIOB)
{
RCC->APB2RSTR|=(1<<3);
RCC->APB2RSTR&=~(1<<3);
}
else if(GPIOX==GPIOC)
{
RCC->APB2RSTR|=(1<<4);
RCC->APB2RSTR&=~(1<<4);
}
else if(GPIOX==GPIOD)
{
RCC->APB2RSTR|=(1<<5);
RCC->APB2RSTR&=~(1<<5);
}
else if(GPIOX==GPIOE)
{
RCC->APB2RSTR|=(1<<6);
RCC->APB2RSTR&=~(1<<6);
}
}

/**================================================================
* @Fn			- MCAL_GPIO_Read_Pin
* @brief 		- read specific pin
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @param [in] 	- pin_number : set pin number according to @GPIO Ref number
* @retval 		- the input pin value (two values based on @ref GPIO_PIN_STATE )
* Note			- none
*/

uint8_t MCAL_GPIO_Read_Pin(GPIO_typedef *GPIOX,uint16_t pin_number)
{
	uint8_t status_bit;
	if((GPIOX->IDR)&(pin_number)!=(uint32_t)GPIO_Pin_RESET)
	{
		status_bit=GPIO_Pin_SET;
	}
	else
	{
		status_bit=GPIO_Pin_RESET;
	}
	return status_bit;
}

/**================================================================
* @Fn			- MCAL_GPIO_Read_Port
* @brief 		- read specific port
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @retval 		- the input port value
* Note			- none
*/
uint16_t MCAL_GPIO_Read_Port(GPIO_typedef *GPIOX)
{
	uint16_t port_val=(uint16_t)GPIOX->IDR	;
	return port_val  ;
}
/**================================================================
* @Fn 			- MCAL_GPIO_write_Pin
* @brief 		- write on specific pin
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* * @param [in] - pin_number -> specifies the pin number
* * @param [in] - value : pin value
* @retval 		- none
* Note			- none
*/
void  MCAL_GPIO_write_Pin(GPIO_typedef *GPIOX,uint16_t pin_number,uint8_t value)
{
	if(value!=(uint8_t)GPIO_Pin_RESET)
	{
		GPIOX->ODR|=pin_number;
	}
	else
	{
		GPIOX->ODR&=~(pin_number);
	}
}
/**================================================================
* @Fn			- MCAL_GPIO_write_Port
* @brief 		- write on specific port
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @param [in] 	- value : port value
* @retval 		- none
* Note			- none
*/
void  MCAL_GPIO_write_Port(GPIO_typedef *GPIOX,uint16_t value)
{
	GPIOX->ODR=(uint32_t)value;
}
/**================================================================
* @Fn			- MCAL_GPIO_toggle_Pin
* @brief 		- toggle a specfic pin according to @GPIO Ref number
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @param [in] 	- pin_number :specify the number of the pin
* @retval 		- none
* Note			- none
*/
void  MCAL_GPIO_toggle_Pin(GPIO_typedef *GPIOX,uint16_t pin_number)
{
	GPIOX->ODR^=(uint32_t)pin_number;
}
/**================================================================
* @Fn			- MCAL_GPIO_lock_Pin
* @brief 		- lock a specfic pin means locking the configuration
* @param [in] 	- GPIOX where x can be A,B,C,D,E
* @param [in] 	- pin_number :specify the number of the pin
* @retval 		- OK if pin config is locked or error if pin is not locked based on @ref GPIO_LOCK
* Note			- none
*/
uint8_t MCAL_GPIO_lock_Pin(GPIO_typedef *GPIOX,uint16_t pin_number)
{
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
volatile uint32_t tmp =1<<16;
tmp|=pin_number;
//	LOCK key writing sequence:
//	Write 1
GPIOX->LCKR=tmp;
//	Write 0
GPIOX->LCKR=pin_number;
//	Write 1
GPIOX->LCKR=tmp;
//	Read 0
tmp=GPIOX->LCKR;
//	Read 1 (this read is optional but confirms that the lock is active)
if((uint32_t)(GPIOX->LCKR)&1<<16)
{
return GPIO_return_lock_enable;
}
else
{
	return GPIO_return_lock_enable;
}
}
