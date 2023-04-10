#pragma once
#ifndef HEAP_PRIORITY_QUEUE_
#define HEAP_PRIORITY_QUEUE_
#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType> {
public:
	HeapPriorityQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcept);
};

#endif



template<class ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue() : ArrayMaxHeap<ItemType>() {}


template<class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}

template<class ItemType>
bool HeapPriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
}

template<class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
	return ArrayMaxHeap<ItemType>::remove();
}

template<class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	try {
		return ArrayMaxHeap<ItemType>::peekTop();
	}
	catch (const PrecondViolatedExcept& e)
	{
		throw PrecondViolatedExcept("Attempt peek into an empty priority queue.");
	}
}