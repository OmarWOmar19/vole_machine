#include <iomanip>
#include <iostream>

#include "../../include/vole/Memory.h"

using namespace std;

Memory::Memory(Screen& _screen) : cells(256, 0), screen(_screen) {}

void Memory::write(uint8_t val, uint8_t address) {

    // Check if user write to cell with address [0xFF] to write this value to screen
    if (address == static_cast<uint8_t>(0xFF)) {
        screen.write(val);
    }

    if (address < cells.size()) {
        cells[address] = val;
    }

}

uint8_t Memory::read(uint8_t address) {

    if (address < cells.size()) {
        return cells[address];
    }

    return 0;

}

void Memory::reset() {
    fill(cells.begin(), cells.end(), 0);
}

void Memory::show() {

    cout << setfill(' ');
    cout << dec; // Reset from hex to decimal (normal)

    cout << setw(4) << left << "Cell" << " | " << setw(5) << "Value" << endl;

    cout << endl;

    for (int start = 0; start < 256; start++) {

        cout << setfill(' ');
        cout << dec; // Reset from hex to decimal (normal)

        cout << showbase << setw(4) << hex << setfill('0') << static_cast<int>(start);
        cout << "   ";
        cout << showbase << setw(4) << hex << setfill('0') << static_cast<int>(cells[start]);
        cout << endl;

    }

    cout << setfill(' ');
    cout << dec; // Reset from hex to decimal (normal)

}
