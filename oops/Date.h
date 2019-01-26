//satyanarayana kotha
//z1805662
//assignment6
//due date:10th oct

#ifndef assignment6_hpp
#define assignment6_hpp

#include <stdio.h>

/* assignment6_hpp */




#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<fstream>

using namespace std;
using std :: cin;
using std :: cout;
using std :: vector;
using std :: endl;
using std :: fstream;
const vector<string> vec {"January","February","March","April","May","June","July","August","September","October","November","December"};



class Date
{
    
    friend istream& operator>>(istream &is, Date &d);
    friend ostream& operator<<(ostream &os, const Date &d);
    
    
public:
    Date();
    Date(const string &m,const int &d,const int &y);
    void setMonth(const string &m);
    void setDay(const int &d);
    void setYear(const int&y);
    string getMonth() const;
    int getDay() const;
    int getYear() const;
    void Month();
    bool isValidDate()const;
    string toString()const;
private:
    
    string month;
    int day;
    int year;
    bool isValidMonth()const;
    int daysInMonth(const string& m)const;
    bool isLeapYear()const;
    string intToString(int n) const;
};
#endif
