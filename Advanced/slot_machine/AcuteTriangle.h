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

#pragma once
#include "Triangle.h"

class AcuteTriangle : public Triangle
{
	public:
	AcuteTriangle(int width); //custom constructor

	AcuteTriangle(int width, char pen, string name); // custom constructor

	int getWidth() const;
	void setWidth(int width);

	int getHeight() const;
	void setHeight(int height);

	double perimeterGeo() const override; // returns the geometric perimeter of this shape

	int areaTxt() const override; // determines the number of characters in the textual area of this shape

	int perimeterTxt() const override; // determines the number of characters in the textual perimeter of this shape

	Canvas draw() const override; // draws the shape on a canvas
};

