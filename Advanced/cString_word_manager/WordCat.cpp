/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact. 
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

#include "Word.h"
#include "WordList.h"
#include "WordCat.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

/**
 * Task 3 - #1a Parameterized conversion constructor
 * A ctor that initializes a category receiving a word object
 * and an empty word list.
 * @param catName The name of the category
*/

WordCat::WordCat(const Word& catName) :
    category(catName), 
    wordList() {}

/**
 * Task 3 - #1b Default constructor
 * A ctor that initializes the category to an empty string
 * and the word list to an empty list.
*/

WordCat::WordCat() : 
    category(), 
    wordList() {}


/**
 * Task 3 - #2 The Big Five
 * #2a Copy constructor
 * A ctor that initializes a WordCat object with the values of another WordCat object.
 * @param other The WordCat object to copy
*/

WordCat::WordCat(const WordCat& other) 
{
	copy(other);
}

/**
 * Task 3 - #2b Move constructor
 * A ctor that initializes a WordCat object with the values of another WordCat object
 * and releases the ownership of the other object.
 * @param other The WordCat object to move
*/

WordCat::WordCat(WordCat&& other) noexcept 
{
	copy(other);
	other.releaseOwnership();
}

/**
 * Task 3 - #2c Copy assignment operator
 * An assignment operator that assigns the values of another WordCat object to this object.
 * @param other The WordCat object to copy
 * @return A reference to this object
 */

WordCat& WordCat::operator=(const WordCat& other) 
{
	if (this != &other) {
		copy(other);
	}
	return *this;
}

/**
 * Task 3 - #2d Move assignment operator
 * An assignment operator that assigns the values of another WordCat object to this object
 * and releases the ownership of the other object.
 * @param other The WordCat object to move
 * @return A reference to this object
 */

WordCat& WordCat::operator=(WordCat&& other) noexcept 
{
	if (this != &other) 
    {
        releaseOwnership();
        copy(other);
		other.releaseOwnership();
	}
	return *this;
}

/**
 * Task 3 - #2e Destructor
 * A destructor that releases the ownership of the category and the word list.
 */

WordCat::~WordCat() 
{
	releaseOwnership();
}

/**
 * Task 3 - #3a Menu-driven interactive dialogue
 * A method that runs an interactive dialogue with the user
 * to manage the words in the category. It displays a menu
 * until the user chooses to exit.
 */

