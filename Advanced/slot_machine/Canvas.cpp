/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: The Canvas class is a class that represents a canvas
 * where shapes can be drawn. The canvas is represented by a 2D vector of
 * characters. The canvas has a fill character, a vertical frame character,
 * a horizontal frame character, and a corner frame character. The canvas
 * can be filled with a character, and shapes can be drawn on the canvas.
 * The canvas can be flipped horizontally and vertically, and two canvases
 * can be concatenated. The canvas can be resized by adding or removing rows.
 * 
 * ***************************************************************************
 */

#include "Canvas.h"
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;


// check()
bool Canvas::check(int r, int c) const
{
	return 
		r > 0 &&
		r < grid.size() - 1 &&
		c > 0 && 
		c < grid[0].size() - 1;
}

// Default constructor
Canvas::Canvas()
	: Canvas(10, 10) {}  // delegates to Canvas(10, 10) below

// Custom constructor
Canvas::Canvas(int rows, int columns, char fillChar)
	: grid(rows + 2, vector<char>(columns + 2, fillChar)), fillChar(fillChar)
{
	// draw the edges of the canvas
	setFrame_cor(frame_cor);

	// draw the horizontal edges
	setFrame_hor(frame_hor);

	// draw the vertical edges
	setFrame_ver(frame_ver);
}

// getFillChar()
char Canvas::getFillChar() const
{
	return fillChar;
}

// setFillChar(char)
void Canvas::setFillChar(char ch)
{
	char oldFillChar = fillChar;  // store the old fill character
	fillChar = ch;			      // set the new fill character

	// iterate through the canvas and replace the old fill character with the new one
	for (int i = 1; i < getRows() + 1; i++)
	{
		for (int j = 1; j < getColumns() + 1; j++) 
		{
			if (grid[i][j] == oldFillChar)
				grid[i][j] = ch;
		}
	}
}

// getFrame_ver() const
char Canvas::getFrame_ver() const
{
	return frame_ver;
}

// setFrame_ver(char)
void Canvas::setFrame_ver(char ch)
{
	frame_ver = ch;	// set the new vertical frame character
	
	// loop through the canvas and draw the vertical frame characters
	for (int j = 1; j < getRows() + 1; j++)
	{
		grid[j][0] = frame_ver;			    	// draw the left edge
		grid[j][getColumns() + 1] = frame_ver;  // draw the right edge
	}
}

// getFrame_hor() const
char Canvas::getFrame_hor() const
{
	return frame_hor;
}

// setFrame_hor(char)
void Canvas::setFrame_hor(char ch)
{
	frame_hor = ch;

	// loop through the canvas and draw the horizontal frame characters
	for (int i = 1; i < getColumns() + 1; i++)
	{
		grid[0][i] = frame_hor;			    // draw the top edge
		grid[getRows() + 1][i] = frame_hor; // draw the bottom edge
	} 
}

// getFrame_cor() const
char Canvas::getFrame_cor() const
{
	return frame_cor;
}

// setFrame_cor(char)
void Canvas::setFrame_cor(char ch)
{
	frame_cor = ch;

	grid[0][0] = frame_cor; // draw the top left corner
	grid[0][getColumns() + 1] = frame_cor; // draw the top right corner
	grid[getRows() + 1][0] = frame_cor; // draw the bottom left corner
	grid[getRows() + 1][getColumns() + 1] = frame_cor; // draw the bottom right corner
}

// getRows()const
int Canvas::getRows() const
{
	return grid.size()-2;
}

// getColumns() const
int Canvas::getColumns() const
{
	return grid[0].size() - 2;
}

// flip_horizontal() const
Canvas Canvas::flip_horizontal() const
{
	Canvas flipped = Canvas(getRows(), getColumns(), getFillChar()); // create a new canvas with flipped dimensions

	// copy the contents of the current canvas to the flipped canvas
	flipped.setFrame_cor(getFrame_cor());
	flipped.setFrame_hor(getFrame_hor());
	flipped.setFrame_ver(getFrame_ver());

	// iterate through the current canvas and copy the contents to the
	// flipped canvas. The first column of the current canvas is copied
	// to the last column of the flipped canvas and so on.
	for (int i = 1; i < getRows() + 1; i++)
	{
		for (int j = 1; j < getColumns() + 1; j++)
		{
			flipped.put(i, getColumns() - j, grid[i][j]);

		}
	}
	return flipped;
}

// flip_vertical() const
Canvas Canvas::flip_vertical() const
{
	Canvas flipped = Canvas(getRows(), getColumns(), getFillChar()); // create a new canvas with flipped dimensions

	// copy the contents of the current canvas to the flipped canvas
	flipped.setFrame_cor(getFrame_cor());
	flipped.setFrame_hor(getFrame_hor());
	flipped.setFrame_ver(getFrame_ver());

	// iterate through the current canvas and copy the contents to the
	// flipped canvas. The first column of the current canvas is copied
	// to the last column of the flipped canvas and so on.
	for (int i = 1; i < getRows() + 1; i++)
	{
		for (int j = 1; j < getColumns() + 1; j++)
		{
			flipped.put(getRows() - i + 1, j, grid[i][j]);

		}
	}
	return flipped;
}

