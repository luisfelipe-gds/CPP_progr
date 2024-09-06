/* ***************************************************************************
 * COMP 5421 - Summer 2024 - Assignment 1 - Professor Sadegh Ghaderpanah
 * Student Name: Luis Felipe Garcia de Souza
 * Student ID: 40266040
 * Date: May 26, 2024
 * ***************************************************************************
 *
 * Please check the ReadMe file for the detailed description of all classes
 * and how they interact.
 *
 * ***************************************************************************
 * Class Description:
 * The main.cpp file contains the main function that calls the test functions
 * for the Word, WordList, WordCat, and WordCatVec classes.
 */


#include "Word.h"
#include "WordList.h"
#include "WordCat.h"
#include "WordCatVec.h"
using std::cout;
using std::cin;
using std::endl;

void test_Word() {

	//Assignment tests
	Word w1("Apple"); // create a word
	w1.print(cout); // test print
	cout << w1 << endl; // test operator<<
	
	Word w2; // an empty word, a word of size zero.
	cout << "Enter a word: "; // prompt the user for input
	
	w2.read(cin); // read actual word from keyboard
	
	Word w3 = w1.concat(w2); // test concat
	
	cout << w3 << endl; // see output in the output box below
	
	// Additional tests
	// Create some words
	Word w11("Apple");
	Word w12("Banana");
	Word w13("Cherry");
	Word w14("Avocado");

	// A. Mutator #1
	cout << "w11: " << w11 << endl;
	w11.changeWord("Apple Seed");
	cout << "changed w11: " << w11 << endl;

	// B. Mutator #2
	cout << "w12: " << w12 << endl;
	w12.changeWord(w1);
	cout << "changed w12: " << w12 << endl;

	// C. Concatenation
	cout << "w13: " << w13 << endl;
	cout << "w14: " << w14 << endl;
	Word w15 = w13.concat(w14, " and ");
	cout << "concatenated w15: " << w15 << endl;

	// D. Less than
	cout << w11 << " < " << w14 << " ? " << (w11.isLess(w14) ? "true" : "false") << endl;
	cout << w14 << " < " << w11 << " ? " << (w14.isLess(w11) ? "true" : "false") << endl;

	// E. At
	cout << "w15[0]: " << w15.at(0) << endl;
	cout << "w15[1]: " << w15.at(1) << endl;
	cout << "w15[2]: " << w15.at(2) << endl;
	cout << "w15[3]: " << w15.at(3) << endl;

	// F. Copy constructor
	Word w16(w15);
	cout << "w16: " << w16 << endl;

	// G. Move constructor
	Word w17("Temporary Word 1");
	cout << "w17: " << w17 << endl;

	// H. Copy assignment operator
	Word w18;
	w18 = w17;
	cout << "w8: " << w18 << endl;	

	// I. Move assignment operator
	Word w19;
	w19 = "Temporary Word 2";
	cout << "w19: " << w19 << endl;

	// Extra test for exception handling
	Word w20 = "Exception Test";
	w20.at(100); // should throw an exception

}

void testWordList() {
	//Assignments tests
	WordList list; //test default ctor
	
	list.push_front(Word("fox"));
	list.push_front(Word("brown"));
	list.push_front(Word("quick"));
	list.push_front(Word("The"));
	list.push_back(Word("jumps")); // <-
	list.push_back(Word("over"));
	list.push_back(Word("the"));
	list.push_back(Word("lazy"));
	list.push_back(Word("dog"));
	
	cout << "All : \n" << list << "\n"; // test operator <<
	

	Word front = list.pop_front(); // test pop_front
	cout << "poped front: \n" << list << "\n";
	
	
	list.pop_back(); // test pop_back
	cout << "poped back : \n" << list << "\n";
	

	list.remove(Word("quick")); // delete a word
	cout << "quick gone : \n" << list << "\n";
	
	// can’t presume that the word to remove is actually in the list
	bool result = list.remove(Word("cat")); // try to delete a word not on the list
	cout << "cat " << (result ? " gone" : " not found") << "\n";
	
	list.remove(Word("lazy")); // delete a word
	cout << "lazy gone : \n" << list << "\n";
	
	Word word("fox");
	bool found = list.lookup(word); // test lookup
	cout << "lookup: " << word;
	cout << (found ? " found" : " not found") << "\n";
	word = Word("lazy"); // this is an example of a ’move’ assignment;
						// here, the right operand Word("lazy") is a temporary

	found = list.lookup(word);
	cout << "lookup: " << word;
	cout << (found ? " found" : " not found") << "\n";

	list.clear(); // test clear

	cout << "Clear : \n" << list << "\n"; 

	return;
}

void testWordCat() {
	WordCat word_cat("fruits");
	word_cat.run();
}

void testWordCatVec() {
	WordCatVec word_cat_vec;
	word_cat_vec.run();
}

int main() {
	
	//test_Word();
	//testWordList();
	//testWordCat();
	testWordCatVec();
	

	return 0;
}