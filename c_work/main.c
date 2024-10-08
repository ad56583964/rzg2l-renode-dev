
#define SCI_BASE            0x1004b800U

#define SCI_SMR             0x00U
#define SCI_SMR_CKS_FOO     (io_reg16_t)0b00000011

#define SCI_BRR             0x00U
#define SCI_BRR_REG         (io_reg8_t )0b11111111

#define SCI_SCR             0x04U
#define SCI_SCR_CKE         (io_reg16_t)0b00000001
#define SCI_SCR_CKE_FOO     (io_reg16_t)0b00000011
#define SCI_SCR_TEIE        (io_reg16_t)0b00000100
#define SCI_SCR_REIE        (io_reg16_t)0b00001000
#define SCI_SCR_RE          (io_reg16_t)0b00010000
#define SCI_SCR_TE          (io_reg16_t)0b00100000
#define SCI_SCR_RIE         (io_reg16_t)0b01000000
#define SCI_SCR_TIE         (io_reg16_t)0b10000000

#define SCI_FTDR            0x06U

#define SCI_FSR             0x08U
#define SCI_FSR_TDFE        (io_reg16_t)0b00100000
#define SCI_FSR_TEND        (io_reg16_t)0b01000000

#define SCI_FCR             0x0CU
#define SCI_FCR_LOOP        (io_reg16_t)0b00000001
#define SCI_FCR_RFRST       (io_reg16_t)0b00000010
#define SCI_FCR_TFRST       (io_reg16_t)0b00000100

#define SCI_LSR             0x12U
#define SCI_LSR_ORER        (io_reg16_t)0b00000001

#define SCI_SEMR            0x14U
#define SCI_SEMR_BRME       (io_reg8_t )0b00100000
#define SCI_SEMR_MDDRS      (io_reg8_t )0b00010000

#define SCI_FTCR            0x16U
#define SCI_TFTC_MASK       0x0FU

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint64_t long long unsigned

typedef volatile uint8_t io_reg8_t;
typedef volatile uint16_t io_reg16_t;

#define CPU_FREQUENCY_HZ 1200000000  // 假设 CPU 频率为 2GHz

void delay_50ms() {
    volatile uint64_t count = (CPU_FREQUENCY_HZ / 20); // 计算循环次数
    while (count--) {
        __asm__ volatile("nop"); // 使用 NOP 指令进行延迟
    }
}

int is_tdfe_set(io_reg16_t *reg) {
    return (*reg & SCI_FSR_TDFE) != 0;
}

int is_tend_set(io_reg16_t *reg) {
    return (*reg & SCI_FSR_TEND) != 0;
}

int main(){
    io_reg16_t *SCR = (io_reg16_t*)(SCI_BASE | SCI_SCR);
    io_reg16_t *FSR =  (io_reg16_t*)(SCI_BASE | SCI_FSR);
    io_reg8_t *FTDR =  (io_reg8_t*)(SCI_BASE | SCI_FTDR);
    // /* init SCR */
    // *SCR = (io_reg16_t)0x0000U;

    // /* 清除 RE 和 TE 位，保持其他位不变 */
    // *SCR &= ~(SCI_SCR_RE | SCI_SCR_TE);

    // /* set FCR.TFRST and RFRST bits to 1 */
    // io_reg16_t *FCR = (io_reg16_t*)(SCI_BASE | SCI_FCR);
    // *FCR |= (SCI_FCR_RFRST | SCI_FCR_TFRST);

    // /* Read status flags of FSR register and LSR.ORER flag. THen set these flags to 0 */

    // io_reg16_t *LSR =  (io_reg16_t*)(SCI_BASE | SCI_LSR);
    // // 读取 LSR 寄存器的值
    // io_reg16_t lsrValue = *LSR;

    // // 提取 ORER 位
    // io_reg16_t orerBit = lsrValue & SCI_LSR_ORER;

    // // SCR set TIE RIE TE RE bits to 0
    // *SCR &= ~(SCI_SCR_TIE | SCI_SCR_RIE | SCI_SCR_TE | SCI_SCR_RE);
    // // set CKE
    // *SCR &= ~SCI_SCR_CKE_FOO;

    // //set SMR, 写一半吧，摆烂了
    // io_reg16_t *SMR =  (io_reg16_t*)(SCI_BASE | SCI_SMR);
    // *SMR &= ~(SCI_SMR_CKS_FOO);

    // //set SEMR.MDDRS to 0
    // io_reg8_t *SEMR =  (io_reg8_t*)(SCI_BASE | SCI_SEMR);
    // *SEMR &= ~SCI_SEMR_MDDRS;

    // //set 115200 BRR N=26
    // io_reg8_t *BRR =  (io_reg8_t*)(SCI_BASE | SCI_BRR);
    // *BRR = 26;

    // //set SEMR to 1
    // *SEMR |= (SCI_SEMR_BRME | SCI_SEMR_MDDRS);

    // //wait 50ms
    // delay_50ms();

    // //set MDDR 不管了，懒得设

    // //set FTCR
    // io_reg16_t *FTCR =  (io_reg16_t*)(SCI_BASE | SCI_FTCR);
    // // 置位
    // *FTCR = (*FTCR & ~SCI_TFTC_MASK) | (0b1111 & SCI_TFTC_MASK);

    // set SCR_TE RE to 1
    *SCR |= (SCI_SCR_TE | SCI_SCR_RE);

    // transmit start
    while(!is_tdfe_set(FSR));

    *FTDR = 'A';
    // *FTDR = 'a';
    // *FTDR = 'A';

    // // set SCR_TIE to 0
    // *SCR &= ~SCI_SCR_TIE;
    // // set SCR_TEIE to 1
    // *SCR |= SCI_SCR_TEIE;

    // wait TEND flag = 1
    while(!is_tdfe_set(FSR));

    // set SCR_TE to 0
    *SCR &= ~SCI_SCR_TE;

    return 0;
}
