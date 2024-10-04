
#define SCI_BASE    0x1004b800U
#define SCI_SCR     0x04
#define SCI_SCR_CKE     0b00000001
#define SCI_SCR_TEIE    0b00000010
#define SCI_SCR_REIE    0b00000100
#define SCI_SCR_RE      0b00001000
#define SCI_SCR_TE      0b00010000
#define SCI_SCR_RIE     0b00100000
#define SCI_SCR_TIE     0b01000000

#define uint8_t unsigned char
#define uint64_t long long unsigned

typedef volatile uint8_t io_reg_t;

int main(){
    io_reg_t *SCR = (io_reg_t*)(SCI_BASE | SCI_SCR);
    /* init SCR */
    *SCR = (io_reg_t)0b00;

    // 清除 RE 和 TE 位，保持其他位不变
    // *SCR &= ~(SCI_SCR_RE | SCI_SCR_TE);



    return 0;
}
