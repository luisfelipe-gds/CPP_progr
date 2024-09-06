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
 * Class Description: The RightTriangle class is a derived class from the Triangle
 * class, which is derived from tha Shape class. The class represents a right 
 * triangle shape. The class has a width and all methods to calculate the area
 * and perimeter of the shape. 
 *
 * ***************************************************************************
 */
#pragma once
#include "Shape.h"
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
	RightTriangle(int width); //custom constructor
	
	RightTriangle(int width, char pen, string name = "Ladder"); // custom constructor

	int getWidth() const;
	void setWidth(int width);

	int getHeight() const;
	void setHeight(int height);

	double perimeterGeo() const override; // calculates the geometric perimeter of the shape

	int areaTxt() const override; // calculates the number of characters in the textual area of the shape

	int perimeterTxt() const override; // determines the number of characters in the textual perimeter of the shape

	Canvas draw() const override; // draws the shape on a canvas
};