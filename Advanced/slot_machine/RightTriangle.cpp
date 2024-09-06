/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: The RightTriangle class is a derived class from the Triangle
 * class, which is derived from tha Shape class. The class represents a right 
 * triangle shape. The class has a width and all methods to calculate the area
 * and perimeter of the shape. 
 *
 * ***************************************************************************
 */
#include "RightTriangle.h"

// Custom constructor
RightTriangle::RightTriangle(int width) 
	: Triangle(width, '*', "Ladder") // Delegates to the base class constructor
{}

// Custom constructor
RightTriangle::RightTriangle(int width, char pen, string name) 
	: Triangle(width, pen, name) // Delegates to the base class constructor
{}

// getWidth()
int RightTriangle::getWidth() const
{
	return width;
}

// setWidth(int)
void RightTriangle::setWidth(int width)
{
	this->width = width;
	this->height = width; // The height is always equal to the width
}

// getHeight()
int RightTriangle::getHeight() const
{
	return height;
}

// setHeight(int)
void RightTriangle::setHeight(int height)
{
	this->height = height;
	this->width = height; // The width is always equal to the height
} 

// perimeterGeo()
double RightTriangle::perimeterGeo() const
{
	return (2+sqrt(2)) * height;
}

// areaTxt()
int RightTriangle::areaTxt() const
{
	return height * (height + 1) / 2;
}

// perimeterTxt()
int RightTriangle::perimeterTxt() const
{
	if (height == 1) // Special case - a single character
	{
		return 1;
	}
	else
	{
		return 3 * (height - 1);
	}
}

// draw()
Canvas RightTriangle::draw() const
{
	// Create a canvas with the right dimensions
	Canvas can( height, width );
	can.setFrame_ver(' ');
	can.setFrame_hor(' ');
	can.setFrame_cor(' ');

	// Iterate over the canvas and draw the right triangle
	// by selecting half of the canvas
	for (int i = 0; i < height + 1; i++)
	{
		for (int j = 0; j < width + 1 ; j++)
		{
			if (j <= i)
			{
				can.put(i, j, pen);
			}
		}
	}
	return can;
}
