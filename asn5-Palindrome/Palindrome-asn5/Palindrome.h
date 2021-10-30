#pragma once
#ifndef PALINDROME_H
#define PALINDROME_H
#include "QueueInterface.hpp"
#include "StackInterface.hpp"
#include <string>

const int DEFAULT_SIZE = 40;

template<class ItemType>
class Palindrome : public QueueInterface<ItemType>, public StackInterface<ItemType>
{
private:
	std::string input;
	int sizeOfInput;
	int sizeOfArr = 0;
	ItemType arr[DEFAULT_SIZE] = {0};

public:
	//constructor
	Palindrome() {}

	//palindrome
	void setInput(const ItemType in);
	std::string getInput() const;
	void setSizeOfArr(const int sz);
	int getSizeOfArr() const;
	int getSizeOfInput() const;

	//interface defintions
	//shared???
	bool isEmpty() const;
	//queue
	bool enqueue(const ItemType& newEntry);
	bool dequeue() override;
	ItemType peekFront() const;
	//stack
	bool push(const ItemType& newEntry);
	bool pop() override;
	ItemType peek();

	//destructor
	//QueueInterface<ItemType>::~QueueInterface();
	//StackInterface<ItemType>::~StackInterface();
	~Palindrome() { }
};
#endif // !PALINDROME_H

