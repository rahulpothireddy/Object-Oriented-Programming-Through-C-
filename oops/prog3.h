
   
#ifndef PROG3_ASSIGNMENT // Defiing the values if not defined previously.
#define PROG3_ASSIGNMENT // Defining the program.
#include <iostream>  // Header files used for the program execution.
#include <string>
#include <fstream>
using namespace std;
const string small_alphabet="abcdefghijklmnopqrstuvwxyz"; //Declaring the default values as constant for variables.
const string cap_alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string input_file_path="/home/cs689/progs/17f/p3/prog3.d2"; // Specifying the path of the file.
void process_infile(int); // Subroutine for printing the output of the program.
string encodeCaesarCipher(string,int); // Subroutine for taking the input for the program.
int new_position(char,int); // Subroutine to change and shift the ascii value.
#endif
