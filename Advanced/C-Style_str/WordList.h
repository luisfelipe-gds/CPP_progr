/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 1 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Date: May 26, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact. Check WordList.cpp for the implementation of the methods.
 * 
 * ***************************************************************************
 * Class Description:
 * 
  * The WordList class represents a list of Word objects. It is a simple class
 * that stores a list of Word objects in a doubly linked list. The class provides
 * methods to add, remove, and search for Word objects in the list, as well as
 * methods to print the list and get the number of words in the list. The class
 * also provides methods to get the first and last Word objects in the list, as
 * well as the Word object at a specific index.
 * ***************************************************************************
 */


#ifndef WORDLIST_H_
#define WORDLIST_H_
#include <iostream>
#include "Word.h"

class WordList 
{
private:
	
    /*
	 * Task 2 - #0 Node struct
     * This is a class that defines a Node in the WordList. I'll call it Requirement #0
    */
    struct Node;
		
    // Instance variables initialized to default values	
	Node* head{ nullptr };
	Node* tail{ nullptr };
	size_t size{ 0 };

  
public:
    // Task 2 - #1 The Big Five
    // Task 2 - #1a Copy constructor 
	WordList(const WordList& other);

	// Task 2 - #1b Move constructor
	WordList(WordList&& other) noexcept;

	// Task 2 - #1c Copy assignment operator
    WordList& operator=(const WordList& other);

	// Task 2 - #1d Move assignment operator
    WordList& operator=(WordList&& other) noexcept;

	// Task 2 - #1e Destructor
    ~WordList();
    
	// Task 2 - #2 Default constructor - creates an empty list
    WordList();
    
	// Task 2 - #3a Accessor function that returns the Word object in the first Node
    const Word& front() const;

	// Task 2 - #3b Accessor function that returns the Word object in the last Node
    const Word& back() const;

	// Task 2 - #4a Method that adds a new Node to the front of the list
    void push_front(const Word& aWord);

	// Task 2 - #4b Method that adds a new Node to the back of the list
    void push_back(const Word& aWord);

	// Task 2 - #5a Method that removes the first Node from the list and returns the Word object in that Node
    Word pop_front();

	// Task 2 - #5b Method that removes the last Node from the list and returns the Word object in that Node
    Word pop_back();

	// Task 2 - #6 Method that inserts a given word in the list in sorted order
    void insertSorted(const Word& aWord);

	// Task 2 - #8 Method that removes the first occurrence of the Word object from the list
    bool remove(const Word& aWord);

    // Task 2 - #10 Method that returns a copy of the Word object in the n'th Node in the list
    const Word fetchWord(int index) const;

	// Task 2 - #11 Method that prints the first n Word objects in the list. By default, it prints the first 5 words
    void print(std::ostream& os, int n = 5) const;

	// Task 2 - #12 Method that returns true if the list is empty
    bool isEmpty() const;

	// Task 2 - #13 Overloaded insertion operator<< as a friend function
    friend std::ostream& operator<<(std::ostream& os, const WordList& list);

	// Task 2 - #14 Lookup Method that returns true if the Word object is in the list
    bool lookup(const Word& aWord);

private:
    // Task 2 - #7 Helper function to search for a Node with the Word object in the list
	Node* search(const Word& aWord) const;

    // Task 2 - #9 Helper function to get the Node at index n - only used internally
	Node* getWord(int n) const;

    // Task 2 - Extra #1 Copy helper function - method to copy the list
    void copy(const WordList& other);

    // Task 2 - Extra #2 Helper function to release ownership of the list
    void releaseOwnership();

    // Task 2 - Extra #3 Helper function to find the position to insert a new Node with the Word object
    Node* findPosition(const Word& aWord);

public:
    // Task 2 - Extra #4 Method to clear the list
    void clear();
    
    // Task 2 - Extra #5 Method to get the number of words in the list
    WordList getWordsStartingWith(char initial) const;    

	// Task 2 - Extra #6 Method to get the number of words in the list
	size_t getSize() const;
};
    

#endif