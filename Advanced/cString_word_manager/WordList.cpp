/* Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
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

#include <iostream>   
#include <iomanip>
#include "Word.h"
#include "WordList.h"

/*
 * Task 2 - #0 Node struct
 * This is a struct that defines a Node in the WordList. I'll call it Requirement #0
 */

struct WordList::Node 
{
     // Node instance variables initialized	
     Word theWord;
     Node* next;
     Node* prev;

	 /* Task 2 - #0a Node constructor
	  * Node Constructor with default arguments for next and prev pointers
	  * @param aWord The Word object to store in the Node
	  * @param next Pointer to the next Node in the list
	  * @param prev Pointer to the previous Node in the list
      */

     Node(const Word& aWord, Node* next = nullptr, Node* prev = nullptr) :
         theWord{ aWord },
         next{ next },
         prev{ prev } {}

	  /*Task 2 - #0b Node special member functions
		 * All special member functions are deleted to prevent copying and moving of Nodes
       */
     
	 Node() = delete; // Default constructor is deleted to prevent creation of empty nodes

	 Node(const Node& other) = delete; // Copy constructor  deleted to prevent creation of copy nodes

	 Node(Node&& other) = delete; // Move constructor deleted to prevent creation of move nodes

	 Node& operator=(const Node& other) = delete; // Copy assignment operator deleted to prevent creation of copy nodes

	 Node& operator=(Node&& other) = delete; // Move assignment operator deleted to prevent creation of move nodes

     virtual ~Node() = default; // Destructor is set to default because the Node does not have any dynamic memory
    };


/**
 * Task 2 - #1 The Big Five
 * The so called Big Five are the five special member functions that a class should define
 * They are the copy constructor, the move constructor, the copy assignment operator,
 * the move assignment operator, and the destructor.
 */

 /**
 * Task 2 - #1a Copy constructor
 * A ctor that initializes the object as a copy of another object.
 * It creates a word list as a copy of another word list.
 * @param other The WordList object to copy
 */

WordList::WordList(const WordList& other) : 
    head(nullptr), 
    tail(nullptr), 
    size(0) 
{
	copy(other);
}

/**
 * Task 2 - #1b Move constructor
 * A ctor that initializes the object by 'stealing' the resources from a temporary object.
 * It creates a word list by moving the resources from another word list.
 * @param other The WordList object to move
 */

WordList::WordList(WordList&& other) noexcept : 
    head(other.head),
    tail(other.tail),
    size(other.size)
{
	other.releaseOwnership();
}

/**
 * Task 2 - #1c Copy assignment operator
 * A ctor that copies the contents of another object to the current
 * object using the assignment operator.
 * @param other The WordList object to copy
 * @return A reference to the current object
 */

WordList& WordList::operator=(const WordList& other) 
{
    if (this != &other) 
    { 
		clear(); // Clear current list
		copy(other); // Copy elements from other list
    }
    return *this;
}

/**
 * Task 2 - #1d Move assignment operator
 * A ctor that moves the contents of a temporary object to the current
 * object using the assignment operator.
 * @param other The WordList object to move
 * @return A reference to the current object
 */

WordList& WordList::operator=(WordList&& other) noexcept 
{
    if (this != &other) 
    {
		clear(); // Clear current list
		head = other.head; // Move head pointer
		tail = other.tail; // Move tail pointer
		size = other.size; // Move size
		other.releaseOwnership(); // Release ownership of other list
    }
    return *this;
}

/**
 * Task 2 - #1e Destructor
 * The destructor for the WordList class. It calls the clear method to pop all the Nodes in the list.
 */

WordList::~WordList() 
{
	clear();
}

/**
 * Task 2 - #2 Default constructor
 * A ctor that initializes the object to a default state receiving no arguments.
 * It initializes the head, tail, and size to nullptr, nullptr, and 0, respectively.
 */

WordList::WordList() :
    head(nullptr),
    tail(nullptr),
    size(0) {}


/*
 * Task 2 - #3a Accessor function that returns the Word object in the first Node
 * The implication of returning a const reference is that the caller cannot modify the Word object
 * @return The Word object in the first Node
 */

const Word& WordList::front() const 
{
    return head->theWord;
}

/*
 * Task 2 - #3b Accessor function that returns the Word object in the last Node
 * @return The Word object in the last Node
 */

