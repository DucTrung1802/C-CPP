CC=arm-none-eabi-gcc
MACHINE=cortex-m4
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACHINE) -mthumb -mfloat-abi=soft --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map


SRC_FILES=$(wildcard *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)


all:$(OBJ_FILES) final.elf

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf

load:
	openocd -f board/stm32f4discovery.cfg

