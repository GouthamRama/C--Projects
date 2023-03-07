/*!************************************************************************
\file point.hpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Programming Lab #05
\date 05-02-2023
\brief
The aim of this lab is to practice with the design and implementation of an ADT using C++ concepts
such as classes, objects, constructors, and operator overloading. Further, the lab emphasizes
improved data encapsulation through a preference for non-member functions over friend
functions. The task is to define a type Point that can be used by clients to represent points in a
two-dimensional Cartesian coordinate system. 

The defined functions include:
overloaded constructors
overloaded operators -
Subscript operator to access the x or y coordinate values by index (0 or 1)
"+=" operator to add two points or a point and a value
"++" operator to increment both x and y coordinates of a point by 1
"--" operator to decrement both x and y coordinates of a point by 1
"%" operator to perform a rotation operation on a point with a given degree
"/" operator to calculate the Euclidean distance between two points
"^" operator to calculate the midpoint between two points
"*" operator to perform a dot product between two points or a scalar multiplication with a value

non-friend functions-
"+" operator to add two points or a point and a value
"<<" operator to output a point in the format (x, y)
">>" operator to input a point in the format (x, y)
and others to perform various operations such as rotation, distance calculation, midpoint calculation, and scalar multiplication.

**************************************************************************/
// Since your clients will not have access to this file, your initial
// inclination will be to avoid documenting this file ...
// However, since you're a client too and will need to understand this
// file's contents at a later point in time, the documentation you provide
// now will make the process of maininting this code base easier and more
// efficient.
// Therefore, make sure to provide file-level documentation and some
// function-level documentation for each function that you'll implement to
// avoid unnecessary grade deductions.

#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt

///////////////////////////////////////////////////////////////////////////////
// declare private stuff here [if any] in this anonymous namespace ...
namespace {
     double const PI {3.14159265358979323846};

}

///////////////////////////////////////////////////////////////////////////////