const Word& WordList::back() const
{
    return tail->theWord;
}

/**
 * Task 2 - #4a Method that adds a new Node to the front of the list
 * @param aWord The Word object to add to the front of the list
*/

void WordList::push_front(const Word& aWord) 
{
	/**
     * Create a new Node with the Word object using the head as the next Node 
	 * and nullptr as the previous Node, because it will be the new head
    */
    Node* newNode = new Node(aWord, head, nullptr); 
    
	/* 
     * Checks if the list is empty. If so, set the tail pointer to the new Node
	 * because it will be the only Node in the list. Otherwise, set the previous
	 * pointer of the current head to the new Node because it will be the new head.
	 * set the head pointer to the new Node in both cases.
     */
    if (head == nullptr) 
    {
        tail = newNode;
    }
    else 
    {
        head->prev = newNode;
    }
    head = newNode;
    size++;
}


/**
 * Task 2 - #4b Method that adds a new Node to the back of the list
 * @param aWord The Word object to add to the back of the list
 */

void WordList::push_back(const Word& aWord) 
{
    /**
	 * Create a new Node with the Word object using the tail as the previous Node
	 * because it will be the new tail, and nullptr as the next Node because it 
     * will be the last Node
    */
    Node* newNode = new Node(aWord, nullptr, tail);

    /**
	 * Checks if the list is empty. If so, set the head pointer to the new Node
	 * because it will be the only Node in the list. Otherwise, set the next
	 * pointer of the current tail to the new Node because it will be the new tail.
	 * Set the tail pointer to the new Node in both cases.
    */
    if (tail == nullptr) 
    {
        head = newNode;
    }
    else 
    {
        tail->next = newNode;
    }
    tail = newNode;
    size++;
}

/**
 * Task 2 - #5a Method that removes the first Node from the list and returns the Word object in that Node
 * @return The Word object in the first Node
*/

Word WordList::pop_front() 
{
	// Check if the list is empty and throw an exception if it is
    if (isEmpty())
    {
        throw std::out_of_range("List is empty");
    }
   
    /**
	 * The first step is to prepare the Node to be removed. We need to store the address
	 * of the first Node, store the Word object in the first Node, and move the head pointer
	 * to the next Node
    */

    Node* temp = head;                  // Store the address of the first Node
    Word poppedWord = temp->theWord;    // Store the Word object in the first Node
    head = head->next;                  // Move the head pointer to the next Node
    
    /**
	 * The second step is to check if the list is empty after removing the first Node.
	 * If the list is not empty, set the previous pointer of the new head to nullptr.
	 * If the list is empty, set the tail pointer to nullptr
    */

    if (head != nullptr)                
    {  
        head->prev = nullptr;            
    }
    else
    {
        tail = nullptr;
    }

	delete temp;	    // Release the memory of the first Node
    size--; 	        // Decrement the size of the list

    return poppedWord;
}

/**
 * Task 2 - #5b Method that removes the last Node from the list and returns the Word object in that Node
 * @return The Word object in the last Node
 */

Word WordList::pop_back() 
{

	//Check if the list is empty and throw an exception if it is    
    if (isEmpty())
    {
        throw std::out_of_range("List is empty");
    }

    /**
     * The logic is similar to the pop_front method, but we need to consider the tail pointer
     * and the previous pointer of the new tail
     */

    Node* temp = tail;
    Word poppedWord = temp->theWord;
    tail = tail->prev;

    /**
	 * Check if the list is empty after removing the last Node.
	 * If the list is not empty, set the next pointer of the new tail to nullptr.
	 * If the list is empty, set the head pointer to nullptr
     */
    if (tail != nullptr) 
    {
        tail->next = nullptr;
    }
    else 
    {
        head = nullptr;
    }

	delete temp;             // Release the memory of the last Node
	size--;			    	 // Decrement the size of the list

    return poppedWord;
}

/**
 * Task 2 - #6 Method that inserts a Word object in the list in sorted order
 * The method first checks if the list is empty. If it is, it inserts the Word object at the head of the list.
 * If the Word object is less than the head, it inserts the Word object at the head of the list.
 * If the Word object is greater than the tail, it inserts the Word object at the tail of the list.
 * Otherwise, it finds the position to insert the Word object and inserts it in the list.
 * @param aWord The Word object to insert in the list 
 */

