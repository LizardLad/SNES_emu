//Implementation of the SNES memory bus
#include <cstdint>
#include <snes_mem.hpp>

bool SNES_MEM::cpu_write(uint32_t loc, uint8_t *data) {
	return true;
}

bool SNES_MEM::cpu_read(uint32_t loc, uint8_t *data) {
	return true;
}
