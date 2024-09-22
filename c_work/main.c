
#define SCI_BASE    0x1004b800U
#define SCI_SCR     0x04
#define SCI_TEST     0x04

#define uint8_t unsigned char
#define uint64_t long long unsigned

int main(){
    uint8_t *SCR = (uint8_t*)(SCI_BASE | SCI_SCR);
    *SCR = 0x1;
    return 0;
}
