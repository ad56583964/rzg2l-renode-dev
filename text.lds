ENTRY(_start) /* 程序的入口点 */

SECTIONS
{
    . = 0x10000; /* 设置加载地址 */

    .text : /* 代码段 */
    {
        *(.text) /* 所有输入文件的 .text 段 */
    }

    .data : /* 数据段 */
    {
        *(.data) /* 所有输入文件的 .data 段 */
    }

    .bss : /* 未初始化数据段 */
    {
        *(.bss) /* 所有输入文件的 .bss 段 */
    }

    /DISCARD/ : /* 丢弃以下段 */
    {
        *(.comment) /* 丢弃所有输入文件的 .comment 段 */
    }
}
