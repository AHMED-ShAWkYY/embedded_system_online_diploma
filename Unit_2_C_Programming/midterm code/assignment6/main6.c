/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
#include<string.h>
int return_unique_number(int arr[],int size);
void main()
{
int a[7]={4,2,5,2,5,7,4},number=0;
fflush(stdin);
fflush(stdout);
number=return_unique_number(a,7);
printf("number=%d",number);
}

int return_unique_number(int arr[],int size)
{
	int i,j,number,count=0,counter=0;
	for(i=0,j=0;j<size;j++)
	{
		number=arr[i];
			if(number==arr[j])
			{
				count++;
			}
			if(count==1&&j==size-1)
			return number;
		if(j==size-1)
		{
			j=0;
			i++;
			count=0;
		}


	}
}
