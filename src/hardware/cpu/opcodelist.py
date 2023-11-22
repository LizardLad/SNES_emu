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
#print("std::array<INSTRUCTION_T, 256> instructions = {")
#for(instruction in raw_instruction_information):
#	print("{.opcode = {opcode}, .bytes = {bytes_base}, 
# .bytes_m = {m_adj_count}", .bytes_x = {x_adj_count}, .cycles = {cycles_base},
# )mxewpt
#
#print("};")