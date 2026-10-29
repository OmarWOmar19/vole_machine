#ifndef PC_H
#define PC_H

#include <cstdint>

class PC {

    private:
        uint8_t value = 0x00;

    public:
        uint8_t get();
        
        void set(uint8_t _value);
        void increment(uint8_t amount);

};

#endif