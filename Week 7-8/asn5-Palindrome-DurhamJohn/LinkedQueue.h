/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    LinkedQueue.h
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398.
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
*/
#pragma once
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "QueueInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <cassert>

template<class ItemType>
class LinkedQueue : public QueueInterface<typename ItemType>
{
private:
	Node<ItemType>* headptr;
	int itemCount;

	Node<ItemType>* getNodeAt(int position) const
	{
		assert((position >= 1) && (position <= itemCount));
		Node<ItemType>* curPtr = headptr;
		for (int skip = 1; skip < position; skip++)
		{
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue<ItemType>& aList);
	~LinkedQueue();

	virtual bool isEmpty() const override;
	virtual bool enqueue(const ItemType& newEntry) override;
	virtual bool dequeue() override;
	virtual ItemType peekFront() const override;

	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
};

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : headptr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aList) : headptr(aList), itemCount(aList.getLength())
{
	itemCount = aList.itemCount;
	if (aList.headptr == nullptr) // if aList is empty
	{
		headptr = nullptr;
	}
	else
	{
		// Copy first node
		headptr = new Node<ItemType>(aList.headptr->getItem());

		// Copy remaining nodes
		Node<ItemType>* origPtr = aList.headptr->getNext();
		Node<ItemType>* newPtr = headptr;

		while (origPtr != nullptr)
		{
			newPtr->setNext(new Node<ItemType>(origPtr->getItem()));
			newPtr = newPtr->getNext();
			origPtr = origPtr->getNext();
		}
	}
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	while (!isEmpty())
		remove(1);
}


template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	// Insert the new node
	if (isEmpty())
	{
		headptr = newNodePtr;
	}
	else
	{
		Node<ItemType>* lastNodePtr = getNodeAt(itemCount);
		lastNodePtr->setNext(newNodePtr);
	}

	++itemCount;

	return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	if (isEmpty()) {
		return false;
	}
	else {
		Node<ItemType>* nodeToDeletePtr = headptr;
		headptr = headptr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		itemCount--;
		return true;
	}
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
	if (isEmpty()) {
		throw(PrecondViolatedExcept("Cannot peek front of an empty queue"));
	}
	return headptr->getItem();
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	if (headptr == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class ItemType>
int LinkedQueue<ItemType>::getLength() const
{
	int length = 0;
	Node<ItemType>* current = headptr;
	while (current != NULL) {
		length++;
		current = current->next;
	}
	return length;
}

template<class ItemType>
bool LinkedQueue<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		if (newPosition == 1)
		{
			newNodePtr->setNest(headptr);
			headptr = newNodePtr;
		}
		else {
			Node<ItemType>* prePtr = getNodeAt(newPosition - 1);
			newNodePtr->setNext(prePtr->getNext());
			prePtr->setNext(newNodePtr);
		}
	}

	return ableToInsert;
}

template<class ItemType>
bool LinkedQueue<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		if (position == 1)
		{
			Node<ItemType>* nodeToDeletePtr = headptr;
			headptr = headptr->getNext();
			delete nodeToDeletePtr;
			nodeToDeletePtr = nullptr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			Node<ItemType>* curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
			delete curPtr;
			curPtr = nullptr;
		}
		itemCount--;
	}
	return ableToRemove;
}

template<class ItemType>
void LinkedQueue<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool canGetEntry = (position >= 1) && (position <= itemCount);
	if (!canGetEntry)
	{
		std::string message = "getEntry() called with an empty queue or invalid position.";
		throw PrecondViolatedExcept(message);
	}

	Node<ItemType>* nodePtr = getNodeAt(position);
	ItemType entry = nodePtr->getItem();

	return entry;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	if ((position < 1) || (position > itemCount)) // check for valid position
	{
		throw PrecondViolatedExcept("replace() called with invalid position.");
	}
	else
	{
		Node<ItemType>* nodeToReplacePtr = getNodeAt(position);
		ItemType oldEntry = nodeToReplacePtr->getItem();
		nodeToReplacePtr->setItem(newEntry);
		return oldEntry;
	}
}
#endif