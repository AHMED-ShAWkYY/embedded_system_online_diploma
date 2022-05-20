#include "platorm_types.h"
typedef union
{
	vuint32 allpins;
	struct
	{
		vuint32 pin0:1;
		vuint32 pin1:1;
		vuint32 pin2:1;
		vuint32 pin3:1;
		vuint32 pin4:1;
		vuint32 pin5:1;
		vuint32 pin6:1;
		vuint32 pin7:1;
		vuint32 pin8:1;
		vuint32 pin9:1;
		vuint32 pin10:1;
		vuint32 pin11:1;
		vuint32 pin12:1;
		vuint32 pin13:1;
		vuint32 pin14:1;
		vuint32 pin15:1;
		vuint32 pin16:1;
		vuint32 pin17:1;
		vuint32 pin18:1;
		vuint32 pin19:1;
		vuint32 pin20:1;
		vuint32 pin21:1;
		vuint32 pin22:1;
		vuint32 pin23:1;
		vuint32 pin24:1;
		vuint32 pin25:1;
		vuint32 pin26:1;
		vuint32 pin27:1;
		vuint32 pin28:1;
		vuint32 pin29:1;
		vuint32 pin30:1;
		vuint32 pin31:1;

	}pin;
}U_S;
#define RCC_base    0x40021000
#define portA_base  0x40010800
#define ARP2ENR 	RCC_base+0x18
#define GPIO_PA_CRH portA_base+0x04
#define GPIO_PA_ODR portA_base+0x0C
volatile unsigned int bss_var ;
volatile unsigned int data_var[3]={1,2,3} ;
void main()
{
	vuint32 i;
	volatile U_S *P_ARB=(volatile U_S*)(ARP2ENR);
	volatile U_S *P_CRH=(volatile U_S*)(GPIO_PA_CRH);
	volatile U_S *P_ODR=(volatile U_S*)(GPIO_PA_ODR);
	P_ARB->pin.pin2=1;
	P_CRH->allpins=0;
	P_CRH->pin.pin21=1;
	while(1)
	{
		P_ODR->pin.pin13=1;
		for(i=0;i<50000;i++);
		P_ODR->pin.pin13=0;
		for(i=0;i<50000;i++);
	}
}
