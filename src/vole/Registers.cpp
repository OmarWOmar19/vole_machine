#include "../../include/vole/Registers.h"

Registers::Registers() : vals(16, 0) {

}

uint8_t Registers::read(uint8_t address) {
    
    if (address < vals.size()) {
        return vals[address];
    }

    return 0;

}

void Registers::set(uint8_t val, uint8_t address) {
    if (address < vals.size()) {
        vals[address] = val;
    }
}

void Registers::reset() {
    fill(vals.begin(), vals.end(), 0);
}