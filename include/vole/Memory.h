#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>

#include "Screen.h"

using namespace std;

class Memory {

    private:
        vector <uint8_t> cells;
        Screen& screen;
        
    public:
        Memory(Screen& screen);
        
        void write(uint8_t val, uint8_t address); // Write a cell to memory
        uint8_t read(uint8_t address); // Read a cell from memory

        void show();
        
        void reset();

};

#endif
