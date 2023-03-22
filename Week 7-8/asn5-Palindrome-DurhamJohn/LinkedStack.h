/*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @author  John Durham
*  @date    02/25/2023
*  @version 0.0.1
*  @file    LinkedStack.h
* -------------------------------------------------------------------------------------------------------------
This is a C++ header file for a linked stack data structure, which implements the StackInterface. The linked stack
is implemented using a linked list data structure, where each node in the list contains an item and a pointer to 
the next node. The class definition for LinkedStack includes a private data member topPtr, which points to the top 
node of the stack.
The implementation of the class uses a linked list data structure, where each node contains an item and a pointer 
to the next node. The LinkedStack() constructor initializes the topPtr to nullptr. 
The LinkedStack(const LinkedStack<ItemType>& aStack) constructor creates a new stack by copying each node of 
another stack. It first checks if the other stack is empty, and if it is, sets the topPtr to nullptr. Otherwise, 
it copies the top node of the other stack and then traverses the other stack, copying each node and linking it to 
the previous one. The ~LinkedStack() destructor deletes all nodes of the stack by repeatedly calling the pop() method 
until the stack is empty. The isEmpty() method returns true if the topPtr is nullptr, and false otherwise. 
The push(const ItemType& newEntry) method adds a new node to the top of the stack by creating a new node with the 
newEntry item and linking it to the previous top node. The pop() method removes the top node of the stack by updating 
the topPtr to point to the next node and deleting the old top node. The peek() method returns the item of the top node 
of the stack without removing it, and throws a PrecondViolatedExcept exception if the stack is empty.
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


//LinkedStack() - the default constructor that sets the topPtr to nullptr.
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}


//LinkedStack(const LinkedStack<ItemType>& aStack) - a copy constructor that 
//creates a new stack by copying each node of another stack.
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


//~LinkedStack() - a destructor that deletes all nodes of the stack.
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}


//isEmpty() - a method that returns a boolean indicating whether the stack is empty or not.
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}


//push(const ItemType& newEntry) - a method that adds a new item to the top of the stack.
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
	topPtr = newNodePtr;
	return true;
}


//pop() - a method that removes the top item from the stack and returns a boolean indicating 
//whether the operation was successful or not.
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


//peek() - a method that returns the top item of the stack without removing it. If the stack 
//is empty, it throws a PrecondViolatedExcept exception.
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

