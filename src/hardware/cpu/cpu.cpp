#include <cstdint>

#include <cpu.hpp>

class CPU {
private:
	//Registers (http://www.6502.org/tutorials/65c816opcodes.html#4)
	std::uint16_t A; //The accumulator. This is the math register. It stores one of two operands or the result of most arithmetic and logical operations.
	std::uint8_t DB; //Data bank register, holds the default bank for memory transfers (DBR / DB)
	std::uint16_t D; //Direct page register, used for direct page addressing modes. Holds the memory bank address of the data the CPU is accessing. (D/DP)
	std::uint8_t B; //Program Bank, holds the bank address of all instruction fetches.
	std::uint16_t PC; //Holds the memory address of the current CPU instruction
	std::uint8_t P; //Holds various important flags, results of tests and 65816 processing states. See https://wiki.superfamicom.org/65816-reference.
	std::uint16_t X; //General purpose index register
	std::uint16_t Y; //General purpose index register
	bool emulation_mode; //Used in conjunction with the P register (processor state)
		
	//Current instruction information
	std::uint8_t opcode;
	std::uint8_t instruction[4];
	std::uint8_t remaining_cycles;
	
	void set_emulation(bool emulation) {
	}

	void set_processor_status_flag(PROCESSOR_STATUS_FLAG_T flag) {
		switch(flag) {
                case BREAK:
                case CARRY:
                case DECIMAL_MODE:
                case EMULATION_MODE:
                case INTERRUPT_DISABLE:
                case ACCUMULATOR_MEMORY_WIDTH:
                case NEGATIVE:
                case OVERFLOW:
                case INDEX_REG_WIDTH:
                case ZERO:
                  break;
                }
        }

public:
	void step(void) {
	}
};
