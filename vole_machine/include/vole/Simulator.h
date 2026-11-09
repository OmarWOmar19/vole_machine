#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Screen.h"
#include "Machine.h"

class Simulator {

    private:
        Screen screen;
        Machine machine;

        void perform_run_line_menu_choice(short choice);
        void perform_main_menu_choice(short choice);

        void show_load_program_menu();
        void show_run_line_by_line_menu();
        void show_run_program_menu();
        void show_main_menu();

    public:
        Simulator();

        void run();
        void reset();

};

#endif