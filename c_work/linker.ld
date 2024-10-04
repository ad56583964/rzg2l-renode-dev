ENTRY(_start)

SECTIONS
{
    . = 0x50000000;

    .text :
    {
        *(.text)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(.bss)
    }
    
    .stack (NOLOAD) :
    {
        . = ALIGN(16);
        . = . + 0x1000;
        . = ALIGN(16);
    }
    _stack_top = .;
}
