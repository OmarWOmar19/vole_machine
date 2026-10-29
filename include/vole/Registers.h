#ifndef REGISTERS_H
#define REGISTERS_H

#include <vector>
#include <cstdint>

using namespace std;

class Registers {

    private:
        vector <uint8_t> vals;

    public:
        Registers();

        uint8_t read(uint8_t address);
        
        void set(uint8_t val, uint8_t address);
        void reset();

};

#endif