void WordList::insertSorted(const Word& aWord)
{
    if (head == nullptr)                          // If the list is empty, insert the object at the head
    {
		push_front(aWord);
    }
	else if (aWord.isLess(head->theWord))         // If the Word is less than the head push front                                                   
    {
        push_front(aWord);
    }
	else if (tail->theWord.isLess(aWord))         // If the Word is greater than the tail push back
	{
		push_back(aWord);
	}
	else 										// Otherwise, find the position to insert the Word object
    {
        Node* insertPosition = findPosition(aWord);    // Find the position to insert the Word object

        if (insertPosition != nullptr)                 // Check if insertPosition is not null
        {
            Node* newNode = new Node(aWord);           // Create a new Node with the Word object

            if (newNode != nullptr)                    // Check if memory allocation was successful
            {
                newNode->next = insertPosition;        // Set the next pointer of the new Node to the insert position
                newNode->prev = insertPosition->prev;  // Set the previous pointer of the new Node to the previous Node
                                                       // of the insert position

                if (insertPosition->prev != nullptr)
                {
                    insertPosition->prev->next = newNode;
                }
                else
                {
                    head = newNode;    // If insertPosition->prev is nullptr, it means insertPosition is the first node in the list
                                       // So, the new node should become the new head of the list
                }

				insertPosition->prev = newNode;	 // Set the previous pointer of the insert position to the new Node

                size++;                 // Increment the size of the list
            }
            else
            {
				throw std::runtime_error("Failed to allocate memory for a new node."); // Handle memory allocation failure
            }
        }
        else
        {
            throw std::runtime_error("Invalid insertion position."); // Handle null insertPosition
        }
    }
}

