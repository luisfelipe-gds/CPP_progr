#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Word.h"
#include "WordList.h"
#include "WordCat.h"
#include "WordCatVec.h"

int main()
{
	/*
	Word test_word_1 = Word("Apple");
	cout << "Word: " << test_word_1.getWord() << endl;
	Word test_word_2 = Word("Banana");
	cout << "Word: " << test_word_2.getWord() << endl;
	cout << "Word: " << (test_word_1 < test_word_2) << endl;
	cout << "Word: " << (test_word_2 < test_word_1) << endl;

	
	WordList test_list = WordList();
	test_list.push_back(test_word_1);
	test_list.push_back(test_word_2);
	cout << "List: " << test_list << endl;
	
	
	WordCat test_cat_1 = WordCat("fruits");
	test_cat_1.run();
	*/

	WordCatVec test_vec = WordCatVec();
	test_vec.run();
	
	return 0;
}