ENTRY(_start)

SECTIONS
{
    . = 0x90001000;

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
        . = . + 0x1000;
    }
    _stack_top = .;
}
