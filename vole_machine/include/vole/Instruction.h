#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

class Instruction {

    private:
        uint8_t opcode, r, x, y;

    public:
        Instruction(uint8_t _opcode = 0x00, uint8_t _r = 0x00, uint8_t _x = 0x00, uint8_t _y = 0x00);

        uint8_t get_opcode();
        uint8_t get_r();
        uint8_t get_x();
        uint8_t get_y();

};

#endif