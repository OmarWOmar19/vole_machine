#ifndef PROGRAMLOADER_H
#define PROGRAMLOADER_H

#include <vector>
#include <cstdint>
#include <string>

#include "Memory.h"

using namespace std;

class ProgramLoader {

    private:
        bool validate_program(const vector <uint16_t>& program);
    public:
        bool load_program(const string& program_path, uint8_t start_address, Memory& memory);

};

#endif