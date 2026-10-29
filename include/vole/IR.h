#ifndef IR_H
#define IR_H

#include <cstdint>

class IR {

    private:
        uint16_t value = 0x0000;

    public:
        uint16_t get();
        void set(uint16_t _value);

};

#endif