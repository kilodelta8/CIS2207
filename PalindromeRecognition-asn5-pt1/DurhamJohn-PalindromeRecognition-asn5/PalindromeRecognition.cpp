/** @file PalindromeRecognition.cpp */
#include "PalindromeRecognition.h"





PalindromeRecognition::PalindromeRecognition(std::string input, int sz)
{
	this->userInput = input;
	this->size = sz;
}


PalindromeRecognition::~PalindromeRecognition()
{

}

//Setters
void PalindromeRecognition::setUserInput(const std::string userIn)
{
	this->userInput = userIn;
}

//Getters
std::string PalindromeRecognition::getUserInput()
{
	return this->userInput;
}

//Others
bool PalindromeRecognition::isPalindrome(char* charArr)
{
	//add each character of the string to both the stack and the queue
	for (int i = 0; i < this->size; i++)
	{
		char nextChar = charArr[i];
	}

	//compare the queue chars witht he stack chars
	bool charsAreEqual = false;
	for (int count = 0; count < this->size; count++)
	{
		if (charArr[count] == this->userInput.at((this->size - count)))
			charsAreEqual = true;
	}
	return charsAreEqual;
}