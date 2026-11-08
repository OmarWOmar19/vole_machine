#ifndef MACHINE_H
#define MACHINE_H

#include "Memory.h"
#include "Registers.h"
#include "CPU.h"
#include "ProgramLoader.h"
#include "Screen.h"

#include <cstdint>
#include <string>

using namespace std;

class Machine {

    private:
        Memory memory;
        Registers registers;
        CPU cpu;
        ProgramLoader loader;

    public:
        Machine(Screen& screen);
        
        bool is_program_loaded = false;

        bool load_program(uint8_t start, const string& program_path);

        bool run_program();
        bool step();

        bool is_halted();

        void show_status();

        void reset();

};

#endif