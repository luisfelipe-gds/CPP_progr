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
 * Class Description: The SlotMachine class is a class that represents a slot
 * machine. Once the game is running, the slot machine generates random shapes
 * and draws them on the screen. The player has 10 tokens to play. The player
 * wins tokens if the shapes drawn on the screen match certain conditions.
 * The game ends when the player runs out of tokens.
 *
 * ***************************************************************************
 */

#pragma once

#include "Canvas.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include <random>
#include <array>
using std::array;

class SlotMachine
{
private:
	int tokens; // saves the state of the player's tokens

public:
	// default constructor
	SlotMachine(int tokens = 10);

	// run
	void run();

	// generate random int between lower and upper
	int genRandomInt(int lower, int upper);

	// get max height
	int getMaxHeight(const array<Canvas, 3>& can);

	// check many win cases
	int checkWin(const array<std::unique_ptr<Shape>, 3>& shapePtr);
};
