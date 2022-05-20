//@ Ahmed Shawki
#include"platorm_types.h"
extern void main();
extern unsigned int stack_top ;
extern unsigned int _E_text ;
extern unsigned int _S_data ;
extern unsigned int _E_data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
void reset_handler();
void default_handler();
void nmi_handler()__attribute__((weak,alias("default_handler")));
void hw_fault_handler()__attribute__((weak,alias("default_handler")));
void mm_fault_handler()__attribute__((weak,alias("default_handler")));
void bus_fault_handler()__attribute__((weak,alias("default_handler")));
void usage_fault_handler()__attribute__((weak,alias("default_handler")));

uint32 vectors[] __attribute__((section(".vectors")))=
{
(uint32)&stack_top	,
(uint32)&reset_handler,
(uint32)&nmi_handler	,
(uint32)&hw_fault_handler	,
(uint32)&mm_fault_handler	,
(uint32)&bus_fault_handler	,
(uint32)&usage_fault_handler	,	
};
void reset_handler()
{
	int i;
	unsigned int data_size =(unsigned char *)&_E_data-(unsigned char *)&_S_data ;
	unsigned int bss_size  =(unsigned char *)&_E_bss-(unsigned char *)&_S_bss ;
	unsigned char * p_src=(unsigned char *)&_E_text ;
	unsigned char * p_dst=(unsigned char *)&_S_data ; 	
	for(i=0;i<data_size;i++,p_dst++,p_src++)
	{
		*p_dst=*p_src;
		
	}
	p_dst=(unsigned char *)&_S_bss ;
	for(i=0;i<data_size;i++,p_dst++)
	{
		*p_dst=(unsigned char)0;
		
	}
	main();
}	
void default_handler()
{
	reset_handler();
}