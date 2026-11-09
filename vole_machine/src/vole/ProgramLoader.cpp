#include <iostream>
#include <exception>

#include "../../include/vole/ProgramLoader.h"
#include "../../include/Utilities.h"

bool ProgramLoader::validate_program(const vector <uint16_t>& v_program_lines, uint8_t start_address) {

    const size_t required_cells = v_program_lines.size() * 2;
    const size_t available_cells = 0xFF - start_address;

    if (required_cells > available_cells) {
        throw runtime_error("program exceeds memory capacity");
    }   

    if (v_program_lines.empty()) {
        throw runtime_error("program file is empty!");
    }

    if (v_program_lines.size() > 128) {
        throw overflow_error("program file size takes over 256 cells!");
    }

    return true; 

}

bool ProgramLoader::load_program(const string& program_path, uint8_t start_address, Memory& memory) {

    vector <uint16_t> v_program_lines;

    try {
        v_program_lines = convert_file_to_vector(program_path);
    } catch (const exception& e) {
        show_error_message(e.what());
        return false;
    }

	uint8_t high_nibble, low_nibble;
	int program_counter = start_address;

    try {

        if (validate_program(v_program_lines, start_address)) {
            // Load Program Instructions To Memory Cells
            for (int i = 0; i < v_program_lines.size(); i++) {

                high_nibble = (v_program_lines[i] >> 8) & 0xFF;
                low_nibble = v_program_lines[i] & 0xFF;

                memory.write(high_nibble, program_counter);
                memory.write(low_nibble, program_counter + 1);

                program_counter += 2;

            }
        }

    } catch (const exception& e) {
        show_error_message(e.what());
        return false;
    }

    return true;

}