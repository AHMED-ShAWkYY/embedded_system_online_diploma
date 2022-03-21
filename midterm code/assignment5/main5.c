/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void count_num_of_ones(int x);
int getbit(number,bitno);
void main()
{
int number;
printf("enter the number: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&number);
count_num_of_ones(number);
}
void count_num_of_ones(int x)
{
//size of int =32 bit
int i,count=0,ret_value;
for(i=0;i<32;i++)
{
	ret_value=getbit(x,i);
	if(ret_value==1)
		count++;
}
printf("num of ones =%d",count);
}
int getbit(number,bitno)
{
	int x;
	x=(number>>bitno)&1;
	return x;
}
