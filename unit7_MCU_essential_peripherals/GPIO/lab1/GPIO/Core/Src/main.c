
#define uint32_t unsigned int
//Clock configuration
#define RCC_Base 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_Base+0x18)


//GPIOA configuration
#define GPIOA_Base 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_Base+0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_Base+0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_Base+0x0c)
#define GPIOA_IDR *(volatile uint32_t *)(GPIOA_Base+0x08)

//GPIOB configuration
#define GPIOB_Base 0x40010C00
#define GPIOB_CRL *(volatile uint32_t *)(GPIOB_Base+0x00)
#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_Base+0x04)
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_Base+0x0c)
#define GPIOB_IDR *(volatile uint32_t *)(GPIOB_Base+0x08)


//TO initialize the clock for the APB2 Bus
void clock_init(void)
{
	//Enabling the clock to APB2 bus GPIOA
	RCC_APB2ENR |= (1<<2);

	//Enabling the clock to APB2 bus GPIOB
	RCC_APB2ENR |= (1<<3);

}
//TO initialize the GPIOA and Pin 13
void gpio_init()
{
	GPIOA_CRL= 0;
	GPIOB_CRL= 0;
	GPIOA_CRH= 0;
	GPIOB_CRH= 0;
	GPIOA_ODR= 0;
	//PA1 FLOATING IN
	GPIOA_CRL|=1<<6;
	//PA13 FLOATING IN
	GPIOA_CRH&=~(0b11<<20);
	GPIOA_CRH|=(1<<22);

	//PB1 OUT PUSH-PULL MODE
	GPIOB_CRL|=(1<<4);
	//PB13 OUT PUSH-PULL MODE
	GPIOB_CRH|=(1<<20);

}


int main(void)
{
	int i;
	clock_init();
	gpio_init();


	while(1)
	{
	//PA1>> PULL UP RESISTOR
	if(((GPIOA_IDR&(1<<1))>>1)==0)//single press
	{
		GPIOB_ODR^=(1<<1);
		while((((GPIOA_IDR&(1<<1))>>1)==0));
	}
	//PA13>> PULL DOWN RESISTOR
	if(((GPIOA_IDR&(1<<13))>>13)==1) //multipress
	{
		GPIOB_ODR^=(1<<13);
		for(i=0;i<50000;i++);
		for(i=0;i<50000;i++);
	}

	}
}
