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
 * Class Description: The WordList class is a container class that holds a list
 * of Word objects. It provides methods to manipulate the list, such as inserting
 * and removing elements, searching for elements, and writing the list to an output
 * stream. The class also provides a method to copy the list into a std::forward_list
 * and a method to return the list as a std::list.
 * ***************************************************************************
 */

#include "WordList.h"

// Default constructor
WordList::WordList() = default;

// Copy constructor
WordList::WordList(const WordList& array) = default;

// Move constructor
WordList::WordList(WordList&& array) noexcept = default;

// Copy assignment operator
WordList& WordList::operator=(const WordList& rhs) = default;

// Move assignment operator
WordList& WordList::operator=(WordList&& rhs) noexcept = default;

// Destructor
WordList::~WordList() = default;

// front()
Word& WordList::front()
{
	return theList.front();
}

// back()
Word& WordList::back()
{
	return theList.back(); // Calls the back method of the list class
}

// front() const
const Word& WordList::front() const
{
	return theList.front(); // Calls the front method of the list class
}

// back() const
const Word& WordList::back() const
{
	return theList.back(); // Calls the back method of the list class
}

// push_front(const Word&)
void WordList::push_front(const Word& word)
{
	theList.push_front(word); // Calls the push_front method of the list class
}

// push_back(const Word&)
void WordList::push_back(const Word& word)
{
	theList.push_back(word); // Calls the push_back method of the list class
}

// pop_front()
void WordList::pop_front()
{
	theList.pop_front();  // Calls the pop_front method of the list class
}

// pop_back()
void WordList::pop_back()
{
	theList.pop_back();  // Calls the pop_back method of the list class
}

// remove(const Word&)
void WordList::remove(const Word& word)
{
	theList.remove(word);  // Calls the remove method of the list class
}

 // get(size_t) const 
 Word WordList::get(size_t n) const
{
	 list<Word>::const_iterator it = theList.begin(); // Create an iterator to the beginning of the list
	 advance(it, n); // Advance the iterator n positions
	 return *it;	 // Return the word at the n position
}
 
 // write(std::ostream&, size_t) const
 void WordList::write(std::ostream& sout, size_t n) const
 {
	 int count = 0; // Counter to keep track of the number of words written

	 if (n == 1)	// If n is 1, write each word in a new line
	 {
		 for (const Word& word : theList)
		 {
			 sout << word << endl;
		 }
	 }
	 else		// If n is different from 1, write n words per line
	 {
		 for (const Word& word : theList)
		 {
			 sout << std::setw(MAX_WORD_LENGTH) << word << '\t'; // Write the word with the correct spacing
			 count++; // Increment the counter
			 
			 if (count == n) // If the counter reaches n, write a new line
			 {
				 sout << endl;
				 count = 0;
			 }
		 }
	 }
 }

 // isEmpty() const
 bool WordList::isEmpty() const
 {
	 return theList.empty(); // Calls the empty method of the list class
 }

 // lookup(const Word&) const
 bool WordList::lookup(const Word& word) const
 {
	 return std::find(theList.begin(), theList.end(), word) != theList.end(); // Calls the find method of the list class
 }
 
 // getSinglyLinkedList() const
 forward_list<Word> WordList::getSinglyLinkedList() const
 {
	 forward_list<Word> flist(theList.begin(), theList.end()); // Create a forward_list with the elements of the list
	 return flist;
 }

 // setMaxLength() const
 void WordList::setMaxLength() const
 {
	 for (const Word& w : theList)
	 {
		 if (w.length() > MAX_WORD_LENGTH) // set MAX_WORD_LENGTH to the length of the longest word
		 {
			 MAX_WORD_LENGTH = w.length();
		 }
	 }
 }

 // clear()
 void WordList::clear()
 {
	 theList.clear(); // Calls the clear method of the list class
 }

 // getDoublyLikedList() const
 list<Word> WordList::getDoublyLinkedList() const
 {
	 return theList; 
 }

 // operator<<(std::ostream&, const WordList&)
 std::ostream& operator<<(std::ostream& sout, const WordList& wl)
 {
	 wl.write(sout); // Calls the write method of the WordList class
	 return sout;
 }
