#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include <string>

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

typedef struct {
	std::uint8_t opcode;
#ifdef DEBUG
	std::string name;
#endif
} INSTRUCTION_T;

INSTRUCTION_T instructions[256] = {
	{.opcode = 0x00, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-e cycles
#ifdef DEBUG
		, .name = "Breakpoint"
#endif
	}, //BRK software interrupt (8-e cycles) (Implied addressing)
	{.opcode = 0x01, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w cycles
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Direct addressing, X)"
#endif
	}, //ORA Bitwise OR accumulator (ORA ($10, X))
	{.opcode = 0x02, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 // 8-e cycles
#ifdef DEBUG
		, .name = "Coprocessor Interrupt"
#endif
	}, //COP software interrupt (8-e cycles) (Implied)
	{.opcode = 0x03, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m cycles
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (stack, S)"
#endif
	}, //ORA Bitwise OR with Accumulator (ORA $32, S) (Stack relative)
	{.opcode = 0x04, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-2*m+w
#ifdef DEBUG
		, .name = "Test and Set Bits (Direct addressing)"
#endif
	}, //TSB test and reset bits of the data with the bits of the accumulator TSB ($10) (Direct addressing)
	{.opcode = 0x05, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4-m+w
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Direct addressing)"
#endif
	}, //ORA Bitwise OR with Accumulator (ORA $10) (Direct addressing)
	{.opcode = 0x06, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-2*m+w
#ifdef DEBUG
		, .name = "Arithmetic Shift Left (Direct addressing)"
#endif
	}, //Arithmetic Shift Left (ASL $10) (Direct addresssing)
	{.opcode = 0x07, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator [Direct]"
#endif
	}, //Bitwise OR with Accumulator (ORA [$10]) ([Direct])
	{.opcode = 0x08, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 3 //3
#ifdef DEBUG
		, .name = "Push Processor Status Register to stack (Implied)"
#endif
	}, //Push processor status register (P) to the stack (PHP) (Implied)
	{.opcode = 0x09, .bytes = 3, .bytes_adj_m = true, .bytes_adj_x = false, .cycles = 3 //3-m
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Immediate)"
#endif
	}, //ORA Bitwise OR with Accumulator (ORA #$54) (Immediate)
	{.opcode = 0x0A, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Arithmetic Shift Left (Accumulator)"
#endif
	}, //Arithmetic Shift Left (ASL) (Accumulator)
	{.opcode = 0x0B, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4
#ifdef DEBUG
		, .name = "Push Direct Page register (Implied)"
#endif
	}, //Push Direct Page register (PHD) (Implied)
	{.opcode = 0x0C, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m
#ifdef DEBUG
		, .name = "Test and Set Bit (Absolute)"
#endif
	}, //Test and Set Bit (TSB $9876) (Absolute)
	{.opcode = 0x0D, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Absolute)"
#endif
	}, //Bitwise OR with Accumulator (ORA $9876) (Absolute)
	{.opcode = 0x0E, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m
#ifdef DEBUG
		, .name = "Arithmetic Shift Left (Absolute)"
#endif
	}, //Arithmetic Shift Left (ASL $9876) (Absolute)
	{.opcode = 0x0F, .bytes = 4, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (long)"
#endif
	}, //Bitwise OR with Accumulator (ORA $FEDBCA) (long)
	{.opcode = 0x10, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2+t+t*e*p
#ifdef DEBUG
		, .name = "Branch if Plus (Relative 8)"
#endif
	}, //Branch if Plus (BPL LABEL) (Relative 8) can branch to -127 or 128 from the address after the branch instruction (typically -126 to 129 bytes from address of branch instruction)
	{.opcode = 0x11, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w-x+x*p
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator ((Direct),Y)"
#endif
	}, //Bitwise OR with Accumulator (ORA ($10),Y) ((Direct),Y)
	{.opcode = 0x12, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m+w
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator ((Direct))"
#endif
	}, //Bitwise OR with Accumulator (ORA ($10)) ((Direct))
	{.opcode = 0x13, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-m
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator ((Stack,S),Y)"
#endif
	}, //Bitwise OR with Accumulator (ORA ($32,S),Y) ((Stack, S),Y)
	{.opcode = 0x14, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-2*m+w
#ifdef DEBUG
		, .name = "Test and Reset Bits (Direct)"
#endif
	}, //Test and Reset Bits (TRB $10) (Direct)
	{.opcode = 0x15, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Direct, X)"
