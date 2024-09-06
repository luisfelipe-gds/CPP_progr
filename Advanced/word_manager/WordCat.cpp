/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 2 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Due Date: June 14th, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. 
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

#include "WordCat.h"

 // Conversion constructor
WordCat::WordCat(const string& name) : cat_name(name), word_list() {};

// Copy constructor
WordCat::WordCat(const WordCat& cat) = default;

// Move constructor
WordCat::WordCat(WordCat&& cat) noexcept = default;

// Copy assignment operator
WordCat& WordCat::operator=(const WordCat& rhs) = default;

// Move assignment operator
WordCat& WordCat::operator=(WordCat&& rhs) noexcept = default;

 // Destructor
WordCat::~WordCat() = default;

// menu()
int WordCat::menu() const
{
    // Display the menu
    cout << "===========================\n";
    cout << "Word Category: " << cat_name << endl;
    cout << "===========================\n";
    cout << "1. Print Words in Category (5 per line)\n";
    cout << "2. Append Word to Category\n";
    cout << "3. Remove Word from Category\n";
    cout << "4. Clear Category\n";
    cout << "5. Modify Category Name\n";
    cout << "6. Search for Word in Category\n";
    cout << "7. Show Sorted Words in Category\n";
    cout << "8. Load Category from Text File\n";
    cout << "9. Save Category to Text File\n";
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        cout << "Invalid input. Please enter a number: ";

        cin >> choice;      // Get the user's choice again
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line

    return choice;
}

// run()
void WordCat::run()
{
	int choice; // variable to store the user's choice

	do
	{
		choice = menu(); // Display the menu and get the user's choice

		switch (choice)		// Switch statement to execute the user's choice
		{
		case 1:
			// Print Words in Category
			printWordsInCategory();
			break;
		case 2:
			// Append Word to Category
			appendWord();
			break;
		case 3:
			// Remove Word from Category
			removeWord();
			break;
		case 4:
			// Clear Category
			clearCategory();
			break;
		case 5:
			// Modify Category Name
			modifyCategoryName();
			break;
		case 6:
			// Search for Word in Category
			searchWord();
			break;
		case 7:
			// Show Sorted Words in Category
			show_sorted(cout);
			break;
		case 8:
			// Load Category from Text File
			loadCategory();
			break;
		case 9:
			// Save Category to Text File
			saveCategory();
			break;
		case 0:
			cout << "Exiting category management module...\n";
			cout << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a number between 0 and 9\n"; // Invalid choice
		}
	} while (choice != 0);
}

// write(std::ostream&, size_t) const
void WordCat::write(std::ostream& sout, size_t n) const
{
	sout << "Category: " << cat_name << endl;
	sout << "Words: " << endl;
	word_list.write(sout, n);
	sout << endl;
}

// show_sorted()
void WordCat::show_sorted(std::ostream& sout, size_t n) const
{
	if (word_list.isEmpty()) // If the list is empty
	{
		sout << "The category is empty. There are no words to sort." << endl;
		sout << endl;
		return;
	}
	else
	{
		cout << "Displaying all words in the category '" << cat_name << "' sorted." << endl;

		WordList sortedList = sortWordList(word_list); // Sort the word_list
		WordList::MAX_WORD_LENGTH = 1; // Initialize the MAX_WORD_LENGTH to 1
		sortedList.setMaxLength(); // Set the MAX_WORD_LENGTH to the length of the longest word in the list
		sortedList.write(sout);   // Write the sorted list
		sout << endl;
		sout << endl;
	}
}

