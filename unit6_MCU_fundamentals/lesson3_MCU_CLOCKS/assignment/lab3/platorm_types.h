/*
 * platform_types.h
 *
 *  Created on: Mar 29, 2022
 *      Author: PC
 */
#include<stdio.h>
#ifndef PLATFORMTYPES_H_
#define PLATFORMTYPES_H_
typedef unsigned char boolean;
typedef signed char   sint8;
typedef signed short  sint16;
typedef signed int	  sint32;
typedef unsigned char  unit8;
typedef unsigned short uint16;
typedef	unsigned int uint32;
typedef long long  sint64;
typedef unsigned long long unit64;
typedef	float 	 float32;
typedef	double 	 float64;
/********************************************/
typedef volatile sint8  vint8;
typedef volatile sint16 vint16;
typedef volatile sint32 vint32;
typedef volatile unit8  vuint8;
typedef volatile uint16 vuint16;
typedef volatile uint32 vuint32;
typedef volatile sint64 vint64;
typedef volatile unit64 vuint64;

/********************************************/
#endif /* PLATFORMTYPES_H_ */

