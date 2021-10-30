#include "QueueInterface.h"
/*
//queue implementations
template<class ItemType>
bool QueueInterface<ItemType>::isEmpty() const
{
	if (objQueue == nullptr)
		return true;
	else
		return false;
}

template<class ItemType>
bool QueueInterface<ItemType>::enqueue(const ItemType& newEntry)
{
	bool success = true;
	for (int i = 0; i < userInput.lenght(); i++)
	{
		if (objQueue[i] == "" || objQueue[i] == nullptr)
		{
			objStack[i] = newEntry;
			success = true;
			break;
		}
		else
		{
			success = false;
		}
	}
	return success;
}

template<class ItemType>
bool QueueInterface<ItemType>::dequeue()
{
	bool success = true;
	int size = userInput.length();
	objStack[size] = "";
	if (obj.Stack[size] == "")
		success = true;
	else
		success = false;
	return success;
}

template<class ItemType>
ItemType QueueInterface<ItemType>::peekFront() const
{
	return objQueue;
}
//TODO - Dont forget the destruct for the queue - SEE PalindromRecognition.h*/