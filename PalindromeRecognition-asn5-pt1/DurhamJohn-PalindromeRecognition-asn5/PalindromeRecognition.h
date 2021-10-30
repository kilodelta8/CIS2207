/** @file PalindromeRecognition.h */
#pragma once
#include <string>
#ifndef PALINDROME_RECOGNITION_H
#define PALINDROME_RECOGNITION_H


class PalindromeRecognition/* : public QueueInterface<ItemType>, public StackInterface<ItemType>*/
{
private:
	std::string userInput = "";
	int size;

public:
	PalindromeRecognition();
	PalindromeRecognition(std::string input, int sz);
	~PalindromeRecognition();

	//Setters
	void setUserInput(const std::string userIn);

	//Getters
	std::string getUserInput();

	//Others
	bool isPalindrome(char* charArr);


};
//#include "PalindromeRecognition.cpp"
#endif // !PALINDROME_RECOGNITION_H

