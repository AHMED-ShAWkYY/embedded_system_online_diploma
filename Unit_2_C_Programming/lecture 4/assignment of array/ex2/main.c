/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
	float a[10],sum=0,avg;
	int i,n;
	printf("enter the numbers of data\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("enter number %d :",i+1);
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&a[i]);
	sum+=a[i];
}
avg=sum/n;
printf("avg=%f",avg);
}
