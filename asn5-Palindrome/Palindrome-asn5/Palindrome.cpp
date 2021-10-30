#include "Palindrome.h"
#include "QueueInterface.hpp"
#include "StackInterface.hpp"





template<class ItemType>
inline void Palindrome<ItemType>::setInput(const ItemType in)
{
	input = in;
	int size = in.length();
	setSizeOfArr(size);
	for (int i = 0; i < sizeOfInput; i++)
	{
		arr[i] = input.at(i);
	}
}

template<class ItemType>
std::string Palindrome<ItemType>::getInput() const
{
	return input;
}

template<class ItemType>
void Palindrome<ItemType>::setSizeOfArr(const int sz)
{
	sizeOfArr = sz;
	sizeOfInput = sz;
}

template<class ItemType>
int Palindrome<ItemType>::getSizeOfArr() const
{
	return sizeOfArr;
}

template<class ItemType>
int Palindrome<ItemType>::getSizeOfInput() const
{
	return sizeOfInput;
}



template<class ItemType>
bool Palindrome<ItemType>::isEmpty() const
{
	//int szOfArr = Palindrome<ItemType>::getSizeOfArr();
	if(sizeOfArr == 0)
		return true;
	else
		return false;
}

template<class ItemType>
bool Palindrome<ItemType>::enqueue(const ItemType& newEntry)
{
	if (arr.empty())
	{
		for (int i = 0; i < sizeOfArr; i++)
		{
			if (arr[i] == 0)
			{
				arr[i] = newEntry;
				break;
			}
		}
		return true;
	}
	return false;
}

template<class ItemType>
bool Palindrome<ItemType>::dequeue()
{
	for (int i = 0; i < sizeOfArr; i++)
	{
		arr[i] = arr[i + 1];
	}
	sizeOfArr--;

	//TODO - need a way to validate
	return true;
}

template<class ItemType>
ItemType Palindrome<ItemType>::peekFront() const
{
	if (!arr.empty())
		return arr[0];
	else
		return 0;
}

template<class ItemType>
bool Palindrome<ItemType>::push(const ItemType& newEntry)
{
	if (arr.empty())
	{
		for (int i = 0; i < sizeOfArr; i++)
		{
			if (arr[i] == 0)
			{
				arr[i] = newEntry;
				break;
			}
		}
		return true;
	}
	return false;
}

template<class ItemType>
bool Palindrome<ItemType>::pop()
{
	arr[sizeOfArr] = 0;
	sizeOfArr--;

	//TODO - validate
	return true;
}

template<class ItemType>
ItemType Palindrome<ItemType>::peek()
{
	return arr[sizeOfArr];
}

/*
template<class ItemType>
QueueInterface<ItemType>::~QueueInterface() {
	std::cout << "Queue Destroyed" << std::endl;
}
template<class ItemType>
StackInterface<ItemType>::~StackInterface() {
	std::cout << "Stack Destroyed" << std::endl;
}
template<class ItemType>
Palindrome<ItemType>::~Palindrome() 
{
	delete[] arr;
}*/