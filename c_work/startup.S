.global _start

_start:
    ldr x0, =_stack_top
    mov sp, x0

    /* 其他初始化代码 */

    bl main

    /* 如果 main 返回，进入死循环 */
1:  b 1b
