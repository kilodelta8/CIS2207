#pragma once
#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_
#include <memory>
#include "Task.h"
#include "HeapInterface.h"
#include "PreCondViolatedExcept.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType> {
public:
	static const int ROOT_INDEX = 0;
	static const int DEFAULT_CAPACITY = 21;
private:std::unique_ptr<ItemType[]> items;
	int itemCount;
	int maxItems;

	int getLeftChildIndex(const int nodeIndex) const;
	int getRightChildIndex(int nodeIndex) const;
	int getParentIndex(int nodeIndex) const;
	bool isLeaf(int nodeIndex) const;
	void heapRebuild(int nodeIndex);
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);
	virtual ~ArrayMaxHeap();

	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const throw(PrecondViolatedExcept);
	bool add(const ItemType& newData);
	bool remove();
	void clear();
};

#endif




template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
	return (2 * nodeIndex) - 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
	return getLeftChildIndex(nodeIndex) >= itemCount;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int nodeIndex)
{
	for (int index = itemCount - 1; index >= 0; index--)
		heapRebuild(index);
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2 - 1; index >= 0; index--)
		heapRebuild(index);
}


template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY), items(std::make_unique<ItemType>()) {}


template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{
	items = std::shared_ptr<ItemType[]>(maxItems);
	for (int i = 0; i < itemCount; i++)
		items[i] = someArray[i];

	heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
	clear();
}


template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	if (itemCount > 0)
		return false;
	else
		return true;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	return itemCount;
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcept)
{
	if (isEmpty())
		throw PrecondViolatedExcept("Attempted to peek into an empty heap.");
	return items[0];
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
	if (itemCount < maxItems)
	{
		//items = std::move(newData);
		items[itemCount] = newData;
		itemCount++;
		return true;
	}
	else
	{
		return false;
	}
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	itemCount--;
	return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount = 0;
}