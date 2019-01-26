#ifndef SIMPLE_H
#define SIMPLE_H
#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<iomanip>

using std::stack;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;
using std::cerr;


void process_token ( const string &token, stack<double> &d );
bool unarySign ( const char& c, const string& token, const unsigned& i );
bool floatPoint ( const char& c, const string& token, const unsigned& i );
double getNumber ( const char& c, const string& token, unsigned& i, const bool& f );
string stringToDouble (const string& token);
bool isValidOperator ( const char& c );
double operation ( const char& c, const double& a, const double& b );
double popStack ( stack < double >& d );
void printResult ( const stack < double >& d );
void emptyStack ( stack < double >& d );

#endif

