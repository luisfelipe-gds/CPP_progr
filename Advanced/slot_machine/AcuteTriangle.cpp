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
 * Class Description: The AcuteTriangle class is a derived class from the
 * Triangle class, which is a derived class from the Shape class. The class
 * represents an acute triangle shape. The class has a width and all methods 
 * to calculate the area and perimeter of the shape.
 *
 * ***************************************************************************
 */

#include "AcuteTriangle.h"

// Custom constructor
AcuteTriangle::AcuteTriangle(int width)
	: Triangle(width, '*', "Wedge") // Call the base class constructor
{
	// Check if the width is even, if so, add 1 to make it odd
	if (width % 2 == 0)
	{
		this->width += 1;
	}
	else
	{
		this->width = width;
	}
	this->height = (width + 1) / 2;
}

// Custom constructor
AcuteTriangle::AcuteTriangle(int width, char pen, string name)
	: Triangle(width, pen, name) // Call the base class constructor
{
	// Check if the width is even, if so, add 1 to make it odd
	if (width % 2 == 0)
	{
		this->width += 1;
	}
	else
	{
		this->width = width;
	}
	this->height = (width + 1) / 2;
}

// getWidth()
int AcuteTriangle::getWidth() const
{
	return width;
}

// setWidth(int)
void AcuteTriangle::setWidth(int width)
{
	this->width = width;
	this->height = (width + 1) / 2; // Recalculate the height
}

// getHeight()
int AcuteTriangle::getHeight() const
{
	return height;
}

// setHeight(int)
void AcuteTriangle::setHeight(int height)
{
	this->height = height;
	this->width = height * 2 - 1; // Recalculate the width
}

// perimeterGeo()
double AcuteTriangle::perimeterGeo() const
{
	return width + sqrt(pow(width, 2) + (4 * pow(height, 2)));
}

// areaTxt()
int AcuteTriangle::areaTxt() const
{
	return pow(height, 2);
}

// perimeterTxt()
int AcuteTriangle::perimeterTxt() const
{
	if (height == 1 || width == 1) // Special case, single character
	{
		return 1;
	}
	else
	{
		return 4 * (height - 1);
	}
}

// draw()
Canvas AcuteTriangle::draw() const
{
	// Create a new canvas
	Canvas can(height, width);
	can.setFrame_ver(' ');
	can.setFrame_hor(' ');
	can.setFrame_cor(' ');

	// loop through the canvas and draw the triangle
	// by checking if each point is inside the triangle's
	// boundaries, which are defined by the height and width
	// of the triangle
	for (int i = 0; i < height + 1; i++)
	{
		for (int j = 0; j < width + 1; j++)
		{
			if (j > height - i && j < height + i )
			{
				can.put(i, j, pen);
			}
		}
	}
	return can;
}

