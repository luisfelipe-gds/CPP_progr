#ifndef FIBGEN_H
#define FIBGEN_H
#include <iostream>
#include <iterator>

class FibGen
{
	using ul = unsigned long;

	ul a{ 1 }, b{ 1 }; // initialize the first Fibonacci number
	ul current{1};	// store the current Fibonacci number
	ul max{};		// store the limit of the Fibonacci numbers
	int counter{};	// store the counter of the Fibonacci numbers
	constexpr void next_fib() 	
	{
		ul next = a + b; // calculate the next Fibonacci number
		a = b;          // update a to the current b
		b = next;       // update b to the next number
		current = a;    // update current to the new Fibonacci number
	}

public:
	FibGen() = default;  // default constructor

	explicit FibGen(ul max) : max{ max } {}  // constructor with a limit

	// dereference operator
	ul operator*() const
	{
		return current; // return the current Fibonacci number
	}	

	// pre-increment operator
	FibGen& operator++()
	{
		next_fib();
		++counter;
		return *this;
	}

	// post-increment operator
	FibGen operator++(int)
	{
		auto temp = *this;   // store the current state
		++(*this);			 // increment the current state
		return temp;		 // return the stored state
	}

	// equality operator
	bool operator==(const FibGen& rhs) const
	{
		return this->counter == rhs.counter; 
	}

	// inequality operator
	bool operator!=(const FibGen& rhs) const
	{
		return !(*this == rhs);
	}

	// begin function
	const FibGen& begin() const
	{
		return *this;
	}

	// end function
	const FibGen end() const
	{
		auto sentinel = FibGen{};  // create a sentinel object
		sentinel.counter = max;    // set the counter to the limit
		return sentinel;           // return the sentinel object
	}

	// operator=
	FibGen& operator=(const FibGen& rhs)
	{
		// copy the data members
		max = rhs.max;
		counter = rhs.counter;
		a = rhs.a;
		b = rhs.b;
		current = rhs.current;
		return *this;
	}
};

#endif