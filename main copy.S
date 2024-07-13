.syntax unified
.cpu cortex-a55
.thumb

/* Assume the base address of the UART controller is UART_BASE */
.equ UART_BASE, 0x2800d000
.equ UART_DR,   UART_BASE + 0x00         /* Data Register */
.equ UART_CR,   UART_BASE + 0x30         /* Control Register */
.equ BAUD_RATE, 115200

.section ".text"
.global _start

_start:
    .data
send_string:
    .ascii "Hello World!\n\0"
    .text
str_ptr:
    .word send_string

    ldr r0, =str_ptr
    ldr r0, [r0]

loop:
    // Read a character
    ldrb r1, [r0], #1
    cmp r1, #0
    beq end_loop

    // Wait until the UART is ready to transmit
    // (Actual code would involve polling the UART status register, simplified here)
    // ...

    // Write the character to the UART data register
    ldr r2, =UART_DR
    strb r1, [r2]

    b loop

end_loop:
    // End the program, typically in U-Boot you would enter an infinite loop
    b .