/* NAME : MRUDULA SUNDRU
   ZID : Z1808014
   COURSE : CSCI 689
   SECTION : 1
   DUE DATE : 09/30/2016 */

#ifndef PROG5_ASSIGNMENT // Defiing the values if not defined previously.
#define PROG5_ASSIGNMENT // Defining the program.
#include <iostream> // header files used for program execution.
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void buildMineField(vector<vector<bool> >& mines, const double& mineProb); // Subroutine to determine the location of mines in mine table.
void fixCounts(const vector <vector <bool> >& mines, vector <vector <unsigned> >& counts); // Subroutine to check the boolean value for each location.
void displayMineLocations(const vector <vector <bool> >& mines); // Subroutine to display the table for mine field on output console.
void displayMineCounts(const vector < vector <unsigned> >& counts); // Subroutine to display the table for the mine count.

#endif
