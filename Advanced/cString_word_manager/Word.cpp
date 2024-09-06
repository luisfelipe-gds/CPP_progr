/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description:
 * The Word class represents a word in a vocabulary. It is a simple class that
 * stores a C-style string and provides methods to manipulate the string.
 * *
 * The class has a default constructor, a conversion constructor, the Big Five
 * special member functions, and methods to get the length of the word, the C-style
 * string, change the word, concatenate two words, check if the word is less than
 * another word, and print the word.
 * ***************************************************************************
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include "Word.h"

/**
 * Task 1 - #1 Default constructor
 * A ctor that initializes the object to a default state receiving no arguments.
 * It creates a Word object with an empty string of size 0.
 */

Word::Word() 
{    
	word = new char[1];     // Allocate memory for the null character - this is an array of chars of size 1
	word[0] = '\0';         // Null-terminate the string
}

/**
 * Task 1 - #2 Conversion constructor
 * A ctor that takes a C-style string as an argument and converts it to a Word object.
 * It creates a Word object with the string passed as an argument.
 * @param str The C-style string to convert to a Word object
 */

Word::Word(const char* str) 
{
	size = std::strlen(str);    // Get the length of the string
	word = new char[size + 1];  // Allocate memory for the string - and array of chars of size (size + 1)
	strcpy(word, str);          // Copy the string
}

/**
 * Task 1 - #3 The Big Five
 * The so called Big Five are the five special member functions that a class should define
 * They are the copy constructor, the move constructor, the copy assignment operator,
 * the move assignment operator, and the destructor.
 */

/**
* Task 1 - #3a Copy constructor
* A ctor that initializes the object as a copy of another object.
* It creates a Word object as a copy of another Word object.
* @param other The Word object to copy
*/

Word::Word(const Word& other) 
{
	copy(other); // Copy the other object
}

/**
* Task 1 - #3b Move constructor
* A ctor that initializes the object by 'stealing' the resources from a temporary object.
* It creates a Word object by moving the resources from another Word object.
* @param other The Word object to move
*/

Word::Word(Word&& other) noexcept : 
	size(other.size),         // initialize the size with the size of the other object
	word(other.word) 	      // initialize the word with the word of the other object
    {
	other.releaseOwnership(); // Leaves the other object in a valid but empty state
}

/**
* Task 1 - #3c Copy assignment operator
* A ctor that copies the contents of another object to the current
* object using the assignment operator.
* @param other The Word object to copy
* @return A reference to the current object
*/
 
Word& Word::operator=(const Word& other) 
{
	if (this != &other)     // Check for self-assignment
    {
		releaseOwnership(); // Release the current object's resources
		copy(other);
    }
	return *this;           // Return a reference to the current object
}

/**
* Task 1 - #3d Move assignment operator
* A ctor that moves the contents of a temporary object to the current 
* object using the assignment operator.
* @param other The Word object to move
* @return A reference to the current object
*/

Word& Word::operator=(Word&& other) noexcept 
{
	if (this != &other)     // Check for self-assignment
    {
		releaseOwnership(); // Release the current object's resources
		copy(other);
		other.releaseOwnership();
    }
	return *this;		   // Return a reference to the current object
}

/*
* Task 1 - #3e Destructor
* The destructor is a special member function that is called when the object goes out of scope
* or when the delete operator is used to destroy the object.
*/

Word::~Word() 
{         
	releaseOwnership(); // Release the dynamically allocated memory
}

/**
 * Task 1 - #4 Accessor for word length
 * Accessor method that returns the length of the word.
 * @return The length of the word
 */

size_t Word::length() const 
{
    return size;
}

/**
 * Task 1 - #5 Accessor for C-style string
 * Accessor method that returns the C-style string.
 * @return The C-style string
 */

const char* Word::c_str() const 
{
    return word;
}

/**
 * Task 1 - #6a Mutator #1 to change the word
 * Mutator method that changes the word to another word.
 * @param other The Word object to change the word to
 */

void Word::changeWord(const Word& other) 
{
	delete[] word;
	copy(other);
}

/**
 * Task 1 - #6b Mutator #2 to change the word
 * Mutator method that changes the word to another word.
 * @param newWord The C-style string to change the word to
 */

void Word::changeWord(const char* newWord) 
{
	delete[] word;
	copy(Word(newWord));
}

/**
 * Task 1 - #7 Method to concatenate two words
 * Method that concatenates two words with a delimiter.
 * @param other The Word object to concatenate with
 * @param delimiter The delimiter to use
 * @return The concatenated Word object
 */

