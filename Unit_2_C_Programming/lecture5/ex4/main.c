/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
int power_num(int num,int powr);
void main()
{
int number,power,result;
char a[20];
printf("enter base number");
fflush(stdin);
fflush(stdout);
scanf("%d",&number);
printf("enter power number(positive integar):");
fflush(stdin);
fflush(stdout);
scanf("%d",&power);
result=power_num(number,power);
printf("%d^%d=%d",number,power,result);
}
int power_num(int num,int powr)
{
	if(powr>0)
	return num*power_num(num,powr-1);
	else
	return 1;
}
