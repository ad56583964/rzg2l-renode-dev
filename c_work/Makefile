CC=aarch64-linux-gnu-gcc

all: main.o startup.o main.bin main.elf

test:
	$(CC) -Wall -nostdlib -lgcc -c  main.c -o build/main.o -l

check:
	aarch64-linux-gnu-objdump -h build/main.o 

main.o: main.c
	aarch64-linux-gnu-gcc -g -ffreestanding -nostdlib -c -o build/main.o main.c

main.bin: main.o startup.o
	aarch64-linux-gnu-ld -T linker.ld -o build/main.bin build/main.o build/startup.o

main.elf: main.o startup.o
	aarch64-linux-gnu-ld -T linker.ld -o build/main.elf build/main.o build/startup.o

startup.o: startup.S
	aarch64-linux-gnu-gcc -g -ffreestanding -nostdlib -c -o build/startup.o startup.S
# main.elf: main.c
# 	$(CC) -g -ffreestanding -o build/main.elf main.c

disasm: main.bin
	aarch64-linux-gnu-objdump -d build/main.elf > build/disassembly.txt

clean:
	rm build/*

read-main:
	aarch64-linux-gnu-objdump -d -S build/main.elf > build/main_disasm.txt
	aarch64-linux-gnu-readelf -a build/main.elf > build/readelf.txt
	aarch64-linux-gnu-nm build/main.elf > build/nm.txt