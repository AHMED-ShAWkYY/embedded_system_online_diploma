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
#define RCC_CFGR 	*((volatile unsigned int *)(RCC_base+0x04))
#define RCC_CR 	*((volatile unsigned int *)(RCC_base+0x0))


void main()
{
	/*Bits 21:18 PLLMUL: PLL multiplication factor
These bits are written by software to define the PLL multiplication factor. These bits can be 
written only when PLL is disabled. 
Caution: The PLL output frequency must not exceed 72 MHz.
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8*/
RCC_CFGR|=(0b0110<<18);
/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock 
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16*/
	RCC_CFGR|=(0b100<<8);

		/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock 
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16*/
	RCC_CFGR|=(0b101<<11);	
	/*Bits 1:0 SW: System clock switch
Set and cleared by software to select SYSCLK source.
Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of 
failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security 
System is enabled).
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
11: not allowed*/
RCC_CFGR|=(0b10<<0);
	/*Bit 24 PLLON: PLL enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the 
PLL clock is used as system clock or is selected to become the system clock.
0: PLL OFF
1: PLL ON*/
RCC_CR|=(1<<24);
	
	



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
