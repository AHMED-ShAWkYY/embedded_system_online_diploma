/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Aug 2, 2022
 *      Author: ahmed shawki
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//includes
#include "stm32f103x6.h"
/****************/
//config structure
typedef struct
{
	uint16_t GPIO_Pin_number;  	//specify the GPIO pin to be configured
	// this parameter must be set based on @GPIO Ref number
	uint8_t  GPIO_mode_define; 	//specify the operating mode for the selected pins
	// this parameter must be set based on @GPIO mode define
	uint8_t  GPIO_output_speed; //specify the GPIO speed
	// this parameter can be a value of @GPIO speed define
}GPIO_Pin_config_t;




//==================
//GPIO configuration registers
/*******************/
//@GPIO Ref number
#define GPIO_PIN_0 		((uint16_t)0x0001)
#define GPIO_PIN_1 		((uint16_t)0x0002)
#define GPIO_PIN_2 		((uint16_t)0x0004)
#define GPIO_PIN_3 		((uint16_t)0x0008)
#define GPIO_PIN_4 		((uint16_t)0x0010)
#define GPIO_PIN_5 		((uint16_t)0x0020)
#define GPIO_PIN_6 		((uint16_t)0x0040)
#define GPIO_PIN_7 		((uint16_t)0x0080)
#define GPIO_PIN_8 		((uint16_t)0x0100)
#define GPIO_PIN_9 		((uint16_t)0x0200)
#define GPIO_PIN_10 	((uint16_t)0x0400)
#define GPIO_PIN_11		((uint16_t)0x0800)
#define GPIO_PIN_12		((uint16_t)0x1000)
#define GPIO_PIN_13		((uint16_t)0x2000)
#define GPIO_PIN_14 	((uint16_t)0x4000)
#define GPIO_PIN_15		((uint16_t)0x8000)
#define GPIO_PIN_ALL 	((uint16_t)0xFFFF)
#define GPIO_PIN_Mask   0x0000FFFFU

//@GPIO mode define
/************
00: Analog mode
01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved
00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain
****************/
#define GPIO_MODE_Analog 				0x00000000u
#define GPIO_MODE_INPUT_FLO 			0x00000001u
#define GPIO_MODE_INPUT_PU 				0x00000002u
#define GPIO_MODE_INPUT_PD				0x00000003u
#define GPIO_MODE_OUTPUT_PP 			0x00000004u
#define GPIO_MODE_OUTPUT_OD 			0x00000005u
#define GPIO_MODE_ALTF_OUTPUT_PP 		0x00000006u
#define GPIO_MODE_ALTF_OUTPUT_OD 		0x00000007u
#define GPIO_MODE_AF_input 				0x00000008u

/************
 01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.
 ***********/
// @GPIO speed define
#define GPIO_speed_10M  0x00000001u    //max speed 10 MHz.
#define GPIO_speed_2M  	0x00000002u    //max speed 2 MHz.
#define GPIO_speed_50M  0x00000003u    //max speed 50 MHz.

//@ref GPIO_PIN_STATE
#define GPIO_Pin_SET   		1
#define GPIO_Pin_RESET 		0


//@ref GPIO_LOCK
#define GPIO_return_lock_enable   		1
#define GPIO_return_lock_error 			0

/**************
 =================================
 	 	 	 APIS -> MCAL GPIO DRIVER
 =================================
 *************/
void MCAL_GPIO_INIT(GPIO_typedef *GPIOX,GPIO_Pin_config_t* pin_config);
void MCAL_GPIO_DEINIT(GPIO_typedef *GPIOX);
uint8_t  MCAL_GPIO_Read_Pin(GPIO_typedef *GPIOX,uint16_t pin_number);
uint16_t MCAL_GPIO_Read_Port(GPIO_typedef *GPIOX);
void  MCAL_GPIO_write_Pin(GPIO_typedef *GPIOX,uint16_t pin_number,uint8_t value);
void  MCAL_GPIO_write_Port(GPIO_typedef *GPIOX,uint16_t value);
void  MCAL_GPIO_toggle_Pin(GPIO_typedef *GPIOX,uint16_t pin_number);
uint8_t  MCAL_GPIO_lock_Pin(GPIO_typedef *GPIOX,uint16_t pin_number);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */



