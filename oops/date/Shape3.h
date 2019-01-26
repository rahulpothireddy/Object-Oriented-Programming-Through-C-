//suresh balusu/z1787540/assign10/csci 689-001/anthony schroeder/due:4/20/2016 
#include "Shape.h"
#include "Shape2.h"
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
	
class Box : public Rectangle
{
private:
double height;
public:
Box(const double& =0,const double& =0, const double& =0);
Box(const Box&);
Box& operator=(const Box&);
Box& operator+=(const Box&);
~Box();
double perimeter() const;
double area() const;
double volume() const;
void print() const;
};

class Cube : public Square
{
public:
Cube(const double& =0);
Cube(const Cube&);
Cube& operator=(const Cube&);
Cube& operator+=(const Cube&);
~Cube();
double perimeter() const;
double area() const;
double volume() const;
void print() const;
};

class Cylinder : public Circle
{
private:
double height;
public:
Cylinder(const double& =0,const double& =0);
Cylinder(const Cylinder&);
Cylinder& operator=(const Cylinder&);
Cylinder& operator+=(const Cylinder&);
~Cylinder();
double perimeter() const;
double area() const;
double volume() const;
void print() const;
};

class Cone : public Circle
{
private:
double height;
public:
Cone(const double& =0,const double& =0);
Cone(const Cone&);
Cone& operator=(const Cone&);
Cone& operator+=(const Cone&);
~Cone();
double perimeter() const;
double area() const;
double volume() const;
void print() const;
};

class Sphere : public Circle
{
public:
Sphere(const double& =0);
Sphere(const Sphere&);
Sphere& operator=(const Sphere&);
Sphere& operator+=(const Sphere&);
~Sphere();
double area() const;
double volume() const;
};

class Tetrahedron : public equTriangle
{
public:
Tetrahedron(const double& =0);
Tetrahedron& operator=(const Tetrahedron&);
Tetrahedron& operator+=(const Tetrahedron&);
Tetrahedron(const Tetrahedron&);
~Tetrahedron();
double perimeter() const;
double area() const;
double volume() const;
};

