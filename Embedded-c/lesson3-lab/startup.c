//startup.c
//Eng.Mostafa-Elshiekh
#include <stdint.h>
void Reset_Handler();

extern int main(void);
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler()__attribute__ ((weak,alias("Default_Handler")));; //wake to can override on any enterupt function 
void H_fault_Handler()__attribute__ ((weak,alias("Default_Handler")));;//alias to collect all function before defination it in one adderss
void MM_fault_Hander()__attribute__ ((weak,alias("Default_Handler")));; 
void Bus_Handler()__attribute__ ((weak,alias("Default_Handler")));;
void Usage_falut_Handler()__attribute__ ((weak,alias("Default_Handler")));;


extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Hander,
	(uint32_t) &Bus_Handler,
	(uint32_t) &Usage_falut_Handler
};


extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
void Reset_Handler()
{
	//Copy data section from falsh to ram
	unsigned int DATA_SIZE	= (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char *P_src= (unsigned char*)&_E_TEXT;
	unsigned char *P_det= (unsigned char*)&_S_DATA;
	int i;

	for(i=0;i<DATA_SIZE;i++)
	{
      
      *((unsigned char*)P_det++)=*(unsigned char*)P_src++;

	}

	//init bss section in sram and inialize it by 0
	unsigned int BSS_SIZE=(unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	P_det=(unsigned char*)&_S_BSS;
	for(i=0;i<BSS_SIZE;i++)
	{
      
      *((unsigned char*)P_det++)=(unsigned char)0;

	}

	//jumb to main()
    main();
}
