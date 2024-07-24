#include <iostream>
#include <cstdint>

#include <cpu_65C816.hpp>
#include <basic_mem.hpp>

const uint8_t loop_program[] = {
	0x18, //CLC
	0xFB, //XCE
	0xC2, 0x30, //REP #$30
	0xA9, 0xFF, 0xFF, //LDA #$FFFF
	0xC9, 0x00, 0x00, //CMP #$0000
	0xF0, 0x03, //BEQ #$03
	0x3A, //DEC
	0x80, 0xF8, //BRA #$F8
	0xDB, //STP
};

int main(int argc, char **argv) {
	CPU_65C816 cpu = CPU_65C816();
	BASIC_MEM mem = BASIC_MEM();

    //std::getc(stdin);

	cpu.attach_memory(&mem);
    //Load the program into memory
    for(int i = 0; i < sizeof(loop_program); i++) {
        mem.cpu_write(i, (uint8_t *)(loop_program + i));
    }

    while(!cpu.waiting_reset) {
        cpu.step();
    }

	return 0;
}
