/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a,b;
printf("enter the value of a: ");
fflush(stdout);
scanf("%f",&a);
printf("enter the value of b: ");
fflush(stdout);
scanf("%f",&b);
a=a*b;
b=a/b;
a=a/b;
printf("after swapping value of a = %f\n",a);
printf("after swapping value of b = %f",b);
}

