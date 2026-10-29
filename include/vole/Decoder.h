#ifndef DECODER_H
#define DECODER_H

#include "Instruction.h"

class Decoder {

    public:
        Instruction decode(uint16_t instruction);

};

#endif