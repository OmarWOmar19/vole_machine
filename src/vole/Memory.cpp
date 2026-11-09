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

    cout << "\n========== MEMORY ==========\n\n";

    // Column headers: 0 to F
    cout << "     ";

    for (int col = 0; col < 16; col++) {
        cout << setw(3) << hex << uppercase << col;
    }

    cout << '\n';

    // Memory contents
    for (int row = 0; row < 16; row++) {

        cout << setw(2) << setfill('0') << hex << uppercase << row * 16 << " | ";

        for (int col = 0; col < 16; col++) {

            int address = row * 16 + col;

            cout << setw(2) << setfill('0') << static_cast<int>(cells[address]) << ' ';
        }

        cout << '\n';
    }

    // Reset stream formatting
    cout << dec << nouppercase << setfill(' ');

}
