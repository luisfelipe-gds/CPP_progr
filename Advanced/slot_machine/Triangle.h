/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: This class is a derived class from the Shape class. It
 * represents a Triangle shape. It has a custom constructor and overrides the
 * getWidth(), getHeight(), areaGeo() and draw() methods from the Shape class.
 * It also has abstract methods that are not implemented in this class.
 *
 * ***************************************************************************
 */

#pragma once
#include "Shape.h"

class Triangle : public Shape
{
protected:
	int width;
	int height;

public:
	Triangle(int width); //custom constructor
	
	Triangle(int width, char pen, string name); //custom constructor

	int getWidth() const;
	virtual void setWidth(int width) = 0;

	int getHeight() const;
	virtual void setHeight(int height) = 0;

	double areaGeo() const override; // returns the geometric area of this shape

	virtual double perimeterGeo() const = 0; // abstract method - returns the geometric perimeter of this shape

	virtual int areaTxt() const = 0; // abstract method - returns the textual area of this shape

	virtual int perimeterTxt() const = 0; // abstract method - returns the textual perimeter of this shape

	virtual Canvas draw() const = 0; // abstract method - draws the shape on a canvas
};
