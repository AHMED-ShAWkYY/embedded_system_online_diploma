/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float number1,number2,product=0;
printf("enter two numbers");
fflush(stdout);
scanf("%f %f",&number1,&number2);
product=number1*number2;
printf("product=%f",product);
}

