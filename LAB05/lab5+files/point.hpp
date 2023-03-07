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

The declared functions include:
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
// make sure to provide file-level documentation and function-level
// documentation for each function that you'll implement to avoid
// unnecessary grade deductions.

////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace hlp2 {
	
class Point {
public:
	// declare constructors (3)
	/*
 	* @brief Constructs a Point object with x and y coordinates set to 0.0.
 	*/
	Point() ;

	/*
 	* @brief Constructs a point object with given x and y coordinates.
 	* @param x_coord The x coordinate of the point.
 	* @param y_coord The y coordinate of the point.
 	*/
	Point(double x_coord, double y_coord);
	
	/*
 	* @brief Constructs a Point object with specified x and y coordinates
 	* @param coordinates An array of two doubles, where the first value is x coordinate and second is y coordinate
 	*/
	Point(double *coordinates);
	// declare overloaded operators (8 member functions)
	
	/*
	@brief Overloads the square bracket operator to access the x and y coordinates of a Point object
	This operator allows a Point object to be treated like an array, where the first element corresponds to the x coordinate
	and the second element corresponds to the y coordinate.
	@param index The index of the coordinate to access (0 for x, 1 for y)
	@return A reference to the corresponding x or y coordinate
	*/
	double& operator[](const int index);

	/*
	@brief Overloaded operator that provides access to the coordinates of the point object as an array.
	This operator is declared as a constant member function and returns a constant reference to a double value.
	It allows accessing the x and y coordinates of the Point object by using the [] operator, just like an array.
	@param _index The index of the coordinate to be accessed (0 for x, 1 for y).
	@return A constant reference to the corresponding coordinate.
	*/
	const double& operator[](const int _index) const;

	/*
	@brief Overloading the "+=" operator to add a point to another point.
	@param coordinates The point to be added to the current point.
	@return Reference to the current point after addition.
	*/
	Point& operator+= (Point coordinates);

	/*
	@brief Overloading the "+=" operator to add a value to another point.
	@param value The value to be added to the current point.
	@return Reference to the current point after addition.
	*/
	Point& operator+= (double value);

	/*
	@brief Overloading the "++" operator to prefix increment a point.
	@return Reference to the current point after addition.
	*/
	Point& operator++();

	/*
	@brief Overloading the "++" operator to postfix increment a point.
	@return Reference to the current point after addition.
	*/
	Point  operator++(int);

	/*
	@brief Overloading the "--" to prefix decrement a point.
	@return Reference to the current point after subtraction.
	*/
	Point& operator-- ();

	/*
	@brief Overloading the "--" to postfix decrement a point.
	@return Reference to the current point after subtraction.
	*/
	Point operator-- (int);
private:
	double x; // The x-coordinate of a Point
	double y; // The y-coordinate of a Point
};
  
// declare 15 non-member, non-friend functions 
/*
@brief Rotation
@param coordinates and degree
@return  current point after rotation.
*/
Point operator% (const Point coordinates, const double degree);

/*
@brief distance between 2 points
@param 2 coordinates 
@return double distance.
*/
double operator/ (const Point pt1, const Point pt2);

/*
@brief midpoint between 2 points
@param 2 coordinates 
@return the midpoint
*/
Point operator^ (const Point pt1, const Point pt2);

/*
@brief dotproduct between 2 points
@param 2 coordinates 
@return dotproduct
*/
double operator* (const Point _p1, const Point _p2);

/*
@brief overload scalar between 2 points
@param 2 coordinates 
@return scaled point
*/
Point operator* (const Point coordinates, const double value);

/*
@brief overload scalar between 2 points
@param 2 coordinates 
@return scaled point
*/
Point operator* (const double value, const Point coordinates);

 /*
@brief "<<" operator to output a point in the format (x, y)
@param coordinates and output stream 
@return refernce to the output stream
*/    
std::ostream& operator<<(std::ostream& os, Point const& coordinates);

 /*
@brief ">>" operator to input a point in the format (x, y)
@param coordinates and input stream 
@return refernce to the input stream
*/ 
std::istream& operator>>(std::istream& is, Point& coordinates);

 /*
@brief add 2 pooints
@param 2 coordinates 
@return point
*/ 
Point operator+ (const Point pt1, const Point pt2);

/*
@brief add pooints by value
@param coordinates and value 
@return point
*/ 
Point operator+ (const Point coordinates, const double value);

/*
@brief add pooints by value
@param coordinates and value 
@return point
*/ 
Point operator+ (const double value, const Point coordinates);

 /*
@brief subtract 2 points
@param 2 coordinates 
@return point
*/ 
Point operator- (const Point pt1, const Point pt2);

 /*
@brief subtract 2 points
@param subtract coordinates by value
@return point
*/ 
Point operator- (const Point coordinates, const double value);

 /*
@brief subtract 2 points
@param subtract coordinates by value
@return point
*/ 
Point operator- (const double value, const Point coordinates);

 /*
@brief negate the points
@param coordinates 
@return point
*/ 
Point operator- (const Point coordinates);
} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
