#include "../../include/vole/Instruction.h"

Instruction::Instruction(uint8_t _opcode, uint8_t _r, uint8_t _x, uint8_t _y) : opcode(_opcode), r(_r), x(_x), y(_y) {

}

uint8_t Instruction::get_opcode() {
    return opcode;
}

uint8_t Instruction::get_r() {
    return r;
}

uint8_t Instruction::get_x() {
    return x;
}

uint8_t Instruction::get_y() {
    return y;
}