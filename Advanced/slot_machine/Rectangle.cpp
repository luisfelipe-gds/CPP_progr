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
 * Class Description: The Rectangle class is a class that represents a
 * rectangle shape object. It has a height and a width. The rectangle can be 
 * drawn on a canvas. The class implements all abstract methods of the base
 * class Shape.
 *
 * ***************************************************************************
 */

#include "Rectangle.h"

// Custom constructor receiving width and height
Rectangle::Rectangle(int height, int width)
	: Shape("Door", '*'), // delegate to the custom constructor of the base class
	  width(width), 
	  height(height) {}

// Custom constructor receiving width, height, name, and pen
Rectangle::Rectangle(int height, int width, char pen, string name)
	: Shape(name, pen), // delegate to the custom constructor of the base class
	  width(width), 
	  height(height) {}

// getWidth()
int Rectangle::getWidth() const
{
	return width;
}

// setWidth(size_t)
void Rectangle::setWidth(int width)
{
	this->width = width;
}

// getHeight()
int Rectangle::getHeight() const
{
	return height;
}

// setHeight(size_t)
void Rectangle::setHeight(int height)
{
	this->height = height;
}

// areaGeo()
double Rectangle::areaGeo() const
{
    return width * height;
}

// perimeterGeo()
double Rectangle::perimeterGeo() const
{
	return 2 * (width + height);
}

// areaTxt()
int Rectangle::areaTxt() const
{
	return width * height;
}

// perimeterTxt()
int Rectangle::perimeterTxt() const
{
	if (width == 1 || height == 1) // if it is a line
		return width * height;
	else
		return 2 * (width + height) - 4;
}

// draw()
Canvas Rectangle::draw() const
{
	// create a canvas with the rectangle's height and width
	Canvas can(height, width); 
	can.setFrame_ver(' ');
    can.setFrame_hor(' ');
	can.setFrame_cor(' ');

	// draw the rectangle 
    for (int i = 0; i < getHeight() + 1; i++)
	{
		for (int j = 0; j < getWidth() + 1; j++)
		{
			can.put(i, j, getPen());
		}
	}
	return can;
}

