/** @file StackInterface.h */
#pragma once
#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
	/** sees whether this stack is empty.
	@return True if the tsack is empty or false if not */
	virtual bool isStackEmpty() const = 0;

	/** Adds a new entry to the top of this stack.
	@post If the operation was successful, newEntryis at the top of the stack.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful or false if not.*/
	virtual bool pushStack(const ItemType& newEntry) = 0;

	/** Removes the top of this stack.
	@post If the operation was successful, the top of the stack as been removed.
	@return True if the removal is successful or false if not.*/
	virtual bool popStack() = 0;

	/** Return a copy of this stack
	@pre The stack is not empty.
	@post A copy of the top of the stack has been returned, and the stack is unchanged.
	@return Ac opy of the top of the stack.*/
	virtual ItemType peekStack() = 0;

	/** Destroys the stack and frees its assigned memory. */
	virtual ~StackInterface() {}
};


#endif // !STACKINTERFACE_H
