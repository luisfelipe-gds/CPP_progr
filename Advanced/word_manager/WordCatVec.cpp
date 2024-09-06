 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. 
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

#include "WordCatVec.h"
 
// Default constructor
WordCatVec::WordCatVec() = default;


// Copy constructor
WordCatVec::WordCatVec(const WordCatVec& vec) = default;


// Move constructor
WordCatVec::WordCatVec(WordCatVec&& vec) noexcept = default;


// Copy assignment operator
WordCatVec& WordCatVec::operator=(const WordCatVec& rhs) = default;


// Move assignment operator
WordCatVec& WordCatVec::operator=(WordCatVec&& rhs) noexcept = default;


// Destructor
WordCatVec::~WordCatVec() = default;

// menu()
int WordCatVec::menu()
{
	// Display the menu
    cout << "===========================\n";
    cout << "Word Vocabulary Center\n";
    cout << "===========================\n";
    cout << "1. Print all Categories\n";
    cout << "2. Add a New Category (Sorted)\n";
    cout << "3. Remove a Category\n";
    cout << "4. Clear a Category\n";
    cout << "5. Interact with a Category\n";
    cout << "6. Show Words in All Categories (Sorted)\n";
    cout << "7. Show All Categories (Sorted Individually)\n";
    cout << "8. Load from text file\n";
    cout << "9. Save to text file\n";
    cout << "0. Exit\n";
    cout << "===========================\n";
    cout << "Enter Your Choice: ";

    int choice;             // variable to store the user's choice
    cin >> choice;		    // read the user's choice

    while (cin.fail())      // validate the user's input
    {
        cin.clear();        // Clear the error state
        cin.ignore(1000, '\n'); // Ignore the rest of the line

        cout << "Invalid input. Please enter a number: ";
        cin >> choice; 	    // Read the user's choice again
    }
    cin.ignore(1000, '\n');  // Ignore the rest of the line

    return choice;
}

// run()
void WordCatVec::run()
{
	int choice; // variable to store the user's choice

	do
	{
		choice = menu(); // display the menu and get the user's choice

		switch (choice)
		{
		case 1:
			printAllCategories();
			break;
		case 2:
			addNewCategory();
			break;
		case 3:
			removeCategory();
			break;
		case 4:
			clearCategory();
			break;
		case 5:
			interactWithCategory();
			break;
		case 6:
			showAllWordsSorted();
			break;
		case 7:
			showAllCategories();
			break;
		case 8:
			loadCategories();
			break;
		case 9:
			saveVector();
			break;
		case 0:
			cout << "Exiting the program...\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number between 0 and 9\n";
			break;
		}
	} while (choice != 0);
}

// printAllCategories()
void WordCatVec::printAllCategories() const
{
	cout << "Print all the categories and words" << endl;
	cout << endl;
	
	if (theVector.size() == 0)      // Check if there are any categories to print
	{
		cout << "No categories to print" << endl;
		cout << "Try adding a new category and words in the category" << endl;
		cout << endl;
	}
	else
	{
		setMaxLengthAllCategories(); // Set the MAX_WORD_LENGTH to longest word 

		for (const WordCat& cat : theVector) // Loop through all categories
		{
			if (!cat.getWordList().isEmpty())
			{
				cat.write(cout); // Print the words in the category
				cout << endl;
			}
			else
			{
				cout << "Category: " << cat.getCatName() << endl;
				cout << "No words in this category." << endl;
				cout << endl;
			}
		}
	}
}

// addNewCategory()
void WordCatVec::addNewCategory()
{
	// Prompt the user to enter a word and insert it into the category
	cout << "Inserting a new category into the vocabulary. \n";
	cout << endl;
	cout << "At any time, press Enter to stop adding categories.\n";
	cout << "Enter a category name: ";

	string categoryToAdd;
	getline(cin, categoryToAdd); // Read the user's input

	if (categoryToAdd.length() == 0)         // Validate the input
	{
		cout << "Invalid input. Please enter a word." << endl;
		cout << endl;
		return;
	}
	else
	{
		while (categoryToAdd.length() != 0) // Loop until the user presses Enter
		{
			if (lookupCategory(categoryToAdd))  // Check if the category already exists
			{
				cout << endl;
				cout << "Category already exists.\n";
				cout << "Please enter a different category name: ";
				getline(cin, categoryToAdd); // Read the user's input
			}
			else
			{
				insertCategorySorted(categoryToAdd);   // Insert the new category in the vector
				cout << endl;
				cout << "Category " << categoryToAdd << " added successfully. \n";
				cout << "Enter a category name: ";
				getline(cin, categoryToAdd); // Read the user's input
				
			}

		}
	}
}

