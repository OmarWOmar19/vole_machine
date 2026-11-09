#ifndef FLOATING_POINT
#define FLOATING_POINT

#include <cstdint>

using namespace std;

class floating_point {

    private:
        uint8_t number;
        float floated_number;

        float to_float(uint8_t _number) const;

    public:
        floating_point(uint8_t _number = 0x00);

        uint8_t to_bits() const;
        floating_point operator+(const floating_point& _other) const;

        float get_float() const;
        void set_float(float _floated_number);

};

#endif