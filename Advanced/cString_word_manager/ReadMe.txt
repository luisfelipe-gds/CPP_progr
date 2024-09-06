General description:
	
This solution is a console-based C++ application developed in Microsoft Visual 
Studio Community 2022 (64-bit)Current Version 17.9.7. 

The application is designed to manage categories of words. 

	Each category is represented by a WordCat object, and all categories are stored
  in a WordCatVec object. The WordCatVec class uses a dynamic array to store WordCat 
  objects. The capacity of the array is managed dynamically, increasing when a category
  is added and decreasing when a category is removed.

	Each WordCat object represents a category of words and includes methods for managing 
  the words in the category. The words in a category are stored in a WordList object. 

	The WordList class uses a doubly linked list to store Word objects. It includes 
  methods for adding, removing, and searching for Word objects in the list.

	The Word class represents a word and includes methods for manipulating the word.
  The solution does not use the <string> header: the Word class implements methods to 
  manipulate C-Style strings.
	
	The main.cpp file includes test functions for the Word, WordList, WordCat, and 
  WordCatVec classes. 

	The solution is designed with a focus on object-oriented programming principles, 
  including encapsulation, inheritance, and polymorphism. It demonstrates the use 
  of dynamic memory management, exception handling, file I/O, and operator overloading
  in C++.

Instructions:
	This program was developed using Microsoft Visual Studio Community 2022 (64-bit) 
  Current Version 17.9.7. There are no special instructions for running it. 
  The program can be compiled and run in an C++ set up environment, as well as in any IDE.

Extra features:
	I implemented the saveToFile() feature for both WordCat and WordCatVec classes. 
  For the last one, that feature was optional. Also, I implemented a file validator to 
  better handle errors in loadFromFile().

There are no known bugs in the program.