// processCategoryFromFile(std::ifstream&, WordList&)
void WordCat::processCategoryFromFile(std::ifstream& file, WordList& repeatedWords)
{
	string line;	// Initialize a new string
	bool isMatchingCategory = false;  // Initialize a bool to check if the category matches

	while (std::getline(file, line))  // Read the file line by line
	{
		if (line.substr(0, 1) == "#") // Check if the line is a category
		{
			Word currentCat = trim(line.substr(1));		   // Get the category name trimmed
			isMatchingCategory = (currentCat == cat_name); // Check if the category matches
		}
		else if (isMatchingCategory)		// If the category matches
		{
			Word newWord(trim(line));		// Get the word trimmed
			
			if (newWord.length() == 0)		// If the word is empty
			{
				continue;
			} 
			else if (word_list.lookup(newWord))  // If the word is already in the category
			{
				repeatedWords.push_back(trim(line)); // Add the word to the repeatedWords list
			}
			else                                    // If the word is not in the category
			{
				word_list.push_back(trim(line)); // Add the word to the category
			}
		}
	}
}

// getWordList() const A method that returns the word_list
const WordList& WordCat::getWordList() const
{
	return word_list;
}

// getCatName() const
const Word& WordCat::getCatName() const
{
	return cat_name;
}

// saveCategoryToFile() A method that saves the category to a text file
void WordCat::saveCategoryToFile(const string& fileName) const
{
	std::ofstream outputFile(fileName, std::ios::app); // Open the file in append mode

	if (!outputFile.is_open()) //checks if the file is open
	{
		cout << "Failed to open the file." << endl;
		cout << endl;
		return;
	}

	printCategoryAndWords(outputFile); // Print the category and words to the file
	outputFile << endl; // Add a newline at the end of the file
	outputFile.close(); // Close the file
}

// printCategoryAndWords(std::ostream&) const
void WordCat::printCategoryAndWords(std::ostream& os) const
{
	os << "#" << cat_name.getStr() << std::endl; // Print the category name

	for (Word word : word_list.getDoublyLinkedList()) // Iterate over the words in the WordList
	{
		os << word.getStr() << std::endl; // Print the word followed by a newline
	}
}

// printWordsInCategory() 
void WordCat::printWordsInCategory() const
{
	cout << "Listing all words in the category: " << cat_name << endl;
	cout << endl;

	if (word_list.isEmpty())          // If the list is empty              
	{
		cout << "Sorry, empty category: " << cat_name << endl; // Print a message
		cout << endl;
		return;
	}
	else
	{
		WordList::MAX_WORD_LENGTH = 1; // Initialize the MAX_WORD_LENGTH to 1
		word_list.setMaxLength(); // Set the MAX_WORD_LENGTH to the length of the longest word in the list
		write(cout);
		cout << endl;
	}
}

// appendWord()
void WordCat::appendWord()
{
	// Prompt the user to enter a word and insert it into the category
	cout << "Inserting a new word into the category: " << cat_name << endl;
	cout << "At any time, press Enter to stop adding words.\n";
	cout << "Enter a word in the category '" << cat_name << "' \n";

	Word newWord;       // Initialize a new Word object
	cin >> newWord;     // Get the word from the user

	if (newWord.length() == 0) // If the input is empty
	{
		cout << "Invalid input. Please enter a word." << endl;
		cout << endl;
		return;
	}
	else
	{
		while (newWord.length() != 0) // While the user do not press Enter
		{
			if (word_list.lookup(newWord)) // If the word is already in the category
			{
				cout << endl;
				cout << "The word " << newWord << " is already in the category '" << cat_name << "'\n";
				cout << "Enter another word in category'" << cat_name << "' \n";
				cin >> newWord;				  // Get the word from the user
			} 
			else
			{
				cout << endl;
				word_list.push_back(newWord); // Append the word to the category
				cout << "The word " << newWord << " has been added to the category '" << cat_name << "' \n";
				cout << "Enter a word in the category '" << cat_name << "' \n";
				cin >> newWord;				  // Get the word from the user
			}
		}
	}
}

