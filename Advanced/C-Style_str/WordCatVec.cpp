/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 1 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Date: May 26, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
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

#include <iostream>
#include <fstream>
#include "Word.h"
#include "WordList.h"
#include "WordCat.h"
#include "WordCatVec.h"
using std::cout;
using std::cin;
using std::endl;

/**
 * Task 4 Basic Constructors
 * Default constructor
 * Initializes an empty word_category array with a capacity of 1.
*/

WordCatVec::WordCatVec() 
{
	capacity = 1;   // Initial capacity
	size = 0;       // Initial size
	word_category = new WordCat[capacity]; // Allocate memory for word_category array
}

/**
 * Conversion constructor
 * Initializes a WordCatVec object with a single category.
*/

WordCatVec::WordCatVec(const Word& catName) 
{
    capacity = 1;   
    size = 0;       
    word_category = new WordCat[capacity]; 
    addCategory(catName); // Add the initial category
}

/**
 * Task 4 - The Big Five
 * Copy constructor
 * @param other - the WordCatVec object to copy
*/ 

WordCatVec::WordCatVec(const WordCatVec& other) 
{
	copy(other);
}

/**
 * Move constructor
 * @param other - the WordCatVec object to move
*/

WordCatVec::WordCatVec(WordCatVec&& other) noexcept 
{
	copy(other);
	releaseOwnership();
}

/**
 * Copy assignment operator
 * @param other - the WordCatVec object to copy
*/

WordCatVec& WordCatVec::operator=(const WordCatVec& other) 
{
	if (this != &other) 
    {
		copy(other);
	}
	return *this;
}

/**
 * Move assignment operator
 * @param other - the WordCatVec object to move
 */

WordCatVec& WordCatVec::operator=(WordCatVec&& other) noexcept {
	if (this != &other) 
    {
		copy(other);
		releaseOwnership();
	}
	return *this;
}

/**
 * Destructor
 * Deallocates the memory used by the word_category array
 */

WordCatVec::~WordCatVec() 
{
	releaseOwnership();
}

/**
* Task 4 - Method to run the interactive dialogue
* The method will display a menu of options to the user and execute the selected option.
* The method will continue to display the menu until the user chooses to exit the program.
* */