// insertCategorySorted()
void WordCatVec::insertCategorySorted(const string& cat)
{
	WordCat newCategory(cat);

	if (theVector.empty())          // Check if the vector is empty and add the category
	{
		theVector.push_back(cat);
		return;
	}
	
	/*
	 * Find the position to insert the new category by comparing the category name
	 * with the existing categories. If the category name is less than the existing
	 * category name, insert the new category before the existing category. 
	 */
	auto it = std::find_if(theVector.begin(), theVector.end(), [cat](const WordCat& category) 
		{ 
			return cat < category.getCatName().getStr(); 
		}); 
	
	theVector.insert(it, newCategory); // Insert the new category in the vector
}

// removeCategory()
 void WordCatVec::removeCategory()
 {
	 cout << "Removing a given category" << endl;
	 cout << "Enter the name of the category to remove: "; // Prompt the user for the category to remove

	 string categoryToRemove;
	 getline(cin, categoryToRemove); // Read the user's input
	 
	 if (categoryToRemove.length() == 0)         // Validate the input
	 {
		 cout << "Invalid input. Please enter a word." << endl;
		 cout << endl;
	 }
	 else if (!lookupCategory(categoryToRemove))  // Check if the category exists
	 {
		 cout << "Category does not exist." << endl;
		 cout << endl;
	 }
	 else
	 {
		 size_t index = searchCategory(categoryToRemove); // Get the index of the category
		 theVector.erase(theVector.begin() + index);      // Remove the category from the vector

		 cout << "Category '" << categoryToRemove << "' removed successfully." << endl;
		 cout << endl;
	 }
 }

 // clearCategory()
 void WordCatVec::clearCategory()
 {
	 cout << "Emptying a category" << endl;
	 cout << "Enter the name of the category to clear: "; // Prompt the user for the category to clear

	 string categoryToClear;
	 getline(cin, categoryToClear); // Read the user's input

	 if (categoryToClear.length() == 0)         // Validate the input
	 {
		 cout << "Invalid input. Please enter a word." << endl;
		 cout << endl;
	 }
	 else if (!lookupCategory(categoryToClear))  // Check if the category exists
	 {
		 cout << "Category does not exist." << endl;
		 cout << endl;
	 }
	 else
	 {
		 size_t index = searchCategory(categoryToClear); // Get the index of the category
		 theVector[index] = WordCat(categoryToClear);    // Clear the category

		 cout << "Category " << categoryToClear << " cleared successfully." << endl;
		 cout << endl;
	 }
 }

// interactWithCategory()
void WordCatVec::interactWithCategory()
{
	cout << "Interacting with a category" << endl;
	cout << "Enter the name of the category to interact with: "; // Prompt the user for the category name

	string categoryToInteract;
	getline(cin, categoryToInteract); // Read the user's input

	if (categoryToInteract.length() == 0)         // Validate the input
	{
		cout << "Invalid input. Please enter a word." << endl;
		cout << endl;
	}
	else if (!lookupCategory(categoryToInteract))  // Check if the category exists
	{
		cout << "Category does not exist." << endl;
		cout << endl;
	}
	else
	{
		cout << "Interacting with category: " << categoryToInteract << endl;
		cout << endl;
		size_t index = searchCategory(categoryToInteract); // Get the index of the category
		theVector[index].run(); // Run the interactive dialogue for the selected category
	}
}

// showAllWordsSorted()
void WordCatVec::showAllWordsSorted()
{
	cout << "Show all words in all categories sorted" << endl;
	cout << endl;

	if (theVector.size() == 0)      // Check if there are any categories to print
	{
		cout << "No categories to print" << endl;
		cout << "Try adding a new category and words in the category" << endl;
		cout << endl;
	}
	else
	{
		WordList allWordsList; 

		for (WordCat& cat : theVector) // Loop through all categories
		{
			for (const Word& word : cat.getWordList().getDoublyLinkedList()) // Loop through all words in the category
			{
				allWordsList.push_back(word); // Add the word to the WordList
			}
		}

		WordList sortedAllWordsList = sortWordList(allWordsList);
		
		cout << "All words in all categories sorted: " << endl;
		sortedAllWordsList.setMaxLength(); // Set the MAX_WORD_LENGTH to the length of the longest word in the category
		sortedAllWordsList.write(cout); // Write the sorted words
		cout << endl;
		cout << endl;
	}
}

// showAllCategories()
void WordCatVec::showAllCategories()
{
	cout << "Show all categories and the respective words sorted individually" << endl;
	cout << endl;

	if (theVector.size() == 0)      // Check if there are any categories to print
	{
		cout << "No categories to print" << endl;
		cout << "Try adding a new category and words in the category" << endl;
		cout << endl;
	}
	else
	{
		setMaxLengthAllCategories(); // Set the MAX_WORD_LENGTH to the longest word

		for (WordCat cat : theVector) // Loop through all categories
		{
			WordList sortedWL = sortWordList(cat.getWordList()); // Sort the words in the category

			cout << "Category: " << cat.getCatName() << endl;
			cout << "Sorted Words: " << endl;
			sortedWL.write(cout); // Write the sorted words
			cout << endl;
			cout << endl;
		}
	}

}

