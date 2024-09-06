#ifndef FUNCTORS_H_
#define FUNCTORS_H_

#include <map>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <set>
#include "FibGen.h"

// Type aliases
using WordVec = std::vector<std::string>;
using WordList = std::list<std::string>;
using WordMap = std::map<std::string, size_t>;

WordVec read_words_into_vector(const std::string& inFileName);
WordMap map_and_count_words_using_lambda(const WordVec& wVec);
WordMap map_and_count_words_using_functor(const WordVec& wVec);
WordVec remove_duplicates(const WordVec& words_vector);
bool is_palindrome(const std::string& phrase);
size_t count_using_lambda(const WordVec& vec, int n);
size_t count_using_Free_Func(const WordVec& vec, int n);
size_t count_using_Functor(const WordVec& vec, int n);
void multisetUsingMyComparator(const WordVec& vec);
void multisetUsingDefaultComparator(const WordVec& vec);
std::vector<int> generate_Fibonacci(int n);

#endif