#endif
	}, //Bitwise OR with Accumulator (ORA $10,X) (Direct, X)
	{.opcode = 0x16, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m+w
#ifdef DEBUG
		, .name = "Arithmetic Shift Left (Direct, X)"
#endif
	}, //Arithmetic Shift Left (ASL $10,X) (Direct, X)
	{.opcode = 0x17, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator ([Direct], Y)"
#endif
	}, //Bitwise OR with Accumulator (ORA [$10],Y) ([Direct], Y)
	{.opcode = 0x18, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Clear Carry (Implied)"
#endif
	}, //Clear Carry (CLC) (Implied)
	{.opcode = 0x19, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m-x+x*p
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Absolute, Y)"
#endif
	}, //Bitwise OR with Accumulator (ORA $9876,Y) (Absolute, Y)
	{.opcode = 0x1A, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Increment (Accumulator)"
#endif
	}, //Increment (INC) (Accumulator)
	{.opcode = 0x1B, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Transfer C accumulator (full 16-bit accumulator) to the Stack pointer (Implied)"
#endif
	}, //Transfer C accumulator (full 16-bit accumulator) to the Stack pointer (TCS) (Implied)
	{.opcode = 0x1C, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m
#ifdef DEBUG
		, .name = "Test and Reset Bits (Absolute)"
#endif
	}, //Test and Reset Bits (TRB $9876) (Absolute)
	{.opcode = 0x1D, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m-x+x*p
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Absolute, X)"
#endif
	}, //Bitwise OR with Accumulator (ORA $9876,X) (Absolute, X)
	{.opcode = 0x1E, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 9 //9-2*m
#ifdef DEBUG
		, .name = "Arithmetic Shift Left (Absolute, X)"
#endif
	}, //Arithmetic Shift Left (ASL $9876,X) (Absolute, X)
	{.opcode = 0x1F, .bytes = 4, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m
#ifdef DEBUG
		, .name = "Bitwise OR with Accumulator (Long, X)"
#endif
	}, //Bitwise OR with Accumulator (ORA $FEDCBA,X) (Long, X)
	{.opcode = 0x20, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6
#ifdef DEBUG
		, .name = "Jump to Subroutine (Absolute)"
#endif
	}, //Jump to Subroutine (JSR $1234) (Absolute)
	{.opcode = 0x21, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ((Direct, X))"
#endif
	}, //Bitwise AND with Accumulator (AND ($10,X)) ((Direct, X))
	{.opcode = 0x22, .bytes = 4, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8
#ifdef DEBUG
		, .name = "Jump Subroutine Long (Long)"
#endif
	}, //Jump Subroutine Long (JSL $123456) (Long)
	{.opcode = 0x23, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Stack, S)"
#endif
	}, //Bitwise AND with Accumulator (AND $32,S) (Stack, S)
	{.opcode = 0x24, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4-m+w
#ifdef DEBUG
		, .name = "BIT test (Direct)"
#endif
	}, //BIT test the bits of the data with the accumulator (BIT $10) (Direct)
	{.opcode = 0x25, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Direct)"
#endif
	}, //Bitwise AND with Accumulator (AND $10) (Direct)
	{.opcode = 0x26, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-2*m+w
#ifdef DEBUG
		, .name = "Rotate Left (Direct)"
#endif
	}, //Rotate Left (ROL $10) (Direct)
	{.opcode = 0x27, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ([Direct])"
#endif
	}, //Bitwise AND with Accumulator (AND [$10]) ([Direct])
	{.opcode = 0x28, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4
#ifdef DEBUG
		, .name = "Pull Processor Status Register (Implied)"
#endif
	}, //Pull Processor Status Register (PLP) (Implied)
	{.opcode = 0x29, .bytes = 3, .bytes_adj_m = true, .bytes_adj_x = false, .cycles = 3 //3-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Immediate)"
#endif
	}, //Bitwise AND with Accumulator #$54 (Immediate)
	{.opcode = 0x2A, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Rotate Left (Accumulator)"
#endif
	}, //Rotate Left (ROL) (Accumulator)
	{.opcode = 0x2B, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Pull Direct Page register from stack (Implied)"
#endif
	}, //Pull Direct Page register from stack (PLD) (Implied)
	{.opcode = 0x2C, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m
#ifdef DEBUG
		, .name = "Test BITS (Absolute)"
#endif
	}, //Test BITS (BIT $9876) (Absolute)
	{.opcode = 0x2D, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Absolute)"
#endif
	}, //Bitwise AND with Accumulator (AND $9876) (Absolute)
	{.opcode = 0x2E, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m
#ifdef DEBUG
		, .name = "Rotate Left (Absolute)"
#endif
	}, //Rotate Left (ROL $9876) (Absolute)
	{.opcode = 0x2F, .bytes = 4, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Long)"
