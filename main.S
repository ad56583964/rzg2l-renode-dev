.global _start

.section .text

.equ UART_BASE, 0x1004D000

.equ UART_SMR, 0x00          // 数据寄存器偏移
.equ UART_BRR, 0x01       
.equ UART_SCR, 0x02          // 数据寄存器偏移
.equ UART_TDR, 0x03         // 标志寄存器偏移
.equ UART_SSR, 0x04          // 标志寄存器偏移
.equ UART_RDR, 0x05
.equ UART_SCMR, 0x06
.equ UART_SEMR, 0x07
.equ UART_SNFR, 0x08
.equ UART_SECR, 0x0D
.equ UART_TDRH, 0x0E
.equ UART_TDRL, 0x0F
.equ UART_TDRHL, 0x0E
.equ UART_RDRH, 0x10
.equ UART_RDRL, 0x11
.equ UART_RDRHL, 0x10

.equ UART_MDDR, 0x12

.equ UART_FR, 0x18          // 标志寄存器偏移
.equ UART_FR_TXFF, 0x20     // 标志寄存器中的发送缓冲区满标志


_start:
    # 写入串口输出(copy from QEMU nuttx)
    ldr   x15, =UART_BASE
