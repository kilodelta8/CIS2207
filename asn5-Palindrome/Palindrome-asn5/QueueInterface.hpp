#pragma once
#ifndef QUEUE_INTERFACE_HPP
#define QUEUE_INTERFACE_HPP
#include <iostream>

template<class ItemType>
class QueueInterface
{
public:

	/** See's whether the queue is empty
	@return True if the queue is empty or false if not. */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to the back of the queue.
	@post If the operation as successful, newEntry is at the back of the queue.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful, false if not. */
	virtual bool enqueue(const ItemType& newEntry) = 0;

	/** Removes the front of this queue
	@post If the operation was successful, the front the queue has been removed.
	@return True if the removal was successful or false if not. */
	virtual bool dequeue() = 0;

	/** Returns the front of this queue.
	@pre The queue is not empty.
	@post The front of the queue has been returned, and the queue is unchanged.
	@return The front of the queue.*/
	virtual ItemType peekFront() const = 0;

	/** Destructor - Destroy this queue and free its memory. */
	//virtual ~QueueInterface();
};
#endif // !QUEUE_INTERFACE_HPP

