.global _start

.section .text

.equ SCI_BASE, 0x1004D000

# SCI 寄存器偏移
.equ SCI_SMR, 0x00
.equ SCI_BRR, 0x01       
.equ SCI_SCR, 0x02          
.equ SCI_TDR, 0x03         
.equ SCI_SSR, 0x04         
.equ SCI_RDR, 0x05
.equ SCI_SCMR, 0x06
.equ SCI_SEMR, 0x07
.equ SCI_SNFR, 0x08
.equ SCI_SECR, 0x0D
.equ SCI_TDRH, 0x0E
.equ SCI_TDRL, 0x0F
.equ SCI_TDRHL, 0x0E
.equ SCI_RDRH, 0x10
.equ SCI_RDRL, 0x11
.equ SCI_RDRHL, 0x10


_start:
    # 加载 UART 基地址到 x0 寄存器
    ldr x0, =SCI_BASE
    # ldr x1, [x0]           // 从 x0 指向的内存地址加载 64 位的数据到 x1
    ldrh w1, [x0, #SCI_SCR]          // 从 x0 指向的内存地址加载 16 位的数据到 w1
    
    # 在 w2 中存放置位 mask, 1 位置代表想要置 0 的位
    mov w2, #0xF4
    # 取其反码
    mvn w2, w2
    # 进行与操作
    and w1, w1, w2
    # 写入 SCR
    strh w1, [x0, #SCI_SCR]
    
    # 验证全 0 pass
    
    # 无限循环
    b .
