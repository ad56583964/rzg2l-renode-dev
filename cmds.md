sudo apt install binutils-arm-none-eabi

arm-none-eabi-as -o main.o main.S;
arm-none-eabi-ld -Ttext 0x48080000 -o main.elf main.o;
arm-none-eabi-objcopy -O binary main.elf main.bin;
rm output/main.bin;
cp main.bin output/main.bin

- 如何查看 uboot 内存映射的合法地址？

binfo

setenv serverip 192.168.0.174

md 0x48080000

tftp 0x48080000 main.elf
tftp 0x48080000 main.bin

go 0x48080000

查看 armv8a

uboot 手册 和 源码？

tftpd-hpa

/etc/xinetd.d/tftp

/etc/init/tftpd-hpa.conf

/etc/default/tftpd-hpa

sudo systemctl restart tftpd-hpa