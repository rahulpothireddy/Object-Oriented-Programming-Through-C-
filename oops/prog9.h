/*********************************************************
Name		: Thummala Rahul Reddy
Zid		: z1795447
Assignment	: 10
Due Date	: 11/15/2016
Description	: Header file to make the calculator
*********************************************************/

#ifndef CALCI_H              /* header guards*/
#define CALCI_H             /* header guards*/


/* header files for various basic input output functions */

using namespace std;

#include<string>
#include<iomanip>
#include<stack>
#include<sstream>
#include<iostream>
#include<math.h>
#include<cstdlib>


void process_token(const string &token,stack<double> &S);   /*function prototype for process_token()*/
bool unarySign(const char &c,const string &token, const unsigned &i); /*function prototype for unarySign()*/
bool floatPoint(const char &c,const string &token, const unsigned &i); /*function prototype for floatPoint()*/
double getNumber(const string &token,unsigned &i,const bool &floatPointFlag); /*function prototype for getNumber()*/
bool isValidOperator(const char &c);                /*function prototype for isValidOperator()*/
double operation(const char &c,const double &x,const double &y);/*function prototype for operation()*/
double popStack(stack<double> &S); /*function prototype for popStack()*/
void emptyStack(stack<double> &S); /*function prototype for emptyStack()*/
void printResult(const stack<double> &S);           /*function prototype for printResult()*/

double stringToDouble( string s);                   /*function prototype for stringToDouble()*/


#endif                          /* header guards*/
