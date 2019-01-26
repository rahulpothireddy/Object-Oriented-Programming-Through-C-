#include "Shape3.h"
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

/*************************************************************************Box*******************************************************************/
Box::Box(const double& l,const double& w, const double& h)
{
length=l;
width=w;
height=h;
}
Box::Box(const Box& b)   //copy constructor
{
	length = b.length;
	width = b. width;
	height =b.height;
}
Box& Box::operator=(const Box& b)   //assignment operator
{
	length = b.length;
	width = b. width;
	height =b.height;
     return *this;
	}
Box& Box::operator+=(const Box& b)  //overloaded append operator +=
{
	length =length+b.length;
	width =width+b. width;
	height =height+b.height;
     return *this;
}

Box::~Box(){}        //destructor

double Box::perimeter() const
{
    Rectangle::perimeter();
	return 0;
}

double Box::area() const
{
    double a,b,c;
    a=Rectangle::perimeter();             // finding the area for the box
    b=Rectangle::area();
    c=2*b+height*a;
	return c;
}

double Box:: volume() const
{
	double a,v;
	a=Rectangle::area();                   //finding the volume of the box
	v=height*a;
	return v;
}

void Box::print() const
{
	cout<<" length = "<<length<<" : width = "<<width<<" : height = "<<height;
}




/************************************************************************Cylinder*************************************************/
Cylinder::Cylinder(const double& a,const double& b)
{
radius=a;
height=b;
}
Cylinder::Cylinder(const Cylinder& c)  //copy constructor
{
	 radius=c.radius;
     height=c.height;
}
Cylinder& Cylinder::operator=(const Cylinder& c)   //assignment operator
{
	radius=c.radius;
     height=c.height;
     return *this;
	}
Cylinder& Cylinder::operator+=(const Cylinder& c)  //overloaded append operator +=
{
	radius=radius+c.radius;
     height=radius+c.height;
     return *this;
}

Cylinder::~Cylinder(){}    //destructor

double Cylinder::perimeter() const
{                                                              //finding the perimeter of the cylinder
    Circle::perimeter();
	return 0;
}

double Cylinder::area() const
{
    double a;
    double b;
	double c;
    a=Circle::area();                              // finding the area for the cylinder
	c=Circle::perimeter();
    b=2*a+height*c;
	return b;
}

double Cylinder:: volume() const
{
	double a,v;                                         //finding the volume of the cylinder
	a=Circle::area();
	v=height*a;
	return v;
}

void Cylinder::print() const
{
	cout<<" radius = "<<radius<<" : height = "<<height;
}

/**************************************************************************Cube ******************************************************/
Cube::Cube(const double& l)
{
length=l;
width=l;
}

Cube::Cube(const Cube& c)  //copy constructor
{
	length = c.length;
	width = c.width;
	
}
Cube& Cube::operator=(const Cube& c)   //assignment operator
{
	length = c.length;
	width = c.width;
	return *this;
	}
Cube& Cube::operator+=(const Cube& c)  //overloaded append operator +=
{
	length =length+c.length;
	width =width+c.width;
	 return *this;
}

Cube::~Cube(){}        //destructor

double Cube::perimeter() const
{                                                             //finding the perimeter of the cube
    Square::perimeter();
	return 0;
}

double Cube::area() const
{
    double a;
    double b;                                     // finding the area for the cube
    a=Square::area();
    b=6*a;
	return b;
}

double Cube:: volume() const
{
	double a,v;
	a=Square::area();                       //finding the volume of the cube
	v=length*a;
	return v;
}

void Cube::print() const
{
cout<<" length = "<<length;
}

/**********************************************************Sphere**********************************************************/

Sphere::Sphere(const double& s)
{
radius=s;
}
Sphere::Sphere(const Sphere& s)   //copy constructor
{
	 radius=s.radius;
     
}
Sphere& Sphere::operator=(const Sphere& s)  //assignment operator
{
	radius=s.radius;
     
     return *this;
	}
Sphere& Sphere::operator+=(const Sphere& s)  //overloaded append operator +=
{
	radius=radius+s.radius;
     return *this;
}

Sphere::~Sphere(){}    //destructor

double Sphere::area() const
{
	double ar,sar;
	ar=Circle::area();
	sar=4*ar;                         // finding the area for sphere
	return sar;
}

double Sphere:: volume() const
{
	double ar,vol;
	ar=Circle::area();                        //finding the volume of sphere
	vol=(4*radius*ar)/3;
	return vol;
}

/*********************************************************Cone ************************************************************/
Cone::Cone(const double& r,const double& h)
{
radius=r;
height=h;
}
Cone::Cone(const Cone& c)  //copy constructor
{
	 radius=c.radius;
     height=c.height;
}
Cone& Cone::operator=(const Cone& c)  //assignment operator
{
	radius=c.radius;
	height=c.height;
     return *this;
	}
Cone& Cone::operator+=(const Cone& c)  //overloaded append operator +=
{
	radius=radius+c.radius;
	height=height+c.height;
     return *this;
}

Cone::~Cone()  {}   //destructor


double Cone::perimeter() const
{
    Circle::perimeter();
	return 0;                                    //finding the perimeter of the cone
}

double Cone::area() const
{
	double a,s,l,m;
	a=Circle::area();
	s=sqrt(radius*radius+height*height);
	l=Circle::perimeter();                             // finding the area for the cone
	m=a+(s*l)/2;
	return m;
}

double Cone:: volume() const
{                                                     //finding the volume of the cone
	double a,v;
	a=Circle::area();
	v=(height*a)/3;
	return v;
}

void Cone::print() const
{
	cout<<" radius = "<<radius<<" : height = "<<height;
}


/************************************************************Tetrahedron********************************************************/
Tetrahedron::Tetrahedron(const double& s):equTriangle(s){}

Tetrahedron::Tetrahedron(const Tetrahedron& t):equTriangle(t.a){}  //copy constructor

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& t)  //assignment operator
{
	a= t.a;
	b= t.b;
	c= t.c;
	
return *this;
}
Tetrahedron& Tetrahedron::operator+=(const Tetrahedron& t)  //overloaded append operator +=
{
	a= a + t.a;
	b= b+t.b;
	c= c+t.c;
return *this;
}
Tetrahedron::~Tetrahedron(){}     //destructor

double Tetrahedron::perimeter() const
{                                                       //finding the perimeter of tetrahedron
	equTriangle::perimeter();
	return 0;
}

double Tetrahedron::area() const
{
	double a,b;
	a=equTriangle::area();             // finding the area for the tetrahedron
	b=4*a;
	return b;
}

double Tetrahedron::volume() const
{
	double l,m,n;
	l=(sqrt(2)/sqrt(3))*c;                                     //finding the volume of the tetrahedron
	m=equTriangle::area();
	n=((l*m)/3);
	return n;
}
