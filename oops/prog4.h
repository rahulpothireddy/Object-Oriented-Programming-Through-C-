#ifndef PROG4_ASSIGNMENT // Defiing the values if not defined previously.
#define PROG4_ASSIGNMENT // Defining the program.
#include <iostream>  // Header files used for the program execution.
#include <string>
#include <fstream>
using namespace std;
const string INF="/home/cs689/progs/16f/p4/prog4-in.cc"; // Specifying the path of the input file.
const string OUTf="prog4-out.cc"; // Specifying the path of the output file.
void open_files(ifstream& is, ofstream& os); // Subroutine used to open the files for computation.
void process_data(ifstream& is, ofstream& os); // Subroutine used to compute the data for deleting the comments in a file.
void close_files(ifstream& is, ofstream& os); // Subroutine used to close the opened files after computation.
#endif
