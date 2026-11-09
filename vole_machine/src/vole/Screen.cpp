#include <string>
#include "../../include/vole/Screen.h"

using namespace std;

void Screen::write(uint8_t val) {
    output += to_string(val);
}

void Screen::display() {
    cout << "++++++++++++ SCREEN OUTPUT ++++++++++++" << endl;
    cout << endl << output << endl;
}

void Screen::reset() {
    output.clear();
}