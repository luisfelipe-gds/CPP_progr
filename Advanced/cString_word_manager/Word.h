/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check Word.cpp for the implementation of the methods.
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

#ifndef WORD_H_
#define WORD_H_
#include <cstring>
#include <cctype>
#include <iostream>

class Word 
{
private:
	
   	// Instance variables initialized to default values	
    char* word{ nullptr }; // C-style string to store the word
	size_t size{ 0 };	   // Length of the word

public:
	// Constants used in the class and elsewhere
    static constexpr int LONGEST_WORD_PLUS_ONE = 65;

    // Task 1 - #1 Default constructor
    Word();

    // Task 1 - #2 Conversion constructor
    Word(const char* str);

    // Task 1 - #3 The Big Five
    // Task 1 - #3a Copy constructor
    Word(const Word& other);

    // Task 1 - #3b Move constructor
    Word(Word&& other) noexcept;

    // Task 1 - #3c Copy assignment operator
    Word& operator=(const Word& other);

    // Task 1 - #3d Move assignment operator
    Word& operator=(Word&& other) noexcept;

	// Task 1 - #3e Destructor
    ~Word();

	// Task 1 - #4 Accessor to get the length of the word
    size_t length() const;

	// Task 1 - #5 Accessor to get the C-style string
    const char* c_str() const;

	// Task 1 - #6a Mutator #1 to change the word
    void changeWord(const Word& newWord);

	// Task 1 - #6b Mutator #2 to change the word
    void changeWord(const char* newStr);

	// Task 1 - #7 Method to concatenate two words
    Word concat(const Word& other, const char* delimiter = " ") const;

	// Task 1 - #8 Method to check if a word is less than another word
    bool isLess(const Word& other) const;

	// Task 1 - #9 Overloaded insertion operator<<
    friend std::ostream& operator<<(std::ostream& os, const Word& aWord);

	// Task 1 - #10 Overloaded extraction operator>>
    friend std::istream& operator>>(std::istream& is, Word& aWord);

    // Task 1 - #11 Method that returns the n'th character in *this object 
    char at(size_t n) const;

	// Task 1 - #12 Method to read an entire line from an input stream
    void read(std::istream& is);

private:
    // #Extra 1 Helper method to copy a C-style string
    void copy(const Word& other);

    // #Extra 2 Helper method to release ownership of the C-style string
    void releaseOwnership();

public:
    // #EXTRA 3 Method to print the Word object
    void print(std::ostream& os) const;

    // #EXTRA 4 Method to check if two Word objects are equal
    bool areEqual(const Word& other) const;
};

#endif /* WORD_H_ */