void WordCat::run() 
{
	int choice;                 // Initialize the choice variable as an integer

	do                          // Do-while loop to keep the menu running until the user chooses to exit
    {                       
		choice = this->menu();  // Get the user's choice
        
		switch (choice)         // Switch statement to handle the user's choice
        {       
        case 1:
            printAllWords();
            break;
        case 2:
            insertWord();
            break;
        case 3:
            removeWord();
            break;
        case 4:
            emptyCategory();
            break;
        case 5:
            modifyCategoryName();
            break;
        case 6:
            searchWord();
            break;
        case 7:
            showWordsStartingWith();
            break;
        case 8:
            loadFromFile();
            break;
        case 9:
            saveToFile();
            break;
        case 0:
            cout << "Exiting category management module...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } 
	while (choice != 0);            // Exit the loop when the user chooses 0
}

/**
 * Task 3 - #3b Menu for interactive dialogue
 * A method that displays the menu for the interactive dialogue
 * and returns the user's choice.
 * @return The user's choice
*/

int WordCat::menu() 
{
	// Display the menu
    cout << "===========================\n";
    cout << "Word Category: " << category << endl;
    cout << "===========================\n";
    cout << "1. Print all the words in this category\n";
    cout << "2. Insert a new word into this category\n";
    cout << "3. Remove a given word from this category\n";
    cout << "4. Empty this category\n";
    cout << "5. Modify the category name\n";
    cout << "6. Search for a specific word in this category\n";
    cout << "7. Show all the words starting with a given letter\n";
    cout << "8. Load from a text file\n";
    cout << "9. Save to a text file\n";
    cout << "0. Exit\n";
    cout << " ===========================\n";
    cout << "Enter Your Choice: ";
   
	int choice;             // Initialize the choice variable as an integer

	cin >> choice;		    // Get the user's choice

    /**
	 * This section validates the user's input.
	 * If the input is invalid, it clears the error state,
	 * ignores the rest of the line, and asks the user to enter a number.
	 * It clears the error state because the user may have entered a character
	 * instead of a number, which would cause the program to enter an infinite loop.
	 * It ignores the rest of the line to prevent the program from reading the same
	 * invalid input again.
    */

	while (cin.fail())      // Validate the input     
    {	
        cin.clear();        // Clear the error state
        cin.ignore(1000, '\n'); // Ignore the rest of the line
        cout << "Invalid input. Please enter a number: ";
        
		cin >> choice;      // Get the user's choice again
    }
    
    cin.ignore(1000, '\n'); // Ignore the rest of the line

    return choice;
}

/**
 * Task 3 - #3c Helper method to print all words in the category
 * If the list is empty, it prints a message. Otherwise, it prints all the words.
 */

void WordCat::printAllWords() 
{
    cout << "Listing all words in the category: " << category << endl;       

	if (wordList.isEmpty())          // If the list is empty              
    {                                  
		cout << "Sorry, empty category: " << category << endl; // Print a message
        cout << endl;
        return;
    }
    else 
    {
		wordList.print(cout); // otherwise, print all the words
        cout << endl;
    }
}

/***
 * Task 3 - #3d Method to insert a new word into the category
 * It prompts the user to enter a word and inserts it into the category
 * in sorted order.
 */

void WordCat::insertWord() 
{
	// Prompt the user to enter a word and insert it into the category
    cout << "Inserting a new word into the category " << category << endl;
    cout << "Enter a word in the category '" << category << "' \n";

	Word newWord;       // Initialize a new Word object
	cin >> newWord;     // Get the word from the user

	if (newWord.length() == 0) // Validate the input
    {
		cout << "Invalid input. Please enter a word." << endl;
        cout << endl;
		return;
	}
    else
    {
        wordList.insertSorted((newWord)); // Insert in sorted order
        cout << "Inserted the word '" << newWord << "' into the category '" << category << "'\n";
        cout << endl;
    }
}

/**
* Task 3 - #3e Method to remove a given word from the category
* It prompts the user to enter a word and removes it from the category.
* If the word is not found, it prints a message.
*/

void WordCat::removeWord() 
{
    // Prompt the user to enter a word and remove it from the category
    cout << "Removing a given word from the category " << category << endl;
    cout << "Enter the word to remove from the category: '" << category << "'\n";
    
	Word wordToRemove;      // Initialize a new Word object
	cin >> wordToRemove;	// Get the word from the user
   
	if (!wordList.remove(wordToRemove))     // If the word is not found
    {       
        cout << "Word " << wordToRemove << " not found in the category " << category << endl;
        cout << endl;
    }
	else                                    // Otherwise, remove the word
    {                                      
        cout << "Removed the word '" << wordToRemove << "' from the category '" << category << "'\n";
        wordList.remove(wordToRemove);
        cout << endl;
    }
}

/**
 * Task 3 - #3f Method to empty the category
 * It empties the category by reassigning an empty WordList.
*/

void WordCat::emptyCategory() 
{
    cout << "Emptying the category: " << category << endl;
	wordList = WordList(); // Reassign an empty WordList
	cout << "Category " << category << " is now empty.\n";
	cout << endl;
}

/**
 * Task 3 - #3g Method to modify the category name
 * It prompts the user to enter a new name for the category and modifies it.
 * The category name is modified by calling the setCategoryName method.
 */

void WordCat::modifyCategoryName() 
{
	// Prompt the user to enter a new name for the category and modify it
    cout << "Modifying the name of the category " << category << endl;
    cout << "Enter a modified name for the category currently named: '" << category << "'\n";
    
	Word newCategoryName;   // Initialize a new Word object 
	cin >> newCategoryName; // Get the new category name from the user
	
	setCategoryName(newCategoryName); // Modify the category name

	cout << "Category name modified to: " << category << endl;
	cout << endl;
}

/**
 * Task 3 - #3h Method to search for a specific word in the category
 * * It prompts the user to enter a word and searches for it in the category.
 * * If the word is found, it prints a message. Otherwise, it prints a message.
*/

void WordCat::searchWord() 
{
	// Prompt the user to enter a word and search for it in the category
    cout << "Searching for a specific word in the category " << category << endl;
    cout << "Enter the word to search for in the category '" << category << "'\n";
    
	Word wordToSearch;   // Initialize a new Word object
	cin >> wordToSearch; // Get the word from the user


	if (wordList.lookup(wordToSearch))      // If the word is found
    { 
        cout << "Word found: the word '" << wordToSearch << "' is in the list of the category '" << category << "'\n";
		cout << endl;
    }
	else                                    // Otherwise, print a message
    {
        cout << "Word NOT found: the word '"<< wordToSearch <<"' is NOT in the list of the category '" << category << "'\n";
        cout << endl;
    }
}

/**
 * Task 3 - #3i Method to show all the words starting with a given letter
 * It prompts the user to enter a letter and shows all the words starting with it.
 * If no words are found, it prints a message.
*/

void WordCat::showWordsStartingWith() 
{
	cout << "Showing all words starting with a given letter" << endl; 
    cout << "Enter the first letter of the words in the category named '" << category << "' " << endl;       // Prompt the user
    char initial;
    cin >> initial;

    cin.ignore(1000, '\n'); // Ignore the rest of the line

    WordList wordsStartingWithInitial = wordList.getWordsStartingWith(initial);

    if (wordsStartingWithInitial.isEmpty()) 
    {
        cout << "No words starting with " << initial << " found.\n";
        cout << endl;
    }
    else {
		cout << "Words beginning with " << initial << " in the category " << category << endl;
        wordsStartingWithInitial.print(cout, 1);
        cout << endl;
    }
}

/**
 * Task 3 - #3j Method to load words from a text file into the category
 * It prompts the user to enter the name of the file containing the words in the category.
 * It reads the file and loads the words into the category.
 */

void WordCat::loadFromFile() 
{
	// Prompt the user to enter the name of the file containing the words in the category
    cout << "Loading from a text file" << endl;
    cout << "Enter the name of the file containing the words in the category: " << category << endl;
    
	wordList = WordList(); // Reassign an empty WordList

	Word filename;      // Initialize a new Word object
	cin >> filename;    // Get the filename from the user
    
	if (!validateInputFile(filename.c_str()))  // Validate the input file
    {
        return;
    }

	std::ifstream inFile(filename.c_str());	   // Open the file

    Word line;
	bool isFirstLine = true;                    // Flag to skip the first line

	while (!inFile.eof())                       // while the file is not at the end
    {
		line.read(inFile);					    // Read the line
        
        if (isFirstLine) // Skip the first line
        {
            isFirstLine = false;
            continue;
        }

        if (line.length() > 0)                  // If the line is not empty
        {
        Word newWord(line);
		wordList.insertSorted(newWord);  // Insert the word in sorted order
        }
    }

	inFile.close();							                // Close the file

	cout << "Words loaded from file " << filename << endl; // Print a message
    cout << endl;
}

/**
 * Task 3 - #3ki Method to save words from the category to a text file
 * It saves the words to the file using the category name as filename.
 */

void WordCat::saveToFile() 
{
    cout << "Saving to a text file" << endl;
    cout << "Enter the name of the file to save the words: " << endl; // Prompt the user for the file name

    Word filename;                         // Create a word to store the filename
    cin >> filename;                       // Read the filename from the user

    if (filename.length() == 0)            // Validate the input
    {
        cout << "Invalid input. Please enter a file name." << endl;
        cout << endl;
        return;
    }
    else if (getWordList().getSize() == 0)                     // Check if there are any words to save
    {
        cout << "No words to save." << endl;
        cout << "Try adding a few words" << endl;
        cout << endl;
        return;
    }
    else
    {
        std::ofstream outFile(filename.c_str()); // Open the file for writing

       if (!outFile) // Check if the file was opened successfully
       {
           cout << "Failed to open the file " << filename << endl;
           cout << endl;
           return;
       }

       printCategoryAndWords(outFile); // Print the category and its words
       outFile << endl; // Add a new line
       
       outFile.close();
       cout << "Words saved to file " << filename << endl;
       cout << endl;
    }
}

/**
 * Task 3 - #3kii Method Print Category and Words
 * A method that prints all the words in the category.
 * It follows the layout set by the assignment.
*/

void WordCat::printCategoryAndWords(std::ostream& os) const
{
    os << "#" << category.c_str() << std::endl; // Print the category name

    for (int i = 0; i < wordList.getSize(); i++) // Iterate over the words in the WordList
    {
        const Word& word = wordList.fetchWord(i); // Fetch the word using the fetchWord method
        os << word.c_str() << std::endl; // Print the word followed by a newline
    }
}

/**
 * Task 3 - #4 Overloaded insertion operator<<
 * Overloaded insertion operator that prints the category name and the word list.
 * @param os The output stream
 * @param wc The WordCat object to print
 * @return The output stream
 */

std::ostream& operator<<(std::ostream& os, const WordCat& wordCat) 
{
    os << "Category: " << wordCat.getCategoryName() << std::endl;
    os << "Words: " << std::endl;
    os << wordCat.getWordList();
    return os;
}

/**
 * Task 3 - Extra #1 Method to copy the values of another WordCat object
 * @param other The WordCat object to copy
 */

void WordCat::copy(const WordCat& other)
{
    category = other.category;
    wordList = other.wordList;
}

/**
 * Task 3 - Extra #2 Method to release the ownership of the category and the word list
 */

void WordCat::releaseOwnership()
{
    category = Word();
    wordList = WordList();
}

/**
 * Task 3 - Extra #3 Method to set the category name
 * @param newCategory The new category name
 */
void WordCat::setCategoryName(const Word& newCategory)
{
    category = newCategory;
}

/**
 * Task 3 - Extra #4 Method to get the category name
 * @return The category name
*/

Word WordCat::getCategoryName() const 
{
	return category;
}

/**
 * Extra #5 Method to get the WordList object
 * @return The WordList object
*/

WordList WordCat::getWordList() const 
{
    return wordList;
}

/**
 * Extra #6 Method to get the WordList object and change it
 * @return The WordList object
*/

WordList& WordCat::returnWordListRef() 
{
    return wordList;
}

/**
 * Extra #7 method to validate the input file
 * It checks if the file is a text file, if it is open, if it is empty,
 * and if it starts with a category name.
 * @param fileName The name of the file to validate
 * @return True if the file is valid, false otherwise
 */

bool WordCat::validateInputFile(const char* filename) 
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

	if (inFile.peek() == std::ifstream::traits_type::eof())     // Peek () the first character of the file
	{                                                           // if it is the end of the file
        cout << "File is empty." << endl;
        cout << endl;
        return false;
    }
    
	char firstChar = inFile.peek();                     // Peek() the first character of the file
	if (firstChar != '#') 							    // If the file does not start with a '#'
    {
        cout << "File does not start with a category name." << endl;
        cout << endl;
        return false;
    } 

	char ch;                  // Initialize a char variable to read the file and skip the first line
	while (inFile.get(ch) && ch != '\n'); // ch not equal to '\n' to skip the first line
    
	bool foundAdditionalHash{ false }; // Flag to check if there is an additional hash in the file

	while (inFile.get(ch))			   // Read the file
    {
		if (ch == '#')                 // If there is a hash
        {
            foundAdditionalHash = true;
            break;
        }
    }

	if (foundAdditionalHash) // If there is an additional hash print an error message
    {
        cout << "File contains more than one category. Only one category is allowed per file." << endl;
        cout << endl;
        return false;
    }

    inFile.close();
    return true;
}

