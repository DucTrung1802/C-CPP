CC=arm-none-eabi-gcc
MACHINE=cortex-m4
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

SRC_FILES=$(wildcard *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)

all: final.elf

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

final.elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf
