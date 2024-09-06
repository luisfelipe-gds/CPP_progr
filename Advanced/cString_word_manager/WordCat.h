/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordCat.cpp for the implementation of the methods.
 *
 * ***************************************************************************
 * Class Description:
 *
 * The WordCat class represents a category of words. The category is defined by a Word object
 * and a WordList object. The class main features are driven by an interactive dialogue
 * with the user. The user can print all the words in the category, insert a new word,
 * remove a word, empty the category, modify the category name, search for a specific word,
 * show all the words starting with a given letter, load words from a text file, and save
 * the words to a text file.
 * ***************************************************************************
 */

#ifndef WORDCAT_H_
#define WORDCAT_H_
#include "Word.h"
#include "WordList.h"
#include <iostream>
#include <fstream>

class WordCat 
{
private:
    Word category;
    WordList wordList;

public:
	// Task 3 - #1a Parameterized conversion constructor
    WordCat(const Word& catName);

	// Task 3 - #1b Default constructor
	WordCat();

	// Task 3 - #2 The Big Five
	// Task 3 - #2a Copy constructor
    WordCat(const WordCat& other);

	// Task 3 - #2b Move constructor
    WordCat(WordCat&& other) noexcept;

	// Task 3 - #2c Copy assignment operator
    WordCat& operator=(const WordCat& other);

	// Task 3 - #2d Move assignment operator
    WordCat& operator=(WordCat&& other) noexcept;

	// Task 3 - #2e Destructor
    ~WordCat();

	// Task 3 - #3a Menu-driven interactive dialogue
    void run();
   
    // Task 3 - #3c Method to print all words in the category
    void printAllWords();

    // Task 3 - #3d Method to insert a new word into the category
    void insertWord();

    // Task 3 - #3e Method to remove a given word from the category
    void removeWord();

    // Task 3 - #3f Method to empty the category - it is public because it is used in WordCatVec
    void emptyCategory();

    // Task 3 - #3g Method to modify the category name
    void modifyCategoryName();

    // Task 3 - #3h Method to search for a specific word in the category
    void searchWord();

    // Task 3 - #3i Method to show all words starting with a given letter
    void showWordsStartingWith();

    // Task 3 - #3j Method to load words from a text file into the category 
    void loadFromFile();

    // Task 3 - #3ki Method to save words from the category to a text file
    void saveToFile();

    // Task 3 - #3kii Helper method to print the category names and wordlists as required
    void printCategoryAndWords(std::ostream& os) const;

    // Task 3 - #4 Overloaded insertion operator<<
    friend std::ostream& operator<<(std::ostream& os, const WordCat& wc);

    // Task 3 - Extra #3 set category name
    void setCategoryName(const Word& newCategory);

    // Task 3 - Extra #4 Method to get the category name
    Word getCategoryName() const;
  
    // Task 3 - Extra #5 Method to get the WordList object
    WordList getWordList() const;

    // Task 3 - Extra #6 Method to get the WordList object and change it
    WordList& returnWordListRef();

private:

    // Task 3 - #3b Menu for interactive dialogue
    int menu();

    // Task 3 - Extra #1 Helper method to copy the category
    void copy(const WordCat& other);

    // Task 3 - Extra #2 Helper method to release ownership of the category
    void releaseOwnership();

    // Task 3 - Extra #7 method to validate the input file
    bool validateInputFile(const char* fileName);
};

#endif /* WORDCAT_H_ */