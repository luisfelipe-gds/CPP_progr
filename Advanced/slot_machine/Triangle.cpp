/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 4 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Due Date: July 27th, 2024
 * ***************************************************************************
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

#include "Triangle.h"
 // Custom constructor
Triangle::Triangle(int width)
	: Shape("Triangle", '*'), // delegate to the base class constructor
	width(width),
	height(width)
{}

// Custom constructor
Triangle::Triangle(int width, char pen, string name)
	: Shape(name, pen), // delegate to the base class constructor
	width(width),
	height(width)
{}

// getWidth()
int Triangle::getWidth() const
{
	return width;
}

// getHeight()
int Triangle::getHeight() const
{
	return height;
}

// areaGeo()
double Triangle::areaGeo() const
{
	return (width * height) / 2.0;
}

