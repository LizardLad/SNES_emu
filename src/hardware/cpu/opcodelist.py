from urllib.request import urlopen
import urllib
import re
import os
import schema

raw_instruction_information_schema = schema.Schema([{
	'opcode': int,
	'length': str,
	'cycles': str,
	'mode': str,
	'status_changes': str,
	'example': str,
	schema.Optional('mnemonic'): str,
	schema.Optional('mode_clear'): str,
}])

url = "http://www.6502.org/tutorials/65c816opcodes.html"
opener = urllib.request.build_opener()
opener.addheaders = [('User-agent', 'Mozilla/5.0 (Windows NT 6.1; Win64; x64)')]
urllib.request.install_opener(opener)
data = urlopen(url).read().decode('UTF-8')

regex = r"([ABCDEF\d][ABCDEF\d]) (\d[^\s]*)\s+(\d[^\s]*)\s+([^\s]+)\s+([^\s]+ [^\s]+)\s+(.+)"
matches = re.finditer(regex, data, re.MULTILINE)
raw_instruction_information = []

for matchNum, match in enumerate(matches, start=1):
	instruction = {}
	for groupNum in range(0, len(match.groups())):
		groupNum = groupNum + 1
		if(groupNum == 1):
			instruction['opcode'] = int(match.group(groupNum), base=16)
		elif(groupNum == 2):
			instruction['length'] = match.group(groupNum)
		elif(groupNum == 3):
			instruction['cycles'] = match.group(groupNum)
		elif(groupNum == 4):
			instruction['mode'] = match.group(groupNum)
		elif(groupNum == 5):
			instruction['status_changes'] = match.group(groupNum)
		elif(groupNum == 6):
			instruction['example'] = match.group(groupNum)
	raw_instruction_information.append(instruction)
raw_instruction_information = sorted(raw_instruction_information, key=lambda x: x['opcode'])

#print("//Information extracted: {}", [x['opcode'] for x in raw_instruction_information_schema.validate(raw_instruction_information)])
#print("//Number of extracted instructions: ", len(raw_instruction_information))

for idx, entry in enumerate(raw_instruction_information):
	if(idx == 255):
		break
	if(entry['opcode'] == raw_instruction_information[idx+1]['opcode']):
		print("Double up!", idx, idx+1)
		os.exit(1)

for idx, instruction in enumerate(raw_instruction_information):
	raw_instruction_information[idx]['mnemonic'] = instruction['example'][:3]
	mode = instruction['mode']
	if(mode == "dir"):
		mode = "Direct"
	elif(mode == "acc"):
		mode = "Accumulator"
	elif(mode == "imm"):
		mode = "Immediate"
	elif(mode == "imp"):
		mode = "Implied"
	elif(mode == "(dir)"):
		mode = "Direct Indirect"
	elif(mode == "[dir]"):
		mode = "Direct Indirect Long"
	elif(mode == "(dir,X)"):
		mode = "Direct Indexed Indirect (dir,X)"
	elif(mode == "stk,S"):
		mode = "Stack,S"
	elif(mode == "(stk,S)"):
		mode = "(Stack,S) Indirect"
	elif(mode == "abs"):
		mode = "Absolute"
	elif(mode == "long"):
		mode = "Long"
	elif(mode == "long,X"):
		mode = "Long indexed X"
	elif(mode == "abs,X"):
		mode = "Absolute indexed X"
	elif(mode == "abs,Y"):
		mode = "Absolute indexed Y"
	elif(mode == "dir,X"):
		mode = "Direct indexed X"
	elif(mode == "dir,Y"):
		mode = "Direct indexed Y"
	elif(mode == "[dir],Y"):
		mode = "Direct indirect indexed long Y"
	elif(mode == "rel8"):
		mode = "Relative 8-bit"
	elif(mode == "(stk,S),Y"):
		mode = "(Stack,S) Indirect Indexed Y"
	elif(mode == "rel16"):
		mode = "Relative 16-bit"
	elif(mode == "(abs)"):
		mode = "Absolute Indirect"
	elif(mode == "[abs]"):
		mode = "Absolute Indirect Long"
	elif(mode == "(dir),Y"):
		mode = "Direct indirect indexed Y"
	elif(mode == "src,dest"):
		mode = "Source, Destination Block Move"
	elif(mode == "(abs,X)"):
		mode = "Absolute indexed indirect X"
	else:
		raise ValueError("Invalid addressing mode")
	raw_instruction_information[idx]['mode_clean'] = mode

byte_counts = set()
for instruction in raw_instruction_information:
	byte_counts.add(instruction['cycles'])
#print(byte_counts)

