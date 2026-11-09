#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <cstdint>
#include <vector>
#include <cstdint>

using namespace std;

void show_error_message(const string& message);
void show_success_message(const string& message);

bool is_whitespace_only(const string& str);

string left_trim(string str);
string right_trim(string str);
string trim(string str);

vector <uint16_t> convert_file_to_vector(const string& file_path);

int read_number(const string& prompt);
int read_choice(const string& prompt, const string& error_message, int from, int to);
string read_file_path();
uint8_t read_address();

#endif