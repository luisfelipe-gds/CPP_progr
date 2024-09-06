/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordCatVec.cpp for the implementation of the methods.
 *
 * ***************************************************************************
 * Class Description:
 * The WordCatVec class represents a vector of WordCat objects. The class is
 * defined by a WordCat array, a capacity, and a size. The main features of the
 * class are driven by an interactive dialogue with the user. The user can print
 * all categories, add a new category, remove a category, clear a category, modify
 * a category, search for a specific word in all categories, show all the words
 * starting with a given letter, load categories from a text file, and save the
 * categories to a text file.
 * ***************************************************************************
 */

#ifndef WORDCATVEC_H_
#define WORDCATVEC_H_
#include <iostream>
#include "Word.h"
#include "WordList.h"
#include "WordCat.h"

class WordCatVec 
{
private:
	WordCat* word_category;
	size_t capacity;
	size_t size;

public:
	/**
	* Task 4 Basic Constructors
	* Default constructor
	*/
	WordCatVec();
	
	// Conversion constructor
	WordCatVec(const Word& catName);

	/**
	* Task 4 - The Big Five
	* Copy constructor
	*/
	WordCatVec(const WordCatVec& other);

	// Move constructor
	WordCatVec(WordCatVec&& other) noexcept;

	// Copy assignment operator
	WordCatVec& operator=(const WordCatVec& other);

	// Move assignment operator
	WordCatVec& operator=(WordCatVec&& other) noexcept;

	// Destructor
	~WordCatVec();

	// Task 4 - Method to run the interactive dialogue
	void run();
	
	// Task 4 - Method to print all categories
	void printAllCategories();

	// Task 4 - Method to add a new category from a given word
	void addCategory(const Word& newCategory);

	// Task 4 - Method to add a new category from user input
	void addCategory();

	// Task 4 - Method to remove a category from user input
	void removeCategory();

	// Task 4 - Method to clear a category
	void clearCategory();

	// Task 4 - Method to modify a category
	void modifyCategory();

	// Task 4 - Method to search for a specific word in all categories
	void searchWordInAllCategories();

	// Task 4 - Method to show all the words starting with a given letter
	void showWordsStartingWithLetter();

	// Task 4 - Method to load categories from a file
	void loadFromFile();

	// Task 4 - Extra Method to save categories to a file
	void saveToFile();

	// Task 4 - Method to search for a specific category
	bool searchCategory(const Word& categoryName);

	// Task 4 - Method to search and get the category with a specific name
	WordCat& getCategory(const Word& catName) const;

private:
	// Task 4 - Method to display the menu of options to the user
	int menu();

	// Task 4 - Method to increase the capacity of the word_category array
	void increaseCapacity();

	// Task 4 - Method to reduce the capacity of the word_category array
	void reduceCapacity();

	// Task 4 - Extra Method to copy the vector
	void copy(const WordCatVec& other);

	// Task 4 - Method to release ownership of the vector
	void releaseOwnership();

	// Task 3 - Method to validate the input file
	bool validateInputFile(const char* fileName);

};

#endif /* WORDCATVEC_H_ */