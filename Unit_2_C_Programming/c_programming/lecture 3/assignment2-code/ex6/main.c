/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
int i=1,n,sum=0;
printf("enter an integar : ");
fflush(stdout);
fflush(stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	sum+=i;
}
printf("sum = %d",sum);
}

