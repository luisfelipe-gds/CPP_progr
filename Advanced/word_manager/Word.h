/* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. 
 *
 * ***************************************************************************
 * Class Description: Word class is a class that represents a word. It has
 * a string instance variable that holds the word. It has methods to manipulate
 * the word, such as concatenating, comparing, reading, writing, and setting.
 * It also has overloaded operators to compare, read, and write the word.
 *
 * ***************************************************************************
 */

#ifndef WORD_H_
#define WORD_H_
#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Word
{
private:
	// Instance variable of the class - theWord is a string that will hold the word
	string theWord;

public:
	/*
	 * Default constructor
	 * A ctor that initializes the object to a default state receiving no arguments.
	 * It creates a Word object as an empty std::string.
	 */
	Word();

	/*
	 * Conversion constructor
	 * A ctor that takes a std::string as an argument and converts it to a Word object.
	 * @param w - a string that will be converted to a Word object.
	 */
	Word(const string& w);

	/*
 	 * Copy constructor
	 * A ctor that initializes the object as a copy of another object.
	 * @param w The Word object to copy
	 */	
	Word(const Word& w);

	/*
	 * Move constructor
	 * A ctor creates a Word object by moving the resources from another Word object.
	 * @param w The Word object to move
	 */
	Word(Word&& w) noexcept;

	/*
	 * Copy assignment operator
	 * A ctor that copies the contents of another object to the current object (operator=).
	 * @param rhs The Word object to copy
	 * @return A reference to the current object
	 */	
	Word& operator=(const Word& rhs);

	/*
	 * Move assignment operator
	 * A ctor that moves the contents of a temporary object to the current object (operator=).
	 * @param rhs The Word object to move
	 * @return A reference to the current object
	 */
	Word& operator=(Word&& rhs) noexcept;

	/*
	 * Destructor
	 * The destructor is a special member function that is called when the object goes out of scope
	 * or when the delete operator is used to destroy the object.
	 * It is virtual to allow derived classes to override it.
	 */
	virtual ~Word();
	
	/*<
	 * length()
	 * A method that returns the length of the word.
	 * @return The length of the word
	 */
	size_t length() const;

	/*
	 * set(const Word&)
	 * A method that sets theWord to wrd.
	 * @param wrd The Word object to set theWord to
  	 */
	void set(const Word& wrd);

	/*
	 * set(const string&)
	 * A method that sets theWord to str.
	 * @param str The string to set theWord to
	 */
	void set(const string& str);

	/*
	 * getStr()
	 * A method that returns the word.
	 * @return The word as a string
	 */
	string getStr() const;

	/*
	 * getWord()
	 * A method that returns *this.
	 * @return The Word object
	 */
	Word getWord() const;

	/*
	 * concat(const Word&, const string&)
	 * A method that concatenates theWord with w.theWord and d, an optional delimiter.
	 * Default is a blank char.
	 * @param w The Word object to concatenate with theWord
	 * @param d The string to concatenate between theWord and w.theWord
	 */
	void concat(const Word& w, const string& d = "");

	/*
	 * compare(const Word&) const
	 * A method that compares theWord with w.theWord and returns an int.
	 * @param w The Word object to compare with theWord
	 * @return An int that represents the comparison
	*/
	int compare(const Word& w) const;

	/*
	 * Overloaded operator <(const Word&, const Word&)
	 * It compares theWord with rhs.theWord and returns a boolean value
	 * @param lhs The left-hand side Word object to compare
	 * @param rhs The right-hand side Word object to compare
	 * @return A boolean value indicating if lhs.theWord is less than rhs.theWord
	*/
	bool operator<(const Word& rhs) const;

	/*
	 * read(std::istream&)
	 * A method that reads from the input stream sin and sets theWord to the input.
	 * @param sin The input stream to read from
	*/
	void read(std::istream& sin);

	/*
	 * write(const std::ostream&) const
	 * A method that writes theWord to the output stream sout.
	 * @param sout The output stream to write to	
     */
	void write(const std::ostream& sout) const;

private:
	/*
	 * c_str()
	 * A method that returns the c-style version of the word.
	 * @return The c-style version of the word
	 */
	const char* c_str() const;
};

/* 
 * ***************************************************************************
 *                           NON-MEMBER FUNCTIONS
 * ***************************************************************************
 */

/* 
 * Overloaded operator >>(std::istream&, Word&) 
 * It reads from the input stream sin and sets theWord to the input using read()
 * @param sin The input stream to read from
 * @param w The Word object to set theWord to
 * @return The input stream sin
 */
std::istream& operator>>(std::istream& sin, Word& w);

/*
 * Overloaded operator <<(std::istream&, Word&) 
 * It writes theWord to the output stream sout using write()
 * @param sout The output stream to write to
 * @param w The Word object to write
 * @return The output stream sout
*/
std::ostream& operator<<(std::ostream& sout, const Word& w);

/*
 * trim(const string&, const string&)
 * It removes the whitespaces from the beginning and end of the string
 * @param str The string to remove the whitespaces from
 * @param whitespaces The string with the whitespaces to remove
 * @return The string without the whitespaces
 */
string trim(const string& str, const string& whitespaces = " \t\n");

	/*
 	* Overloaded operator ==(const Word&, const Word&)
 	* It compares theWord with rhs.theWord and returns a boolean value
 	* @param lhs The left-hand side Word object to compare
 	* @param rhs The right-hand side Word object to compare
 	* @return A boolean value indicating if lhs.theWord is equal to rhs.theWord
 	*/
 	bool operator==(const Word& lhs, const Word& rhs);

#endif // !WORD_H_	
