#include <iostream>
#include <iomanip>

#include "../../include/vole/Registers.h"

using namespace std;

Registers::Registers() : vals(16, 0) {

}

uint8_t Registers::read(uint8_t address) {
    
    if (address < vals.size()) {
        return vals[address];
    }

    return 0;

}

void Registers::set(uint8_t val, uint8_t address) {
    if (address < vals.size()) {
        vals[address] = val;
    }
}

void Registers::reset() {
    fill(vals.begin(), vals.end(), 0);
}

void Registers::show() {

    cout << "\n========== REGISTERS ==========\n\n";

    for (int row = 0; row < 4; row++) {

        for (int col = 0; col < 4; col++) {
            int index = row + col * 4;
            cout << "R" << hex << uppercase << index << " = " << setw(2) << setfill('0') << static_cast<int>(vals[index]) << "     ";
        }

        cout << '\n';
    }

    // Reset stream formatting
    cout << dec << nouppercase << setfill(' ');
}