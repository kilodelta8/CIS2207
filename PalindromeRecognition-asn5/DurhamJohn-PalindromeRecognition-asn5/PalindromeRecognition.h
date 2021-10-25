/** @file PalindromeRecognition.h */
#pragma once
#include <string>
#include "QueueInterface.h"
#include "StackInterface.h"
#ifndef PALINDROME_RECOGNITION_H
#define PALINDROME_RECOGNITION_H

template<class ItemType>
class PalindromeRecognition: public QueueInterface, public StackInterface
{
private:
	std::string userInput;
	QueueInterface<ItemType>* objQueue = nullptr;
	StackInterface<ItemType>* objStack = nullptr;

public:
	//queue implementation declarations
	QueueInterface(std::string userIn) {
		int size = userInput.length();
		objQueue = new QueueInterface[size];
	}
	template<class ItemType>
	bool QueueInterface<ItemType>::isQempty() const;
	template<class ItemType>
	bool QueueInterface<ItemType>::enqueue(const ItemType& newEntry);
	template<class ItemType>
	bool QueueInterface<ItemType>::dequeue();
	template<class ItemType>
	ItemType QueueInterface<ItemType>::peekQfront() const;
	//TODO - Dont forget the destruct for the queue
	~QueueInterface() { delete objQueue; objQueue = nullptr; }
	
	//stack implementation declarations
	StackInterface() {
		int size = userInput.length();
		objStack = new StackInterface[size];
	}
	template<class ItemType>
	bool StackInterface<ItemType>::isStackEmpty() const;
	template<class ItemType>
	bool StackInterface<ItemType>::pushStack(const ItemType& newEntry);
	template<class ItemType>
	bool StackInterface<ItemType>::popStack();
	template<class ItemType>
	ItemType StackInterface<ItemType>::peekStack();
	//TODO - Dont forget the destruct for the stack
	~StackInterface() { delete objStack; objStack = nullptr; }

	//Setters
	template<class ItemType>
	void setUserInput(ItemType userIn);

	//Getters
	template<class ItemType>
	ItemType getUserInput():

	//Others
	bool isPalindrome(std::string input);
};
#endif // !PALINDROME_RECOGNITION_H

