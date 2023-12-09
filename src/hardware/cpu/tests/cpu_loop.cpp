#include <iostream>
#include <cstdint>

#include <cpu_65C816.hpp>
#include <snes_mem.hpp>

const uint8_t loop_program[] = {
	0x18, //CLC
	0xFB, //XCE
	0xC2, 0x30, //REP #$30
	0xA9, 0xFF, 0xFF, //LDA #$FFFF
	0xC9, 0x00, 0x00, //CMP #$0000
	0xD0, 0x03, //BNE #$03
	0x3A, //DEC
	0x80, 0xF8, //BRA #$F8
	0xD8, //STP
};

int main(int argc, char **argv) {
	CPU_65C816 cpu = CPU_65C816();
	SNES_MEM mem = SNES_MEM();

	cpu.attach_memory(mem);

	std::cout << "Hello world! testing testing!\n";

	return 0;
}