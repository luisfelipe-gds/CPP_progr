/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: The Shape class is an abstract class that represents a
 * geometric shape. The class has a name, a pen character, and an identifier.
 * Apart from the getters and setters, all methods are pure virtual and must
 * be implemented by the derived classes. 
 * 
 * ***************************************************************************
 */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <typeinfo>
#include "Canvas.h"
using std::string;
using std::cout;
using std::endl;

class Shape
{
protected:
	string name;
	char pen;
	int id; // unique identifier, to be setup in the constructor

public:
	static int idCounter; // static member to keep track of the number of shapes created

	Shape(string name, char pen); // custom constructor
	
	virtual ~Shape() = default; // virtual destructor

	string getName() const;
	void setName(string name);

	char getPen() const;
	void setPen(char pen);

	int getId() const;
	
	string toString() const; // returns a string representation of this shape

	virtual double areaGeo() const = 0; // returns the geometric area of this shape

	virtual double perimeterGeo() const = 0; // returns the geometric perimeter of this shape

	virtual int areaTxt() const = 0; // determines the number of characters in the textual representation of this shape

	virtual int perimeterTxt() const = 0; // determines the number of characters in the textual representation of the 
										  // perimeter of this shape
	virtual Canvas draw() const = 0;      // draws the shape on the canvas

	virtual int getHeight() const = 0;    // computes and returns the height of the shape

	virtual int getWidth() const = 0;     // computes and returns the width of the shape

};

// overloaded insertion operator
std::ostream& operator<<(std::ostream& out, const Shape& shape);
