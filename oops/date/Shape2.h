//suresh balusu/z1787540/assign10/csci 689-001/anthony schroeder/due:4/20/2016 
#include "Shape.h"
#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include <string>

using std :: cout; 
using std :: cin;
using std :: endl;
using std::string;
using std::fixed;
using std::showpoint;



 class Rectangle : public Shape 
 {
	 
    protected:
	double length;
	double width;
	
	public:
	Rectangle(const double& l=0,const double& w=0);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	Rectangle& operator+=(const Rectangle&);
	~Rectangle();
	double perimeter() const;
	double area() const;
	void print() const;
	
};

class Circle : public Shape {
	public:
    double PI=M_PI;
	Circle(const double& r=0);
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	Circle& operator+=(const Circle&);
	~Circle();
	double perimeter() const;
	double area() const;
	void print() const;
	protected:
	double radius;
};

class Triangle : public Shape {
	public:
	Triangle(const double& =0,const double& =0,const double& =0);
	Triangle(const Triangle&);
	Triangle& operator=(const Triangle&);
	Triangle& operator+=(const Triangle&);
	~Triangle();
	double perimeter() const;
	double area() const;
	void print() const;
	protected:
	double a;
	double b;
	double c;
};

class Square : public Rectangle{
	public:
	Square(const double& a=0);
	Square(const Square&);
	Square& operator=(const Square&);
	Square& operator+=(const Square&);
	~Square();
	double perimeter() const;
	double area() const;
	void print() const;
};


class rightTriangle: public Triangle {
	public:
	rightTriangle(const double& g=0,const double& f=0);
	rightTriangle(const rightTriangle&);
	rightTriangle& operator=(const rightTriangle&);
	rightTriangle& operator+=(const rightTriangle&);
	~rightTriangle();
	double perimeter() const;
	double area() const;
	void print() const;
};

class equTriangle: public Triangle{
	public:
	equTriangle(const double& ea);
	equTriangle& operator=(const equTriangle&);
	equTriangle& operator+=(const equTriangle&);
	equTriangle(const equTriangle&);
	~equTriangle();
	double perimeter() const;
	double area() const;
	void print() const;
};

