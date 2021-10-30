#include <iostream>
#include <string>
#include "Palindrome.h"
#include "QueueInterface.hpp"
#include "StackInterface.hpp"

int main()
{
	char choice = 'y';
	std::string input;
	//Palindrome<std::string> pal1;
	//Palindrome<std::string> pal2;
	StackInterface<char>* pal2;
	QueueInterface<char>* pal1;

	do {
		pal1 = new Palindrome<char>();
		pal2 = new Palindrome<char>();

		std::cout << "Enter a word or phrase to see if it is a Palindrome: ";
		getline(std::cin, input);

		int size = input.length();
		for (int i = 0; i < size; i++)
		{
			pal1->enqueue(input.at(i));
			pal2->push(input.at(i));
		}

		//pal1->setInput(input);
		//pal2->setInput(input);
		//stk->setInput(input);
		//que->setInput(input);

		bool success = false;
		for (int i = 0; i < size; i++)
		{
			if (pal2->peek() == pal1->peekFront())
			{
				success = true;
			}
			else
			{
				success = false;
			}
			pal1->dequeue();
			pal2->pop();
		}

		if (success)
		{
			std::cout << input << " is indeed a Palindrome!" << std::endl;
		}
		if (!success)
		{
			std::cout << input << " is NOT a Palindrome!" << std::endl;
		}
		std::cout << "Do you wish to try another? ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("CLS");

		delete pal1;
		delete pal2;
		pal1 = nullptr;
		pal2 = nullptr;

	} while (choice == 'Y' || choice == 'y');


	return 0;
}