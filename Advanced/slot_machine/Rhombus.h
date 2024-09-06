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
 * Class Description: The Rhombus class is a derived class from the Shape class.
 * The class represents a rhombus shape. The class has a diagonal, and all methods
 * to calculate the area and perimeter of the shape. The class also has methods
 * to calculate the number of characters in the textual representation of the shape
 * and to draw the shape on a canvas.
 *
 * ***************************************************************************
 */

#pragma once
#include "Shape.h"

class Rhombus : public Shape
{
private:
	int diagonal;
	 
public:
	Rhombus(int diagonal); // custom constructor

	Rhombus(int diagonal, char pen, string name); // custom constructor

	int getWidth() const;
	void setWidth(int diagonal);

	int getHeight() const;
	void setHeight(int diagonal);

	double areaGeo() const override; // calculate the area of the shape

	double perimeterGeo() const override; // calculate the perimeter of the shape

	int areaTxt() const override; // calculate the number of characters in the textual representation of the shape

	int perimeterTxt() const override; // calculate the number of characters in the textual representation of the shape

	Canvas draw() const override; // draw the shape on a canvas
};
