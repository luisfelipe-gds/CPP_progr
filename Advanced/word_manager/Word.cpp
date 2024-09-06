 * ***************************************************************************
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

#include "Word.h"

// Default constructor
Word::Word() = default;

 // Conversion constructor
Word::Word(const string& w) : theWord(w) {};

// Copy constructor
Word::Word(const Word& w) = default;

// Move constructor
Word::Word(Word&& w) noexcept = default;

// Copy assignment operator
Word& Word::operator=(const Word& rhs) = default;

// Move assignment operator
Word& Word::operator=(Word&& rhs) noexcept = default;

// Destructor
Word::~Word() = default;

// length()
size_t Word::length() const
{
	return theWord.length();  // calls the string length method
}

// c_str()
const char* Word::c_str() const
{
	return theWord.c_str();  // calls the string c_str method
}

// set(const Word&)
void Word::set(const Word& wrd)
{
	theWord = wrd.theWord; 
}

// set(const string&)
void Word::set(const string& str)
{
	theWord = str;
}

// getStr()
string Word::getStr() const
{
	return theWord;
}

// getWord()
Word Word::getWord() const
{
	return *this;
}

// concat(const Word&, const string&)
void Word::concat(const Word& w, const string& d)
{
	theWord += d + w.theWord;	// concatenate using += from string class
}

// compare(const Word&)
int Word::compare(const Word& w) const
{
	return theWord.compare(w.theWord);  // calls the string compare method
}

// read(std::istream&)
void Word::read(std::istream& sin)
{
	std::getline(sin, theWord);		 // read a line using getline from string class
}

// write(const std::ostream&) const
void Word::write(const std::ostream& sout) const
{
	cout << theWord;
}

// Overloaded operator<(const Word&, const Word&)
bool Word::operator<(const Word& rhs)
{
	return theWord.compare(rhs.theWord) < 0;  // calls the string compare method
}

// Overloaded operator==(const Word&, const Word&)
bool operator==(const Word& lhs, const Word& rhs)
{
	return lhs.getStr() == rhs.getStr();  // calls the string == operator
}

// Overloaded operator>>(std::istream&, Word&)
std::istream& operator>>(std::istream& sin, Word& w)
{
	w.read(sin);
	return sin;
}

// Overloaded operator<<(std::ostream&, const Word&)
std::ostream& operator<<(std::ostream& sout, const Word& w)
{
	w.write(sout);
	return sout;
}

// trim(const string&, const string&)
string trim(const string& str, const string& whitespaces)
{
	// find the position of the first non-whitespace character in str
	size_t start = str.find_first_not_of(whitespaces);

	if (start == string::npos) // did the call above find a non-whitespace character? 
	{
		return ""; // no, it did not, so return an empty string 
	}
	// the call above to find() did succeed. 
	// we now know that there is at least one non-whitespace character in str. 
	// find the position of the last non-whitespace character in str. 

	size_t finish = str.find_last_not_of(whitespaces); // Extract from str the substring between start and finish, inclusive 
	string trimmed_str = str.substr(start, finish - start + 1);
	return trimmed_str;
}
