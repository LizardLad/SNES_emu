#ifndef MEM_HPP
#define MEM_HPP

#include <cstdint>

class MEM {
	public:
		virtual bool cpu_write(uint32_t loc, uint8_t *data) = 0;
		virtual bool cpu_read(uint32_t loc, uint8_t *data) = 0;
};

#endif
