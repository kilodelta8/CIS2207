#include <iostream>
#include "PalindromeRecognition.h"
#include <string>
#include <stack>
#include <queue>


int main()
{	
	char* charPtr = nullptr;
	char choice = 'y';
	std::string input;
	std::stack<char> stk;
	std::queue<char> que;

	do {

		std::cout << "Enter a word or phrase to see if it is a Palindrome: ";
		getline(std::cin, input);

		int sz = input.length();

		for (int i = 0; i < sz; i++)
		{
			stk.push(input.at(i));
			que.push(input.at(i));
		}


		bool success = false;
		for (int i = 0; i < sz; i++)
		{
			std::cout << "stack  ---  queue" << std::endl;
			std::cout << stk.top() << "            " << que.front() << std::endl;
			if (stk.top() == que.front())
			{
				success = true;
			}
			else
			{
				success = false;
			}
			que.pop();
			stk.pop();
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
	} while (choice == 'Y' || choice == 'y');

	std::cout << "Good-Bye!" << std::endl;

	return 0;
}