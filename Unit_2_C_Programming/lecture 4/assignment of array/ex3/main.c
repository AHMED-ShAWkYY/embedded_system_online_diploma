/*
 * main.c
 *
 *  Created on: Mar 12, 2022
 *      Author: PC
 */
#include<stdio.h>
void main()
{
float a[10][10],t[2][2];
int i,j,row,col;
printf("enter the rows and cols of the matrix \n");
fflush(stdin);
fflush(stdout);
scanf("%d",&row);
scanf("%d",&col);
printf("enter elements of matrix\n");
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
	{
		printf("enter element a[%d][%d] :",i+1,j+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&a[i][j]);
	}
}
printf("entered matrix :\n");
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
	{
		printf("%.0f  ",a[i][j]);
	}
	printf("\n");
}
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
	{
	t[j][i]=a[i][j];
	}
}
printf("transpose matrix :\n");
for(i=0;i<col;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%.0f  ",t[i][j]);
	}
	printf("\n");
}
}
