#ifndef MEM_HPP
#define MEM_HPP

class SNES_MEM {
	/*
	This is a description of the SNES memory map. (https://wiki.superfamicom.org/memory-mapping)
	The SNES has one 8-bit data bus and two address busses typically known as 
	 "Address Bus A" and "Address Bus B".

	Data Bus:
		If nothing sets a value on the data bus for any read request, the last 
		value placed on the bus is read instead (known as "Open Bus")

	Address Bus A:
		This address bus is 24 bits, with read and write lines (/RD and /WR) and 
		two aux lines (/CART and /WRAM). WRAM (work RAM) is connected here as well 
		as the cart connector.

	Address Bus B:
		This address bus is 8 bits, along with read and write lines (/RD and /WR). d/WRAM). 
		WRAM, PPU1, PPU2, and APU are connected to this bus, as well as the cart and
		expansion ports. Bus B is also known as the SNES bus.

	Cartridge:
		"LoROM", and "HiROM" are just the cart responding differently to addresses placed on
		Address Bus A.

		The cartridge is expected to respond when /CART is active, but can respond to any address
		on either bus that is not otherwise mapped. Similarly the device in the expansion port may
		may respond to any unmapped register on Address Bus B.

	WRAM:
		WRAM responds to Address Bus A whenever /WRAM is active, and to registers 0x2180-0x2183 on
		Address Bus B.
	
	APU:
		APU responds to 0x40-0x7F on Address Bus B.
	
	PPU1, PPU2:
		PPUx respond to 0x2100-0x213F on Address Bus B

	SNES:
		The SNES master clock runs at 21MHz (probably as close to 1.89e9/88Hz as possible). Internal
		operation CPU cycles always take 6 master cycles. Fast memory access takes 6 cycles, 
		slow memory access takes 8 master cycles, and XSlow memory access takes 12 master cycles.


	Banks   |  Addresses  | Speed | Mapping
	--------+-------------+-------+---------
	$00-$3F | $0000-$1FFF | Slow  | Address Bus A + /WRAM (mirror $7E:0000-$1FFF)
    	    | $2000-$20FF | Fast  | Address Bus A
        	| $2100-$21FF | Fast  | Address Bus B
	        | $2200-$3FFF | Fast  | Address Bus A
    	    | $4000-$41FF | XSlow | Internal CPU registers (see Note 1 below)
        	| $4200-$43FF | Fast  | Internal CPU registers (see Note 1 below)
	        | $4400-$5FFF | Fast  | Address Bus A
    	    | $6000-$7FFF | Slow  | Address Bus A
        	| $8000-$FFFF | Slow  | Address Bus A + /CART
	--------+-------------+-------+---------
	$40-$7D | $0000-$FFFF | Slow  | Address Bus A + /CART
	--------+-------------+-------+---------
	$7E-$7F | $0000-$FFFF | Slow  | Address Bus A + /WRAM
	--------+-------------+-------+---------
	$80-$BF | $0000-$1FFF | Slow  | Address Bus A + /WRAM (mirror $7E:0000-$1FFF)
    	    | $2000-$20FF | Fast  | Address Bus A
	        | $2100-$21FF | Fast  | Address Bus B
    	    | $2200-$3FFF | Fast  | Address Bus A
        	| $4000-$41FF | XSlow | Internal CPU registers (see Note 1 below)
	        | $4200-$43FF | Fast  | Internal CPU registers (see Note 1 below)
    	    | $4400-$5FFF | Fast  | Address Bus A
        	| $6000-$7FFF | Slow  | Address Bus A
        	| $8000-$FFFF | Note2 | Address Bus A + /CART
	--------+-------------+-------+---------
	$C0-$FF | $0000-$FFFF | Note2 | Address Bus A + /CART


	Note 1: The address for internal CPU registers may go out Address Bus A, however the CPU ignores the 
	data bus. It is unknown whether the data bus is ignored for the whole memory region, or just for those 
	addresses which are actually registers. It is also unknown whether CPU writes show up on the data bus 
	or not. Current theory is that addresses and writes will show up, but reads may or may not, and the 
	data bus is only ignored for those bits of those registers actually mapped 
	(e.g., data bus is ignored for only bit 7 of $4211).

	Note 2: If bit 1 of CPU register $420D is set, the speed is Fast, otherwise it is Slow.
	*/

	private:
		//Memory map description


	public:
		//Read and Writes


};

#endif