/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    LinkedStack.h
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398.
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
*/
#pragma once
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <cassert>

template<class ItemType>
class LinkedStack : public StackInterface<typename ItemType>
{
private:
	Node<ItemType>* topPtr;

public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);
	~LinkedStack();

	virtual bool isEmpty() const override;
	virtual bool push(const ItemType& newEntry) override; 
	virtual bool pop() override;
	virtual ItemType peek() override;
};

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	// Set topPtr to null if the other stack is empty
	if (aStack.topPtr == nullptr)
	{
		topPtr = nullptr;
	}
	else
	{
		// Copy the top node of the other stack
		topPtr = new Node<ItemType>(aStack.topPtr->getItem());

		// Traverse the other stack and copy each node
		Node<ItemType>* otherCurrentPtr = aStack.topPtr->getNext();
		Node<ItemType>* currentPtr = topPtr;

		while (otherCurrentPtr != nullptr)
		{
			ItemType nextItem = otherCurrentPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			currentPtr->setNext(newNodePtr);

			currentPtr = currentPtr->getNext();
			otherCurrentPtr = otherCurrentPtr->getNext();
		}
	}
}


template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
	topPtr = newNodePtr;
	return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();

		// Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}
	return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() throw(PrecondViolatedExcept)
{
	if (isEmpty())
	{
		throw(PrecondViolatedExcept("The List Stack is Empty."));
	}
	else {
		return topPtr->getItem();
	}
}

#endif

