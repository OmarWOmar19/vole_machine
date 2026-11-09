#include <string>
#include <sstream>

#include "../../include/vole/Screen.h"

using namespace std;

void Screen::write(uint8_t val) {

    stringstream ss; 
    ss << "0x" << hex << uppercase << static_cast<int>(val) << "\n";

    output += ss.str();

}

void Screen::display() {
    cout << "++++++++++++ SCREEN OUTPUT ++++++++++++" << endl;
    cout << endl << output << endl;
}

void Screen::reset() {
    output.clear();
}