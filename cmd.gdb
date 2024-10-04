set architecture aarch64
target remote localhost:1234

symbol-file ./c_work/build/main.elf

dashboard registers
dashboard assembly