/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a,b,swap;
printf("enter the value of a: ");
fflush(stdout);
scanf("%f",&a);
printf("enter the value of b: ");
fflush(stdout);
scanf("%f",&b);
swap=a;
a=b;
b=swap;
printf("after swapping value of a = %f\n",a);
printf("after swapping value of a = %f",b);
}