namespace hlp2 {

// define 3 constructors
/*!***********************************************************************
\brief
Contructor of class Point.
*************************************************************************/
Point::Point()
{
    x = 0;
    y = 0;

}

/*!***********************************************************************
\brief
Parameterized constructor of class Point.
\param[in] _v1
The first value of the x component of the class Point
\param[in] _v2
The first value of the y component of the class Point
*************************************************************************/
Point::Point(double _v1, double _v2)
{
    x = x_coord;
    y = x_coord;
}

/*!***********************************************************************
\brief
Parameterized constructor of class Point.
\param[in] *_value
A pointer to the values to initialise the x and y components of the class 
Point
*************************************************************************/
Point::Point(double* _coordinates)
{
    x = _value[0];
    y = _value[1];
}

// define 8 member functions
/*!***********************************************************************
\brief
Subscript operator to access the member variable
\param[in] _index
index 0 to access x, index 1 to access y
\return
A referance of the member varaible.
*************************************************************************/
double& Point::operator[](const int _index)
{
    return _index == 0 ? this->x : this->y;
}

/*!***********************************************************************
\brief
Subscript operator to access the member variable
\param[in] _index
index 0 to access x, index 1 to access y
\return
A constant referance of the member varaible.
*************************************************************************/
const double& Point::operator[] (const int _index) const
{
    return _index == 0 ? this->x : this->y;
}

/*!***********************************************************************
\brief
Add to operator to add a point to the member variables of a object of 
class Point.
\param[in] _point
The Point to be added.
\return
A referance to the object of class Point.
*************************************************************************/
Point& Point::operator+= (Point _point)
{
    x += _point.x;
    y += _point.y;
    return *this;
}

/*!***********************************************************************
\brief
Add to operator to add a double to the member variables of a object of 
class Point.
\param[in] _value
The double to be added.
\return
A referance to the object of class Point.
*************************************************************************/
Point& Point::operator+= (double _value)
{
    x += _value;
    y += _value;
    return *this;
}

/*!***********************************************************************
\brief
Prefix increment operator to increment member variables of a 
object of class Point.
\return
A referance to the object of class Point.
*************************************************************************/
Point& Point::operator++ ()
{
    ++x;
    ++y;
    return *this;
}

/*!***********************************************************************
\brief
Prefix decrement operator to increment member variables of a 
object of class Point.
\return
A referance to the object of class Point.
*************************************************************************/
Point& Point::operator-- ()
{
    --x;
    --y;
    return *this;
}

/*!***********************************************************************
\brief
Postfix increment operator to increment member variables of a 
object of class Point.
\param int
To let the compiler know that this is a postfix increment operator.
\return
A referance to the object of class Point.
*************************************************************************/
Point Point::operator++ (int)
{
    const Point temp = *this;
    ++(*this);
    return temp;
}

/*!***********************************************************************
\brief
Postfix decrement operator to increment member variables of a 
object of class Point.
\param int
To let the compiler know that this is a postfix decrement operator.
\return
A referance to the object of class Point.
*************************************************************************/
Point Point::operator-- (int)
{
    Point temp; 
    temp.x = x;
    temp.y = y;

    --x;
    --y;
    return temp;
}

// define 15 non-member, non-friend functions

/*!***********************************************************************
\brief
Return Point obtained by rotating Point by double
degrees.
\param[in] constant Point _point
The Point to be rotated.
\param[in] constant double _degree
The degrees to rotate the point by.
\return
An object of class Point.
*************************************************************************/
Point operator% (const Point _point, const double _degree)
{
    Point temp;
    temp[0] = (cos(_degree * PI/180.0) * _point[0]) - (sin(_degree * M_PI/180.0) * _point[1]);
    temp[1] = (sin(_degree * PI/180.0) * _point[0]) + (cos(_degree * M_PI/180.0) * _point[1]);
    temp[0] = (temp[0] > -0.00001 && temp[0] < 0.00001) ? 0.0 : temp[0];
    temp[1] = (temp[1] > -0.00001 && temp[1] < 0.00001) ? 0.0 : temp[1];
    return temp;
}

/*!***********************************************************************
\brief
Return distance between two Points.
\param[in] constant Point _p1
One of the points to find the distance between.
\param[in] constant Point _p2
One of the points to find the distance between.
\return
The distance between the two points.
*************************************************************************/
double operator/ (const Point _p1, const Point _p2)
{
    Point dist;
    dist[0] = _p1[0] - _p2[0];
    dist[1] = _p1[1] - _p2[1];
    double distance = sqrt(dist[0] * dist[0] + dist[1] * dist[1]);
    return distance;
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by adding two Points.
\param[in] constant Point _p1
One of the points to add.
\param[in] constant Point _p2
One of the points to add.
\return
An object of type class Point with added values of the two points.
*************************************************************************/
Point operator+ (const Point _p1, const Point _p2)
{
    Point temp;
    temp[0] = _p1[0] + _p2[0];
    temp[1] = _p1[1] + _p2[1];
    return temp; 
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by adding a Point and a double.
\param[in] constant Point _point
The points to add.
\param[in] constant double _value
The double to add.
\return
An object of type class Point with added values of the points and double.
*************************************************************************/
Point operator+ (const Point _point, const double _value)
{
    Point temp;
    temp[0] = _point[0] + _value;
    temp[1] = _point[1] + _value;
    return temp;
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by adding a Point and a double.
\param[in] constant double _value
The double to add.
\param[in] constant Point _point
The points to add.
\return
An object of type class Point with added values of the points and double.
*************************************************************************/
Point operator+ (const double _value, const Point _point)
{
    Point temp;
    temp[0] = _point[0] + _value;
    temp[1] = _point[1] + _value;
    return temp;
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by subtracting a Point by a Point.
\param[in] constant Point _p1
The point to be subtracted.
\param[in] constant Point _p2
The point to be subtracted by.
\return
An object of type class Point with subtracted values between the two points.
*************************************************************************/
Point operator- (const Point _p1, const Point _p2)
{
    Point temp;
    temp[0] = _p1[0] - _p2[0];
    temp[1] = _p1[1] - _p2[1];
    return temp; 
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by subtracting a Point's member 
variable by a double.
\param[in] constant Point _point
The point to be subtracted.
\param[in] constant double _value
The double to be subtracted by.
\return
An object of type class Point with the values of a Point subtracted by a 
double.
*************************************************************************/
Point operator- (const Point _point, const double _value)
{
    Point temp;
    temp[0] = _point[0] - _value;
    temp[1] = _point[1] - _value;
    return temp;
}

/*!***********************************************************************
\brief
Returns a object of class Point obtained by subtracting a double by a 
Point's member variables.
\param[in] constant double _value
The double to be subtracted by.
\param[in] constant Point _point
The point to be subtracted by.
\return
An object of type class Point with the values of a double subtracted by a 
Point.
*************************************************************************/
Point operator- (const double _value, const Point _point)
{
    Point temp;
    temp[0] = _value - _point[0];
    temp[1] = _value - _point[1];
    return temp;
}

/*!***********************************************************************
\brief
Return Point obtained by negating operand's coordinates.
\param[in] constant Point _point
The Point to be negated.
\return
An object of type class Point with the values the negated Point.
*************************************************************************/
Point operator- (const Point _point)
{
    Point temp;
    temp[0] = _point[0] * -1;
    temp[1] = _point[1] * -1;
    return temp;
}

/*!***********************************************************************
\brief
Return Point midway between two Point s.
\param[in] constant Point _p1
One of the points to calculate the mid point.
\param[in] constant Point _p2
One of the points to calculate the mid point.
\return
A object of type class Point with the values of the midpoint.
*************************************************************************/
Point operator^ (const Point _p1, const Point _p2)
{
    Point mid;
    mid[0] = (_p1[0] + _p2[0]) / 2.f;
    mid[1] = (_p1[1] + _p2[1]) / 2.f;
    return mid;
}

/*!***********************************************************************
\brief
Return double representing dot or scalar product of two
Point operands.
\param[in] constant Point _p1
One of the points to find the dot product of.
\param[in] constant Point _p2
One of the points to find the dot product of.
\return
The dot product of two points.
*************************************************************************/
double operator* (const Point _p1, const Point _p2)
{
    double temp = _p1[0]*_p2[0] + _p1[1]*_p2[1];
    return temp; 
}

/*!***********************************************************************
\brief
Return Point obtained by scaling Pointand double operands.
\param[in] constant Point _point
The Point to be scaled.
\param[in] constant double _value
The double to be scaled by.
\return
A object of type class Point with the values of the scaled point.
*************************************************************************/
Point operator* (const Point _point, const double _value)
{
    Point temp;
    temp[0] = _point[0] * _value;
    temp[1] = _point[1] * _value;
    return temp;
}

/*!***********************************************************************
\brief
Return Point obtained by scaling Point and double operands.
\param[in] constant double _value
The double to be scaled by.
\param[in] constant Point _point
The Point to be scaled.
\return
A object of type class Point with the values of the scaled point.
*************************************************************************/
Point operator* (const double _value, const Point _point)
{
    Point temp;    
    temp[0] = _point[0] * _value;
    temp[1] = _point[1] * _value;
    return temp;
}

/*!***********************************************************************
\brief
Writes to output stream coordinates of Point in format (x, y).
\param[in] ostream reference _os
The reference to the output stream.
\param[in] constant Point reference _point
The reference to the Point to be outputted.
\return
The reference of the output stream.
*************************************************************************/
std::ostream& operator<<(std::ostream& _os, Point const& _point) {
  _os << "(" << _point[0] << ", " << _point[1] << ")";
  return _os;
}

/*!***********************************************************************
\brief
Reads two doubles as Point from input stream.
\param[in] istream reference _os
The reference to the input stream.
\param[in] constant Point reference _point
The reference of the point to write to.
\return
The reference of the input stream.
*************************************************************************/
std::istream& operator>>(std::istream& _is, Point& _point) {
  _is >> _point[0] >> _point[1];
  return _is;
}

} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace {
}