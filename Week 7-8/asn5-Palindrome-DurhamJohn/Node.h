/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    Node.h
* -------------------------------------------------------------------------------------------------------------
* This code implements a template class for a Node that will be used in a linked data structure. 
  The Node class has two data members: an ItemType object and a pointer to the next Node in the linked data structure. 
  The class provides a constructor, a destructor, and methods for getting and setting the item and the next Node pointer.
  The code defines a class Node that represents a node in a linked list. The class has a template parameter ItemType to 
  allow it to store items of any type. The class has the following member functions:
*/
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
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};


//Node() - default constructor that initializes the next pointer to nullptr.
template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {}


//Node(const ItemType& anItem) - constructor that initializes the item to the provided value and the next pointer to nullptr.
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}


//Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) - constructor that initializes the item to the provided value and 
//the next pointer to the provided nextNodePtr.
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) {}


//void setItem(const ItemType& anItem) - sets the value of the item to the provided value.
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}


//void setNext(Node<ItemType>* nextNodePtr) - sets the value of the next pointer to the provided nextNodePtr.
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}


//ItemType getItem() const - returns the value of the item.
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}


//Node<ItemType>* getNext() const - returns the value of the next pointer.
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

#endif

