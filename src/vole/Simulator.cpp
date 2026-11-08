#include <iostream>
#include <exception>

#include "../../include/vole/Simulator.h"
#include "../../include/Utilities.h"

using namespace std;

Simulator::Simulator() : screen(), machine(screen) {}

void Simulator::show_load_program_menu() {

    string program_path = read_file_path();
    uint8_t start_address = read_address();

    system("cls");

    try {

        if (machine.load_program(start_address, program_path)) {
            show_success_message("Program has been loaded successfully!");
        }

    } catch (const exception& e) {
        show_error_message(e.what());
    }

}

void Simulator::show_run_line_by_line_menu() {

    int choice = 1;

    do {

        system("cls");

        if (machine.is_halted()) {

            cout << "HALT instruction encountered!" << endl;
            cout << "Program execution has stopped." << endl;
            cout << endl;

            system("pause");

            return;

        }

        cout << "\n========== STEP-BY-STEP EXECUTION ==========\n";

        cout << "1. Execute Next Instruction" << endl;
        cout << "2. Show Machine State" << endl;
        cout << "3. Display Screen Output" << endl;
        cout << "4. Return to Main Menu" << endl;

        cout << endl;
        choice = read_choice("Enter an option: ", "invalid option!", 1, 4);

        switch (choice) {

            case 1:
                system("cls");
                if (machine.step()) show_success_message("Instruction has been executed!");
                system("pause");
                break;

            case 2:
                system("cls");
                machine.show_status();
                system("pause");
                break;
            
            case 3:
                system("cls");
                screen.display();
                system("pause");
                break;

            case 4:
                return;

            default:
                ;

        }

    } while (choice != 4);

}

void Simulator::show_run_program_menu() {

    if (!machine.is_program_loaded) {
        show_error_message("program file isn't loaded!");
        system("pause");
        return;
    }

    cout << " 1. Run the whole program.\n";
    cout << " 2. Run line by line.\n";

    cout << endl;

    short choice = read_choice("Enter an option: ", "invalid option!", 1, 2);

    switch (choice) {

        case 1: {
            
            system("cls");

            bool run = machine.run_program();

            if (run) { show_success_message("Program has been executed successfully!"); }
            else { show_error_message("program running has been failed!"); } 

            system("pause");

            break;

        }

        case 2:
            system("cls");
            show_run_line_by_line_menu();
            break;

        default:
            ;

    }

}

void Simulator::perform_main_menu_choice(short choice) {

    switch (choice) {

        case 1:
            system("cls");
            show_load_program_menu();
            system("pause");
            break;
        
        case 2:
            system("cls");
            show_run_program_menu();
            break;
        
        case 3:
            system("cls");
            screen.display();
            system("pause");
            break;

        case 4:
            system("cls");
            machine.show_status();
            system("pause");
            break;

        case 5:
            system("cls");
            this->reset();
            show_success_message("Simulator has been successfully reset!");
            system("pause");
            break;

        case 6:
            return;
        
        default:
            ;

    }

}

void Simulator::show_main_menu() {

    cout << "========================================================\n";
    cout << "\t\t\tVOLE MACHINE\n";
    cout << "========================================================\n";
    cout << " 1. Load Progarm File" << endl;
    cout << " 2. Run Program" << endl;
    cout << " 3. View Screen Output" << endl;
    cout << " 4. View Machine State" << endl;
    cout << " 5. Reset Simulator" << endl;
    cout << " 6. Exit" << endl;
    cout << "========================================================\n";

}

void Simulator::run() {

    short choice = 1;

    do {

        system("cls");

        show_main_menu();

        choice = read_choice(" Enter an option: ", "invalid option!", 1, 6);
        perform_main_menu_choice(choice);

    } while (choice != 6);

}

void Simulator::reset() {

    screen.reset();
    machine.reset();

}