void WordCatVec::run() 
{
	int choice;       // initialize the choice variable
	do                // loop to display the menu until the user chooses to exit
    {
		choice = this->menu(); // display the menu and get the user's choice
        
		switch (choice)        // switch statement to execute the selected option
        {
        case 1:
            printAllCategories();
            break;
        case 2:
            addCategory();
            break;
        case 3:
            removeCategory();
            break;
        case 4:
            clearCategory();
            break;
        case 5:
            modifyCategory();
            break;
        case 6:
            searchWordInAllCategories();
            break;
        case 7:
            showWordsStartingWithLetter();
            break;
        case 8:
            loadFromFile();
            break;
		case 9:
			saveToFile();
			break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } 
	while (choice != 0); // exit the loop when the user chooses to exit the program
}

/**
 * Task 4 - Method to display the menu of options to the user
 * The method will display a menu of options to the user and return the user's choice.
 * The method will validate the user's input and prompt the user to enter a number if the input is invalid.
*/

int WordCatVec::menu() 
{
    cout << "===========================\n";
    cout << "Word Vocabulary Center\n";
    cout << "===========================\n";
    cout << "1. Print all categories\n";
    cout << "2. Add a new category\n";
    cout << "3. Remove a category\n";
    cout << "4. Clear a category\n";
    cout << "5. Modify a category\n";
    cout << "6. Search all categories for a specific word\n";
    cout << "7. Show all the words starting with a given letter\n";
    cout << "8. Load from a text file\n";
    cout << "9. Save to a text file\n";
    cout << "0. Exit\n";
    cout << "===========================\n";
    cout << "Enter Your Choice: ";

	int choice;             // variable to store the user's choice
	cin >> choice;		    // read the user's choice

	while (cin.fail())      // validate the user's input
    {
        cin.clear();        // Clear the error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        
        cout << "Invalid input. Please enter a number: ";
		cin >> choice; 	    // Read the user's choice again
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the line

    return choice;
}

/**
 * Task 4 - Method to print all categories
 * The method will print all categories and their words to the console.
 */

void WordCatVec::printAllCategories() 
{
    cout << "Print all the category names" << endl; 
    cout << endl;

	if (size == 0)      // Check if there are any categories to print
	{
		cout << "No categories to print" << endl;
        cout << "Try adding a new category and words in the category" << endl;
		cout << endl;
	}
	else 			    // Print all categories and their words
    {
		for (size_t i = 0; i < size; i++)   // Loop through all categories
        {
			if (word_category[i].getWordList().isEmpty())  // Check if the category is empty, if so, print a message
            {
                cout << "Category: " << word_category[i].getCategoryName().c_str() << " is empty." << endl;
                cout << endl;
                cout << endl;
            }
			else                                            // Print the category and its words
            {
                cout << "Category: " << word_category[i].getCategoryName().c_str() << endl;
                cout << "==========" << endl;
                word_category[i].getWordList().print(cout);
                cout << endl;
            }
        }
    }
}

/**
* Task 4 - Method to add a new category from a given word
* @param newCategory - the word to use as the category name
*/

void WordCatVec::addCategory(const Word& newCategory) 
{
	increaseCapacity();
    WordCat newWordCat(newCategory);            // Create a new WordCat object
    word_category[size] = newWordCat;           // Add the new WordCat object to the array
	size++;                                     // Increment the size
}

/***        
 * Task 4 - Method to add a new category from user input
 * The method will prompt the user for the name of the new category and add the category to the array.
 * Before adding the category, the method will validate the input, check if the category already exists,
 * and increase the capacity if necessary.
**/

void WordCatVec::addCategory()
{
    cout << "Add a new category" << endl; 
    cout << "Enter the name of the new category: "; // Prompt the user for the new category name

    Word newCategory;
    newCategory.read(cin);

    if (newCategory.length() == 0)         // Validate the input
    {
        cout << "Invalid input. Please enter a word." << endl;
        cout << endl;
	}
	else if (searchCategory(newCategory))  // Check if the category already exists
	{
		cout << "Category already exists." << endl;
        cout << endl;
	}
	else                                    // Add the new category
	{
        increaseCapacity();                 // Increase the capacity if necessary
        addCategory(newCategory);
		cout << "Category '" << newCategory << "' sucessfully added" << endl;
        cout << endl;
	}
}

/**
 * Task 4 - Method to remove a category
 * The method will prompt the user for the name of the category to remove.
 * and remove the category from the array by shifting all elements to the left
 * of the removed category and decrementing the size.
 * After removing the category, the method will reduce the capacity if necessary.
 */
void WordCatVec::removeCategory()
{
    cout << "Removing a given category" << endl;
    cout << "Enter the name of the category to remove: "; // Prompt the user for the category to remove

	Word categoryToRemove;          // Variable to store the category to remove
	cin >> categoryToRemove;        // Read the category to remove from the user

	int indexToRemove = -1;		    // Variable to store the index of the category to remove
	                                // it is initialized to -1 to indicate that the category was not found

	for (size_t i = 0; i < size; i++)  // Loop through all categories and check if the category exists
    {
        if (word_category[i].getCategoryName().areEqual(categoryToRemove))
        {
            indexToRemove = i;
            break;
        }
    }

	if (indexToRemove == -1)            // Check if the category was not found and print an error message
    {
        cout << "Category '" << categoryToRemove << "' not found" << endl;
        cout << endl;
        return;
    }
  
	for (size_t i = indexToRemove; i < size - 1; i++)  // if the category is found, remove it from the array
	{                                                  // by shifting all elements to the left and then decrement the size
        word_category[i] = word_category[i + 1];
    }

    size--; // Decrement the size
    reduceCapacity(); // Reduce the capacity if necessary

    cout << "Category '" << categoryToRemove << "' successfully removed" << endl;
    cout << endl;
}


/**
 * Task 4 - Method to increase the capacity of the word_category array
 * The method will create a new array with double the capacity of the current array.
 * It will copy all the elements from the current array to the new array.
 * It will then deallocate the memory used by the current array and set the current array to the new array.
 * This is a solution to memory management issues that may arise when the array is full.
 */

void WordCatVec::increaseCapacity() 
{
    if (capacity == size) // Check if the capacity is full
    {
        WordCat* temp = new WordCat[capacity * 2]; // Create a new temp array with double the capacity

        for (size_t i = 0; i < size; i++) // Copy all elements to the new array
        {
            temp[i] = word_category[i];
        }

        delete[] word_category;           // Deallocate the memory used by the current array
        word_category = temp; 		      // Set the current array to the new array
        capacity *= 2;  			      // Double the capacity value
    }
}

/**
 * Task 4 - Method to reduce the capacity of the word_category array
 * The method will create a new array with half the capacity of the current array.
 * It will copy all the elements from the current array to the new array.
 * It will then deallocate the memory used by the current array and set the current array to the new array.
 * This is a solution to memory management issues that may arise when the array is full.
 *
*/

void WordCatVec::reduceCapacity() 
{
    if (capacity <= 2)
    {
        return;
    }
    else if (size < (capacity / 2))     // Check if the capacity is less than half full
    {
        size_t newCapacity = capacity / 2;        // Calculate the new capacity
        WordCat* temp = new WordCat[newCapacity]; // Create a new temp array with the new capacity

        if (word_category != nullptr) { // Check if word_category is not null before copying elements
            for (size_t i = 0; i < size; i++)  // Copy all elements to the new array
            {
                temp[i] = word_category[i];
            }

            delete[] word_category; // Deallocate the memory used by the current array
            word_category = temp;   // Set the current array to the new array
            capacity = newCapacity; // Set the capacity to the new capacity
        }
    }
}
/**
 * Task 4 - Method to clear a category
 * The method will prompt the user for the name of the category to clear.
 * It will then remove all words from the category.
*/

void WordCatVec::clearCategory()
{
	cout << "Emptying a category" << endl;
    cout << "Enter the name of the category to clear: "; // Prompt the user for the category to clear

    Word categoryToClear;
    cin >> categoryToClear;

    try {
        WordCat& category = getCategory(categoryToClear); // Get the category
        category.emptyCategory();                         // Empty the category

        cout << "Removed all words from the category " << categoryToClear.c_str() << "." << endl;
        cout << endl;
    }
    catch (std::invalid_argument& e) {
        cout << e.what() << endl; // Print the error message if the category is not found
        cout << endl;
    }
}


/**
 * Task 4 - Method to modify a category
 * This method will prompt the user for the name of the category to modify.
 * It will then run the interactive dialogue for the selected category.
 */

void WordCatVec::modifyCategory()
{
    cout << "Modifying a category\n";
    cout << "Enter the name of the category to modify: "; // Prompt the user for the category to modify

    Word categoryToModify;
    cin >> categoryToModify;

    try {
        cout << "Modifying category: " << categoryToModify << endl;
        cout << endl;
        WordCat& category = getCategory(categoryToModify); // Get the category
        category.run(); // Run the interactive dialogue for the category
    }
    catch (std::invalid_argument& e) {
        cout << e.what() << endl; // Print the error message if the category is not found
    }
}

/**
 * Task 4 - Method to search for a specific category
 * The method will prompt the user for the word to search for.
 * It will then search for the word in all categories and print the categories where the word is found.
*/

bool WordCatVec::searchCategory(const Word& categoryName) 
{
	for (size_t i = 0; i < size; i++)  // Loop through all categories and check if the category exists
    {
        if (word_category[i].getCategoryName().areEqual(categoryName)) 
        {
            return true;
        }
    }
    return false;
}

/**
* Task 4 - Method to search and get the category with a specific name
* @param catName - the name of the category to get
* @return the category with the specified name
* @throws std::invalid_argument if the category is not found
**/

WordCat& WordCatVec::getCategory(const Word& catName) const 
{
	for (size_t i = 0; i < size; i++)  // Loop through all categories and return the category with the specified name
    {
		if (word_category[i].getCategoryName().areEqual(catName)) 
        {
			return word_category[i];
		}
	}
	throw std::invalid_argument("Category not found");
}

/**
 * Task 4 - Method to search for a specific word in all categories
 * The method will prompt the user for the word to search for.
 * It will then search for the word in all categories and print the categories where the word is found.
*/

void WordCatVec::searchWordInAllCategories() 
{
	cout << "Search for a specific word in all categories\n";
    cout << "Enter the word to search for: "; // Prompt the user for the word to search for
	Word wordToSearch;
	cin >> wordToSearch;

	if (wordToSearch.length() == 0)         // Validate the input
	{
		cout << "Invalid input. Please enter a word." << endl;
        cout << endl;
	}
	else if (size == 0)                     // Check if there are any categories to search
	{
		cout << "No categories to search." << endl;
        cout << "Try adding a category and words" << endl;
        cout << endl;
	}
	else 								    // Search for the word in all categories
    {
        for (size_t i = 0; i < size; i++)
        {
            if (word_category[i].getWordList().lookup(wordToSearch))
            {
                cout << "The word '" << wordToSearch.c_str() << "' is in the list of the category '" << word_category[i].getCategoryName().c_str() << "'\n";
                cout << endl;
            }
            else
            {
                cout << "The word '" << wordToSearch.c_str() << "' is not in the list of the category '" << word_category[i].getCategoryName().c_str() << "'\n";
                cout << endl;
            }
        }
    }
}

/**
 * Task 4 - Method to show all the words starting with a given letter
 * The method will prompt the user for the initial letter.
 * It will then search for words starting with the given letter in all categories and print the words found.
**/

void WordCatVec::showWordsStartingWithLetter() 
{
    cout << "Show all the words in all categories starting with a given letter\n";
    cout << "Enter the first letter of the words to search for: "; // Prompt the user for the initial letter

	char initial;                         // Variable to store the initial letter
	cin >> initial;					      // Read the initial letter from the user

	for (size_t i = 0; i < size; i++)  // loop through all categories and print the words starting with the initial letter
    {
		WordList wordsStartingWithInitial = word_category[i].getWordList().getWordsStartingWith(initial);

		if (wordsStartingWithInitial.isEmpty()) 
        {
			cout << "No words starting with " << initial << " found in the category " << word_category[i].getCategoryName().c_str() << ".\n";
			cout << endl;
		}
		else 
        {
			cout << "Words starting with " << initial << " in the category " << word_category[i].getCategoryName().c_str() << ":\n";
			wordsStartingWithInitial.print(cout, 1);
            cout << endl;
		}
	}
}

/***
* Task 4 - Method to load categories from a file
* The method will prompt the user for the name of the file containing the categories.
* It will then read the file line by line, creating a new category when a line starts with '#'
* and adding words to the category when the line is not empty and does not start with '#'.
* It also increases the capacity if necessary before adding a new category.
*/

void WordCatVec::loadFromFile()
{
    cout << "Loading from a text file" << endl;
    cout << "Enter the name of the file containing the categories and words: " << endl;

    Word filename;                         // Create a word to store the filename
    cin >> filename;                       // Read the filename from the user     

    std::ifstream inFile(filename.c_str()); // Open the file for reading

    if (!validateInputFile(filename.c_str()))  // Validate the input file
    {
        return;
    }

    WordCat* currentCategory = nullptr; // Pointer to the current category being read
    Word line;                          // Create a word to store each line of the file

    while (inFile >> line) // Read a line from the file
    {
        if (line.length() > 0) // If the line is not empty
        {
            if (line.at(0) == '#') // If the line starts with '#', it's a category
            {
                increaseCapacity(); // Increase the capacity if necessary

                Word newCategory(line.c_str() + 1); // Skip the '#' and save the rest as category name
                WordCat newWordCat(newCategory);    // Create a new WordCat object
                word_category[size] = newWordCat;   // Add the new WordCat object to the array
                currentCategory = &word_category[size]; // Set the current category to the new element in the array

                size++; // Increment the size
            }
            else if (currentCategory != nullptr) // Otherwise, it's a word
            {
                currentCategory->returnWordListRef().insertSorted(line); // Add the word to the current category
            }
        }
    }

    inFile.close(); // Close the file
    cout << "Categories loaded from file " << filename << endl;
    cout << endl;
}

/**
 * Task 4 - Save to a text file
 * The method will prompt the user for the name of the file to save the categories.
*/

void WordCatVec::saveToFile()
{
	cout << "Saving to a text file" << endl;
	cout << "Enter the name of the file to save the categories: " << endl; // Prompt the user for the file name

	Word filename;                         // Create a word to store the filename
	cin >> filename;                       // Read the filename from the user

	if (filename.length() == 0)            // Validate the input
	{
		cout << "Invalid input. Please enter a file name." << endl;
        cout << endl;
		return;
	}
	else if (size == 0)                     // Check if there are any categories to save
    {
		cout << "No categories to save." << endl;
		cout << "Try adding a category and words" << endl;
        cout << endl;
		return;
	}
	else
    {
        std::ofstream outFile(filename.c_str()); // Open the file for writing

        for (size_t i = 0; i < size; i++)       // Loop through all categories and save them to the file
        {
			word_category[i].printCategoryAndWords(outFile); // Print the category and its words
			outFile << endl; // Add a new line
        }
        outFile.close();
        cout << "Categories saved to file " << filename << endl;
        cout << endl;
    }
}

/**
 * Task 4 - Extra #1 Method to copy another WordCatVec object
 * @param other - the WordCatVec object to copy
*/

void WordCatVec::copy(const WordCatVec& other) 
{
	capacity = other.capacity;	           // Copy the capacity
	size = other.size; 		               // Copy the size
	word_category = new WordCat[capacity]; // Allocate memory for the new word_category array
    
	for (size_t i = 0; i < size; i++)      // Copy each element of the word_category array
	{
		word_category[i] = WordCat(other.word_category[i]);
	}
}

/**
 * Task 4 - Extra #2 Method to release ownership of the WordCatVec object
 */

void WordCatVec::releaseOwnership()
{
	capacity = 0;            // Set the capacity to 0
	size = 0;                // Set the size to 0
	word_category = nullptr; // Set the word_category array to nullptr
}

/**
 * Task 4 - Method to validate the input file
 * The method will check if the file is a text file, if the file is open, and if the file is empty.
 * It will also check if the file starts with a category name.
 * @param filename - the name of the file to validate
 * @return true if the file is valid, false otherwise
 */

bool WordCatVec::validateInputFile(const char* filename)
{
    const char* extension = strrchr(filename, '.');         // Find the last '.' in the filename

    if (!extension || strcmp(extension + 1, "txt") != 0)    // Check if the file is a text file
    {
        cout << "Invalid file type. Please provide a text file." << endl;
        cout << endl;
        return false;
    }

    std::ifstream inFile(filename);             // Open the file

    if (!inFile)                                // Check if the file is open  
    {
        cout << "Unable to open file " << filename << endl;     // Print an error message
        cout << endl;
        return false;
    }

    if (inFile.peek() == std::ifstream::traits_type::eof())     // Check if the file is empty
    {
        cout << "File is empty." << endl;
        cout << endl;
        return false;
    }

    char firstChar = inFile.peek();                     // Check if the file starts with a '#'
    if (firstChar != '#')
    {
        cout << "File does not start with a category name." << endl;
        cout << endl;
        return false;
    }

    inFile.close();
    return true;
}