/* Task 2 - #7 Method that searches for a Word object in the list
 * It starts at the head of the list and iterates through the list
 * until it finds the Word object or reaches the end of the list
 * @param aWord The Word object to search for
 * @return The Node containing the Word object or nullptr if the Word object is not found
*/
WordList::Node* WordList::search(const Word& aWord) const
{
    Node* current = head;
    while (current != nullptr)
    {
		if (!current->theWord.isLess(aWord) && !aWord.isLess(current->theWord)) // Iterate through the list until
                                                                                // the Word object is found
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

/**
* Task 2 - #8 Method that removes a Word object from the list
* @param aWord The Word object to remove
* @return True if the Word object was removed, false otherwise
*/
bool WordList::remove(const Word& aWord) 
{
    if (isEmpty()) 
    {
        return false; // Word not found in an empty list
    }

	Node* node = search(aWord);  // Create a pointer to the Node containing the Word object to remove

    /**
	 * If the Word object is found in the head, pop the front of the list
	 * If the Word object is found in the tail, pop the back of the list
	 * Otherwise, set the next pointer of the previous Node to the next Node
	 * and the previous pointer of the next Node to the previous Node
	 * Delete the Node containing the Word object and decrement the size of the list 
    */

	if (node != nullptr)
    {
        if (node == head) 
        {
            pop_front();
        }
        else if (node == tail) 
        {
            pop_back();
        }
        else
        {
            if (node->prev != nullptr)
            {
                node->prev->next = node->next;
            }
            if (node->next != nullptr)
            {
                node->next->prev = node->prev;
            }
            delete node;
            size--;
        }
        return true; // Word found and removed
    }
    return false;  // Word not found
}

/**
 * Task 2 - #9 Helper function to get the Node at index n - only used internally
 * If the index is out of range, it returns nullptr
 * @param n The index of the Node to get
 * @return The Node at index n
 */

WordList::Node* WordList::getWord(int n) const
{
	if (n < 0 || n >= size)
    {
        return nullptr;
	}
    Node* current = head;
    for (int i = 0; i < n; i++) 
    {
        current = current->next;
    }
    return current;
}

/**
 * Task 2 - #10 Method that returns the Word in the n'th Node in the list
 * If the index is out of range, it throws an out_of_range exception
 * @param index The index of the Node to get
 * @return The Word object in the n'th Node
 */

const Word WordList::fetchWord(int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range");
	}
    Node* node = getWord(index);
    return node->theWord;
}

/**
 * Task 2 - #11 Method that prints the first n Word objects in the list
 * By default, it prints the first 5 words
 * @param os The output stream
 * @param n The number of words to print
 */

void WordList::print(std::ostream& os, int n) const 
{
	Node* current = head;           // Create a pointer to the head of the list
	int count = 0;  		        // Initialize a counter to 0  
	
    
	while (current != nullptr)     // Iterate through the list and print the Word objects
    {
        if (n == 1) {
			// If n is 1, print the Word object without a tab
			os << current->theWord;
        }
        else
        {
            os << std::setw(15) << current->theWord << '\t'; // Set the field width to 15
        }
        
        count++;
        
		if (count % n == 0)        // Print a new line every n words (modulo operation)
        {
            os << '\n';
        }

		current = current->next;   // Move the pointer to the next Node
    }
	if (count % n != 0) 	   	  // Print a new line if the last line is not complete
    {
        os << '\n';
    }
}

/**
 * Task 2 - #12 Method that checks if the list is empty
 * @return True if the list is empty, false otherwise
 */

bool WordList::isEmpty() const 
{
    return size == 0;
}

/**
 * Task 2 - #13 Overloaded insertion operator<<
 * * Overloaded insertion operator that prints the WordList object to the output stream.
 * * @param os The output stream
 * * @param list The WordList object to print
 * * @return The output stream
*/

std::ostream& operator<<(std::ostream& os, const WordList& list) 
{
	list.print(os);
	return os;
}

/**
 * Task 2 - #14 Lookup Method
 * Method that searches for a Word object in the list
 * @param aWord The Word object to search for
 * @return True if the Word object is found, false otherwise
 */
bool WordList::lookup(const Word& aWord) 
{
	return search(aWord) != nullptr;
}

/**
 * Task 2 - Extra #1 Copy
 * Helper method to copy the contents of another WordList object
 * @param other The WordList object to copy
 */

void WordList::copy(const WordList& other)
{
    // initialize the list to empty
    size = 0;
    head = nullptr;
    tail = nullptr;

    // check if the other list is empty
    if (other.head == nullptr)
    {
        return;
    }

    Node* current = other.head;         // create a pointer to the head of the other list

    head = new Node(current->theWord);  // create a new Node with the same Word object
    size++;							   // increment the size of the list

    Node* newNode = head;			   // create a pointer to the head of the new list
    current = current->next;		   // move the pointer to the next Node in the other list

    // iterate through the other list and copy the Word objects to the new list
    while (current)
    {
        Node* temp = new Node(current->theWord, nullptr, newNode);
        newNode->next = temp;
        newNode = temp;
        current = current->next;
        size++;
    }
}

/**
 * Task 2 - Extra #2 Helper method to release ownership of the list
 */

void WordList::releaseOwnership()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/* Task 2 - Extra #3 Method that finds a position for a Word object in the list
 * It starts at the head of the list and iterates through the list
 * until it finds the correct position or reaches the end of the list
 * @param aWord The Word object to find a position for
 * @return The Node containing the Word object or nullptr if the Word object is not found
*/

WordList::Node* WordList::findPosition(const Word& aWord)
{
    Node* current = head;
    while (current != nullptr && current->theWord.isLess(aWord)) // Iterate through the list until the Word object is less
        // than the current Word object
    {
        current = current->next;
    }
    return current;
}

/**
 * Task 2 - Extra #4 Helper method to clear the list using the pop_front method
 */

void WordList::clear()
{
    while (!isEmpty())
    {
        pop_front();
    }
}

/**
 * Task 2 - Extra #5 Method that returns the number of words in the list
 * @return The number of words in the list
 */

WordList WordList::getWordsStartingWith(char initial) const
{
	WordList wordsStartingWithInitial;  // Create a new WordList to store the words starting with the given letter
	Node* current = head;               // Create a pointer to the head of the list


    while (current != nullptr)      
    {
        if (current->theWord.c_str()[0] == initial)                     // If the word starts with the given letter
        { 
			wordsStartingWithInitial.insertSorted(current->theWord);    // Insert the word in the new list
        }
		current = current->next;										// Move the pointer to the next Node
    }
	return wordsStartingWithInitial;								    // Return the new list
}

/**
 * Task 2 - Extra #6 Method that returns the number of words in the list
 * @return The number of words in the list
 */

size_t WordList::getSize() const 
{
	return size;
}