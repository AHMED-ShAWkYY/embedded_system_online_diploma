/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "lcd.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103x6.h"
//TO initialize the clock for the APB2 Bus
#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10
void clock_init(void)
{
	//Enabling the clock to APB2 bus GPIOA
	RCC_GPIOA_CLK_EN();
	//Enabling the clock to APB2 bus GPIOB
	RCC_GPIOB_CLK_EN();
}
void GPIO_INIT()
{
	GPIO_Pin_config_t PIN_Config;
	PIN_Config.GPIO_Pin_number=GPIO_PIN_9;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_10;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_11;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_12;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_13;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_14;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
	PIN_Config.GPIO_Pin_number=GPIO_PIN_15;
	PIN_Config.GPIO_output_speed=GPIO_speed_10M;
	PIN_Config.GPIO_mode_define=GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB,&PIN_Config);
}

int main()
{
	int i;
	char pressed_key;
	clock_init();
	LCD_init();
	LCD_WRITE_STRING("ahmed shawky");
	wait(200);
	LCD_Clear_Screen();
	GPIO_INIT();
	unsigned char seg[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	unsigned short lcd[]={'0','1','2','3','4','5','6','7','8','9'};
	for(i=0;i<10;i++)
	{
		LCD_WRITE_CHAR(lcd[i]);
		MCAL_GPIO_write_Port(GPIOB, seg[i]<<9);
		wait(100);
	}
	LCD_Clear_Screen();
	LCD_WRITE_STRING("keypad is ready");
	LCD_Clear_Screen();
	keypad_init();
	while(1)
	{
		pressed_key=keyoad_getchar();
		switch(pressed_key)
		{
		case ('!'):
						LCD_Clear_Screen();
		break;
		case ('N'):
						break;
		default:
			LCD_WRITE_CHAR(pressed_key);
			break;
		}
	}
}
