/**You are asked to complete Programming Problem 1 on page 589 of your textbook.
* "Complete the implementation of the class ArrayDictionary as given in listing 18-3."
* This program is meant to apply what you have learned in this topic.
* Complete the implementation of the class ArrayDictionary as given in Listing 18 - 3.
* Implement :
*	 DictionaryInterface.h in Listing 81 - 1 on pp. 552 - 553.
*	 Entry.h in Listing 18 - 2 on p. 555.
*	 NotFoundException.h
*	 PrecondViolatedExcept.h
*	 ArrayDictionary.h in Listing18 - 3 on pp. 557 - 558.
* 
* asn  - ArrayDictionary
* 23.SP.CIS.2207.501 Data Structures & Algorithms
* @author John Durham
* @date 3/22/23
* @version 0.0.1
* @file Source.cpp
*/
#include <iostream>
#include <string>
#include "ArrayDictionary.h"

void preScreen();
int mainMenu();
template<class KeyType, class ValueType>
int subMenu(ArrayDictionary<KeyType, ValueType>& dict);

int main() {

	preScreen();
	std::cin.ignore();
	ArrayDictionary<int, std::string> dict;
	int choice;
	std::string str;

	do {
		system("CLS");

		choice = mainMenu();

		switch (choice) {
		case -1:  //wrong choice
			break;
		case 1:  //add
		{
			std::cout << "Enter a number for the Key: \n";
			std::cin >> choice;
			std::wcout << "Enter a string for the Value: \n";
			std::cin >> str;
			try {
				dict.add(choice, str);
			}
			catch (PrecondViolatedExcept) {
				std::cout << "PCVExeption occured during add()....\n";
				system("PAUSE");
				continue;
			}
			break; }
		case 2:  //remove
		{
			std::cout << "Enter the numeric Key to remove the entry: \n";
			std::cin >> choice;
			dict.remove(choice);
			break; }
		case 3:  //search
		{
			std::cout << "Enter the numeric Key to see if the array contains the entry: \n";
			std::cin >> choice;
			if (dict.contains(choice))
				std::cout << "The entry " << choice << " : " << dict.getValue(choice) << " is in the dictionary.\n";
			else
				std::cout << "That is not in the dictionary. Try again.\n";
			break; }
		case 4:  //print
		{
			try {
				if (dict.isEmpty())
				{
					std::cout << "The dictionary is empty.\n";
				}
				else
				{
					for (int i = 0; i < dict.getNumberOfEntries(); i++)
					{
						std::cout << 1 << " : " << dict.getValue(i) << "\n";
					}
				}
			}
			catch (NotFoundException) {
				std::cout << "NFException occurred.....\n";
				system("PAUSE");
			}
			break; }
		case 5:  //traverse
		{
			subMenu(dict);
			break; }
		case 6:  //quit
			break;
		default:  //worse case
			std::cout << "Worse case in main switch statement\n";
		}

	} while (choice != 6);

	std::cout << "........Good Bye......." << std::endl;


	return 0;
}



void preScreen()
{
	std::cout << "*****************************************************************" << std::endl;
	std::cout << "                                                                 " << std::endl;
	std::cout << "    NOTE:  This assignment is array based as there were no       " << std::endl;
	std::cout << "           explicit instruction to imlement a binary tree.       " << std::endl;
	std::cout << "           I can only assume that is in the next lesson?         " << std::endl;
	std::cout << "           I have also hardwired the dictionary data types       " << std::endl;
	std::cout << "           to be Key=int and Value=string, instead of coding     " << std::endl;
	std::cout << "           out the user to have the option as, again, the        " << std::endl;
	std::cout << "           instructions were not excplicit to this.              " << std::endl;
	std::cout << "                                                                 " << std::endl;
	std::cout << "*****************************************************************" << std::endl;
	std::cout << "                     Press Enter to continue                     " << std::endl;
	//TODO - command to prompt user to press enter.....
}


int mainMenu()
{
	int choice;
	std::cout << "=================================================================" << std::endl;
	std::cout << "|            Array Based Dictionary Implementation              |" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "|                           1. Add                              |" << std::endl;
	std::cout << "|                           2. Remove                           |" << std::endl;
	std::cout << "|                           3. Search                           |" << std::endl;
	std::cout << "|                           4. Print                            |" << std::endl;
	std::cout << "|                           5. Traverse                         |" << std::endl;
	std::cout << "|                           6. Quit                             |" << std::endl;
	std::cout << "=================================================================\n";
	std::cout << "                             ";
	std::cin >> choice;
	if (choice < 1 || choice > 6)
		return -1;
	else
		return choice;
}


template<class KeyType, class ValueType>
int subMenu(ArrayDictionary<KeyType, ValueType>& dict)
{
	int choice;
	std::cout << "=================================================================" << std::endl;
	std::cout << "|                 Traverse Array of Dictionaries                |" << std::endl;
	std::cout << "|                1. Advance   2. Reverse   3. Exit              |" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	//show info on dict array per selections, e.i. subscript/total, key, value
	return -1;
}