/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a[2][2],b[2][2],c[2][2];
int i,j;
printf("enter the elements of frist matrix \n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("enter a[%d][%d] :",i+1,j+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&a[i][j]);
	}
}
printf("enter the elements of second matrix \n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("enter b[%d][%d] :",i+1,j+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&b[i][j]);
	}
}
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
	c[i][j]=a[i][j]+b[i][j];
	}
}
printf("sum of matrix\n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("%.1f  ",c[i][j]);
	}
	printf("\n");
}
}
