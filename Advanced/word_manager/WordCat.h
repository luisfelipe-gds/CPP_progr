 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordCat.cpp for the implementation of the methods.
 *
 * ***************************************************************************
 * Class Description: The WordCat class is a container class that holds a Word
 * object and a WordList object. It is driven by a menu that allows the user to
 * manipulate the WordCat object. The class provides methods to print the category
 * name and the words in the word_list, insert a word into the word_list, remove a
 * word from the word_list, clear the word_list, modify the category name, search
 * for a word in the word_list, show the words in the word_list sorted, load a
 * category from a file, save a category to a file.
 * ***************************************************************************
 */

#ifndef WORDCAT_H_
#define WORDCAT_H_
#include "Word.h"
#include "WordList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::endl;
using std::cin;

class WordCat
{
private:
	// Instance variable of the class 
	Word cat_name; // A Word object that holds the category name
	WordList word_list; // A WordList object that holds the words in the category

public:
	/*
	 * Default constructor
	 * A ctor that initializes the object to a default state receiving no arguments.
	 * It creates an empty WordCat object with an empty Word object and an empty 
	 * WordList object.
	 */
	WordCat() = delete;

	/*
	 * Conversion constructor 
	 * A ctor that initializes the object with a given category name.
	 * It creates a WordCat object with the given category name and an empty WordList.	 
	 */
	WordCat(const string& name);

	/*
	 * Copy constructor
	 * A ctor that initializes the object as a copy of another object.
	 * @param cat The WordList object to copy
	 */
	WordCat(const WordCat& cat);

	/*
	 * Move constructor
	 * A ctor creates a WordCat object by moving the resources from another WordCat object.
	 * @param cat The WordCat object to move
	 */
	WordCat(WordCat&& cat) noexcept;

	/*
	 * Copy assignment operator
	 * A ctor that copies the contents of another object to the current object (operator=).
	 * @param rhs The WordCat object to copy
	 * @return A reference to the current object
	 */
	WordCat& operator=(const WordCat& rhs);

	/*
	* Move assignment operator
	* A ctor that moves the contents of a temporary object to the current object (operator=).
	* @param rhs The WordCat object to move
	* @return A reference to the current object
	*/
	WordCat& operator=(WordCat&& rhs) noexcept;

	/*
	 * Destructor
	 * A dtor that destroys the WordCat object
	 * it is virtual to allow for polymorphism
	 */
	virtual ~WordCat();

	/*
	 * run()
	 * Method that repeatedly prompts the user to select an option from the menu.
	 * It executes the selected option until the user decides to exit the program.
	*/
	void run();

	/*
	 * write(std::std::ostream&, size_t) const
	 * A method that writes to output stream sout the elements of the category n
	 * elements per line, n=5 by default
	 * @param sout - the output stream
	 */
	void write(std::ostream& sout, size_t n = 5) const;

	/*
	 * show_sorted(std::ostream&, size_t) const
	 * A method that displays all words in this category sorted, with five words per line.
	 * It calls the sortWordList() method to sort the word_list.
	 * @param sout - the output stream
	*/
	void show_sorted(std::ostream& sout, size_t n = 5) const;

	/*
	 * processCategoryFromFile(std::ifstream&, WordList&)
	 * Helper method that reads a category from a file and processes it.
	 * It does not return anything, but it modifies the repeatedWords WordList object
	 * and the word_list WordList object.
	 * @param file - the input file stream
	 * @param repeatedWords - a WordList object that holds the repeated words
	 */
	void processCategoryFromFile(std::ifstream& file, WordList& repeatedWords);

	/*
	 * getWordList() const
	 * A method that returns the word_list as a const WordList reference
	 * @return the word_list
	*/
	const WordList& getWordList() const;

	/*
	 * getCatName() const
	 * A method that returns the cat_name as a const Word reference
	 * @return the cat_name
	 */
	const Word& getCatName() const;

	/*
	 * saveCategoryToFile(const string&) const
	 * A helper method that writes the cat_name and word_list to a file
	 * @param fileName - the name of the file to save the category
	*/
	void saveCategoryToFile(const string& fileName) const;

	/**
	 * printCategoryAndWords(std::ostream&) const;
	 * A method that prints all the words in the category.
	 * It follows the layout set by the assignment.
	 */
	void printCategoryAndWords(std::ostream& os) const;

private:
	/*
	 * menu() const 
	 * Method that displays a menu with the options for the user to select.
	 * @return The selected option
 	*/
	int menu() const;

	/*
	 * printWordsInCategory() const
	 * Method called by run() that prints the words in the word_list.
	 */
	void printWordsInCategory() const;

	/*
	 * appendWord() 
	 * Method called by run() that allows the user to append a Word object
	 * to the word_list. It is a while loop that keeps asking the user for
	 * input until the user decides to exit by pressing "enter".
	 */
	void appendWord();

	/* 
	 * removeWord()
	 * Method called by run() that allows the user to remove a given Word
	 * from the word_list, provided that the word is in the list.
	 */
	void removeWord();

	/*
	 * clearCategory()
	 * Method called by run() that clears the word_list.
	 */
	void clearCategory();

	/*
	 * modifyCategoryName()
	 * Method called by run() that allows the user to modify the cat_name
	 * by reading from the input stream.
	 */
	void modifyCategoryName();
	
	/* 
	 * searchWord() const
	 * A method that allows the user to search for a given word in the 
	 * word_list. It indicates if the word is in the list or not.
	 */
	void searchWord() const;

	/**
	 * loadCategory() 
	 * A method that allows the user to load a category from a text file.
	 * It checks if the file is valid and processes the category.
	 * It skips blank lines and trims leading and trailing spaces.
	 */
	void loadCategory();

	/**
	 * saveCategory() const
	 * A method that allows the user to save a category in a text file.
	 * It checks if the input is valid and write the category and words.
	 */
	void saveCategory() const;
};

/*
 * ***************************************************************************
 *                           NON-MEMBER FUNCTIONS
 * ***************************************************************************
 */

/*
 * Overloaded operator ==(const WordCat&, const WordCat&);
 * It compares lhs.cat_name with rhs.cat_name and returns a boolean value
 * @param lhs The left-hand side WordCat object to compare
 * @param rhs The right-hand side WordCat object to compare
 * @return A boolean value indicating if lhs.cat_name is equal to rhs.cat_name
 */
bool operator==(const WordCat& lhs, const WordCat& rhs);

/*
 * Overloaded operator <<(std::istream&, Word&)
 * It writes the WordCat object to the output stream sout using write()
 * @param sout The output stream to write to
 * @param cat The WordCat object to write
 * @return The output stream sout
 */
std::ostream& operator<<(std::ostream& sout, const WordCat& cat);

/*
 * sortWordList(const WordList&)
 * A helper method that sorts the word_list
 * It converts the list<word> object to a forward_list and sorts it
 * @param wl The WordList object to sort 
 * @return A sorted WordList object
 */
WordList sortWordList(const WordList& wl);

/**
 * validateInputFile(const string&)
 * A helper method that validates the input file
 * It runs several checks and returns a boolean value
 */
bool validateInputFile(const string& fileName);

#endif /* WORDCAT_H_ */
