/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//c program to find area of a circle ,passing arguments to macro
#include<stdio.h>
#include<string.h>
#define circle_area(r) (3.14*r*r)
void main()
{
	float r,area;
	printf("enter the radius");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&r);
	area=circle_area(r);
	printf("area=%.2f",area);
}
