/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 5 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Due Date: August 15th, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description: This class contains the implementation of the functions
 * in the assignment5.h file. These implementations test several concepts
 * such as lambda functions, functors, and free functions. Also, it tests
 * the use of iterators and algorithms from the STL library. Lastly, it tests
 * implementing a class that works as a functor and as an iterator.
 * ***************************************************************************
 */

#include "functors.h"

// TASK 1
WordVec read_words_into_vector(const std::string& inFileName) 
{
	std::ifstream ifs(inFileName);  // create an input file stream

	if (!ifs.is_open())   // check that the file is open
	{
		std::cerr << "Error: Could not open file " << inFileName << std::endl;
		throw std::runtime_error("Error: Could not open file " + inFileName);
	}
	
	WordVec words_vector; // an empty vector of strings

	// define the start and end of the stream
	std::istream_iterator<std::string> is_start = std::istream_iterator<std::string>(ifs);
	std::istream_iterator<std::string> is_end = std::istream_iterator<std::string>();
	
	std::copy(
		is_start, // start of stream
		is_end,    // end of stream
		std::back_inserter(words_vector)         // destination
		);

	return words_vector;
}

// TASK 2
WordMap map_and_count_words_using_lambda(const WordVec& wVec)
{
	WordMap wMap; // an empty map of strings and size_t

	std::for_each(
		wVec.begin(),
		wVec.end(),
		[&wMap](const std::string& word) { wMap[word]++; } // lambda function
	);

	return wMap;
}

// TASK 3
class WordCountFunctor
{
	WordMap wMap; // an empty map of strings and size_t

public:
	void operator()(const std::string& word) // overload the operator ()
	{
		wMap[word]++;
	}

	WordMap getWordMap() const
	{
		return wMap;
	}
};


WordMap map_and_count_words_using_functor(const WordVec& wVec)
{
	WordCountFunctor wcf{}; // create an instance of the WordCountFunctor

	std::for_each(
		wVec.begin(),
		wVec.end(),
		std::ref(wcf)); // call the functor with the instance

	return wcf.getWordMap(); // return the map from the functor
}

// TASK 4
WordVec remove_duplicates(const WordVec& wVec)
{
	WordVec words_vec(wVec); // copy the input vector

	std::sort(words_vec.begin(), words_vec.end()); // sort the vector

	auto it = std::unique(words_vec.begin(), words_vec.end()); // remove duplicates

	words_vec.erase(it, words_vec.end()); // erase the duplicates

	return words_vec;
}

// TASK 5
// define a predicate function to check if a char is alphabetic
bool is_alphabetic(char ch)
{
	return !std::isalpha(ch); // cast to unsigned char
}

bool is_palindrome(const std::string& phrase)
{
	// create a temporary string to store only the alphabetic chars
	std::string temp;

	// use remove_copy_if to move only the alphabetic chars from phrase to temp
	std::remove_copy_if(
		phrase.begin(),
		phrase.end(),
		std::back_inserter(temp),  // destination is a back_inserter
		is_alphabetic);			   // predicate function

	// convert all chars in temp to lowercase
	std::transform(
		temp.begin(),
		temp.end(),
		temp.begin(),
		[](char ch) { return std::tolower(ch); });

	// use std::equal to check if temp is a palindrome
	return std::equal(
		temp.begin(),
		temp.begin() + temp.size() / 2,
		temp.rbegin());
}

// TASK 6

// 6 a - Lambda
size_t count_using_lambda(const WordVec& vec, int n)
{
	// use std::count_if with a lambda function to count the number of words with size n
	size_t count;

	count = std::count_if(
		vec.begin(),
		vec.end(),
		[n](const std::string& word) -> bool {return word.size() == n; }
	);

	return count;
}

// 6 b - Functor
class CountWordsFunctor
{
	size_t n;
	size_t count = 0;

public:
	CountWordsFunctor(size_t n) : n(n), count(0) {}
	
	bool operator()(const std::string& word)
	{
		if (word.size() == n)
		{
			count++;
		}
		return word.size() == n;
	}

	size_t getCount() const
	{
		return count;
	}
};

size_t count_using_Functor(const WordVec& vec, int n)
{
	// create an instance of the CountWordsFunctor
	CountWordsFunctor cwf(n);

	// call the functor with the instance
	std::count_if(
		vec.begin(),
		vec.end(),
		cwf);

	return cwf.getCount(); // return the count from the functor
}

// 6 c - Free Function
bool freeFunc(const std::string& word, int n)
{
	return word.size() == n;
}

size_t count_using_Free_Func(const WordVec& vec, int n)
{
	auto unaryFreeFunc = std::bind(freeFunc, std::placeholders::_1, n);

	size_t count = std::count_if(
		vec.begin(),
		vec.end(),
		unaryFreeFunc);

	return count;
}

// TASK 7
void multisetUsingDefaultComparator(const WordVec& vec)
{
	std::multiset<std::string> stringSet;  // an empty string set

	// to print a sorted version of the supplied vector
	// we first copy vec to our stringSet and then print the set
	// we can't use a front or back inserter here, must use an inserter

	std::copy(
		vec.begin(),
		vec.end(),
		std::inserter(stringSet,
			stringSet.begin())); // insert at the beginning

	// create an ostream iterator attached to cout
	std::ostream_iterator<std::string> out(std::cout, " ");

	// output the set elements to cout
	std::copy(
		stringSet.begin(),
		stringSet.end(),
		out);
}

struct MyComparator
{
	bool operator()(const std::string& lhs, const std::string& rhs) const
	{
		if (lhs.size() != rhs.size())  // if the sizes are different
		{
			return lhs.size() < rhs.size();  // return the size comparison
		}
		return lhs < rhs;  // otherwise return the string comparison
	}
};

void multisetUsingMyComparator(const WordVec& vec)
{
	std::multiset<std::string, MyComparator> stringSet;  // an empty string set

	// to print a sorted version of the supplied vector
	// we first copy vec to our stringSet and then print the set
	// we can't use a front or back inserter here, must use an inserter
	
	std::copy(
		vec.begin(),
		vec.end(),
		std::inserter(stringSet,
		              stringSet.begin())); // insert at the beginning

	// create an ostream iterator attached to cout
	std::ostream_iterator<std::string> out(std::cout, " ");

	// output the set elements to cout
	std::copy(
		stringSet.begin(),
		stringSet.end(),
		out);
}

// TASK 8
class FibGenFunctor
{
	int a{ 0 }, b{ 1 }; // initialize the first two Fibonacci numbers
	int current{ 0 };	// store the current Fibonacci number

public:
	int operator()()
	{
		current = a;  // store the current Fibonacci number
		int next = a + b; // calculate the next Fibonacci number

		a = b;		      // update a to the current b
		b = next;	      // update b to the next number

		return current;	      // return the current Fibonacci number
	}
};

std::vector<int> generate_Fibonacci(int n)
{
	std::vector<int> fibs(n); // create a vector of n elements

	FibGenFunctor fibGen; // create an instance of the FibGen functor

	// use std::generate_n to fill the vector with the first n Fibonacci numbers
	std::generate_n(
		fibs.begin(),
		n,
		fibGen);

	return fibs;
}