
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
/************************************************************Rectangle ******************************************************************************/
Rectangle:: Rectangle(const double& l,const double& w):length(l),width(w){}

Rectangle::Rectangle(const Rectangle& r):length(r.length),width(r.width){} //copy constructor

Rectangle& Rectangle::operator=(const Rectangle& r)    //assignment operator
{
	   length=r.length;
		width=r.width;
	   return *this;
}

Rectangle& Rectangle::operator+=(const Rectangle& r)   //overloaded append operator +=
{
		length+=r.length;
		width+=r.width;
	    return *this;
}

Rectangle::~Rectangle(){} //destructor

double Rectangle::area() const
{
	double a;
	a=length*width;                //finding the area of the rectangle
	return a;
}
double Rectangle::perimeter() const
{
	double p;
	p=2*(length+width);        //finding the perimeter of the rectangle
	return p;
}

void Rectangle::print() const
{
	cout<<" length = "<<length<<" : "<<"width = "<<width;
}

/********************************************************************Traingle*************************************************************/
Triangle:: Triangle(const double& a,const double& b,const double& c):a(a),b(b),c(c){}

Triangle::Triangle(const Triangle& t):a(t.a),b(t.b),c(t.c){} //copy constructor

Triangle& Triangle::operator=(const Triangle& t)   //assignment operator
	{
	  a=t.a;
	  b=t.b;
	  c=t.c;
	return *this;
			}
	Triangle& Triangle::operator+=(const Triangle& t) //overloaded append operator +=
	{
		a+=t.a;
		b+=t.b;
		c+=t.c;	
		return *this;
	}

Triangle::~Triangle(){}   //destructor

double Triangle::perimeter() const
	{
	double p;
	p=a+b+c;                                       //finding the perimeter of the traingle
	return p;
	}

	double Triangle::area() const
	{
		double k,i;                     // finding the area for  traingle
		k=(a+b+c)/2;
		i=sqrt(k*(k-a)*(k-b)*(k-c));
		return i;
	}
	void Triangle::print() const
	{
		cout<<" a = "<<a<<" b = "<<b<<" c = "<<c;
	}
	
	
/**********************************************************************Circle************************************************************/
	
	
	Circle:: Circle(const double& r):radius(r){}

	Circle::Circle(const Circle& c):radius(c.radius)  {} //copy constructor

	Circle& Circle::operator=(const Circle& r)    //assignment operator
	{
		radius=r.radius;
		return *this;
	}

	Circle& Circle::operator+=(const Circle& r)  //overloaded append operator +=
	{
		
	radius+=r.radius;
	return *this;	
	}
	Circle::~Circle(){}    //destructor

	double Circle::perimeter() const
	{                                         //finding the perimeter of the circle
		double p;
		p=2*(PI)*(radius);
		return p;
	}

	double Circle::area() const
	{
		double a;                        // finding the area for circle
		a=(PI)*(radius)*(radius);
		return a;
	}

	void Circle::print() const
	{
		cout<<" radius = "<<radius;
	}
	
	/*********************************************************Equilateral Traingle*************************************************************/
	equTriangle::equTriangle(const double& e)
	{
		a=e;
		b=e;
		c=e;
	}
	equTriangle::equTriangle(const equTriangle& i)  //copy constructor
	{
		a=i.a;
		b=i.a;
		c=i.a;
	}
	equTriangle& equTriangle::operator=(const equTriangle& e)  //assignment operator
	{
		a=e.a;
		b=e.b;
		c=e.c;
		return *this;
	}
	equTriangle& equTriangle::operator+=(const equTriangle& r)  //overloaded append operator +=
	{
		a=a+r.a;
		b=b+r.b;
		c=c+r.c;
		return *this;
	}
	equTriangle::~equTriangle(){}

	double equTriangle::perimeter() const
	{
		double p;                                         //finding the perimeter of the equiletral traingle
		p=Triangle::perimeter();
		return p;
	}
	double equTriangle:: area() const
	{
		double i;                                  // finding the area for equilateral traingle
		i=Triangle::area();
		return i;
	}
	void equTriangle::print() const
	{
		cout<<" length = "<<a;
	}
	
	/***********************************************************Right angle traingle*****************************************************/
	rightTriangle::rightTriangle(const double& g,const double& f)
	{
		a=g;
		b=f;
		c=sqrt(g*g+f*f);
	}
	rightTriangle::rightTriangle(const rightTriangle& i)  //copy constructor
	{
		a=i.a;
		b=i.a;
		c=i.a;
	}
	rightTriangle& rightTriangle:: operator=(const rightTriangle& r)  //assignment operator
	{
		a=r.a;
		b=r.b;
		c=r.c;
		return *this;
	}
	
	rightTriangle& rightTriangle:: operator+=(const rightTriangle& r)   //overloaded append operator +=
	{
		a=a+r.a;
		b=b+r.b;
		c=c+r.c;
		return *this;
	}
	rightTriangle::~rightTriangle(){}  //destructor

	double rightTriangle::perimeter() const
	{
		double p;                                          //finding the perimeter of the right traingle
		p=Triangle::perimeter();
		return p;
	}
	double rightTriangle::area() const
	{
		double i;
		i=Triangle::area();                   // finding the area for rightangle traingle
		return i;
	}
	void rightTriangle::print() const
	{
		cout<<" length = "<<a<<" : height = "<<b;
	}
	
	/**********************************************************************Square *********************************************************/
	Square::Square(const double& s)
	{
		length=s;
		width=s;
	}
	Square::Square(const Square& a)   //copy constructor
	{
		length=a.length;
		width = a.width;
	}
	Square& Square::operator+=(const Square& s)  //overloaded append operator +=
	{
	
	length+=s.length;
	width+=s.width;
	return *this;
	}
	
	Square& Square::operator=(const Square& s)  //assignment operator
	{
	
		length=s.length;
		width=s.width;
	    return *this;
		
	}
	Square::~Square(){}

	double Square::perimeter() const
	{                                                     //finding the perimeter of the square
		double p;
		p=Rectangle::perimeter();
		return p;
	}
	double Square::area() const
	{
		double a;                    // finding the area for the square
		a=Rectangle::area();
		return a;
	}
	void Square::print() const
	{
		cout<<" length = "<<length;
	}
	
	
