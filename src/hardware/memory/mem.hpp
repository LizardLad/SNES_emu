#ifndef MEM_HPP
#define MEM_HPP

class MEM {
	public:
		virtual bool cpu_write(uint32_t loc, uint8_t *data);
		virtual bool cpu_read(uint32_t loc, uint8_t *data);
};

#endif