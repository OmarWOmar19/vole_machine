#include "../../include/vole/PC.h"

uint8_t PC::get() {
    return value;
}

void PC::set(uint8_t _value) {
    value = _value;
}

void PC::increment(uint8_t amount) {
    value += amount;
}