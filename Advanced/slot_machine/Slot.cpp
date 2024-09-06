/* ***************************************************************************
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

#include "Slot.h"
using std::cin;

// default constructor
SlotMachine::SlotMachine(int tokens) : tokens{ tokens } {}

// run
void SlotMachine::run()
{
	array<Canvas, 3> reel; // Array of Canvas objects to store the shapes drawn on the screen

	array<std::unique_ptr<Shape>, 3> shapePtr{}; // Array of unique pointers to Shape objects

	int bet = 1;

	// Welcome message
	cout << "Welcome to the 3-Reel Lucky Slot Machine Game! Let's dive in: \n";
	cout << "1. Each reel will randomly display one of four shapes, \n";
	cout << "   each available in 25 different sizes. \n";
	cout << "2. To win 3 times your bet : \n";
	cout << "   Get two similar shapes AND two shapes with equal Textual Areas. \n";
	cout << "3. To win 2 times your bet : \n";
	cout << "   Get three similar shapes. \n";
	cout << "4. To win 1 time your bet : \n";
	cout << "   Ensure that the Textual Area of the middle shape is greater \n";
	cout << "   than the combined Textual Areas of the left and right shapes. \n";
	cout << "5. If you get the same shapes on the left and right, you neither win nor lose. \n";
	cout << "6. Otherwise, unfortunately, you lose your bet. \n";
	cout << "7. You start with 10 free slot tokens! \n";
	cout << endl;

	// Main loop
	while (tokens > 0 && bet != 0)
	{
		while (true)
		{
			// Prompt the user for a bet
			cout << "How much would you like to bet (enter 0 to quit)? \n";
			cin >> bet;

			// Check if the input is a valid integer
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input! Please enter a valid integer. \n";
				cout << endl;
				continue;
			}

			// Check if the bet is whithin the valid range
			if (bet < 0 || bet > tokens)
			{
				cout << "Invalid bet! Please enter a bet between 0 and " << tokens << endl;
				cout << endl;
				continue;
			}

			// if the bet is zero, break the loop and quit the game
			if (bet == 0)
			{
				cout << "Thank you for playing! \n";
				return;
			};

			// if the bet is valid, break the loop
			break;
		}

		// Generate the shapes
		for (int i = 0; i < 3; i++)
		{
			int n = genRandomInt(0, 3);  // 0 = Rhombus, 1 = AcuteTriangle, 2 = RightTriangle, 3 = Rectangle
			int w = genRandomInt(1, 25); // Width of the shape

			// create the shapes and set them in the shapePtr array
			if (n == 0)
			{
				shapePtr[i] = std::make_unique<Rhombus>(w);
			}
			else if (n == 1)
			{
				shapePtr[i] = std::make_unique<AcuteTriangle>(w);
			}
			else if (n == 2)
			{
				shapePtr[i] = std::make_unique<RightTriangle>(w);
			}
			else
			{
				int h = genRandomInt(1, 25);
				shapePtr[i] = std::make_unique<Rectangle>(h, w);
			}

			reel[i] = shapePtr[i]->draw();
		}

		// Print the shapes
		cout << endl;
		cout << "Left Shape: \n";
		cout << endl;
		cout << (*shapePtr[0]) << endl;
		cout << "Middle Shape: \n";
		cout << endl;
		cout << (*shapePtr[1]) << endl;
		cout << "Right Shape: \n";
		cout << endl;
		cout << (*shapePtr[2]) << endl;

		// Print the payLine
		Canvas spaceCanvas = Canvas(getMaxHeight(reel), 1, ' ');
		Canvas payLine = reel[0];
		payLine += spaceCanvas;
		payLine += reel[1];
		payLine += spaceCanvas;
		payLine += reel[2];
		cout << payLine << endl;

		// Check for a win
		int win = checkWin(shapePtr);

		// Print the result
		if (win == 3)
		{
			cout << "Two similar shapes and two shapes with equal Textual Areas! \n";
			cout << "Congratulations! You win 3 times your bet: " << bet * 3 << endl;
			tokens += 3 * bet;
			cout << "You now have " << tokens << " tokens. \n";
		}
		else if (win == 2)
		{
			cout << "Three similar shapes \n";
			cout << "Congratulations! You win 2 times your bet: " << bet * 2 << endl;
			tokens += 2 * bet;
			cout << "You now have " << tokens << " tokens. \n";
		}
		else if (win == 1)
		{
			cout << "Middle > Left + Right, in Textual Areas \n";
			cout << "Congratulations! You win your bet: " << bet << endl;
			tokens += bet;
			cout << "You now have " << tokens << " tokens. \n";
		}
		else if (win == 0)
		{
			cout << "Same shapes on the left and right! \n";
			cout << "You neither win nor lose! \n";
			cout << "You have " << tokens << " tokens. \n";
		}
		else
		{
			cout << "Sorry, you lose your bet! \n";
			tokens -= bet;
			if (tokens <= 0)
			{
				cout << "You just ran out of tokens. Better luck next time! \n";
				cout << "Game Over! \n";
				break;
			}
			else
			{
				cout << "You now have " << tokens << " tokens. \n";
			}
		}
	}
}

// genRandomInt()
int SlotMachine::genRandomInt(int lower, int upper)
{
	// Create a random device and use it to seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	// Create a distribution in the range [lower, upper]
	std::uniform_int_distribution<> distrib(lower, upper);

	// Generate and return a random number in the specified range
	return distrib(gen);
}

// getMaxHeight()
int SlotMachine::getMaxHeight(const array<Canvas, 3>& can)
{
	for (int i = 0; i < 3; i++)
	{
		if (can[i].getRows() > can[(i + 1) % 3].getRows())
		{
			if (can[i].getRows() > can[(i + 2) % 3].getRows())
			{
				return can[i].getRows();
			}
			else
			{
				return can[(i + 2) % 3].getRows();
			}
		}
	}
}

// checkWin()
int SlotMachine::checkWin(const array<std::unique_ptr<Shape>, 3>& shapePtr)
{
	int win = 0;

	// Check for two similar shapes and two shapes with equal Textual Areas
	if ( (typeid(*shapePtr[0]) == typeid(*shapePtr[1]) ||
		  typeid(*shapePtr[1]) == typeid(*shapePtr[2]) ||	
		  typeid(*shapePtr[0]) == typeid(*shapePtr[2]))
		&&
		 (shapePtr[0]->areaTxt() == shapePtr[1]->areaTxt() ||
		  shapePtr[1]->areaTxt() == shapePtr[2]->areaTxt() ||
		  shapePtr[0]->areaTxt() == shapePtr[2]->areaTxt()) )
	{
		win = 3;
	}
	// Check for three similar shapes
	else if (typeid(*shapePtr[0]) == typeid(*shapePtr[1]) &&
		     typeid(*shapePtr[1]) == typeid(*shapePtr[2]))
	{
		win = 2;
	}
	// Check for the Textual Area of the middle shape is greater than the combined Textual Areas of the left and right shapes
	else if (shapePtr[1]->areaTxt() > shapePtr[0]->areaTxt() + shapePtr[2]->areaTxt())
	{
		win = 1;
	}
	// check for the same shapes on the left and right
	else if (typeid(*shapePtr[0]) == typeid(*shapePtr[2]))
	{
		win = 0;
	}
	// Otherwise, unfortunately, you lose your bet
	else
	{
		win = -1;
	}

	return win;
}