for idx, instruction in enumerate(raw_instruction_information):
	name = ""
	if(instruction['mnemonic'] == "ADC"):
		name = "Add with carry"
	elif(instruction['mnemonic'] == "SBC"):
		name = "Subtract with carry"
	elif(instruction['mnemonic'] == "CMP"):
		name = "Compare to accumulator"
	elif(instruction['mnemonic'] == "CPX"):
		name = "Compare to X"
	elif(instruction['mnemonic'] == "CPY"):
		name = "Compare to Y"
	elif(instruction['mnemonic'] == "DEC"):
		name = "Decrement accumulator"
	elif(instruction['mnemonic'] == "DEX"):
		name = "Decrement X"
	elif(instruction['mnemonic'] == "DEY"):
		name = "Decrement Y"
	elif(instruction['mnemonic'] == "INC"):
		name = "Increment accumulator"
	elif(instruction['mnemonic'] == "INX"):
		name = "Increment X"
	elif(instruction['mnemonic'] == "INY"):
		name = "Increment Y"
	elif(instruction['mnemonic'] == "AND"):
		name = "Bitwise AND with accumulator"
	elif(instruction['mnemonic'] == "EOR"):
		name = "Exclusive OR with accumulator"
	elif(instruction['mnemonic'] == "ORA"):
		name = "Bitwise OR with accumulator"
	elif(instruction['mnemonic'] == "BIT"):
		name = "Test BITs"
	elif(instruction['mnemonic'] == "TRB"):
		name = "Test and Reset Bits"
	elif(instruction['mnemonic'] == "TSB"):
		name = "Test and Set Bits"
	elif(instruction['mnemonic'] == "ASL"):
		name = "Arithmetic Shift Left"
	elif(instruction['mnemonic'] == "LSR"):
		name = "Logical Shift Right"
	elif(instruction['mnemonic'] == "ROL"):
		name = "Rotate Left"
	elif(instruction['mnemonic'] == "ROR"):
		name = "Rotate Right"
	elif(instruction['mnemonic'] == "BCC"):
		name = "Branch if Carry Clear"
	elif(instruction['mnemonic'] == "BCS"):
		name = "Branch if Carry Set"
	elif(instruction['mnemonic'] == "BEQ"):
		name = "Branch if Equal"
	elif(instruction['mnemonic'] == "BMI"):
		name = "Branch if Minus"
	elif(instruction['mnemonic'] == "BNE"):
		name = "Branch if Not Equal"
	elif(instruction['mnemonic'] == "BPL"):
		name = "Branch if Plus"
	elif(instruction['mnemonic'] == "BRA"):
		name = "Branch Always"
	elif(instruction['mnemonic'] == "BVC"):
		name = "Branch if Overflow Clear"
	elif(instruction['mnemonic'] == "BVS"):
		name = "Branch if Overflow Set"
	elif(instruction['mnemonic'] == "BRL"):
		name = "Branch Long"
	elif(instruction['mnemonic'] == "JMP"):
		name = "Jump"
	elif(instruction['mnemonic'] == "JSL"):
		name = "Jump to Subroutine Long"
	elif(instruction['mnemonic'] == "JSR"):
		name = "Jump to Subroutine"
	elif(instruction['mnemonic'] == "RTL"):
		name = "Return from Subroutine Long"
	elif(instruction['mnemonic'] == "RTS"):
		name = "Return from Subroutine"
	elif(instruction['mnemonic'] == "BRK"):
		name = "Breakpoint"
	elif(instruction['mnemonic'] == "COP"):
		name = "CoProcessor"
	elif(instruction['mnemonic'] == "RTI"):
		name = "Return from Interrupt"
	elif(instruction['mnemonic'] == "CLC"):
		name = "Clear Carry"
	elif(instruction['mnemonic'] == "CLD"):
		name = "Clear Decimal Mode"
	elif(instruction['mnemonic'] == "CLI"):
		name = "Clear Interrupt Disable"
	elif(instruction['mnemonic'] == "CLV"):
		name = "Clear Overflow"
	elif(instruction['mnemonic'] == "SEC"):
		name = "Set Carry"
	elif(instruction['mnemonic'] == "SED"):
		name = "Set Decimal Mode"
	elif(instruction['mnemonic'] == "SEI"):
		name = "Set Interrupt Disable"
	elif(instruction['mnemonic'] == "REP"):
		name = "Reset Processor Status Bits"
	elif(instruction['mnemonic'] == "SEP"):
		name = "Set Processor Status Bits"
	elif(instruction['mnemonic'] == "LDA"):
		name = "Load Accumulator"
	elif(instruction['mnemonic'] == "LDX"):
		name = "Load X register"
	elif(instruction['mnemonic'] == "LDY"):
		name = "Load Y register"
	elif(instruction['mnemonic'] == "STA"):
		name = "Store Accumulator"
	elif(instruction['mnemonic'] == "STX"):
		name = "Store X register"
	elif(instruction['mnemonic'] == "STY"):
		name = "Store Y register"
	elif(instruction['mnemonic'] == "STZ"):
		name = "Store Zero"
	elif(instruction['mnemonic'] == "MVN"):
		name = "Move Memory Negative"
	elif(instruction['mnemonic'] == "MVP"):
		name = "Move Memory Positive"
	elif(instruction['mnemonic'] == "NOP"):
		name = "No operation"
	elif(instruction['mnemonic'] == "WDM"):
		name = "William D. Mensch, Jr. (2 cycle NOP)"
	elif(instruction['mnemonic'] == "PEA"):
		name = "Push Effective Address"
	elif(instruction['mnemonic'] == "PEI"):
		name = "Push Effective Indirect Address"
	elif(instruction['mnemonic'] == "PER"):
		name = "Push Effective Relative Address"
	elif(instruction['mnemonic'] == "PHA"):
		name = "Push Accumulator"
	elif(instruction['mnemonic'] == "PHX"):
		name = "Push X register"
	elif(instruction['mnemonic'] == "PHY"):
		name = "Push Y register"
	elif(instruction['mnemonic'] == "PLA"):
		name = "Pull Accumulator"
	elif(instruction['mnemonic'] == "PLX"):
		name = "Pull X register"
	elif(instruction['mnemonic'] == "PLY"):
		name = "Pull Y register"
	elif(instruction['mnemonic'] == "PHB"):
		name = "Push Data Bank Register"
	elif(instruction['mnemonic'] == "PHD"):
		name = "Push Direct Register"
	elif(instruction['mnemonic'] == "PHK"):
		name = "Push K Register"
	elif(instruction['mnemonic'] == "PHP"):
		name = "Push Processor Status Register"
	elif(instruction['mnemonic'] == "PLB"):
		name = "Pull Data Bank Register"
	elif(instruction['mnemonic'] == "PLD"):
		name = "Pull Direct Register"
	elif(instruction['mnemonic'] == "PLP"):
		name = "Pull Processor Status Register"
	elif(instruction['mnemonic'] == "STP"):
		name = "Stop The Clock"
	elif(instruction['mnemonic'] == "WAI"):
		name = "Wait For Interrupt"
	elif(instruction['mnemonic'] == "TAX"):
		name = "Transfer Accumulator to X Register"
	elif(instruction['mnemonic'] == "TAY"):
		name = "Transfer Accumulator to Y Register"
	elif(instruction['mnemonic'] == "TSX"):
		name = "Transfer Stack Pointer to X Register"
	elif(instruction['mnemonic'] == "TXA"):
		name = "Transfer X Register to Accumulator"
	elif(instruction['mnemonic'] == "TXS"):
		name = "Transfer X Register to Stack Pointer"
	elif(instruction['mnemonic'] == "TXY"):
		name = "Transfer X Register to Y Register"
	elif(instruction['mnemonic'] == "TYA"):
		name = "Transfer Y register to Accumulator"
	elif(instruction['mnemonic'] == "TYX"):
		name = "Transfer Y register to X register"
	elif(instruction['mnemonic'] == "TCD"):
		name = "Transfer C Accumulator to Direct Register"
	elif(instruction['mnemonic'] == "TCS"):
		name = "Transfer C Accumulator to Stack Pointer"
	elif(instruction['mnemonic'] == "TDC"):
		name = "Transfer Direct Register to C Accumulator"
	elif(instruction['mnemonic'] == "TSC"):
		name = "Transfer Stack Pointer to C Accumulator"
	elif(instruction['mnemonic'] == "XBA"):
		name = "Exchange B and A Accumulator"
	elif(instruction['mnemonic'] == "XCE"):
		name = "Exchange Carry and Emulation Flags"
	else:
		raise ValueError(f"Invalid opcode! %s", instruction['mnemonic'])
	
	instruction['name'] = name

print("const std::array<INSTRUCTION_T, 256> CPU_65C816_instructions = {{")
for idx, instruction in enumerate(raw_instruction_information):
	print(f"\t{{.opcode = {hex(idx)}\n#ifdef DEBUG\n\t, .name = \"{instruction['name']}\",\n\t.mnemonic = \"{instruction['mnemonic']}\"\n#endif\n\t}}, //{instruction['name']} | {instruction['mode_clean']} |  ({instruction['example']}) Length: ({instruction['length']}) Cycles: ({instruction['cycles']})")
print("}};")
