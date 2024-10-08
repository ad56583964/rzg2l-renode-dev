
#include <string.h>
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

int send_str(io_reg8_t* ftdr_addr, char* str, uint16_t len){
    // transmit start
    while(!is_tdfe_set(FSR));

    for(int i = 0; i < len; i++){
        *ftdr_addr = str[i];
    }

    // wait TEND flag = 1
    while(!is_tend_set(FSR));
}

int main(){
    io_reg16_t *SCR = (io_reg16_t*)(SCI_BASE | SCI_SCR);
    io_reg16_t *FSR = (io_reg16_t*)(SCI_BASE | SCI_FSR);
    io_reg8_t *FTDR = (io_reg8_t*)(SCI_BASE | SCI_FTDR);

    // transmit start
    send_str(FTDR,"Hello World",strlen("Hello World"));
    // set SCR_TE to 0
    // *SCR &= ~SCI_SCR_TE;

    return 0;
}
