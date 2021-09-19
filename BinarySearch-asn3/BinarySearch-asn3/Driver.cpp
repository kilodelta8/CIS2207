/** @file Driver.cpp to utilize binarySearch() from implemetataion file */
/** @author John Durham */
/** @date 09/16/2021 */
/** @version 0.0.1 */
/* CIS 2207.501
* You are asked to complete Programming Problem 3 on page 94 of your textbook. 
* Problem 3: Implement the binarySearch algorithm presented in this chapter for an array of string.
* This program is meant to apply what you have learned in this topic.
* Make sure to implement the binarySearch algorithm presented in this chapter for the array of strings (page 70). 
* Note that the binarySearch is a recursive algorithm.
*/
#include <iostream>
#include "Search.h"

//array size
const int SIZE = 10;
const int MIN = 0;

int main() {

	std::string input;
	char choice;
	std::string strArr[] = { "This is string one.",
						"Oddly, this is string two!",
						"I bet you can just about guess this one?",
						"This shall be labeled String Four minus one.", 
						"If you really want to hear about it, the first thing you'll probably want to know is where I was born, and what my lousy childhood was like, and how my parents were occupied and all before they had me, and all that David Copperfield kind of crap, but I don't feel like going into it, if you want to know the truth.",
						"",
						"   ",
						"I really quite enjoy C++.",
						"I need a dev job asap",
						"I legit can't stand it anymore."};


	std::cout << "Enter a string to search for and we will sort this bad boy and search it.\n";
	std::cout << "Enter the search phrase now: ";
	getline(std::cin, input);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Now how would you like the array sorted?" << std::endl;
	std::cout << "B - bubble sort" << std::endl;
	std::cout << "S - selection sort" << std::endl;
	std::cout << "choose wisely: ";
	std::cin >> choice;

	if (choice != 'b' && choice != 'B' || choice != 's' && choice != 'S')
	{
		std::cout << "You have entered an unknown value, so I will choose the method of sort for you." << std::endl;
		choice = 'B';
	}

	switch (choice)
	{
	case 'b':
	case 'B':
		Search::bubbleSort(strArr, SIZE);
		std::cout << "The array has been sorted using Bubble Sort." << std::endl;
		break;
	case 's':
	case 'S':
		Search::selectionSort(strArr, SIZE);
		std::cout << "The array has been sorted using Selection Sort." << std::endl;
		break;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Now searching the array using binary search methods... .. ..   ..   ..      ..      ." << std::endl;
	int found = Search::binarySearch(strArr, MIN, SIZE, input);
	if (found == -1)
		std::cout << "Target not found" << std::endl;
	else
		std::cout << "Target found at index " << found << ". " << std::endl;


	std::cout << "The end." << std::endl;
	

	return 0;
}