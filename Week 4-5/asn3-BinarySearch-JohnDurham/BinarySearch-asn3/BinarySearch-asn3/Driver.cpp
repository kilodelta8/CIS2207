/** @file Driver.cpp to utilize binarySearch() from implemetataion file */
/** @author John Durham */
/** @date 02/02/2023 */
/** @version 0.0.3 */
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

	//string to hold user input and char for sort choice
	std::string input;
	char choice;
	//string array initialized with strings
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




	//prompt the user
	std::cout << "Do you wish to try this search?  You will be prompted to enter a phrase of which we will\n";
	std::cout << "search a pre arranged array for that phrase and return the index, IF it is in fact in the array.\n";
	std::cout << "But not before sorting it, as a binary search requires sorting.  Do you?\n";
	std::cout << "Here, before you is the contents of the array.\n";



	//print the unsorted array
	for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE)
		{
			std::cout << i << ": " << strArr[i] << std::endl;
		}
		std::cout << i << " : " << strArr[i] << std::endl;
	}




	//prompt user all the pertinent things
	std::cout << "Enter a string to search for and we will sort this bad boy and search it.\n";
	std::cout << "Enter the search phrase now: ";
	getline(std::cin, input);
	std::cout << "\n";
	std::system("CLS");
	std::cout << "\n";
	std::cout << "Now how would you like the array sorted?\n";
	std::cout << "B - bubble sort\n";
	std::cout << "S - selection sort\n";
	std::cout << "choose wisely: ";
	std::cin >> choice;

	



	//deep sigh......you already know
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
	default:
		std::cout << "You have entered an unknown value, so I will choose the method of bubble sort for you." << std::endl;
		choice = 'B';
	}



	//print the ascention sorted array
	std::cout << "\n";
	std::cout << " Here is the newly sorted array:\n";
	for (int j = 0; j < SIZE; j++)
	{
		if (j == SIZE)
		{
			std::cout << j << ": " << strArr[j] << std::endl;
		}
		std::cout << j << " : " << strArr[j] << std::endl;
	}
	std::cout << "\n"; 
	std::cout << "Now searching the array using binary search methods... .. ..   ..   ..      ..      ." << std::endl;



	//perform binary search using recursive functionality then alert the user
	int found = Search::binarySearch(strArr, SIZE, MIN, SIZE, input);
	if (found == -1)
		std::cout << "Target not found" << std::endl;
	else
		std::cout << "Target found at index " << found << ". " << std::endl;





	//the end of the program
	std::cout << "The end." << std::endl;
	                       

	return 0;
}