Word Word::concat(const Word& other, const char* delimiter) const 
{	
	size_t delimiterSize = std::strlen(delimiter);  // Get the length of the delimiter

	size_t resultSize = size + other.size + delimiterSize; // Calculate the size of the resulting string

	char* result = new char[resultSize + 1];                // Allocate memory for the resulting string
	
	strcpy(result, word);		// Copy the first word to the result
	strcat(result, delimiter);  // Concatenate the delimiter
	strcat(result, other.word); // Concatenate the second word

	Word newWord(result);	    // Create a new Word object with the resulting string
	delete[] result;			// Release the memory for the resulting string
	return newWord;			
}

/**
 * Task 1 - #8 Method to check if the word is less than another word
 * @param other The Word object to compare with
 * @return True if the word is less than the other word, false otherwise
 */

bool Word::isLess(const Word& other) const 
{
	// Check if the other word is empty or if its word member is a nullptr
	if (other.size == 0 || other.word == nullptr) return false;

	// Check if this word is empty or if its word member is a nullptr
	if (this->size == 0 || this->word == nullptr) return true;

	// Compare the strings
	return strcmp(word, other.word) < 0;
}

/**
 * Task 1 - #9 Overloaded insertion operator<<
 * Overloaded insertion operator that prints the Word object to the output stream.
 * @param os The output stream
 * @param word The Word object to print
 * @return The output stream
 */

std::ostream& operator<<(std::ostream& os, const Word& aWord) 
{
	os << aWord.c_str(); // Print the C-style string
    return os;
}

/**
 * Task 1 - #10 Overloaded extraction operator>>
 * Overloaded extraction operator that reads a Word object from the input stream.
 * @param is The input stream
 * @param word The Word object to read
 * @return The input stream
 */

std::istream& operator>>(std::istream& is, Word& aWord) 
{
	aWord.read(is);	// Read the Word object
	return is;
}

/*
 * Task 1 - #11 Method that returns the n'th character in *this object
 * @param n The index of the character
 * @return The n'th character in the word
*/

char Word::at(size_t n) const 
{
	if (n >= size) 
		{
		std::cerr << "Index out of bounds" << std::endl; // Print an error message
		return '\0';									// Return null character
	}
	return word[n];					// Return the n'th character
}

/**
 * Task 1 - #12 Method to read an entire line from the input stream
 * Reads an entire line from the input stream and stores it in the Word object.
 * Trims trailing whitespace.
 * @param sin The input stream
 */

void Word::read(std::istream& sin) 
{
	static char buffer[LONGEST_WORD_PLUS_ONE];		// static buffer to avoid reallocation set to the longest possible word
    sin.getline(buffer, LONGEST_WORD_PLUS_ONE - 1); // keep last byte free for \0

	/**
	 * Trim trailing whitespace
	 */ 

	int i = strlen(buffer) - 1;						// get the length of the input
	while (i >= 0 && isspace(buffer[i]))			// while the character is a space
	{			
		buffer[i] = '\0';							// set the character to null
		i--;										// move to the next character
	}

	delete[] word;                        // avoid memory leak

	size = strlen(buffer);						    // get the length of the input
    word = new char[size + 1];                      // allocate space, +1 to accomodate the final ’\0’
    strcpy(word, buffer);                           // copy buffer to word
}

/**
* Extra #1 Copy
* Helper method to copy a C-style string
* @param other The Word object to copy
*/

void Word::copy(const Word& other) 
{
	size = other.size;            // Copy the size
	word = new char[size + 1];    // Allocate memory for the string
	strcpy(word, other.word);	  // Copy the string
}

/**
 * Extra #2 Release Ownership
 * Helper method to release ownership of the C-style string
 * Releases the dynamically allocated memory for the C-style string and sets the
 * pointer to null, leaving the object in a valid but empty state, so that it
 * can be safely destroyed.
 */

void Word::releaseOwnership() 
{
	word = nullptr;         // Set the pointer to null
	size = 0;			    // Set the size to 0
}

/**
 * EXTRA #3 Method to print the Word object
 * @param os The output stream
*/

void Word::print(std::ostream& os) const 
{
	os << word;
}

/*
 * EXTRA #4 Method to check if two Word objects are equal
 * @param other The Word object to compare with
 * @return True if the Word objects are equal, false otherwise
 */

bool Word::areEqual(const Word& other) const 
{
    return strcmp(word, other.word) == 0;
}
