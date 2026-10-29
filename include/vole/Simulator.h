#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Screen.h"
#include "Machine.h"

class Simulator {

    private:
        Screen screen;
        Machine machine;

    public:

        Simulator();
        
        void show_main_menu();
        void run();
        void reset();

};

#endif