#endif
	}, //Bitwise AND with Accumulator (AND $FEDBCA) (Long)
	{.opcode = 0x30, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2+t+t*e*p
#ifdef DEBUG
		, .name = "Branch if Minus (Relative 8)"
#endif
	}, //Branch if Minus (BMI LABEL) (Relative 8)
	{.opcode = 0x31, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w-x+x*p
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ((Direct), Y)"
#endif
	}, //Bitwise AND with Accumulator (AND ($10),Y) ((Direct), Y)
	{.opcode = 0x32, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ((Direct))"
#endif
	}, //Bitwise AND with Accumulator (AND ($10)) ((Direct))
	{.opcode = 0x33, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ((Stack,S),Y)"
#endif
	}, //Bitwise AND with Accumulator (AND ($32,S),Y) ((Stack,S),Y)
	{.opcode = 0x34, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m+w
#ifdef DEBUG
		, .name = "Test BIT (Direct,X)"
#endif
	}, //Test BIT (BIT $10,X) (Direct,X)
	{.opcode = 0x35, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Direct,X)"
#endif
	}, //Bitwise AND with Accumulator (AND $10,X) (Direct,X)
	{.opcode = 0x36, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 8 //8-2*m+w
#ifdef DEBUG
		, .name = "Rotate Left (Direct X)"
#endif
	}, //Rotate Left (ROL $10,X) (Direct X)
	{.opcode = 0x37, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator ([Direct], Y)"
#endif
	}, //Bitwise AND with Accumulator (AND [$10],Y) ([Direct], Y)
	{.opcode = 0x38, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Set Carry (Implied)"
#endif
	}, //Set Carry (SEC) (Implied)
	{.opcode = 0x39, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m-x+x*p
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Absolute, Y)"
#endif
	}, //Bitwise AND with Accumulator (AND $9876,Y) (Absolute, Y)
	{.opcode = 0x3A, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Decrement (Accumulator)"
#endif
	}, //Decrement (DEC) (Accumulator)
	{.opcode = 0x3B, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "Transfer Stack Pointer to C accumulator (Implied)"
#endif
	}, //Transfer Stack Pointer to C accumulator (TSC) (Implied)
	{.opcode = 0x3C, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m-x+x*p
#ifdef DEBUG
		, .name = "Test BITs (Absolute, X)"
#endif
	}, //Test BITs (BIT $9876,X) (Absolute,X)
	{.opcode = 0x3D, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m-x+x*p
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Absolute, X)"
#endif
	}, //Bitwise AND with Accumulator (AND $9876,X) (Absolute,X)
	{.opcode = 0x3E, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 9 //9-2*m
#ifdef DEBUG
		, .name = "Rotate Left (Absolute, X)"
#endif
	}, //Rotate Left (ROL $9876,X) (Absolute,X)
	{.opcode = 0x3F, .bytes = 4, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 6 //6-m
#ifdef DEBUG
		, .name = "Bitwise AND with Accumulator (Long, X)"
#endif
	}, //Bitwise AND with Accumulator (AND $FEDCBA,X) (Long,X)
	{.opcode = 0x40, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-e
#ifdef DEBUG
		, .name = "Return from interrupt (Implied)"
#endif
	}, //Return from interrupt (RTI) (Implied)
	{.opcode = 0x41, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Exclusive OR with Accumulator (Direct, X)"
#endif
	}, //Exclusive OR with Accumulator (EOR ($10,X)) (Direct, X)
	{.opcode = 0x42, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 2 //2
#ifdef DEBUG
		, .name = "William D. Mensch, Jr (Implied)"
#endif
	}, //2 cycle NOP (WDM) (Immediate)
	{.opcode = 0x43, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 5 //5-m
#ifdef DEBUG
		, .name = "Exclusive OR with Accumulator (Stack, S)"
#endif
	}, //Exclusive OR with Accumulator (EOR ($32,S)) (Stack, S)
	{.opcode = 0x44, .bytes = 3, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7
#ifdef DEBUG
		, .name = "Move Memory Positive (src, dest)"
#endif
	}, //Move memory (MVP #$12,#$34) (src,dest)
	{.opcode = 0x45, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4-m+w
#ifdef DEBUG
		, .name = "Exclusive OR with Accumulator (Direct)"
#endif
	}, //Exclusive OR with Accumulator (EOR $10) (Direct)
	{.opcode = 0x46, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-2*m+w
#ifdef DEBUG
		, .name = "Logical Shift Right (Direct)"
#endif
	}, //Logical Shift Right (LSR $10) (Direct)
	{.opcode = 0x47, .bytes = 2, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 7 //7-m+w
#ifdef DEBUG
		, .name = "Exclusive OR with Accumulator ([Direct])"
#endif
	}, //Exclusive OR with Accumulator (EOR [$10]) ([Direct])
	{.opcode = 0x48, .bytes = 1, .bytes_adj_m = false, .bytes_adj_x = false, .cycles = 4 //4-m
#ifdef DEBUG
		, .name = "Exclusive OR with Accumulator ([Direct])"
#endif
	}, //Exclusive OR with Accumulator (EOR [$10]) ([Direct])
	
	
};




#endif