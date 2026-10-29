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

        bool load_program(uint8_t start, const string& program_file);
        
        void run_program();
        void step();
        
        void reset();

};

#endif
