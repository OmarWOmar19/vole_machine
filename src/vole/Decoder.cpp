#include "../../include/vole/Decoder.h"

Instruction Decoder::decode(uint16_t instruction) {

    uint8_t _opcode, _r, _x, _y;

    _opcode = (instruction >> 12) & 0x0F;
    _r = (instruction >> 8) & 0x0F;
    _x = (instruction >> 4) & 0x0F;
    _y = instruction & 0x0F;

    return { _opcode, _r, _x, _y };

}