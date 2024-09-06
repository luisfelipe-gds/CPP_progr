 /* ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordList.cpp for the implementation of the methods.
 *
 * ***************************************************************************
 * Class Description: The WordList class is a container class that holds a list
 * of Word objects. It provides methods to manipulate the list, such as inserting
 * and removing elements, searching for elements, and writing the list to an output
 * stream. The class also provides a method to copy the list into a std::forward_list
 * and a method to return the list as a std::list.
 * ***************************************************************************
 */

#ifndef WORDLIST_H_
#define WORDLIST_H_
#include "Word.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <forward_list>

using std::string;
using std::list;
using std::forward_list;
using std::cout;
using std::endl;
using std::cin;

class WordList
{
private:
	// Instance variable of the class - theList is a std::list of Word objects
	list<Word> theList;

public:
	/*
	 * MAX_WORD_LENGTH is a static variable that holds the length of the longest
	 * word in the list. it is static to allow for access without an object and 
	 * inline to allow for multiple definitions.
	 * It is used mainly to format the output of the write method.
	 */
	static inline size_t MAX_WORD_LENGTH = 1;
	
	/*
	 * Default constructor
	 * A ctor that initializes the object to a default state receiving no arguments.
	 * It creates an empty WordList object list<Word>.
	 */
	WordList();

	/*
	 * Copy constructor
	 * A ctor that initializes the object as a copy of another object.
	 * @param array The WordList object to copy
	 */
	WordList(const WordList& array);

	/*
	 * Move constructor
	 * A ctor creates a WordList object by moving the resources from another WordList object.
	 * @param array The WordList object to move
	 */
	WordList(WordList&& array) noexcept;

	/*
	 * Copy assignment operator
	 * A ctor that copies the contents of another object to the current object (operator=).
	 * @param rhs The WordList object to copy
	 * @return A reference to the current object
	 */
	WordList& operator=(const WordList& rhs);

	/*
	* Move assignment operator
	* A ctor that moves the contents of a temporary object to the current object (operator=).
	* @param rhs The WordList object to move
	* @return A reference to the current object
	*/
	WordList& operator=(WordList&& rhs) noexcept;

	/*
	 * Destructor
	 * A dtor that destroys the WordList object
	 * it is virtual to allow for polymorphism
	 */
	virtual ~WordList();

	/*
	 * front() A method that returns a reference to the first Word object in the list
	 * @return a reference to the first Word object in the list
	 */
	Word& front();

	/*
	 * back() A method that returns a reference to the last Word object in the list
	 * @return a reference to the last Word object in the list
	 */
	Word& back();

	/*
	 * front() const A method that returns a const reference to the first Word object in the list
	 * @return a const reference to the first Word object in the list
	 */
	const Word& front() const;

	/*
	 * back() A method that returns a const reference to the last Word object in the list
	 * @return a const reference to the last Word object in the list
	 */
	const Word& back() const;

	/*
	 * push_front(const Word&) A method that inserts a Word object at the beggining of the list
	 * @param word - the Word object to be inserted
	 *
	 */
	void push_front(const Word& word);

	/*
	 * push_back(const Word&) A method that inserts a Word object at the end of the list
	 * @param word - the Word object to be inserted
	 */
	void push_back(const Word& word);
	
	/*
	 * pop_front() A method that removes the first Word object in the list
	 */
	void pop_front();

	/*
	 * pop_back() A method that removes the last Word object in the list
	 */
	void pop_back();

	
	/*
	 * remove(const Word&) A method that removes a Word object from the list
	 * @param word - the Word object to be removed
	 */
	void remove(const Word& word);

	/*
	 * get(size_t) A method that returns a copy of the n'th element in the list, provided
	 * that n is a valid index. If n is not a valid index, the method will return the
	 * last element in the list.
 	 * @param n - the index of the element to be returned
	 * @return a copy of the n'th element in the list
	 */
	Word get(size_t n) const;


	/*
	 * write(std::std::ostream&, size_t)
	 * A method that writes to output stream sout the elements of the list n
	 * elements per line, n=5 by default
	 * @param sout - the output stream
	 */
	void write(std::ostream& sout, size_t n = 5) const;

	/*
	 * isEmpty()
	 * A method that returns a boolean value indicating whether the list is empty
	 * @return true if the list is empty, false otherwise
	 */
	bool isEmpty() const;

	/**
	 * lookup(const Word&) A method that searches for a Word object in the list
	 * @param word - the Word object to search for
	 * @return true if the word is found, false otherwise
	 */
	bool lookup(const Word& word) const;

	/*
	 * getSinglyLinkedList() const
	 * A method that copies the list into a std::forward_list and returns a copy of it
	 * @return a copy of the list as a std::forward_list
	 */
	forward_list<Word> getSinglyLinkedList() const;

	/*
	 * getDoublyLinkedList() const
	 * A method that returns the copy of the list as a std::list
	 * @return a copy of the list as a std::list
	 */
	list<Word> getDoublyLinkedList() const;

	/*
	 * setMaxLength() 
	 * A method that sets the MAX_WORD_LENGTH to the length of the longest word in the list
	 */
	void setMaxLength() const;

	/*
	 * clear() 
	 * A method that clears the list
	 */
	void clear();
};	


/*
 * ***************************************************************************
 *                           NON-MEMBER FUNCTIONS
 * ***************************************************************************
 */

/*
 * Overloaded operator <<(std::istream&, Word&) 
 * It writes theList to the output stream sout using write()
 * @param sout The output stream to write to
 * @param wl The Word object to write
 * @return The output stream sout
 */
std::ostream& operator<<(std::ostream& sout, const WordList& wl);

#endif /* WORDLIST_H_ */
