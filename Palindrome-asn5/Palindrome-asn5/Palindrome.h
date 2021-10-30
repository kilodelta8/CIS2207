#pragma once
#ifndef PALINDROME_H
#define PALINDROME_H
#include "QueueInterface.hpp"
#include "StackInterface.hpp"
#include <string>

const int DEFAULT_SIZE = 40;

template<class ItemType>
class Palindrome : public QueueInterface<char>, public StackInterface<char>
{
private:
	std::string input;
	int sizeOfInput;
	int sizeOfArr = 0;
	char arr[DEFAULT_SIZE] = {0};

public:
	//constructor
	Palindrome() : input("") {}

	//palindrome
	void setInput(const ItemType in);
	std::string getInput() const;
	void setSizeOfArr(const int sz);
	int getSizeOfArr() const;
	int getSizeOfInput() const;

	//interface defintions
	//shared???
	bool isEmpty() const override;
	//queue
	bool enqueue(const ItemType& newEntry) override;
	bool dequeue() override;
	ItemType peekFront() const override;
	//stack
	bool push(const ItemType& newEntry) override;
	bool pop() override;
	ItemType peek() override;

	//destructor
	~Palindrome();
};
#endif // !PALINDROME_H

