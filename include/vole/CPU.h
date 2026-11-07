#ifndef CPU_H
#define CPU_H

#include <cstdint>

#include "IR.h"
#include "PC.h"
#include "Memory.h"
#include "Registers.h"
#include "Decoder.h"
#include "Instruction.h"

class CPU {

    private:
        PC pc;
        IR ir;
        Memory& memory;
        Registers& registers;
        Decoder decoder;
        Instruction decoded_instruction;

        bool halted = false;
        bool validate_instruction();

    public:
        CPU(Memory& _memory, Registers& _registers);

        bool run_instruction();
        bool is_halted();
        void set_pc(uint8_t address);

        void reset();


};

#endif