// removeWord() 
void WordCat::removeWord()
{
	// Prompt the user to enter a word to remove from the category
	cout << "Removing a word from the category: " << cat_name << endl;
	cout << "Enter a word to remove from the category '" << cat_name << "' \n";

	Word wordToRemove;      // Initialize a new Word object
	cin >> wordToRemove;    // Get the word from the user

	if (wordToRemove.length() == 0) // If the input is empty
	{
		cout << "Invalid input. Please enter a word." << endl;
		cout << endl;
		return;
	}
	else if (word_list.isEmpty()) // If the list is empty
	{
		cout << "The category is empty. There are no words to remove." << endl;
		cout << endl;
		return;
	}
	else if (!word_list.lookup(wordToRemove)) // If the word is not in the category
	{
		cout << "The word " << wordToRemove << " was not found in the category." << endl;
		cout << endl;
		return;
	}
	else
	{
		word_list.remove(wordToRemove); 		// If the word is in the category, remove it
		cout << "The word " << wordToRemove << " has been removed from the category '" << cat_name << "' \n";
		cout << endl;
	}
}

// clearCategory()
void WordCat::clearCategory()
{
	cout << "Emptying the category: " << cat_name << endl;

	while (!word_list.isEmpty())  // While the list is not empty, remove the first element
	{
		word_list.pop_front();
	}
	cout << "Category '" << cat_name << "' is now empty.\n";
	cout << endl;
}

// modifyCategoryName()
void WordCat::modifyCategoryName()
{
	// Prompt the user to enter a new category name
	cout << "Modifying the category name: " << cat_name << endl;
	cout << "Enter a new name for the category '" << cat_name << "' \n";

	Word newName;     // Initialize a new string
	cin >> newName;     // Get the new name from the user

	if (newName.length() == 0) // If the input is empty
	{
		cout << "Invalid input. Please enter a name." << endl;
		cout << endl;
		return;
	}
	else
	{
		cat_name.set(newName); // Modify the category name
		cout << "The category name has been modified to: " << cat_name << endl;
		cout << endl;
	}
}

// searchWord() 
void WordCat::searchWord() const
{
	// Prompt the user to enter a word to search for in the category
	cout << "Searching for a word in the category: " << cat_name << endl;
	cout << "Enter a word to search for in the category '" << cat_name << "' \n";

	Word wordToSearch;      // Initialize a new Word object
	cin >> wordToSearch;    // Get the word from the user

	if (wordToSearch.length() == 0) // If the input is empty
	{
		cout << "Invalid input. Please enter a word." << endl;
		cout << endl;
		return;
	}
	else if (word_list.isEmpty()) // If the list is empty
	{
		cout << "The category is empty. There are no words to search for." << endl;
		cout << endl;
		return;
	}
	else if (!word_list.lookup(wordToSearch)) // Search for the word in the category
	{
		cout << "The word " << wordToSearch << " was not found in the category." << endl;
		cout << endl;
		return;
	}
	else // The word is in the category
	{
		cout << "The word " << wordToSearch << " was found in the category." << endl;
		cout << endl;
	}
}

// loadCategory()
void WordCat::loadCategory()
{
	// Prompt the user to enter the name of the file to load
	cout << "Loading a category from a text file." << endl;
	cout << "Enter the name of the file to load: ";

	string fileName;    // Initialize a new string
	cin >> fileName;    // Get the file name from the user

	if (!validateInputFile(fileName)) // Run checks on the input file, if it is invalid return
	{
		return;
	}
	else // If the file is valid, process the category
	{
		std::ifstream file(fileName); // Open the file

		if (!file.is_open()) //checks if the file is open
		{
			cout << "Error: File not found." << endl;
			cout << "Please enter a valid file name." << endl;
			cout << endl;
			return;
		}

		WordList repeatedWordsList; // create a WordList object to store the repeated words

		processCategoryFromFile(file, repeatedWordsList); // Process the category from the file

		cout << "The words not already in category '" << cat_name << "' have been loaded from file: " << fileName << endl;
		cout << endl;

		if (!repeatedWordsList.isEmpty()) // If there are repeated words
		{
			cout << "The following words are repeated or were already in category '" << cat_name << "': " << endl;
			repeatedWordsList.write(cout); // Write the repeated words
			cout << endl;
			cout << endl;
		}
		else // If there are no repeated words
		{
			cout << "All words from file '" << fileName << "' were loaded in category '" << cat_name << "'. \n";
			cout << endl;
		}
		file.close(); // Close the file
	}
}

