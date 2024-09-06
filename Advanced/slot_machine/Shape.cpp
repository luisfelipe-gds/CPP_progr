/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: The Shape class is an abstract class that represents a
 * geometric shape. The class has a name, a pen character, and an identifier.
 * Apart from the getters and setters, all methods are pure virtual and must
 * be implemented by the derived classes. 
 * 
 * ***************************************************************************
 */

#include "Shape.h"

// Static member to keep track of the number of shapes created
int Shape::idCounter = 0;

// Custom constructor
Shape::Shape(string name, char pen)
	: name(name), pen(pen), id(++idCounter) {}

// getName()
string Shape::getName() const
{
	return name;
}

// setName(string)
void Shape::setName(string name)
{
	this->name = name;
}

// getPen()
char Shape::getPen() const
{
	return pen;
}

// setPen(char)
void Shape::setPen(char pen)
{
	this->pen = pen;
}

// getId()
int Shape::getId() const
{
	return id;
}

// toString()
string Shape::toString() const {
    std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getId() << "\n";
    oss << "Shape name: " << getName() << "\n";
    oss << "Pen character: " << getPen() << "\n";
    oss << "Height: " << getHeight() << "\n";
    oss << "Width: " << getWidth() << "\n";
    oss << "Textual area: " << areaTxt() << "\n";
    oss << "Geometric area: " << std::fixed << std::setprecision(2) << areaGeo() << "\n";
    oss << "Textual perimeter: " << perimeterTxt() << "\n";
    oss << "Geometric perimeter: " << std::fixed << std::setprecision(2) << perimeterGeo() << "\n";
    oss << "Static type: " << typeid(this).name() << "\n";
    oss << "Dynamic type: " << typeid(*this).name() << "\n";
    return oss.str();
}

// Overloading the << operator
ostream& operator<<(ostream& os, const Shape& shape)
{
	os << shape.toString();
	return os;
}

