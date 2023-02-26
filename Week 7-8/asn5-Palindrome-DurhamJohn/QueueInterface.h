/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    QueueInterface.h
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398.
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
*/
#pragma once
#include <iostream>
#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

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
	virtual ~QueueInterface() { std::cout << "Queue Destroyed\n"; }
};

#endif