// saveCategory() const A method that saves the category to a text file
void WordCat::saveCategory() const
{
	// Prompt the user to enter the name of the file to save
	cout << "Saving the category to a text file." << endl;
	cout << "Enter the name of the file to save: ";

	string fileName;    // Initialize a new string
	cin >> fileName;    // Get the file name from the user

	if (fileName.length() == 0) // If the input is empty
	{
		cout << "Invalid input. Please enter a file name." << endl;
		cout << endl;
		return;
	}
	else if (!(fileName.substr(fileName.length() - 4, 4) == ".txt")) // If the file name does not have the .txt extension
	{
		cout << "Invalid file name. Please enter a different file name." << endl;
		cout << endl;
		return;
	}
	else if (word_list.isEmpty()) // if the list is empty
	{
		cout << "No words to save." << endl;
		cout << "Try adding a few words" << endl;
		cout << endl;
		return;
	}
	else // If the input is valid
	{
		saveCategoryToFile(fileName); // Save the category to the file
		cout << "The category '" << cat_name << "' has been saved to file: " << fileName << endl;
		cout << endl;
	}
}

// overloaded operator==(const WordCat&, const WordCat&)
bool operator==(const WordCat& lhs, const WordCat& rhs)
{
	return lhs.getCatName() == rhs.getCatName();
}

// pverloaded operator<<(std::ostream&, const WordCat&)
std::ostream& operator<<(std::ostream& sout, const WordCat& cat)
{
	cat.write(sout); // Calls the write method of the WordCat class
	return sout;
}

// sortWordList(const WordList&)
WordList sortWordList(const WordList& wl)
{
	std::forward_list<Word> flist  // creates a forward_list with the elements of the list
	{
		wl.getSinglyLinkedList()			// calls the getSinglyLinkedList method of the WordList class
	};

	flist.sort();				// sorts the flist
	WordList sortedList;		// creates a new WordList object

	for (const Word& word : flist) // for each word in the flist insert it in the sortedList
	{
		sortedList.push_back(word);
	}
	return sortedList;			// returns the sortedList
}


// validateInputFile(const string&)
bool validateInputFile(const string& fileName)
{
	std::ifstream file(fileName); // Open the file
	if (!file.is_open())		  // Checks if the file is open
	{
		cout << "Error: File not found." << endl;
		cout << "Please enter a valid file name." << endl;
		cout << endl;
		return false;
	}

	if (file.peek() == std::ifstream::traits_type::eof()) // Checks if the file is empty
	{
		cout << "Error: File is empty." << endl;
		cout << "Please enter a valid file." << endl;
		cout << endl;
		file.close();
		return false;
	}

	std::string extension = ".txt";		         // Set the file extension
	size_t fileNameLength = fileName.length();   // Get the length of the file name
	size_t extensionLength = extension.length(); // Get the length of the extension

	if (fileNameLength > extensionLength) // Checks if fileName a valid size
	{
		// Compare the file extension with the last characters of the file name
		int comparisonResult = fileName.compare(fileNameLength - extensionLength, extensionLength, extension);

		if (comparisonResult != 0)		// Checks if the comparison result is not 0 (not equal)
		{
			cout << "Error: Invalid file extension." << endl;
			cout << "Please enter a valid file name." << endl;
			cout << endl;
			file.close();
			return false;
		}
	}
	else
	{
		cout << "Error: Invalid file extension." << endl;
		cout << "Please enter a valid file name." << endl;
		cout << endl;
		file.close();
		return false;
	}

	file.close(); // Close the file after all checks are done
	return true;
}
