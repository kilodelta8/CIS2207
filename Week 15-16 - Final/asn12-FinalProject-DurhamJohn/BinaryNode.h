#pragma once
#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <string>
using namespace std;

template <class ItemType>
class BinaryNode
{
private:
	ItemType item;
	BinaryNode<ItemType>* leftChildPtr;
	BinaryNode<ItemType>* rightChildPtr;

public:
	BinaryNode();
	BinaryNode(const ItemType& entry);
	BinaryNode(const ItemType& entry,
		BinaryNode<ItemType>* left,
		BinaryNode<ItemType>* right);
	void setItem(const ItemType& anItem);
	ItemType getItem() const;

	bool isLeaf() const;

	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;

	void setLeftChildPtr(BinaryNode<ItemType>* left);
	void setRightChildPtr(BinaryNode<ItemType>* right);

	BinaryNode<ItemType> operator= (const BinaryNode<ItemType>& other);
};
#endif
template class BinaryNode<string>;




//=======================================================================
template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>()
{
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>(const ItemType& entry)
{
	item = entry;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>(const ItemType& entry, BinaryNode<ItemType>* left, BinaryNode<ItemType>* right)
{
	item = entry;
	leftChildPtr = left;
	rightChildPtr = right;
}


template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
	return item;
}

template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	if (leftChildPtr == nullptr && rightChildPtr == nullptr)
	{
		return true;
	}
	return false;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* left)
{
	leftChildPtr = left;
}

template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* right)
{
	rightChildPtr = right;
}

template <class ItemType>
BinaryNode<ItemType> BinaryNode<ItemType>::operator=(const BinaryNode<ItemType>& other)
{
	item = other.getItem();
	leftChildPtr = other.getLeftChildPtr();
	rightChildPtr = other.getRightChildPtr();
	return *this;
}