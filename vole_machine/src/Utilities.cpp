#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cctype>

#include "../include/Utilities.h"

void show_error_message(const string& message) {
    cout << "\a" << "\033[31m" << "Error: " << message << "\033[0m" << "\n";
}

void show_success_message(const string& message) {
    cout << "\a" << "\033[32m" << message << "\033[0m" << "\n";
}

bool is_whitespace_only(const string& str) {
    return str.find_first_not_of(" \t\n\v\f\r") == string::npos;
}

bool is_valid_hex(const string& line) {
	
	for (const char& c : line) {
		if (!isxdigit(c)) {
			return false;
		}
	}
	
	return true;
	
}

string left_trim(string str) {

    size_t counter = 0;

    while (counter < str.length() && str[counter] == ' ') {
        counter++;
    }

    str.erase(0, counter);

    return str;
}

string right_trim(string str) {

    if (str.empty()) {
        return str;
    }

    size_t counter = str.length();

    while (counter > 0 && str[counter - 1] == ' ') {
        counter--;
    }

    str.erase(counter);

    return str;
}

string trim(string str) {
    return right_trim(left_trim(str));
}

vector <uint16_t> convert_file_to_vector(const string& file_path) {

    vector <uint16_t> v_file = {};

    ifstream file;	// Reading mode
	file.open(file_path);
	
	if (!file.is_open()) {
		throw runtime_error("no such file at this specific path!");
	}

    string line = "";
    uint16_t instruction = 0x00;
	short line_counter = 0;

    while (getline(file, line)) {

        line_counter++;

        if (is_whitespace_only(line)) {
            continue;
        }

		size_t pos = line.find(';');

        if (pos != string::npos) {
			line.erase(pos);
		}
		
        line = trim(line);

        if (line.empty()) {
			continue;
        }

        if (line.length() != 4) {
			throw runtime_error("syntax error at line " + to_string(line_counter) + " \'" + line + "\'");
		} 

        if (!is_valid_hex(line)) {
            throw runtime_error("invalid hex code at line "+ to_string(line_counter) + " \'" + line + "\'");
        }

		instruction = static_cast<uint16_t>(stoi(line, nullptr, 16));
        v_file.push_back(instruction);

	}

    file.close();

    return v_file;

}

int read_number(const string& prompt) {

    int number = 0;

    cout << prompt;
    cin >> number;

    while (cin.fail()) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        show_error_message("Error: Invalid input!!!\nPlease Enter a numeric value!!!");

        cout << endl;

        cout << prompt;
        cin >> number;

    }

    return number;

}

int read_choice(const string& prompt, const string& error_message, int from, int to) {

    short choice = 0;

    do {

        choice = read_number(prompt);

        if (!(choice >= from && choice <= to)) {
            show_error_message(error_message);
        }

    } while (!(choice >= from && choice <= to));

    return choice;

}

string read_file_path() {

    string file_path = "";

    cout << "Program File Path: ";
    getline(cin >> ws, file_path);

    return file_path;

}

uint8_t read_address() {

    int start_address;

    cout << "Start Address: ";
    cin >> hex >> start_address;

    return static_cast<uint8_t>(start_address);

}