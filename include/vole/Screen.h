#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <cstdint>

using namespace std;

class Screen {

    private:
        string output = "";

    public:
        void write(uint8_t val);
        void display();
        void reset();

};

#endif