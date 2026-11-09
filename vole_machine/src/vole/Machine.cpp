#include <filesystem>
#include <iostream>

#include "../../include/vole/Machine.h"
#include "../../include/Utilities.h"

using namespace std;

Machine::Machine(Screen& _screen) : memory(_screen), cpu(memory, registers) {}

bool Machine::load_program(uint8_t start, const string& program_path) {

    filesystem::path file_path(program_path);

    if (exists(file_path)) {

        bool load = loader.load_program(program_path, start, memory);

        if (load) {
            cpu.reset();
            cpu.set_pc(start);
            is_program_loaded = true;
            return true;
        } else {
            throw invalid_argument("machine could not load program");
        }

    } else {
        throw invalid_argument("file does not exist");
    }

}

bool Machine::run_program() {

    while (!cpu.is_halted()) {

        bool run = cpu.run_instruction();

        if (!run) {
            show_error_message("compilation error!");
            return false;
        }

    }

    return true;

}

bool Machine::is_halted() {
    return cpu.is_halted();
}

bool Machine::step() {

    bool step = cpu.run_instruction();

    if (!step) {
        show_error_message("compilation error");
        return false;
    }

    return true;

}

void Machine::show_status() {

    cout << "Memory: \n\n";

    memory.show();

    cout << "________________________________________\n\n";

    cout << "Registers: \n\n";

    registers.show();

}

void Machine::reset() {

    memory.reset();
    registers.reset();
    cpu.reset();

    is_program_loaded = false;

}