/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
void prime_num(int start,int end);
void main()
{
int n1,n2;
printf("enter the frist number: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&n1);
printf("enter the second number: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&n2);
prime_num(n1,n2);
}
void prime_num(int start,int end)
{
int i,j,count=0;
for(i=start;i<=end;i++)
{
	count=0;
	for(j=1;j<=i;j++)
	{
		if(i%j==0)
			count++;
	}
	if(count==2)
		printf("%d ",i);
}
}
