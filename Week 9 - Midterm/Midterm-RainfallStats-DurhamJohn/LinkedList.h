#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getNodeAt(int positon) const;

public:
	LinkedList() : headPtr(nullptr), itemCount(0) {}
	LinkedList(const LinkedList<ItemType>& aList);
	~LinkedList();

	int getLength(Node<ItemType>* head) const;
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	bool isEmpty() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear(int cnt);

	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
};



//
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {}



//
template<class ItemType>
LinkedList<ItemType>::~LinkedList() {}



//
template<class ItemType>
int LinkedList<ItemType>::getLength(Node<ItemType>* head) const
{
	return head.getCount(head);
}



//
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}
}



//
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	assert((position >= 1) && (position <= itemCount));
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
	{
		curPtr = curPtr->getNext();
	}
	return curPtr;
}



//
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}



//
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (newPosition == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return ableToInsert;
}



//
template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;
	}
	return ableToRemove;
}



//
template<class ItemType>
void LinkedList<ItemType>::clear(int cnt)
{
	int cnt2 = 0;
	while (cnt2 < cnt)
		remove(1);
}



//
template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
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

#endif // !LINKEDLIST_H

