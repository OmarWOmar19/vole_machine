#include <string>
#include <sstream>
#include <iostream>

#include "../../include/vole/Screen.h"

using namespace std;

void Screen::write(uint8_t val) {

    stringstream ss; 
    ss << "0x" << hex << uppercase << static_cast<int>(val) << "\n";

    output += ss.str();

}

void Screen::display() {

    cout << "\n========== SCREEN OUTPUT ==========\n\n";

    if (output.empty()) {
        cout << "(empty)\n";
    } else {
        cout << output << '\n';
    }

    cout << "\n===================================\n";

}

void Screen::reset() {
    output.clear();
}