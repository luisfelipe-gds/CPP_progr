/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: The Rhombus class is a derived class from the Shape class.
 * The class represents a rhombus shape. The class has a diagonal, and all methods
 * to calculate the area and perimeter of the shape. The class also has methods
 * to calculate the number of characters in the textual representation of the shape
 * and to draw the shape on a canvas.
 *
 * ***************************************************************************
 */

#include "Rhombus.h"

 // Custom constructor receiving diagonal
Rhombus::Rhombus(int diagonal)
	: Shape("Diamond", '*'),
	  diagonal(diagonal)
{
	if (diagonal % 2 == 0)
	{ 
		this->diagonal += 1;
	}
	else
	{
		this->diagonal = diagonal;
	}
	this->diagonal = this->diagonal;
}

// Custom constructor receiving diagonal, name, and pen
Rhombus::Rhombus(int diagonal, char pen, string name)
	: Shape(name, pen),
	diagonal(diagonal)
{
	if (diagonal % 2 == 0)
	{
		this->diagonal += 1;
	}
	else
	{
		this->diagonal = diagonal;
	}
	this->diagonal = this->diagonal;
}

// getWidth()
int Rhombus::getWidth() const
{
	return diagonal;
}

// setWidth(int)
void Rhombus::setWidth(int diagonal)
{
	this->diagonal = diagonal;
}

// getHeight()
int Rhombus::getHeight() const
{
	return diagonal;
}

// setHeight(int)
void Rhombus::setHeight(int diagonal)
{
	this->diagonal = diagonal;
}

// areaGeo()
double Rhombus::areaGeo() const
{
	return pow(diagonal, 2) / 2.0;
}

// perimeterGeo()
double Rhombus::perimeterGeo() const
{
	return (2 * std::sqrt(2)) * diagonal;
}

// areaTxt()
int Rhombus::areaTxt() const
{
	double n = diagonal / 2;
	return 2 * n * (n + 1) + 1;
	 
}

// perimeterTxt()
int Rhombus::perimeterTxt() const
{
	if (diagonal == 1)
		return 1;
	else
		return 2 * (diagonal - 1);
}

// draw()
Canvas Rhombus::draw() const
{
	// Draw an empty canvas with the size of the diagonal
	Canvas can(diagonal, diagonal);
	can.setFrame_ver(' ');
	can.setFrame_hor(' ');
	can.setFrame_cor(' ');

	// Set middle, lower, and upper variables
	// to draw the rhombus
	int mid = getHeight() / 2;
	int lower = mid;
	int upper = mid;

	// iterate through the canvas and draw the rhombus
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			// If the position is within the rhombus, draw the pen
			if (j >= lower && j <= upper)
			{
				can.put(i + 1, j + 1, getPen());
			}
		}
		// If the position is within the middle, increase the lower and decrease the upper
		if (i < mid)
		{
			lower--;
			upper++;
		}
		// If the position is within the lower half, increase the lower and decrease the upper
		else
		{
			lower++;
			upper--;
		}
	}
	return can;
}
