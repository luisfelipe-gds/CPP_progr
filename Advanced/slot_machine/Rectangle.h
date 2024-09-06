/* ***************************************************************************
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

#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	int height;
	int width;
public:
	Rectangle(int height, int width); // custom constructor

	Rectangle(int height, int width, char pen, string name); // custom constructor
	
	int getWidth() const;
	void setWidth(int width);
	
	int getHeight() const;
	void setHeight(int height);
		
	double areaGeo() const override; // returns the geometric area of this shape
	
	double perimeterGeo() const override; // returns the geometric perimeter of this shape
	
	int areaTxt() const override; // determines the number of characters in the textual representation of this shape
	
	int perimeterTxt() const override; // determines the number of characters in the textual representation of this shape
	
	Canvas draw() const override; // draws the shape on the canvas
};
