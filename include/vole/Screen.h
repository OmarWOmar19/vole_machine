#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <cstdint>

using namespace std;

class Screen {

    private:
        string output = "";

    public:
        void write(uint8_t val){
            output.push_back(static_cast<char>(val)) 
}
        void display()
{             
               cout << output<< endl;

        }
        void reset(){
                     output.clear();}

};

#endif
