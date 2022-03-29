/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
int fact(int num);
void main()
{
int num,ret_value;
printf("enter an positive number");
fflush(stdin);
fflush(stdout);
scanf("%d",&num);
ret_value=fact(num);
printf("factorial of %d = %d",num,ret_value);
}
int fact(int num)
{
if(num>1)
return num*fact(num-1);
}
