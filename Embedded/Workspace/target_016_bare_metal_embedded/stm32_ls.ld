ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		end_of_text = .;
	}> FLASH

	_la_data = LOADADDR(.data);

	.data :
	{
		start_of_data = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		end_of_data = .;
	}> SRAM AT> FLASH

	.bss :
	{
		start_of_bss = .;
		__bss_start__ = start_of_bss;
		*(.bss)
		*(.bss.*)
		. = ALIGN(4);
		end_of_bss = .;
		__bss_end__ = end_of_bss;
		. = ALIGN(4);
		end = .;
	}> SRAM
}
