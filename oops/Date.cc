//satyanarayana kotha
//z1805662
//assignment6
//due date:10th oct
#include"Date.h"
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<cstdlib>

Date::Date()
{
    month="January";
    day=1;      // assigning the default values
    year=2000;
}
Date::Date(const string &m,const int &d,const int &y)
{
    month=m;
    day=d;            // constructor to create date object for month date and year
    year=y;
    Month();
}
void Date::setMonth(const string &m)
{
    month=m;
    Month();      // accessor method to set month
}
void Date::setDay(const int &d)
{
    day=d;     //accessor method to set day
}
void Date::setYear(const int &y)
{
    year=y;   //accessor method to set year
}
string Date::getMonth() const
{
    return month;  // accessor method to get month
}
int Date::getDay() const
{
    return day;    // accessor method to get day
}
int Date::getYear() const
{
    return year;  // accessor method to get year
}
void Date::Month()
{
    char c;
    c=month[0];
    if(isalpha(c)) //to check the alphabet
        month[0]=toupper(c); // to convert the first character to uppercase
    for(unsigned i=1;i<month.length();i++)
    {
        char c=month[i];
        if(isalpha(c))
            month[i]=tolower(c); //to convert the rest of the month component to lowercase
    }
}
bool Date:: isValidMonth() const//validate month entered
{
    if(isValidDate()){
    if(month=="January")
    {
            return true;                                     
    }   
    else if(month=="February")
    {
            return true;                                 
        
    }
    else if(month=="March")
    {
            return true;
    }
    else if(month=="April")
    {
            return true;
    }
    else if(month=="May")
    {
            return true;
    }
    else if(month== "June")
    {
            return true;
    }
    else if(month=="July")
    {
            return true;
    }
    else if(month=="August")
    {
       /*validates days*/
            return true;
    }
    
    else if(month=="September")
    {
            return true;
    }
    else if(month== "October")
    {
            return true;
    }
    
    else if(month=="November")
    {
            return true;
    }
    else if(month=="December")
    {
            return true;
    }
    
    else return false;
}return false;}
int  Date::daysInMonth(const string& month)const//returns days in every month
{
    if(month=="January")
    {
        return 31;
    }
    
    else if(month=="February")
    {
        if(isLeapYear()==true)
            return 29;                                // for february in a leap year there are 29 days and for non leap year there are 28 days
        else if(isLeapYear()==false)
            return 28;
    }
    
    else if(month=="March")
    {
            return 31;
    }
    
    else if(month=="April")
    {
            return 30;
    }
    else if(month=="May")
    {
            return 31;
    }
    else if(month== "June")
    {
            return 30;
    }
    else if(month=="July")
    {
            return 31;
    }
    else if(month=="August")
    {
        /*validates days*/
            return 31;
    }
    
    else if(month=="September")
    {
            return 30;
    }
    else if(month== "October")
    {
            return 31;
    }
    
    else if(month=="November")
    {
            return 30;
    }
    else if(month=="December")
    {
            return 31;
    }
    else
	 return 0; // to get the correct days in month
}
bool Date::isLeapYear()const
{
    if(year%4==0 && year%100==0 && year%400==0)
        return true;
    else if(year%4==0 && year%100!=0)
        return true;                            // logic to check for leap year
    else
        return false;
}
bool Date::isValidDate() const
{        if(year<1)
    return false;
int days=daysInMonth(month);
if(day<=days)
return true;
return false;
 // to check if it is valid month
}
string Date::intToString(int n) const
{
    ostringstream oss;
    oss << n;               //to take the intiger value and return the value in string
    return oss.str();
}

string Date::toString() const
{
    return intToString(day)+ "-" + month.substr(0,3) + "-" +intToString(year);   // converts the date into string
}
istream& operator>>(istream &is,Date &d)
{
    char  a;
    is>>d.month;      // input operator overloading
    is>>d.day;
    is>>a;
    if(isdigit(a))
        is.unget();
    is>>d.year;
    return is;
}
ostream& operator<<(ostream &os,const Date &d)
{
    os<<d.month<<" "<<d.day<<","<<" "<<d.year;
    return os;      // output operator overloading
}