// lookupCategory()
bool WordCatVec::lookupCategory(const WordCat& cat) const
{
	for (const WordCat& c : theVector) // Loop through all categories
	{
		if (c == cat) // Check if the category exists
		{
			return true;
		}
	}
	return false;
}

// searchCategory()
size_t WordCatVec::searchCategory(const WordCat& cat) const
{
	for (size_t i = 0; i < theVector.size(); i++) // Loop through all categories
	{
		if (theVector[i] == cat) // Check if the category exists
		{
			return i;
		}
	}
	return -1;
}

// loadCategories() 
void WordCatVec::loadCategories()
{
	cout << "Loading categories from a file" << endl;
	cout << "Enter the name of the file: "; // Prompt the user for the file name

	string fileName;
	getline(cin, fileName); // Read the user's input

	if (!validateInputFile(fileName))
	{
		return;
	}
	else
	{
	// Load the category from the file
	std::ifstream file(fileName); // Open the file

		addCategoriesFromFile(file); // Add the categories from the file

		file.clear(); // Clear the end-of-file flag
		file.seekg(0); // Move the file position indicator back to the beginning

		WordList repeatedWordsList; // Create a new WordList object to store the repeated words

		for (WordCat& cat : theVector) // Loop through all categories
		{
			cat.processCategoryFromFile(file, repeatedWordsList); // Process the category from the file
				
			if (!repeatedWordsList.isEmpty())
			{
				cout << "The following words are repeated or were already in category '" << cat.getCatName() << "': " << endl;
				repeatedWordsList.write(cout); // Write the repeated words
				cout << endl;
				cout << endl;
				repeatedWordsList.clear(); // Clear the repeated words list
			}

			file.clear(); // Clear the end-of-file flag
			file.seekg(0); // Move the file position indicator back to the beginning
		}

		cout << endl;
		cout << "The categories have been loaded from the file: " << fileName << endl;
		cout << endl;
		file.close(); // Close the file	
	}
	
}

// addCategoriesFromFile() 
void WordCatVec::addCategoriesFromFile(std::ifstream& file)
{
	string line; // variable to store the line read from the file

	while (std::getline(file, line)) // Read the file line by line
	{
		if (line[0] == '#') // Check if the line starts with '#'
		{
			if (!lookupCategory(trim(line.substr(1)))) // Check if the category already exists
			{
				string newCategory(trim(line.substr(1))); // Create a new category as a substring of the line
				insertCategorySorted(newCategory); // Insert the new category in the vector
			}
		}
	}
}

// push_back() 
void WordCatVec::push_back(const WordCat& cat)
{
	theVector.push_back(cat);
}

// saveVector() 
void WordCatVec::saveVector() const
{
	// Prompt the user to enter the name of the file to save
	cout << "Saving the categories to a text file." << endl;
	cout << "Enter the name of the file to save: ";

	string fileName;    // Initialize a new string
	cin >> fileName;    // Get the file name from the user

	if (fileName.length() == 0) // Validate the input
	{
		cout << "Invalid input. Please enter a file name." << endl;
		cout << endl;
		return;
	}
	else if (!(fileName.substr(fileName.length() - 4, 4) == ".txt"))
	{
		cout << "Invalid input. Please enter a file name with the extension '.txt' \n"; // Validate the input
		cout << endl;
		return;
	}
	else if (theVector.empty()) // Validate the input
	{
		cout << "No words to save." << endl;
		cout << "Try adding a few words" << endl;
		cout << endl;
		return;
	}
	else
	{
		for (const WordCat& cat : theVector) // Loop through all categories
		{
			cat.saveCategoryToFile(fileName); // Save the category to the file
		}
		
		cout << "The categories have been saved to file: " << fileName << endl;
		cout << endl;
	}
}

// write()
void WordCatVec::write(std::ostream& sout, size_t n) const
{
	setMaxLengthAllCategories(); // Set the MAX_WORD_LENGTH to the longest word 

	for (const WordCat& cat : theVector) // Loop through all categories
	{
		if (!cat.getWordList().isEmpty())
		{
			cat.write(sout, n); // Print the words in the category
			sout << endl;
		}
		else
		{
			sout << "Category: " << cat.getCatName() << endl;
			sout << "No words in this category." << endl;
			sout << endl;
		}
	}
}

// setMaxLengthAllCategories()
void WordCatVec::setMaxLengthAllCategories() const
{
	WordList::MAX_WORD_LENGTH = 1; // Initialize the MAX_WORD_LENGTH to 1
	for (const WordCat& cat : theVector) // Loop through all categories
	{
		cat.getWordList().setMaxLength(); // Set the MAX_WORD_LENGTH to the length of the longest word in the category
	}
}
