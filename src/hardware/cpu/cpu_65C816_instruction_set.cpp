#include <array>

#include <cpu_65C816.hpp>

const std::array<INSTRUCTION_T, 256> CPU_65C816_instructions = {{
	{.opcode = 0x0
#ifdef DEBUG
	, .name = "Breakpoint",
	.mnemonic = "BRK"
#endif
	}, //Breakpoint | Implied |  (BRK) Length: (1) Cycles: (8-e)
	{.opcode = 0x1
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct Indexed Indirect (dir,X) |  (ORA ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x2
#ifdef DEBUG
	, .name = "CoProcessor",
	.mnemonic = "COP"
#endif
	}, //CoProcessor | Immediate |  (COP #$12) Length: (2) Cycles: (8-e)
	{.opcode = 0x3
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Stack,S |  (ORA $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0x4
#ifdef DEBUG
	, .name = "Test and Set Bits",
	.mnemonic = "TSB"
#endif
	}, //Test and Set Bits | Direct |  (TSB $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x5
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct |  (ORA $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x6
#ifdef DEBUG
	, .name = "Arithmetic Shift Left",
	.mnemonic = "ASL"
#endif
	}, //Arithmetic Shift Left | Direct |  (ASL $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x7
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct Indirect Long |  (ORA [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x8
#ifdef DEBUG
	, .name = "Push Processor Status Register",
	.mnemonic = "PHP"
#endif
	}, //Push Processor Status Register | Implied |  (PHP) Length: (1) Cycles: (3)
	{.opcode = 0x9
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Immediate |  (ORA #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0xa
#ifdef DEBUG
	, .name = "Arithmetic Shift Left",
	.mnemonic = "ASL"
#endif
	}, //Arithmetic Shift Left | Accumulator |  (ASL) Length: (1) Cycles: (2)
	{.opcode = 0xb
#ifdef DEBUG
	, .name = "Push Direct Register",
	.mnemonic = "PHD"
#endif
	}, //Push Direct Register | Implied |  (PHD) Length: (1) Cycles: (4)
	{.opcode = 0xc
#ifdef DEBUG
	, .name = "Test and Set Bits",
	.mnemonic = "TSB"
#endif
	}, //Test and Set Bits | Absolute |  (TSB $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0xd
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Absolute |  (ORA $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0xe
#ifdef DEBUG
	, .name = "Arithmetic Shift Left",
	.mnemonic = "ASL"
#endif
	}, //Arithmetic Shift Left | Absolute |  (ASL $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0xf
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Long |  (ORA $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0x10
#ifdef DEBUG
	, .name = "Branch if Plus",
	.mnemonic = "BPL"
#endif
	}, //Branch if Plus | Relative 8-bit |  (BPL LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0x11
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct indirect indexed Y |  (ORA ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0x12
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct Indirect |  (ORA ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0x13
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | (Stack,S) Indirect Indexed Y |  (ORA ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0x14
#ifdef DEBUG
	, .name = "Test and Reset Bits",
	.mnemonic = "TRB"
#endif
	}, //Test and Reset Bits | Direct |  (TRB $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x15
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct indexed X |  (ORA $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x16
#ifdef DEBUG
	, .name = "Arithmetic Shift Left",
	.mnemonic = "ASL"
#endif
	}, //Arithmetic Shift Left | Direct indexed X |  (ASL $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0x17
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Direct indirect indexed long Y |  (ORA [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x18
#ifdef DEBUG
	, .name = "Clear Carry",
	.mnemonic = "CLC"
#endif
	}, //Clear Carry | Implied |  (CLC) Length: (1) Cycles: (2)
	{.opcode = 0x19
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Absolute indexed Y |  (ORA $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x1a
#ifdef DEBUG
	, .name = "Increment accumulator",
	.mnemonic = "INC"
#endif
	}, //Increment accumulator | Accumulator |  (INC) Length: (1) Cycles: (2)
	{.opcode = 0x1b
#ifdef DEBUG
	, .name = "Transfer C Accumulator to Stack Pointer",
	.mnemonic = "TCS"
#endif
	}, //Transfer C Accumulator to Stack Pointer | Implied |  (TCS) Length: (1) Cycles: (2)
	{.opcode = 0x1c
#ifdef DEBUG
	, .name = "Test and Reset Bits",
	.mnemonic = "TRB"
#endif
	}, //Test and Reset Bits | Absolute |  (TRB $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0x1d
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Absolute indexed X |  (ORA $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x1e
#ifdef DEBUG
	, .name = "Arithmetic Shift Left",
	.mnemonic = "ASL"
#endif
	}, //Arithmetic Shift Left | Absolute indexed X |  (ASL $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0x1f
#ifdef DEBUG
	, .name = "Bitwise OR with accumulator",
	.mnemonic = "ORA"
#endif
	}, //Bitwise OR with accumulator | Long indexed X |  (ORA $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0x20
#ifdef DEBUG
	, .name = "Jump to Subroutine",
	.mnemonic = "JSR"
#endif
	}, //Jump to Subroutine | Absolute |  (JSR $1234) Length: (3) Cycles: (6)
	{.opcode = 0x21
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct Indexed Indirect (dir,X) |  (AND ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x22
#ifdef DEBUG
	, .name = "Jump to Subroutine Long",
	.mnemonic = "JSL"
#endif
	}, //Jump to Subroutine Long | Long |  (JSL $123456) Length: (4) Cycles: (8)
	{.opcode = 0x23
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Stack,S |  (AND $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0x24
#ifdef DEBUG
	, .name = "Test BITs",
	.mnemonic = "BIT"
#endif
	}, //Test BITs | Direct |  (BIT $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x25
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct |  (AND $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x26
#ifdef DEBUG
	, .name = "Rotate Left",
	.mnemonic = "ROL"
#endif
	}, //Rotate Left | Direct |  (ROL $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x27
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct Indirect Long |  (AND [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x28
#ifdef DEBUG
	, .name = "Pull Processor Status Register",
	.mnemonic = "PLP"
#endif
	}, //Pull Processor Status Register | Implied |  (PLP) Length: (1) Cycles: (4)
	{.opcode = 0x29
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Immediate |  (AND #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0x2a
#ifdef DEBUG
	, .name = "Rotate Left",
	.mnemonic = "ROL"
#endif
	}, //Rotate Left | Accumulator |  (ROL) Length: (1) Cycles: (2)
	{.opcode = 0x2b
#ifdef DEBUG
	, .name = "Pull Direct Register",
	.mnemonic = "PLD"
#endif
	}, //Pull Direct Register | Implied |  (PLD) Length: (1) Cycles: (5)
	{.opcode = 0x2c
#ifdef DEBUG
	, .name = "Test BITs",
	.mnemonic = "BIT"
#endif
	}, //Test BITs | Absolute |  (BIT $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x2d
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Absolute |  (AND $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x2e
#ifdef DEBUG
	, .name = "Rotate Left",
	.mnemonic = "ROL"
#endif
	}, //Rotate Left | Absolute |  (ROL $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0x2f
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Long |  (AND $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0x30
#ifdef DEBUG
	, .name = "Branch if Minus",
	.mnemonic = "BMI"
#endif
	}, //Branch if Minus | Relative 8-bit |  (BMI LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0x31
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct indirect indexed Y |  (AND ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0x32
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct Indirect |  (AND ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0x33
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | (Stack,S) Indirect Indexed Y |  (AND ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0x34
#ifdef DEBUG
	, .name = "Test BITs",
	.mnemonic = "BIT"
#endif
	}, //Test BITs | Direct indexed X |  (BIT $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x35
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct indexed X |  (AND $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x36
#ifdef DEBUG
	, .name = "Rotate Left",
	.mnemonic = "ROL"
#endif
	}, //Rotate Left | Direct indexed X |  (ROL $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0x37
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Direct indirect indexed long Y |  (AND [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x38
#ifdef DEBUG
	, .name = "Set Carry",
	.mnemonic = "SEC"
#endif
	}, //Set Carry | Implied |  (SEC) Length: (1) Cycles: (2)
	{.opcode = 0x39
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Absolute indexed Y |  (AND $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x3a
#ifdef DEBUG
	, .name = "Decrement accumulator",
	.mnemonic = "DEC"
#endif
	}, //Decrement accumulator | Accumulator |  (DEC) Length: (1) Cycles: (2)
	{.opcode = 0x3b
#ifdef DEBUG
	, .name = "Transfer Stack Pointer to C Accumulator",
	.mnemonic = "TSC"
#endif
	}, //Transfer Stack Pointer to C Accumulator | Implied |  (TSC) Length: (1) Cycles: (2)
	{.opcode = 0x3c
#ifdef DEBUG
	, .name = "Test BITs",
	.mnemonic = "BIT"
#endif
	}, //Test BITs | Absolute indexed X |  (BIT $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x3d
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Absolute indexed X |  (AND $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x3e
#ifdef DEBUG
	, .name = "Rotate Left",
	.mnemonic = "ROL"
#endif
	}, //Rotate Left | Absolute indexed X |  (ROL $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0x3f
#ifdef DEBUG
	, .name = "Bitwise AND with accumulator",
	.mnemonic = "AND"
#endif
	}, //Bitwise AND with accumulator | Long indexed X |  (AND $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0x40
#ifdef DEBUG
	, .name = "Return from Interrupt",
	.mnemonic = "RTI"
#endif
	}, //Return from Interrupt | Implied |  (RTI) Length: (1) Cycles: (7-e)
	{.opcode = 0x41
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct Indexed Indirect (dir,X) |  (EOR ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x42
#ifdef DEBUG
	, .name = "William D. Mensch, Jr. (2 cycle NOP)",
	.mnemonic = "WDM"
#endif
	}, //William D. Mensch, Jr. (2 cycle NOP) | Immediate |  (WDM) Length: (2) Cycles: (2)
	{.opcode = 0x43
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Stack,S |  (EOR $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0x44
#ifdef DEBUG
	, .name = "Move Memory Positive",
	.mnemonic = "MVP"
#endif
	}, //Move Memory Positive | Source, Destination Block Move |  (MVP #$12,#$34) Length: (3) Cycles: (7)
	{.opcode = 0x45
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct |  (EOR $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x46
#ifdef DEBUG
	, .name = "Logical Shift Right",
	.mnemonic = "LSR"
#endif
	}, //Logical Shift Right | Direct |  (LSR $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x47
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct Indirect Long |  (EOR [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x48
#ifdef DEBUG
	, .name = "Push Accumulator",
	.mnemonic = "PHA"
#endif
	}, //Push Accumulator | Implied |  (PHA) Length: (1) Cycles: (4-m)
	{.opcode = 0x49
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Immediate |  (EOR #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0x4a
#ifdef DEBUG
	, .name = "Logical Shift Right",
	.mnemonic = "LSR"
#endif
	}, //Logical Shift Right | Accumulator |  (LSR) Length: (1) Cycles: (2)
	{.opcode = 0x4b
#ifdef DEBUG
	, .name = "Push K Register",
	.mnemonic = "PHK"
#endif
	}, //Push K Register | Implied |  (PHK) Length: (1) Cycles: (3)
	{.opcode = 0x4c
#ifdef DEBUG
	, .name = "Jump",
	.mnemonic = "JMP"
#endif
	}, //Jump | Absolute |  (JMP $1234) Length: (3) Cycles: (3)
	{.opcode = 0x4d
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Absolute |  (EOR $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x4e
#ifdef DEBUG
	, .name = "Logical Shift Right",
	.mnemonic = "LSR"
#endif
	}, //Logical Shift Right | Absolute |  (LSR $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0x4f
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Long |  (EOR $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0x50
#ifdef DEBUG
	, .name = "Branch if Overflow Clear",
	.mnemonic = "BVC"
#endif
	}, //Branch if Overflow Clear | Relative 8-bit |  (BVC LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0x51
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct indirect indexed Y |  (EOR ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0x52
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct Indirect |  (EOR ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0x53
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | (Stack,S) Indirect Indexed Y |  (EOR ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0x54
#ifdef DEBUG
	, .name = "Move Memory Negative",
	.mnemonic = "MVN"
#endif
	}, //Move Memory Negative | Source, Destination Block Move |  (MVN #$12,#$34) Length: (3) Cycles: (7)
	{.opcode = 0x55
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct indexed X |  (EOR $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x56
#ifdef DEBUG
	, .name = "Logical Shift Right",
	.mnemonic = "LSR"
#endif
	}, //Logical Shift Right | Direct indexed X |  (LSR $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0x57
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Direct indirect indexed long Y |  (EOR [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x58
#ifdef DEBUG
	, .name = "Clear Interrupt Disable",
	.mnemonic = "CLI"
#endif
	}, //Clear Interrupt Disable | Implied |  (CLI) Length: (1) Cycles: (2)
	{.opcode = 0x59
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Absolute indexed Y |  (EOR $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x5a
#ifdef DEBUG
	, .name = "Push Y register",
	.mnemonic = "PHY"
#endif
	}, //Push Y register | Implied |  (PHY) Length: (1) Cycles: (4-x)
	{.opcode = 0x5b
#ifdef DEBUG
	, .name = "Transfer C Accumulator to Direct Register",
	.mnemonic = "TCD"
#endif
	}, //Transfer C Accumulator to Direct Register | Implied |  (TCD) Length: (1) Cycles: (2)
	{.opcode = 0x5c
#ifdef DEBUG
	, .name = "Jump",
	.mnemonic = "JMP"
#endif
	}, //Jump | Long |  (JMP $FEDCBA) Length: (4) Cycles: (4)
	{.opcode = 0x5d
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Absolute indexed X |  (EOR $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x5e
#ifdef DEBUG
	, .name = "Logical Shift Right",
	.mnemonic = "LSR"
#endif
	}, //Logical Shift Right | Absolute indexed X |  (LSR $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0x5f
#ifdef DEBUG
	, .name = "Exclusive OR with accumulator",
	.mnemonic = "EOR"
#endif
	}, //Exclusive OR with accumulator | Long indexed X |  (EOR $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0x60
#ifdef DEBUG
	, .name = "Return from Subroutine",
	.mnemonic = "RTS"
#endif
	}, //Return from Subroutine | Implied |  (RTS) Length: (1) Cycles: (6)
	{.opcode = 0x61
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct Indexed Indirect (dir,X) |  (ADC ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x62
#ifdef DEBUG
	, .name = "Push Effective Relative Address",
	.mnemonic = "PER"
#endif
	}, //Push Effective Relative Address | Immediate |  (PER LABEL) Length: (3) Cycles: (6)
	{.opcode = 0x63
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Stack,S |  (ADC $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0x64
#ifdef DEBUG
	, .name = "Store Zero",
	.mnemonic = "STZ"
#endif
	}, //Store Zero | Direct |  (STZ $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x65
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct |  (ADC $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x66
#ifdef DEBUG
	, .name = "Rotate Right",
	.mnemonic = "ROR"
#endif
	}, //Rotate Right | Direct |  (ROR $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0x67
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct Indirect Long |  (ADC [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x68
#ifdef DEBUG
	, .name = "Pull Accumulator",
	.mnemonic = "PLA"
#endif
	}, //Pull Accumulator | Implied |  (PLA) Length: (1) Cycles: (5-m)
	{.opcode = 0x69
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Immediate |  (ADC #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0x6a
#ifdef DEBUG
	, .name = "Rotate Right",
	.mnemonic = "ROR"
#endif
	}, //Rotate Right | Accumulator |  (ROR) Length: (1) Cycles: (2)
	{.opcode = 0x6b
#ifdef DEBUG
	, .name = "Return from Subroutine Long",
	.mnemonic = "RTL"
#endif
	}, //Return from Subroutine Long | Implied |  (RTL) Length: (1) Cycles: (6)
	{.opcode = 0x6c
#ifdef DEBUG
	, .name = "Jump",
	.mnemonic = "JMP"
#endif
	}, //Jump | Absolute Indirect |  (JMP ($1234)) Length: (3) Cycles: (5)
	{.opcode = 0x6d
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Absolute |  (ADC $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x6e
#ifdef DEBUG
	, .name = "Rotate Right",
	.mnemonic = "ROR"
#endif
	}, //Rotate Right | Absolute |  (ROR $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0x6f
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Long |  (ADC $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0x70
#ifdef DEBUG
	, .name = "Branch if Overflow Set",
	.mnemonic = "BVS"
#endif
	}, //Branch if Overflow Set | Relative 8-bit |  (BVS LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0x71
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct indirect indexed Y |  (ADC ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0x72
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct Indirect |  (ADC ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0x73
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | (Stack,S) Indirect Indexed Y |  (ADC ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0x74
#ifdef DEBUG
	, .name = "Store Zero",
	.mnemonic = "STZ"
#endif
	}, //Store Zero | Direct indexed X |  (STZ $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x75
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct indexed X |  (ADC $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x76
#ifdef DEBUG
	, .name = "Rotate Right",
	.mnemonic = "ROR"
#endif
	}, //Rotate Right | Direct indexed X |  (ROR $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0x77
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Direct indirect indexed long Y |  (ADC [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x78
#ifdef DEBUG
	, .name = "Set Interrupt Disable",
	.mnemonic = "SEI"
#endif
	}, //Set Interrupt Disable | Implied |  (SEI) Length: (1) Cycles: (2)
	{.opcode = 0x79
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Absolute indexed Y |  (ADC $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x7a
#ifdef DEBUG
	, .name = "Pull Y register",
	.mnemonic = "PLY"
#endif
	}, //Pull Y register | Implied |  (PLY) Length: (1) Cycles: (5-x)
	{.opcode = 0x7b
#ifdef DEBUG
	, .name = "Transfer Direct Register to C Accumulator",
	.mnemonic = "TDC"
#endif
	}, //Transfer Direct Register to C Accumulator | Implied |  (TDC) Length: (1) Cycles: (2)
	{.opcode = 0x7c
#ifdef DEBUG
	, .name = "Jump",
	.mnemonic = "JMP"
#endif
	}, //Jump | Absolute indexed indirect X |  (JMP ($1234,X)) Length: (3) Cycles: (6)
	{.opcode = 0x7d
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Absolute indexed X |  (ADC $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0x7e
#ifdef DEBUG
	, .name = "Rotate Right",
	.mnemonic = "ROR"
#endif
	}, //Rotate Right | Absolute indexed X |  (ROR $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0x7f
#ifdef DEBUG
	, .name = "Add with carry",
	.mnemonic = "ADC"
#endif
	}, //Add with carry | Long indexed X |  (ADC $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0x80
#ifdef DEBUG
	, .name = "Branch Always",
	.mnemonic = "BRA"
#endif
	}, //Branch Always | Relative 8-bit |  (BRA LABEL) Length: (2) Cycles: (3+e*p)
	{.opcode = 0x81
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct Indexed Indirect (dir,X) |  (STA ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x82
#ifdef DEBUG
	, .name = "Branch Long",
	.mnemonic = "BRL"
#endif
	}, //Branch Long | Relative 16-bit |  (BRL LABEL) Length: (3) Cycles: (4)
	{.opcode = 0x83
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Stack,S |  (STA $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0x84
#ifdef DEBUG
	, .name = "Store Y register",
	.mnemonic = "STY"
#endif
	}, //Store Y register | Direct |  (STY $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0x85
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct |  (STA $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0x86
#ifdef DEBUG
	, .name = "Store X register",
	.mnemonic = "STX"
#endif
	}, //Store X register | Direct |  (STX $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0x87
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct Indirect Long |  (STA [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x88
#ifdef DEBUG
	, .name = "Decrement Y",
	.mnemonic = "DEY"
#endif
	}, //Decrement Y | Implied |  (DEY) Length: (1) Cycles: (2)
	{.opcode = 0x89
#ifdef DEBUG
	, .name = "Test BITs",
	.mnemonic = "BIT"
#endif
	}, //Test BITs | Immediate |  (BIT #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0x8a
#ifdef DEBUG
	, .name = "Transfer X Register to Accumulator",
	.mnemonic = "TXA"
#endif
	}, //Transfer X Register to Accumulator | Implied |  (TXA) Length: (1) Cycles: (2)
	{.opcode = 0x8b
#ifdef DEBUG
	, .name = "Push Data Bank Register",
	.mnemonic = "PHB"
#endif
	}, //Push Data Bank Register | Implied |  (PHB) Length: (1) Cycles: (3)
	{.opcode = 0x8c
#ifdef DEBUG
	, .name = "Store Y register",
	.mnemonic = "STY"
#endif
	}, //Store Y register | Absolute |  (STY $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0x8d
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Absolute |  (STA $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x8e
#ifdef DEBUG
	, .name = "Store X register",
	.mnemonic = "STX"
#endif
	}, //Store X register | Absolute |  (STX $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0x8f
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Long |  (STA $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0x90
#ifdef DEBUG
	, .name = "Branch if Carry Clear",
	.mnemonic = "BCC"
#endif
	}, //Branch if Carry Clear | Relative 8-bit |  (BCC LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0x91
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct indirect indexed Y |  (STA ($10),Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x92
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct Indirect |  (STA ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0x93
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | (Stack,S) Indirect Indexed Y |  (STA ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0x94
#ifdef DEBUG
	, .name = "Store Y register",
	.mnemonic = "STY"
#endif
	}, //Store Y register | Direct indexed X |  (STY $10,X) Length: (2) Cycles: (5-x+w)
	{.opcode = 0x95
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct indexed X |  (STA $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0x96
#ifdef DEBUG
	, .name = "Store X register",
	.mnemonic = "STX"
#endif
	}, //Store X register | Direct indexed Y |  (STX $10,Y) Length: (2) Cycles: (5-x+w)
	{.opcode = 0x97
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Direct indirect indexed long Y |  (STA [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0x98
#ifdef DEBUG
	, .name = "Transfer Y register to Accumulator",
	.mnemonic = "TYA"
#endif
	}, //Transfer Y register to Accumulator | Implied |  (TYA) Length: (1) Cycles: (2)
	{.opcode = 0x99
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Absolute indexed Y |  (STA $9876,Y) Length: (3) Cycles: (6-m)
	{.opcode = 0x9a
#ifdef DEBUG
	, .name = "Transfer X Register to Stack Pointer",
	.mnemonic = "TXS"
#endif
	}, //Transfer X Register to Stack Pointer | Implied |  (TXS) Length: (1) Cycles: (2)
	{.opcode = 0x9b
#ifdef DEBUG
	, .name = "Transfer X Register to Y Register",
	.mnemonic = "TXY"
#endif
	}, //Transfer X Register to Y Register | Implied |  (TXY) Length: (1) Cycles: (2)
	{.opcode = 0x9c
#ifdef DEBUG
	, .name = "Store Zero",
	.mnemonic = "STZ"
#endif
	}, //Store Zero | Absolute |  (STZ $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0x9d
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Absolute indexed X |  (STA $9876,X) Length: (3) Cycles: (6-m)
	{.opcode = 0x9e
#ifdef DEBUG
	, .name = "Store Zero",
	.mnemonic = "STZ"
#endif
	}, //Store Zero | Absolute indexed X |  (STZ $9876,X) Length: (3) Cycles: (6-m)
	{.opcode = 0x9f
#ifdef DEBUG
	, .name = "Store Accumulator",
	.mnemonic = "STA"
#endif
	}, //Store Accumulator | Long indexed X |  (STA $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0xa0
#ifdef DEBUG
	, .name = "Load Y register",
	.mnemonic = "LDY"
#endif
	}, //Load Y register | Immediate |  (LDY #$54) Length: (3-x) Cycles: (3-x)
	{.opcode = 0xa1
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct Indexed Indirect (dir,X) |  (LDA ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xa2
#ifdef DEBUG
	, .name = "Load X register",
	.mnemonic = "LDX"
#endif
	}, //Load X register | Immediate |  (LDX #$54) Length: (3-x) Cycles: (3-x)
	{.opcode = 0xa3
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Stack,S |  (LDA $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0xa4
#ifdef DEBUG
	, .name = "Load Y register",
	.mnemonic = "LDY"
#endif
	}, //Load Y register | Direct |  (LDY $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0xa5
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct |  (LDA $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0xa6
#ifdef DEBUG
	, .name = "Load X register",
	.mnemonic = "LDX"
#endif
	}, //Load X register | Direct |  (LDX $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0xa7
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct Indirect Long |  (LDA [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xa8
#ifdef DEBUG
	, .name = "Transfer Accumulator to Y Register",
	.mnemonic = "TAY"
#endif
	}, //Transfer Accumulator to Y Register | Implied |  (TAY) Length: (1) Cycles: (2)
	{.opcode = 0xa9
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Immediate |  (LDA #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0xaa
#ifdef DEBUG
	, .name = "Transfer Accumulator to X Register",
	.mnemonic = "TAX"
#endif
	}, //Transfer Accumulator to X Register | Implied |  (TAX) Length: (1) Cycles: (2)
	{.opcode = 0xab
#ifdef DEBUG
	, .name = "Pull Data Bank Register",
	.mnemonic = "PLB"
#endif
	}, //Pull Data Bank Register | Implied |  (PLB) Length: (1) Cycles: (4)
	{.opcode = 0xac
#ifdef DEBUG
	, .name = "Load Y register",
	.mnemonic = "LDY"
#endif
	}, //Load Y register | Absolute |  (LDY $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0xad
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Absolute |  (LDA $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0xae
#ifdef DEBUG
	, .name = "Load X register",
	.mnemonic = "LDX"
#endif
	}, //Load X register | Absolute |  (LDX $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0xaf
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Long |  (LDA $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0xb0
#ifdef DEBUG
	, .name = "Branch if Carry Set",
	.mnemonic = "BCS"
#endif
	}, //Branch if Carry Set | Relative 8-bit |  (BCS LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0xb1
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct indirect indexed Y |  (LDA ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0xb2
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct Indirect |  (LDA ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0xb3
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | (Stack,S) Indirect Indexed Y |  (LDA ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0xb4
#ifdef DEBUG
	, .name = "Load Y register",
	.mnemonic = "LDY"
#endif
	}, //Load Y register | Direct indexed X |  (LDY $10,X) Length: (2) Cycles: (5-x+w)
	{.opcode = 0xb5
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct indexed X |  (LDA $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0xb6
#ifdef DEBUG
	, .name = "Load X register",
	.mnemonic = "LDX"
#endif
	}, //Load X register | Direct indexed Y |  (LDX $10,Y) Length: (2) Cycles: (5-x+w)
	{.opcode = 0xb7
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Direct indirect indexed long Y |  (LDA [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xb8
#ifdef DEBUG
	, .name = "Clear Overflow",
	.mnemonic = "CLV"
#endif
	}, //Clear Overflow | Implied |  (CLV) Length: (1) Cycles: (2)
	{.opcode = 0xb9
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Absolute indexed Y |  (LDA $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xba
#ifdef DEBUG
	, .name = "Transfer Stack Pointer to X Register",
	.mnemonic = "TSX"
#endif
	}, //Transfer Stack Pointer to X Register | Implied |  (TSX) Length: (1) Cycles: (2)
	{.opcode = 0xbb
#ifdef DEBUG
	, .name = "Transfer Y register to X register",
	.mnemonic = "TYX"
#endif
	}, //Transfer Y register to X register | Implied |  (TYX) Length: (1) Cycles: (2)
	{.opcode = 0xbc
#ifdef DEBUG
	, .name = "Load Y register",
	.mnemonic = "LDY"
#endif
	}, //Load Y register | Absolute indexed X |  (LDY $9876,X) Length: (3) Cycles: (6-2*x+x*p)
	{.opcode = 0xbd
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Absolute indexed X |  (LDA $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xbe
#ifdef DEBUG
	, .name = "Load X register",
	.mnemonic = "LDX"
#endif
	}, //Load X register | Absolute indexed Y |  (LDX $9876,Y) Length: (3) Cycles: (6-2*x+x*p)
	{.opcode = 0xbf
#ifdef DEBUG
	, .name = "Load Accumulator",
	.mnemonic = "LDA"
#endif
	}, //Load Accumulator | Long indexed X |  (LDA $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0xc0
#ifdef DEBUG
	, .name = "Compare to Y",
	.mnemonic = "CPY"
#endif
	}, //Compare to Y | Immediate |  (CPY #$54) Length: (3-x) Cycles: (3-x)
	{.opcode = 0xc1
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct Indexed Indirect (dir,X) |  (CMP ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xc2
#ifdef DEBUG
	, .name = "Reset Processor Status Bits",
	.mnemonic = "REP"
#endif
	}, //Reset Processor Status Bits | Immediate |  (REP #$12) Length: (2) Cycles: (3)
	{.opcode = 0xc3
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Stack,S |  (CMP $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0xc4
#ifdef DEBUG
	, .name = "Compare to Y",
	.mnemonic = "CPY"
#endif
	}, //Compare to Y | Direct |  (CPY $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0xc5
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct |  (CMP $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0xc6
#ifdef DEBUG
	, .name = "Decrement accumulator",
	.mnemonic = "DEC"
#endif
	}, //Decrement accumulator | Direct |  (DEC $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0xc7
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct Indirect Long |  (CMP [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xc8
#ifdef DEBUG
	, .name = "Increment Y",
	.mnemonic = "INY"
#endif
	}, //Increment Y | Implied |  (INY) Length: (1) Cycles: (2)
	{.opcode = 0xc9
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Immediate |  (CMP #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0xca
#ifdef DEBUG
	, .name = "Decrement X",
	.mnemonic = "DEX"
#endif
	}, //Decrement X | Implied |  (DEX) Length: (1) Cycles: (2)
	{.opcode = 0xcb
#ifdef DEBUG
	, .name = "Wait For Interrupt",
	.mnemonic = "WAI"
#endif
	}, //Wait For Interrupt | Implied |  (WAI) Length: (1) Cycles: (3)
	{.opcode = 0xcc
#ifdef DEBUG
	, .name = "Compare to Y",
	.mnemonic = "CPY"
#endif
	}, //Compare to Y | Absolute |  (CPY $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0xcd
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Absolute |  (CMP $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0xce
#ifdef DEBUG
	, .name = "Decrement accumulator",
	.mnemonic = "DEC"
#endif
	}, //Decrement accumulator | Absolute |  (DEC $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0xcf
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Long |  (CMP $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0xd0
#ifdef DEBUG
	, .name = "Branch if Not Equal",
	.mnemonic = "BNE"
#endif
	}, //Branch if Not Equal | Relative 8-bit |  (BNE LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0xd1
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct indirect indexed Y |  (CMP ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0xd2
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct Indirect |  (CMP ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0xd3
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | (Stack,S) Indirect Indexed Y |  (CMP ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0xd4
#ifdef DEBUG
	, .name = "Push Effective Indirect Address",
	.mnemonic = "PEI"
#endif
	}, //Push Effective Indirect Address | Direct |  (PEI $12) Length: (2) Cycles: (6+w)
	{.opcode = 0xd5
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct indexed X |  (CMP $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0xd6
#ifdef DEBUG
	, .name = "Decrement accumulator",
	.mnemonic = "DEC"
#endif
	}, //Decrement accumulator | Direct indexed X |  (DEC $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0xd7
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Direct indirect indexed long Y |  (CMP [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xd8
#ifdef DEBUG
	, .name = "Clear Decimal Mode",
	.mnemonic = "CLD"
#endif
	}, //Clear Decimal Mode | Implied |  (CLD) Length: (1) Cycles: (2)
	{.opcode = 0xd9
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Absolute indexed Y |  (CMP $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xda
#ifdef DEBUG
	, .name = "Push X register",
	.mnemonic = "PHX"
#endif
	}, //Push X register | Implied |  (PHX) Length: (1) Cycles: (4-x)
	{.opcode = 0xdb
#ifdef DEBUG
	, .name = "Stop The Clock",
	.mnemonic = "STP"
#endif
	}, //Stop The Clock | Implied |  (STP) Length: (1) Cycles: (3)
	{.opcode = 0xdc
#ifdef DEBUG
	, .name = "Jump",
	.mnemonic = "JMP"
#endif
	}, //Jump | Absolute Indirect Long |  (JMP [$1234]) Length: (3) Cycles: (6)
	{.opcode = 0xdd
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Absolute indexed X |  (CMP $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xde
#ifdef DEBUG
	, .name = "Decrement accumulator",
	.mnemonic = "DEC"
#endif
	}, //Decrement accumulator | Absolute indexed X |  (DEC $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0xdf
#ifdef DEBUG
	, .name = "Compare to accumulator",
	.mnemonic = "CMP"
#endif
	}, //Compare to accumulator | Long indexed X |  (CMP $FEDCBA,X) Length: (4) Cycles: (6-m)
	{.opcode = 0xe0
#ifdef DEBUG
	, .name = "Compare to X",
	.mnemonic = "CPX"
#endif
	}, //Compare to X | Immediate |  (CPX #$54) Length: (3-x) Cycles: (3-x)
	{.opcode = 0xe1
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct Indexed Indirect (dir,X) |  (SBC ($10,X)) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xe2
#ifdef DEBUG
	, .name = "Set Processor Status Bits",
	.mnemonic = "SEP"
#endif
	}, //Set Processor Status Bits | Immediate |  (SEP #$12) Length: (2) Cycles: (3)
	{.opcode = 0xe3
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Stack,S |  (SBC $32,S) Length: (2) Cycles: (5-m)
	{.opcode = 0xe4
#ifdef DEBUG
	, .name = "Compare to X",
	.mnemonic = "CPX"
#endif
	}, //Compare to X | Direct |  (CPX $10) Length: (2) Cycles: (4-x+w)
	{.opcode = 0xe5
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct |  (SBC $10) Length: (2) Cycles: (4-m+w)
	{.opcode = 0xe6
#ifdef DEBUG
	, .name = "Increment accumulator",
	.mnemonic = "INC"
#endif
	}, //Increment accumulator | Direct |  (INC $10) Length: (2) Cycles: (7-2*m+w)
	{.opcode = 0xe7
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct Indirect Long |  (SBC [$10]) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xe8
#ifdef DEBUG
	, .name = "Increment X",
	.mnemonic = "INX"
#endif
	}, //Increment X | Implied |  (INX) Length: (1) Cycles: (2)
	{.opcode = 0xe9
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Immediate |  (SBC #$54) Length: (3-m) Cycles: (3-m)
	{.opcode = 0xea
#ifdef DEBUG
	, .name = "No operation",
	.mnemonic = "NOP"
#endif
	}, //No operation | Implied |  (NOP) Length: (1) Cycles: (2)
	{.opcode = 0xeb
#ifdef DEBUG
	, .name = "Exchange B and A Accumulator",
	.mnemonic = "XBA"
#endif
	}, //Exchange B and A Accumulator | Implied |  (XBA) Length: (1) Cycles: (3)
	{.opcode = 0xec
#ifdef DEBUG
	, .name = "Compare to X",
	.mnemonic = "CPX"
#endif
	}, //Compare to X | Absolute |  (CPX $9876) Length: (3) Cycles: (5-x)
	{.opcode = 0xed
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Absolute |  (SBC $9876) Length: (3) Cycles: (5-m)
	{.opcode = 0xee
#ifdef DEBUG
	, .name = "Increment accumulator",
	.mnemonic = "INC"
#endif
	}, //Increment accumulator | Absolute |  (INC $9876) Length: (3) Cycles: (8-2*m)
	{.opcode = 0xef
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Long |  (SBC $FEDBCA) Length: (4) Cycles: (6-m)
	{.opcode = 0xf0
#ifdef DEBUG
	, .name = "Branch if Equal",
	.mnemonic = "BEQ"
#endif
	}, //Branch if Equal | Relative 8-bit |  (BEQ LABEL) Length: (2) Cycles: (2+t+t*e*p)
	{.opcode = 0xf1
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct indirect indexed Y |  (SBC ($10),Y) Length: (2) Cycles: (7-m+w-x+x*p)
	{.opcode = 0xf2
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct Indirect |  (SBC ($10)) Length: (2) Cycles: (6-m+w)
	{.opcode = 0xf3
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | (Stack,S) Indirect Indexed Y |  (SBC ($32,S),Y) Length: (2) Cycles: (8-m)
	{.opcode = 0xf4
#ifdef DEBUG
	, .name = "Push Effective Address",
	.mnemonic = "PEA"
#endif
	}, //Push Effective Address | Immediate |  (PEA #$1234) Length: (3) Cycles: (5)
	{.opcode = 0xf5
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct indexed X |  (SBC $10,X) Length: (2) Cycles: (5-m+w)
	{.opcode = 0xf6
#ifdef DEBUG
	, .name = "Increment accumulator",
	.mnemonic = "INC"
#endif
	}, //Increment accumulator | Direct indexed X |  (INC $10,X) Length: (2) Cycles: (8-2*m+w)
	{.opcode = 0xf7
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Direct indirect indexed long Y |  (SBC [$10],Y) Length: (2) Cycles: (7-m+w)
	{.opcode = 0xf8
#ifdef DEBUG
	, .name = "Set Decimal Mode",
	.mnemonic = "SED"
#endif
	}, //Set Decimal Mode | Implied |  (SED) Length: (1) Cycles: (2)
	{.opcode = 0xf9
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Absolute indexed Y |  (SBC $9876,Y) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xfa
#ifdef DEBUG
	, .name = "Pull X register",
	.mnemonic = "PLX"
#endif
	}, //Pull X register | Implied |  (PLX) Length: (1) Cycles: (5-x)
	{.opcode = 0xfb
#ifdef DEBUG
	, .name = "Exchange Carry and Emulation Flags",
	.mnemonic = "XCE"
#endif
	}, //Exchange Carry and Emulation Flags | Implied |  (XCE) Length: (1) Cycles: (2)
	{.opcode = 0xfc
#ifdef DEBUG
	, .name = "Jump to Subroutine",
	.mnemonic = "JSR"
#endif
	}, //Jump to Subroutine | Absolute indexed indirect X |  (JSR ($1234,X)) Length: (3) Cycles: (8)
	{.opcode = 0xfd
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Absolute indexed X |  (SBC $9876,X) Length: (3) Cycles: (6-m-x+x*p)
	{.opcode = 0xfe
#ifdef DEBUG
	, .name = "Increment accumulator",
	.mnemonic = "INC"
#endif
	}, //Increment accumulator | Absolute indexed X |  (INC $9876,X) Length: (3) Cycles: (9-2*m)
	{.opcode = 0xff
#ifdef DEBUG
	, .name = "Subtract with carry",
	.mnemonic = "SBC"
#endif
	}, //Subtract with carry | Long indexed X |  (SBC $FEDCBA,X) Length: (4) Cycles: (6-m)
}};