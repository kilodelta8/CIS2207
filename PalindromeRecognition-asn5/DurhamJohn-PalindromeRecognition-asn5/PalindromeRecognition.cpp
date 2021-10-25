/** @file PalindromeREcognition.cpp */
#include "PalindromeRecognition.h"
#include "QueueInterface.h"
#include "StackInterface.h"

//queue implementations
template<class ItemType>
bool QueueInterface<ItemType>::isQempty() const
{
	if (objQueue == nullptr)
		return true;
	else
		return false;
}

template<class ItemType>
bool QueueInterface<ItemType>::enqueue(const ItemType& newEntry)
{
	bool success = true;
	int size = objQueue.length() + 1;
	//objQueue[size]
	return success;
}

template<class ItemType>
bool QueueInterface<ItemType>::dequeue()
{
	return true;
}

template<class ItemType>
ItemType QueueInterface<ItemType>::peekQfront() const
{
	return ItemType;
}
//TODO - Dont forget the destruct for the queue - SEE PalindromRecognition.h



//stack implementation declarations
template<class ItemType>
bool StackInterface<ItemType>::isStackEmpty() const
{
	if (objStack == nullptr)
		return true;
	else
		return false;
}

template<class ItemType>
bool StackInterface<ItemType>::pushStack(const ItemType& newEntry)
{
	return true;
}

template<class ItemType>
bool StackInterface<ItemType>::popStack()
{
	return true;
}

template<class ItemType>
ItemType StackInterface<ItemType>::peekStack()
{
	return ItemType;
}
//TODO - Dont forget the destruct for the stack - SEE PalindromRecognition.h


//Setters
template<class ItemType>
void setUserInput(ItemType userIn)
{
	userInput = userIn;
}

//Getters
template<class ItemType>
ItemType getUserInput()
{
	return userInput;
}

//Others
bool isPalindrome(std::string input)
{
	//create empty queue and stack
	QueueInterface<char>* queuePtr = nullptr;
	StackInterface<char>* stackPtr = nullptr;

	//add each character of the string to both the stack and the queue
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		char nextChar = input.at(i);
		queuePtr->enqueue(nextChar);      //TODO - these return a bool!!!!!
		stackPtr->pushStack(nextChar);
	}

	//compare the queue chars witht he stack chars
	bool charsAreEqual = true;
	while (!queuePtr->isQempty() && charsAreEqual)
	{
		char queueFront = queuePtr->peekQfront();
		char stackTop = stackPtr->peekStack();    //TODO - this seems off, like it should return the last element not a copy of the entire stack
		if (queueFront == stackTop)
		{
			queuePtr->dequeue();   //TODO - these return a bool!
			stackPtr->popStack();
		}
		else
			charsAreEqual = false;
	}
	return charsAreEqual;
}
