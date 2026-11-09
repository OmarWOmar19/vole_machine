#include "../../include/vole/floating_point.h"

#include <cmath>
#include <stdexcept>

float floating_point::to_float(uint8_t _number) const {

    // Zero representation
    if (_number == 0x00) {
        return 0.0f;
    }

    uint8_t sign = (_number >> 7) & 0x01;
    uint8_t exponent = (_number >> 4) & 0x07;
    uint8_t mantissa = _number & 0x0F;

    int actual_exponent = static_cast<int>(exponent) - 4;

    // Mantissa is a binary fraction: .xxxx
    float mantissa_value = static_cast<float>(mantissa) / 16.0f;

    float result = std::ldexp(mantissa_value, actual_exponent);

    if (sign == 1) {
        result = -result;
    }

    return result;
}

floating_point::floating_point(uint8_t _number)
    : number(_number),
      floated_number(to_float(_number)) {
}

uint8_t floating_point::to_bits() const {

    if (floated_number == 0.0f) {
        return 0x00;
    }

    if (!std::isfinite(floated_number)) {
        throw std::invalid_argument("Invalid floating-point value");
    }

    uint8_t sign = (floated_number < 0) ? 1 : 0;

    float magnitude = std::fabs(floated_number);

    int exponent;
    float mantissa = std::frexp(magnitude, &exponent);

    int stored_exponent = exponent + 4;

    if (stored_exponent < 0) {
        return 0x00;
    }

    int stored_mantissa = static_cast<int>(
        std::round(mantissa * 16.0f)
    );

    if (stored_mantissa == 16) {
        stored_mantissa = 8;
        stored_exponent++;
    }

    if (stored_exponent > 7) {
        stored_exponent = 7;
        stored_mantissa = 15;
    }

    return static_cast<uint8_t>(
        (sign << 7) |
        (stored_exponent << 4) |
        stored_mantissa
    );
}

void floating_point::set_float(float _floated_number) {

    if (!std::isfinite(_floated_number)) {
        throw std::invalid_argument("Invalid floating-point value");
    }

    floated_number = _floated_number;
    number = to_bits();
}

float floating_point::get_float() const {
    return floated_number;
}

floating_point floating_point::operator+(const floating_point& _other) const {

    float result = floated_number + _other.floated_number;

    floating_point answer;
    answer.set_float(result);

    return answer;
}