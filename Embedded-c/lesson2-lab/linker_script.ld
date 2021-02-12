ENTRY(reset)
MEMORY
{
	Mem(rwx):ORIGIN =0x00000000 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
	    startup.o(.text)
	}> Mem

	.text :
	{
	   *(.texe)
	}> Mem

	.data :
	{
	   *(.data)
	}>Mem

	.bss :
	{
	   *(.bss)
	}> Mem
	. = . + 0x10000 ;
	stack_top = . ;
}