/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
#include<stdio.h>
#include<string.h>
double return_square_root(float number);
void main()
{
double num,root;
printf("enter the number\n");
fflush(stdin);
fflush(stdout);
scanf("%lf",&num);
root=return_square_root(num);
printf("number=%.2lf",root);
}

double return_square_root(float number)
{
	double i;
	for(i=.01;i*i<number;i+=.01);
	i-=.01;
	return i;

}
