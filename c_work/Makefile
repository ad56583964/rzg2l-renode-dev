CC=aarch64-linux-gnu-gcc

all: main.o main.bin

test:
	$(CC) -Wall -nostdlib -lgcc -c  main.c -o build/main.o -l

check:
	aarch64-linux-gnu-objdump -h build/main.o 

main.o: main.c
	aarch64-linux-gnu-gcc -g -ffreestanding -nostdlib -c -o build/main.o main.c

main.bin: main.o
	aarch64-linux-gnu-ld -T linker.ld -o build/main.elf build/main.o

# main.elf: main.c
# 	$(CC) -g -ffreestanding -o build/main.elf main.c

disasm: main.bin
	aarch64-linux-gnu-objdump -d build/main.elf > build/disassembly.txt

clean:
	rm build/*

read-main:
	aarch64-linux-gnu-objdump -d -S build/main.o > build/main_disasm.txt
	aarch64-linux-gnu-readelf -a build/main.o > build/readelf.txt
	aarch64-linux-gnu-nm build/main.o > build/nm.txt