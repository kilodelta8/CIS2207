/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    Source.cpp
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what 
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398. 
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include "QueueInterface.h"
#include "StackInterface.h"


//------------------------
std::string toLowerCase(const std::string& str);
bool isPalindrome(std::string str);
std::string menu();


int main() {
	bool stillPlaying = true;

	do {
		system("CLS");
		char answer;
		std::string ret = menu();
		std::string retLower = toLowerCase(ret);
		if (isPalindrome(retLower))
		{
			std::cout << "* * *  That IS in fact a Palindrome!  * * *" << std::endl;
		}
		else
		{
			std::cout << "* * *  That IS NOT a Palindrome:(  * * *\n";
		}

		std::cout << "* * *  Do you wish to try another: (Yy/Nn) ";
		std::cin >> answer;
		switch (answer)
		{
		case 'N':
		case 'n':
			stillPlaying = false;
			break;
		case 'Y':
		case 'y':
			break;
		default:
			std::cout << "* * *  That is not a valid or acceptable entry, try again.  * * *\n";
			system("PAUSE");
		}
		std::cin.ignore();
	} while (stillPlaying);


	std::cout << "* * *            GoodBye!            * * *" << std::endl;


	return 0;
}


//=====================================
std::string toLowerCase(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c){ return std::tolower(c); });
	return result;
}

std::string menu()
{
	std::string input;
	std::cout << "====================================================================" << std::endl;
	std::cout << "|              P a l i n d r o m e    C h e c k e r                |" << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << "          Enter a word to check if it is a Palindrome: \n";
	getline(std::cin, input);
	return input;
}

bool isPalindrome(std::string str)
{
	LinkedQueue<char>* qList = new LinkedQueue<char>();
	LinkedStack<char>* sList = new LinkedStack<char>();

	for (int i = 0; i < str.length(); i++)
	{
		qList->LinkedQueue<char>::enqueue(str[i]);
		sList->LinkedStack<char>::push(str[i]);
	}

	bool charsAreEqual = true;
	while (!qList->LinkedQueue<char>::isEmpty())
	{
		char qFront = qList->LinkedQueue<char>::peekFront();
		char sTop = sList->LinkedStack<char>::peek();
		if (qFront == sTop)
		{
			qList->LinkedQueue<char>::dequeue();
			sList->LinkedStack<char>::pop();
		}
		else
		{
			charsAreEqual = false;
			break;
		}
	}

	delete qList;
	delete sList;
	qList = nullptr;
	sList = nullptr;

	return charsAreEqual;
}