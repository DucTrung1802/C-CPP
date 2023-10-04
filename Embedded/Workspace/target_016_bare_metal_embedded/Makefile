CC=arm-none-eabi-gcc
MACHINE=cortex-m4
CFLAGS= -c -mcpu=$(MACHINE) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

all:main.o onboard_leds.o stm32_startup.o final.elf

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

onboard_leds.o: onboard_leds.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_startup.o: stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o onboard_leds.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o *.elf

load:
	openocd -f board/stm32f4discovery.cfg