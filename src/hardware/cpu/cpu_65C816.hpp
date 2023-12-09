#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include <string>

#include <mem.hpp>

struct CPU_65C816_Accumulator_substructure {
	std::uint8_t A;
	std::uint8_t B;
};

union CPU_65C816_Accumulator{
	struct CPU_65C816_Accumulator_substructure bytes;
	std::uint16_t val;
};

typedef enum {
	BREAK,
	CARRY,
	DECIMAL_MODE,
	EMULATION_MODE,
	INTERRUPT_DISABLE,
	ACCUMULATOR_MEMORY_WIDTH,
	NEGATIVE,
	OVERFLOW,
	INDEX_REG_WIDTH,
	ZERO
} PROCESSOR_STATUS_FLAG_T;

typedef struct {
	unsigned char n: 1; //Associated with the negative flag
	unsigned char v: 1; //Associated with the overflow flag
	unsigned char m: 1; //Associated with the accumulator and memory width flag (Native mode only) (16 bits when flag is 0, 8 bits when flag is set)
	unsigned char x_b: 1; //X: Index register width, B: Break flag (X in native mode, B in emulation mode)
	unsigned char d: 1; //Associated with decimal mode
	unsigned char i: 1; //Associated with the interrupt disable flag
	unsigned char z: 1; //Associated with the zero flag
	unsigned char c: 1; //Associated with the carry flag
} PROCESSOR_STATUS_REGISTER_T;

class CPU_65C816 {
private:
	//Registers (http://www.6502.org/tutorials/65c816opcodes.html#4)
	union CPU_65C816_Accumulator A; //The accumulator. This is the math register. It stores one of two operands or the result of most arithmetic and logical operations.
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

public:
	void step(void);
	void attach_memory(MEM mem);
};

typedef struct {
	std::uint8_t opcode;
	void (CPU_65C816::*impl)(void);
#ifdef DEBUG
	std::string name;
	std::string mnemonic;
#endif
} INSTRUCTION_T;



#endif