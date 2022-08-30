/*
 * main.c
 *
 *  Created on: Mar 15, 2022
 *      Author: PC
 */
//c program to add two complex nums by passing structures to fn
#include<stdio.h>
#include<string.h>
struct Snumber
{
float real;
float imaginary;
};
void add_complex_nums(struct Snumber x,struct Snumber y);
void main()
{
struct Snumber number1,number2;
printf("for 1st complex numbers \n");
fflush(stdin);
fflush(stdout);
printf("enter real and imaginary respectively: ");
fflush(stdout);
scanf("%f%f",&number1.real,&number1.imaginary);
printf("for 2nd complex numbers \n");
fflush(stdin);
fflush(stdout);
printf("enter real and imaginary respectively: ");
fflush(stdout);
scanf("%f%f",&number2.real,&number2.imaginary);
add_complex_nums(number1,number2);
}
void add_complex_nums(struct Snumber x,struct Snumber y)
{
	struct Snumber sum;
	sum.real=x.real+y.real;
	sum.imaginary=(x.imaginary+y.imaginary);
	printf("sum=%.1f+%.1fi",sum.real,sum.imaginary);
}
