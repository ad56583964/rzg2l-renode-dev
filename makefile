# Makefile for compiling and linking an ARM assembly file into a binary

ASFLAGS := -mcpu=cortex-a55
OBJCOPYFLAGS := -O binary

OUTPUT_DIR := output
SOURCE_FILE := main.S
OBJECT_FILE := $(OUTPUT_DIR)/main.o
ELF_FILE := $(OUTPUT_DIR)/main.elf
BIN_FILE := $(OUTPUT_DIR)/main.bin

all: $(BIN_FILE)

$(BIN_FILE): $(ELF_FILE)
	aarch64-linux-gnu-objcopy $(OBJCOPYFLAGS) $< $@

$(ELF_FILE): $(OBJECT_FILE)
	aarch64-linux-gnu-ld $(LDFLAGS) -o $@ $<

$(OBJECT_FILE): $(SOURCE_FILE)
	aarch64-linux-gnu-as $(ASFLAGS) -o $@ $<

clean:
	rm -f $(OBJECT_FILE) $(ELF_FILE) $(BIN_FILE)

gdb:
	gdb-multiarch -x cmd.gdb

qemu:
	qemu-system-aarch64 -M virt -cpu cortex-a53 -kernel output/main.bin -nographic -s -S

renode:
	cd ${CURDIR}/renode && \
	renode -e "s @./demo.resc"

.PHONY: all clean gdb renode