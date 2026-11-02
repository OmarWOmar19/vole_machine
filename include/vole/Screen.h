#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <cstdint>

using namespace std;
class Screen
{
    string output;
public:

    void write(uint8_t val)
    {
        output += (char)val;
    }
void reset(){
    output.clear();
}
void display(){
   cout << output<< endl;


}
#endif
