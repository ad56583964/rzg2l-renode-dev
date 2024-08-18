.global _start

.section .text

.equ SCI_BASE, 0x1004b800

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
    ldrb w1, [x0, #SCI_SCR]          // 从 x0 指向的内存地址加载 16 位的数据到 w1
    
    # 在 w2 中存放置位 mask, 1 位置代表想要置 0 的位
    mov w2, #0xF4
    # 取其反码
    mvn w2, w2
    # 进行与操作
    and w1, w1, w2
    # 写入 SCR
    strb w1, [x0, #SCI_SCR]
    
    # 验证全 0 pass
    
    # 开始 GPIO 操作？
    # 就当已经开了吧

    # set SCR CKE,均使用内部时钟
    ldrb w1, [x0, #SCI_SCR]
    # xxxx xx00
    mov w2, #0x3
    mvn w2, w2
    and w1, w1, w2
    strb w1, [x0, #SCI_SCR]


    ldrb w5, [x0, #SCI_SMR]
    mov w1, #0x00
    strb w1, [x0, #SCI_SMR]


    ldrb w5, [x0, #SCI_SCMR]
    mov w1, #0x72
    strb w1, [x0, #SCI_SCMR]
loop_start:
    # set TE = 1
    # 1xxx xxxx
    mov w2, #0x90
    orr w1, w1, w2
    strb w1, [x0, #SCI_SCR]

    # load TDR
    mov w3, #0x41
    strb w3, [x0, #SCI_TDR]

    # set TE = 1
    # 1xxx xxxx
    mov w2, #0x90
    orr w1, w1, w2
    strb w1, [x0, #SCI_SCR]

    # load TDR
    mov w3, #0x41
    strb w3, [x0, #SCI_TDR]

    b loop_start
