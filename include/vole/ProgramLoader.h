#ifndef PROGRAMLOADER_H
#define PROGRAMLOADER_H

#include <vector>
#include <cstdint>
#include <fstream>
#include <string>

using namespace std;

class ProgramLoader {

    public:
        bool load_program(const string& program_file, uint8_t start_address);
        bool validate_program(const vector <uint16_t>& program);

};

#endif
