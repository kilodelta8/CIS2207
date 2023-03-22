#pragma once
#ifndef NODE_H
#define NODE_H


template<class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	~Node();
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	int getCount(Node* head);
};

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

template<class ItemType>
Node<ItemType>::~Node() {}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

template<class ItemType>
int Node<ItemType>::getCount(Node* head)
{
	// Base Case
	if (head == 0)
	{
		return 0;
	}
	// Count this node plus the rest
	// of the list
	else
	{
		return 1 + getCount(head->next);
	}
}

#endif // !NODE_H

