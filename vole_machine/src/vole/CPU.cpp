#include <stdexcept>

#include "../../include/vole/CPU.h"
#include "../../include/vole/floating_point.h"

using namespace std;

CPU::CPU(Memory& _memory, Registers& _registers) : memory(_memory), registers(_registers) {}

bool CPU::validate_instruction() {

    uint8_t opcode = decoded_instruction.get_opcode();
    uint8_t r = decoded_instruction.get_r();
    uint8_t x = decoded_instruction.get_x();
    uint8_t y = decoded_instruction.get_y();

    switch (opcode) {
        case 0x1: 
        case 0x2:
        case 0x3:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0x9:
        case 0xB:
            return true;

        case 0x4:
            return r == 0;

        case 0xA:
            return x == 0;

        case 0xC:
            return r == 0 && x == 0 && y == 0;

        default:
            return false;
    }

}

bool CPU::is_halted() {
    return halted;
}

void CPU::set_pc(uint8_t address) {
    pc.set(address);
}

bool CPU::run_instruction() {

    uint8_t high_nibble = memory.read(pc.get()), low_nibble = memory.read(pc.get() + 1);
    ir.set((high_nibble << 8) | low_nibble);
    
    decoded_instruction = decoder.decode(ir.get());

    if (!validate_instruction()) {
        return false;
    }
    
    pc.increment(2);

    uint8_t opcode = decoded_instruction.get_opcode();
    uint8_t r = decoded_instruction.get_r();
    uint8_t x = decoded_instruction.get_x();
    uint8_t y = decoded_instruction.get_y();

    uint8_t combined_xy = (x << 4) | y;
    uint8_t S = registers.read(x), T = registers.read(y);
    
    switch (opcode) {

        case 0x1:
            registers.set(memory.read(combined_xy), r);
            break;

        case 0x2:
            registers.set(combined_xy, r);
            break;

        case 0x3:
            memory.write(registers.read(r), combined_xy);
            break;

        case 0x4:
            registers.set(registers.read(x), y);
            break;

        case 0x5:
            registers.set(S + T, r);
            break;

        case 0x6: {

            floating_point first(S), second(T);
            floating_point result = first + second;

            registers.set(result.to_bits(), r);

            break;
        }

        case 0x7:
            registers.set(S | T, r);
            break;

        case 0x8:
            registers.set(S & T, r);
            break;

        case 0x9:
            registers.set(S ^ T, r);
            break;

        case 0xA: {

            if (x != 0) {
                throw runtime_error("invalid rotate right (ROT) instruction");
            }

            uint8_t value = registers.read(r);
            uint8_t amount = y % 8;

            if (amount != 0) {
                value = static_cast<uint8_t>((value >> amount) | (value << (8 - amount)));
            }

            registers.set(value, r);

            break;

        }

        case 0xB: {

            uint8_t address = (x << 4) | y;

            if (registers.read(r) == registers.read(0)) {
                pc.set(address);
            }

            break;
        
        }

        case 0xC:
            halted = true;
            break;

        default:
            return false;

    }

    return true;

}

void CPU::reset() {

    pc.set(0);
    ir.set(0);

    halted = false;

    decoded_instruction = Instruction();

}