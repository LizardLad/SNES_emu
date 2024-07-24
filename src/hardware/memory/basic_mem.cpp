//Implementation of the SNES memory bus
#include <cstdint>
#include <basic_mem.hpp>

BASIC_MEM::BASIC_MEM () {
    this->mem = std::vector<uint8_t> (UINT16_MAX);
    this->limit = UINT16_MAX;
}

bool BASIC_MEM::cpu_write(uint32_t loc, uint8_t *data) {
    if(loc >= this->limit) {
        return false;
    }
    this->mem[loc] = *data;
	return true;
}

bool BASIC_MEM::cpu_read(uint32_t loc, uint8_t *data) {
    if(loc >= this->limit) {
        return false;
    }
    *data = this->mem[loc];
	return true;
}
