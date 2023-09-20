#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct Packet {
	uint8_t crc;			// 2 bit	LSB
	uint8_t status;			// 1 bit
	uint16_t payload;		// 12 bit
	uint8_t bat;			// 3 bit
	uint8_t sensor;			// 3 bit
	uint8_t long_addr;		// 8 bit
	uint8_t short_addr;		// 2 bit
	uint8_t addr_mode;		// 1 bit	MSB
};

void bin(unsigned n);
void print_packet(struct Packet input_packet);

int main() {
	uint32_t hex_code;
	struct Packet data_packet;

	printf("Input hex code: ");
	scanf("%X", &hex_code);

	printf("Input in hex: \t\t%X\n", hex_code);
	printf("Input in binary: \t");
	bin(hex_code);

	data_packet.crc = (hex_code >> 0) & 0x03;
	data_packet.status = (hex_code >> 2) & 0x01;
	data_packet.payload = (hex_code >> 3) & 0x0FFF;
	data_packet.bat = (hex_code >> 15) & 0x07;
	data_packet.sensor = (hex_code >> 18) & 0x07;
	data_packet.long_addr = (hex_code >> 21) & 0xFF;
	data_packet.short_addr = (hex_code >> 29) & 0x03;
	data_packet.addr_mode = (hex_code >> 31) & 0x01;

	print_packet(data_packet);

	printf("Press any key to continue...");
	fflush(stdin);
	getchar();
	return 0;
}

void bin(uint32_t n) {
	uint32_t i;
	for (i = 1 << 31; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}

void print_packet(struct Packet input_packet) {
	printf("crc:\t\t\t");
	bin(input_packet.crc);
	printf("status:\t\t\t");
	bin(input_packet.status);
	printf("payload:\t\t");
	bin(input_packet.payload);
	printf("bat:\t\t\t");
	bin(input_packet.bat);
	printf("sensor:\t\t\t");
	bin(input_packet.sensor);
	printf("long_addr:\t\t");
	bin(input_packet.long_addr);
	printf("short_addr:\t\t");
	bin(input_packet.short_addr);
	printf("addr_mode:\t\t");
	bin(input_packet.addr_mode);
}
