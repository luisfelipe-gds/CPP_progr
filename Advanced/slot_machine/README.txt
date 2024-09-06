General description:
	This solution is a console-based C++ application developed in Microsoft Visual Studio Community 2022 (64-bit)
  Current Version 17.9.7. The application is designed to simulate a slot machine game in which a player bets on 
  three reels, each contaning one of the following shapes: rectangle, rhombus, acute triangle, and right triangle. 

	Reels are implemented as a Canvas objects, essentialy two-dimensional arrays of characteres 
  std::vector<std::vector<char>> 

	The assignment submission consists of 17 files: "Canvas.h", "Canvas.cpp", "Shape.h", "Shape.cpp", "Rectangle.h", 
  "Rectangle.cpp", "Rhombus.h", "Rhombus.cpp", "Triangle.h", "Triangle.cpp", "AcuteTriangle.h", "AcuteTriangle.cpp",
  "RightTriangle.h", "RightTriangle.cpp", and "SlotTestDriver.cpp".

	These classes are designed using an inheritance structure as follows. 
  Shape -> Rectangle, Rhombus, Triangle -> AcuteTriangle, RightTriangle.

	The header files contain all declarations for member and non-member functions, the definitions for instance and 
  global variables, as well as descriptive comments about each function. ".cpp" files contain the definitions for 
  all methods and functions. 

	The solution is designed with a focus on object-oriented programming principles, including encapsulation. 
  It demonstrates the extensive use of inheritance in C++.

Instructions:
	This program was developed using Microsoft Visual Studio Community 2022 (64-bit) - Current Version 17.9.7. 
  It was compiled using c++20. There are no special instructions for running it. The program can be compiled 
  and run in an C++ set up environment, as well as in any IDE.

Extra features:
	I included additional assert statements on the main file so that all operatoions were tested.

There are no known bugs in the program.