// print()
void Canvas::print(ostream& sout) const
{
	// iterate through the canvas and print the contents
	for (const auto& row : grid)
	{
		for (const auto& ch : row)
			sout << ch;
		sout << endl;
	}
}

// get(int int) const
char Canvas::get(int r, int c) const
{
	return grid[r][c];
}

// put(int, int, char)
void Canvas::put(int r, int c, char ch = ' ')
{
	if (check(r, c)) // check if the row and column are valid
		grid[r][c] = ch;
	else
		return;
}

// fill(char)
void Canvas::fill(char ch)
{
	// iterate through the canvas and fill it with the character
	for(int i = 1; i < getRows() + 1; i++)
	{
		for (int j = 1; j < getColumns() + 1; j++)
		{
			grid[i][j] = ch;
		}
	}
}

// write_horizontal(int, int, const string&)
void Canvas::write_horizontal(int r, int c, const string str)
{
	int str_counter = 0;
	while (check(r, c) && (str_counter < str.length()))  // check if the row and column are valid and if the string has ended
	{
		grid[r][c] = str.substr(str_counter, 1)[0]; // write the character to the canvas
		str_counter++;								// move to the next character in the string
		c++;
	}
}

// write_vertical(int, int, const string&)
void Canvas::write_vertical(int r, int c, const string str)
{
	int str_counter = 0;
	while (check(r, c) && (str_counter < str.length()))  // check if the row and column are valid and if the string has ended
	{
		grid[r][c] = str.substr(str_counter, 1)[0]; // write the character to the canvas
		str_counter++;								// move to the next character in the string
		r++;
	}
}

// overlay(const Canvas&, size_t, size_t)
void Canvas::overlay(const Canvas& can, size_t r, size_t c)
{
	// iterate through the canvas
	for (int i = 1; i < can.getRows() + 1; i++)
	{
		for (int j = 1; j < can.getColumns() + 1; j++)
		{
			// check if the character in the other canvas is not the fill character
			// if so, put the character in the current canvas
			if (can.get(i, j) != can.getFillChar())
			{
				if (check(r + i - 1, c + j - 1))
				{
					put(r + i - 1, c + j - 1, can.get(i, j));
				}
			}
		}
	}
}

// overloaded operator +=
Canvas& Canvas::operator+=(const Canvas& can)
{
	*this = concat(can);
	return *this;
}

// concat(const Canvas& can)
Canvas Canvas::concat(const Canvas& can)
{
	// First find the maximum number of rows between the two canvases
	int newRows = std::max(this->getRows(), can.getRows());

	Canvas concatCanvas = 
		Canvas(newRows,
		       getColumns() + can.getColumns(),
			   getFillChar()); // create a new canvas with concatenated dimensions + 1 column

	// copy the contents of the *this canvas to the concatenated canvas
	for (int i = 1; i < getRows() + 1; i++)
	{
		for (int j = 1; j < getColumns() + 1; j++)
		{
			concatCanvas.put(i, j, (*this).get(i, j));
		}
	}

	// copy the contents of the other canvas to the concatenated canvas
	for (int i = 1; i < can.getRows() + 1; i++)
	{
		for (int j = 1; j < can.getColumns() + 1; j++)
		{
			concatCanvas.put(i, getColumns() + j, can.get(i, j));
		}
	}
	return concatCanvas;
}

// resizeRows(size_t)
void Canvas::resizeRows(size_t n)
{
	// Calculate the new total number of rows including the frame
	size_t newTotalRows = n + 2;

	// Store the index of the previous last row before resizing
	size_t prevLastRowIndex = grid.size() - 1;

	// Resize the grid to the new number of rows
	grid.resize(newTotalRows, vector<char>(getColumns() + 2, fillChar));

	// Overwrite the previous last row to remove the old bottom edge
	// Check if the canvas was actually enlarged to avoid unnecessary operations
	if (newTotalRows > prevLastRowIndex + 1) {
		for (size_t col = 0; col < grid[prevLastRowIndex].size(); ++col) {
			// Overwrite the previous last row with the fill character
			// This effectively removes the old bottom edge line
			grid[prevLastRowIndex][col] = fillChar;
		}
	}

	// Reapply the frame characters to ensure the frame is correct after resizing
	// This includes drawing the new bottom edge at the correct position
	setFrame_cor(frame_cor);
	setFrame_hor(frame_hor);
	setFrame_ver(frame_ver);
}

// overloaded operator +
Canvas operator+(const Canvas& can1, const Canvas& can2)
{
	Canvas canvasToConcat = can1;
	return canvasToConcat.concat(can2);
}

// Overloaded insertion operator
ostream& operator<< (ostream& sout, const Canvas& can)
{
	can.print(sout);
	return sout;
}
