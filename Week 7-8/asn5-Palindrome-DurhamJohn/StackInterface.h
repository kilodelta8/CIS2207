/* @author  John Durham
*  asn4-Palindrome
*  23.SP.CIS.2207.501 Data Structures & Algorithms
*  @date    02/25/2023
*  @version 0.0.1
*  @file    StackInterface.h
* -------------------------------------------------------------------------------------------------------------
* You are asked to complete Programming Problem 3 on page 413 on your textbook. This program is meant to apply what
  you have learned in this topic. Implement the palindrome-recognition algorithm described in Section 13.2.2 on page 398.
  Note that the algorithm uses both a Stack and a Queue, both of which you are expected to implement for this assignment.
  StackInterface.h in Listing 6-1 on p. 197.
  QueueInterface.h in Listing 13-1 on p. 396.
*/
#pragma once
#include <iostream>
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

template<class ItemType>
class StackInterface
{
public:

	/** sees whether this stack is empty.
	@return True if the stack is empty or false if not */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to the top of this stack.
	@post If the operation was successful, newEntryis at the top of the stack.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful or false if not.*/
	virtual bool push(const ItemType& newEntry) = 0;

	/** Removes the top of this stack.
	@post If the operation was successful, the top of the stack as been removed.
	@return True if the removal is successful or false if not.*/
	virtual bool pop() = 0;

	/** Return a copy of this stack
	@pre The stack is not empty.
	@post A copy of the top of the stack has been returned, and the stack is unchanged.
	@return Ac opy of the top of the stack.*/
	virtual ItemType peek() = 0;

	/** Destrucotr - Destroys the stack and frees its assigned memory. */
	virtual ~StackInterface() { std::cout << "Stack Destroyed\n"; }
};

#endif

