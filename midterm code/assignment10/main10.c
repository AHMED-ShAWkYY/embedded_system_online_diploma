/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
#include<string.h>
int max_num(int number);
int getbit(int number,int bitno);
void main()
{
int num,max=0;
printf("enter the number\n");
fflush(stdin);
fflush(stdout);
scanf("%d",&num);
max=max_num(num);
printf("number of ones=%d",max);
}
int max_num(int number)
{
	int i,count=0,ret_value,max=0;
	for(i=0;i<32;i++)
{
	ret_value=getbit(number,i);
	if(ret_value==1)
	{
		count++;
		if(count>max)
		{
		max=count;
		}
	}
	else
		count=0;
}
	return max;
}
int getbit(int number,int bitno)
{
	int x;
	x=(number>>bitno)&1;
	return x;
}
