SECTIONS
{
  . = 0x48080000;
  .text : { *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) }
}
