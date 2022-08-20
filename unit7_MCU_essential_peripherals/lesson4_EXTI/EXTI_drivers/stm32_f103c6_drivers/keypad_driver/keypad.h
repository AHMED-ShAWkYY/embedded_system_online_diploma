/*
 * keypad.h
 *
 *  Created on: Aug 9, 2022
 *      Author: PC
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_
#define F_CPU 8000000UL
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
#define keypad_port GPIOB
#define r0 GPIO_PIN_0
#define r1 GPIO_PIN_1
#define r2 GPIO_PIN_3
#define r3 GPIO_PIN_4
#define c0 GPIO_PIN_5
#define c1 GPIO_PIN_6
#define c2 GPIO_PIN_7
#define c3 GPIO_PIN_8
char keypad_get();
void keypad_init();

#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
