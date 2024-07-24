#include <cstdint>
#include <iostream>

#include <mem.hpp>
#include <cpu_65C816.hpp>
#include <cpu_65C816_instruction_set.hpp>

void CPU_65C816::step(void) {
	if(this->remaining_cycles == 0) {
		if(this->waiting_interrupt) {
			//TODO Handle interrupt
			return;
		}

		//Start new instruction
		this->memory->cpu_read(this->PC, &(this->opcode));
		this->PC++;
        INSTRUCTION_T instruction = CPU_65C816_instructions[this->opcode];
        /*std::cout << "PC: " << +(this->PC) << ", Processor status: " << +this->P.n << +this->P.v <<
            +this->P.m << +this->P.x_b << +this->P.d << +this->P.d << +this->P.i << +this->P.z <<
            +this->P.c << std::endl;*/
        //std::cout << "Opcode: " << +(this->opcode) << ", Mnemonic: " << instruction.mnemonic << ", Name: " << instruction.name << std::endl;


        (this->*(instruction.impl))();

	} else {
        this->remaining_cycles--;
    }

	return;
}

void CPU_65C816::attach_memory(MEM *mem) {
	this->memory = mem;
	return;
}

void CPU_65C816::reset() {
	this->A.val =0;
	this->DB = 0;
	this->D = 0;
	this->PB = 0;
	this->X = 0;
	this->Y = 0;

	this->waiting_interrupt = false;

	this->PC = 0xFFFC; //Reset vector https://softpixel.com/~cwright/sianse/docs/65816NFO.HTM#3.15

}
