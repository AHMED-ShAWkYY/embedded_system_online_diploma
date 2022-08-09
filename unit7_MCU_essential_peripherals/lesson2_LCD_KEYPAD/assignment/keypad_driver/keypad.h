/*
 * keypad.h
 *
 * Created: 7/29/2022 2:53:08 PM
 *  Author: PC
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 8000000UL
#include "avr/io.h"
#include "util/delay.h"
#define keypad_dir DDRD
#define keypad_port PORTD
#define keypad_input PIND
#define r0 0
#define r1 1
#define r2 2
#define r3 3
#define c0 4
#define c1 5
#define c2 6
#define c3 7
char keypad_get();
void keypad_init();
#endif /* KEYPAD_H_ */