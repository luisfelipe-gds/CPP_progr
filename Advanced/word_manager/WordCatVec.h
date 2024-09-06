/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 2 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Due Date: June 14th, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordCatVec.cpp for the implementation of the methods.
 *
 * ***************************************************************************
 * Class Description: WordCatVec class is a container class that holds a vector
 * of WordCat objects. It is driven by a menu that allows the user to manipulate
 * the WordCatVec object. The class provides methods to print all categories and
 * their words, add a new category, remove a category, clear a category, interact
 * with a category, show all words in all categories sorted, show all categories
 * and the respective words sorted individually, load categories from a file, and
 * save categories to a file.
 * ***************************************************************************
 */

#ifndef WORDCATVEC_H_
#define WORDCATVEC_H_
#include "Word.h"
#include "WordList.h"
#include "WordCat.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::cin;


class WordCatVec
{
private:
	// Instance variable of the class - A vector of WordCat objects that holds the categories
	vector<WordCat> theVector;

public:
	/*
	 * Default constructor
	 * A ctor that initializes the object to a default state receiving no arguments.
	 */
	WordCatVec();

	/*
	 * Copy constructor
	 * A ctor that initializes the object as a copy of another object.
	 * @param vec The WordCatVec object to copy
	 */
	WordCatVec(const WordCatVec& vec);

	/*
	 * Move constructor
	 * A ctor creates a WordCatVec object by moving the resources from another WordCatVec object.
	 * @param vec The WordCatVec object to move
	 */
	WordCatVec(WordCatVec&& vec) noexcept;
	
	/*
	 * Copy assignment operator
	 * A ctor that copies the contents of another object to the current object (operator=).
	 * @param rhs The WordCatVec object to copy
	 * @return A reference to the current object
	 */
	WordCatVec& operator=(const WordCatVec& rhs);

	/*
	* Move assignment operator
	* A ctor that moves the contents of a temporary object to the current object (operator=).
	* @param rhs The WordCatVec object to move
	* @return A reference to the current object
	*/
	WordCatVec& operator=(WordCatVec&& rhs) noexcept;

	/*
	 * Destructor
	 * A dtor that destroys the WordCatVec object
	 * it is virtual to allow for polymorphism
	 */
	virtual ~WordCatVec();

	/*
	 * write(std::std::ostream&, size_t) const
	 * A method that writes to output stream sout the elements of the category n
	 * elements per line, n=5 by default
	 * @param sout - the output stream
	 */
	void write(std::ostream& sout, size_t n = 5) const;

	/*
	 * run()
	 * Method that repeatedly prompts the user to select an option from the menu.
	 * It executes the selected option until the user decides to exit the program.
	*/
	void run();

private:
	/*
	 * Method to display the menu of options to the user
	 * The method will display a menu of options to the user and return the user's choice.
	 * It will prompt the user to enter a number if the input is invalid.
	 */
	int menu();

	/*
	 * printAllCategories() const
	 * Method called by run() that prints the categories and words in the theVector.
	 */
	void printAllCategories() const;

	/*
	 * addNewCategory()
	 * Method called by run() that allows the user to append a WordCat object
	 * to theVector. 
	 */
	void addNewCategory();

	/*
	 * insertCategorySorted(const string& cat)
	 * Helper Method called by addNewCategory() that searches for the correct
	 * position to insert the new category in theVector and inserts it. 
	 */
	void insertCategorySorted(const string& cat);

	/*
	 * removeCategory()
	 * Method called by run() that allows the user to remove a given WordCat
	 * from theVector, provided that the WordCat is in the vector.
	 */
	void removeCategory();

	/*
	 * clearCategory()
	 * Method called by run() that clears the words from a given WordCat
	 * provided that the WordCat is in the vector.
	 */
	void clearCategory();

	/*
	 * interactWithCategory()
	 * Method called by run() that allows the user to interact with a given WordCat
	 * provided that the WordCat is in the vector. It calls the run() method of the
	 * WordCat object.
	 */
	void interactWithCategory();

	/*
	 * showAllWordsSorted()
	 * Method called by run() that shows all words in all categories sorted, but the
	 * categories are not displayed.
	 */
	void showAllWordsSorted();

	/*
	 * showAllCategories()
	 * Method called by run() that shows all categories and the respective words sorted
	 * individually.
	 */
	void showAllCategories();

	/*
	 * lookupCategory(const WordCat& cat) const
	 * Helper method that searches for a given WordCat in theVector.
	 */
	bool lookupCategory(const WordCat& cat) const;

	/*
	 * searchCategory(const WordCat& cat) const;
	 * Helper method that searches for a given WordCat in theVector and returns the index.
	 */
	size_t searchCategory(const WordCat& cat) const;

	/*
	 * loadCategories()
	 * Method called by run() that loads categories from a file.
	 * It will prompt the user to enter a file name and check if 
	 * the input is valid.
	 */
	void loadCategories();

	/*
	 * addCategoriesFromFile(std::ifstream& file)
	 * Helper method called by loadCategories() that reads the categories from a file
	 * and adds them to theVector.
	 * @param file - the input file stream
	 */
	void addCategoriesFromFile(std::ifstream& file);

	/*
	 * saveVector() const
	 * Method called by run() that saves the categories to a file.
	 * It will prompt the user to enter a file name and check if the 
	 * input is valid.
	 */
	void saveVector() const;

	/* 
	 * Helper method that inserts a WordCat object in theVector
	 * @param cat - the WordCat object to be inserted
	 */
	void push_back(const WordCat& cat);

	/**
	 * Helper method that sets MAX_WORD_LENGTH equals to the length
	 * of the longest word in all categories.
	*/
	void setMaxLengthAllCategories() const;
};
#endif /* WORDCATVEC_H_ */
