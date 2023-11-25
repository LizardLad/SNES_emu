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

print("//Information extracted: {}", [x['opcode'] for x in raw_instruction_information_schema.validate(raw_instruction_information)])
print("//Number of extracted instructions: ", len(raw_instruction_information))

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
print(byte_counts)

for idx, instruction in enumerate(raw_instruction_information):
	name = ""
	if(instruction['opcode'] == "ADC"):
		name = "Add with carry"
	elif(instruction['opcode'] == "SBC"):
		name = "Subtract with carry"
	elif(instruction['opcode'] == "CMP"):
		name = "Compare to accumulator"
	elif(instruction['opcode'] == "CMX"):
		name = "Compare to X"
	elif(instruction['opcode'] == "CMY"):
		name = "Compare to Y"
	elif(instruction['opcode'] == "DEC"):
		name = "Decrement accumulator"
	elif(instruction['opcode'] == "DEX"):
		name = "Decrement X"
	elif(instruction['opcode'] == "DEY"):
		name = "Decrement Y"
	elif(instruction['opcode'] == "INC"):
		name = "Increment accumulator"
	elif(instruction['opcode'] == "INX"):
		name = "Increment X"
	elif(instruction['opcode'] == "INY"):
		name = "Increment Y"
	elif(instruction['opcode'] == "AND"):
		name = "Bitwise AND with accumulator"
	elif(instruction['opcode'] == "EOR"):
		name = "Exclusive OR with accumulator"
	elif(instruction['opcode'] == "ORA"):
		name = "Bitwise OR with accumulator"
	elif(instruction['opcode'] == "BIT"):
		name = "Test BITs"
	elif(instruction['opcode'] == "TRB"):
		name = "Test and Reset Bits"
	elif(instruction['opcode'] == "TSB"):
		name = "Test and Set Bits"
	elif(instruction['opcode'] == "ASL"):
		name = ""
	elif(instruction['opcode'] == "LSR"):
		name = ""
	elif(instruction['opcode'] == "ROL"):
		name = ""
	elif(instruction['opcode'] == "ROR"):
		name = ""
	elif(instruction['opcode'] == "BCC"):
		name = ""
	elif(instruction['opcode'] == "BCS"):
		name = ""
	elif(instruction['opcode'] == "BEQ"):
		name = ""
	elif(instruction['opcode'] == "BMI"):
		name = ""
	elif(instruction['opcode'] == "BNE"):
		name = ""
	elif(instruction['opcode'] == "BPL"):
		name = ""
	elif(instruction['opcode'] == "BRA"):
		name = ""
	elif(instruction['opcode'] == "BVC"):
		name = ""
	elif(instruction['opcode'] == "BVS"):
		name = ""
	elif(instruction['opcode'] == "BRL"):
		name = ""
	elif(instruction['opcode'] == "JMP"):
		name = ""
	elif(instruction['opcode'] == "JSL"):
		name = ""
	elif(instruction['opcode'] == "JSR"):
		name = ""
	elif(instruction['opcode'] == "RTL"):
		name = ""
	elif(instruction['opcode'] == "RTS"):
		name = ""
	elif(instruction['opcode'] == "BRK"):
		name = ""
	elif(instruction['opcode'] == "COP"):
		name = ""
	elif(instruction['opcode'] == "RTI"):
		name = ""
	elif(instruction['opcode'] == "CLC"):
		name = ""
	elif(instruction['opcode'] == "CLD"):
		name = ""
	elif(instruction['opcode'] == "CLI"):
		name = ""
	elif(instruction['opcode'] == "CLV"):
		name = ""
	elif(instruction['opcode'] == "SEV"):
		name = ""
	elif(instruction['opcode'] == "SED"):
		name = ""
	elif(instruction['opcode'] == "SEI"):
		name = ""
	elif(instruction['opcode'] == "REP"):
		name = ""
	elif(instruction['opcode'] == "SEP"):
		name = ""
	elif(instruction['opcode'] == "LDA"):
		name = ""
	elif(instruction['opcode'] == "LDX"):
		name = ""
	elif(instruction['opcode'] == "LDY"):
		name = ""
	elif(instruction['opcode'] == "STA"):
		name = ""
	elif(instruction['opcode'] == "STX"):
		name = ""
	elif(instruction['opcode'] == "STY"):
		name = ""
	elif(instruction['opcode'] == "STZ"):
		name = ""
	elif(instruction['opcode'] == "MVN"):
		name = ""
	elif(instruction['opcode'] == "MVP"):
		name = ""
	elif(instruction['opcode'] == "NOP"):
		name = ""
	elif(instruction['opcode'] == "WDM"):
		name = ""
	elif(instruction['opcode'] == "PEA"):
		name = ""
	elif(instruction['opcode'] == "PEI"):
		name = ""
	elif(instruction['opcode'] == "PER"):
		name = ""
	elif(instruction['opcode'] == "PHA"):
		name = ""
	elif(instruction['opcode'] == "PHX"):
		name = ""
	elif(instruction['opcode'] == "PHY"):
		name = ""
	elif(instruction['opcode'] == "PLA"):
		name = ""
	elif(instruction['opcode'] == "PLX"):
		name = ""
	elif(instruction['opcode'] == "PLY"):
		name = ""
	elif(instruction['opcode'] == "PHB"):
		name = ""
	elif(instruction['opcode'] == "PHD"):
		name = ""
	elif(instruction['opcode'] == "PHK"):
		name = ""
	elif(instruction['opcode'] == "PHP"):
		name = ""
	elif(instruction['opcode'] == "PLB"):
		name = ""
	elif(instruction['opcode'] == "PLD"):
		name = ""
	elif(instruction['opcode'] == "PLP"):
		name = ""
	elif(instruction['opcode'] == "STP"):
		name = ""
	elif(instruction['opcode'] == "WAI"):
		name = ""
	elif(instruction['opcode'] == "TAX"):
		name = ""
	elif(instruction['opcode'] == "TAY"):
		name = ""
	elif(instruction['opcode'] == "TSX"):
		name = ""
	elif(instruction['opcode'] == "TXA"):
		name = ""
	elif(instruction['opcode'] == "TXS"):
		name = ""
	elif(instruction['opcode'] == "TXY"):
		name = ""
	elif(instruction['opcode'] == "TYA"):
		name = ""
	elif(instruction['opcode'] == "TYX"):
		name = ""
	elif(instruction['opcode'] == "TCD"):
		name = ""
	elif(instruction['opcode'] == "TCS"):
		name = ""
	elif(instruction['opcode'] == "TDC"):
		name = ""
	elif(instruction['opcode'] == "TSC"):
		name = ""
	elif(instruction['opcode'] == "XBA"):
		name = ""
	elif(instruction['opcode'] == "XCE"):
		name = ""
	else:
		raise ValueError(f"Invalid opcode! %s", instruction['opcode'])


#print("std::array<INSTRUCTION_T, 256> instructions = {")
#for(instruction in raw_instruction_information):
#	print("{.opcode = {opcode}, \n
##ifndef DEBUG
#	, .name = \"{name}\"
##endif
# }")
#
#print("};")