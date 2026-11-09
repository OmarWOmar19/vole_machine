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

    cout << setfill(' ');
    cout << dec; // Reset from hex to decimal (normal)

    cout << setw(4) << left << "R" << " | " << setw(5) << "Value" << endl;

    cout << endl;

    for (int start = 0; start < 16; start++) {

        cout << setfill(' ');
        cout << dec; // Reset from hex to decimal (normal)

        cout << setw(4) << start;
        cout << "   ";
        cout << showbase << setw(4) << hex << setfill('0') << static_cast<int>(vals[start]);
        cout << endl;
    
    }

    cout << setfill(' ');
    cout << dec; // Reset from hex to decimal (normal)

}