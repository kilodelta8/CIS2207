#pragma once
/**  An array based implementation of the ADT Dictionary that organizes the entries in sorted search key order.
* Search keys in the dictionary are unique.
* @author John Durham
* @date 3/22/23
* @version 0.0.1
* @file ArrayDictionary.h 
*/

#ifndef ARRAY_DICTIONARY_H
#define ARRAY_DICTIONARY_H

#include <memory>
#include <utility>
#include "DictionaryInterface.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template<class KeyType, class ValueType>
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType> {
private:
	static const int DEFAULT_CAPACITY = 21;
	Entry<KeyType, ValueType> entries[DEFAULT_CAPACITY];
	//std::unique_ptr<Entry<KeyType, ValueType>[]> entries;
	int entryCount;
	int maxEntries = DEFAULT_CAPACITY;

	void destroyDictionary()
	{
		for (int i = 0; i < entryCount; i++) {
			delete entries[i];
			entries[i] = nullptr;
		}
		entryCount = 0;
	}

	int findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const
	{
		if (firstIndex > lastIndex) {  // Base case: search key not found
			return -1;
		}

		int midIndex = firstIndex + (lastIndex - firstIndex) / 2;
		if (entries[midIndex].getKey() == searchKey) {  // Base case: search key found
			return midIndex;
		}
		else if (entries[midIndex].getKey() > searchKey) {  // Search in the left half
			return findEntryIndex(firstIndex, midIndex - 1, searchKey);
		}
		else {  // Search in the right half
			return findEntryIndex(midIndex + 1, lastIndex, searchKey);
		}
	}

public:
	ArrayDictionary();
	ArrayDictionary(int maxNumberOfEntries);
	ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& dictionary);

	virtual ~ArrayDictionary();

	virtual bool isEmpty() const override;
	virtual int getNumberOfEntries() const override;
	virtual bool add(const KeyType& searchKey, const ValueType& newValue) throw(PrecondViolatedExcept) override;
	virtual bool remove(const KeyType& searchKey) override;
	virtual void clear() override;
	virtual ValueType getValue(const KeyType& searchKey) const throw(NotFoundException)override;
	virtual bool contains(const KeyType& searchKey) const override;

	virtual void traverse(void visit(ValueType)) const override;
};



template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary() : entryCount(0)
{
}

template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(int maxNumberOfEntries) : maxEntries(maxNumberOfEntries)
{
	entries = new Entry[maxEntries];
	entryCount = 0;
}

template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& dictionary) : entries(dictionary)
{
	maxEntries = dictionary.maxEntries;
	entryCount = dictionary.itemCount;
	entries = new Entry[maxEntries];

	for (int i = 0; i < entryCount; i++) {
		entries[i] = dictionary.entries[i];
	}
}


template<class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::~ArrayDictionary() { clear(); }


template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const
{
	return entryCount == 0;
}

template<class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
	return entryCount;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) throw(PrecondViolatedExcept)
{
	// Check if there is space in the array to add a new entry
	if (entryCount >= maxEntries)
	{
		throw PrecondViolatedExcept("Cannot add more entries to the dictionary.");
	}

	// Check if the search key already exists in the dictionary
	if (contains(searchKey))
	{
		return false;
	}

	// Create a new entry and add it to the array
	Entry<KeyType, ValueType> newEntryPtr = Entry<KeyType, ValueType>(searchKey, newValue);
	entries[entryCount] = newEntryPtr;
	entryCount++;

	return true;
	/*
	if (entryCount == maxEntries)
	{
		throw PrecondViolatedExcept("Dictionary full.");
	}

	int existingIndex = findEntryIndex(0, entryCount - 1, searchKey);

	if (existingIndex != -1) // Entry with same key exists
	{
		entries[existingIndex].setValue(newValue);
	}
	else // Entry with same key does not exist
	{
		Entry<KeyType, ValueType>* newEntryPtr = new Entry<KeyType, ValueType>(searchKey, newValue);
		//entries[entryCount] = std::move(std::unique_ptr<Entry<KeyType, ValueType>>(newEntryPtr));
		entries[entryCount] = std::make_unique<Entry<KeyType, ValueType>>(newEntryPtr);
		entryCount++;
	}

	return true;*/
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& searchKey)
{
	int entryIndex = findEntryIndex(0, entryCount - 1, searchKey);
	if (entryIndex == -1) // Entry not found
	{
		return false;
	}
	else // Entry found
	{
		// Shift all entries after the removed entry to the left
		for (int i = entryIndex; i < entryCount - 1; i++)
		{
			entries[i] = entries[i + 1];
		}
		entryCount--;
		return true;
	}
}

template<class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear()
{
	entryCount = 0;
}

template<class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) const throw(NotFoundException)
{
	int index = findEntryIndex(0, entryCount - 1, searchKey); // find the index of the entry with the given search key
	if (index == -1) // the entry does not exist in the dictionary
		throw NotFoundException("Entry not found in dictionary");

	return entries[index].getValue(); // return the value associated with the search key
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const
{
	// Find the index of the entry with the given search key
	int index = findEntryIndex(0, entryCount - 1, searchKey);

	// Return true if an entry with the given search key was found
	return (index != -1);
}


template<class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::traverse(void visit(ValueType)) const
{
	for (int i = 0; i < entryCount; i++) {
		visit(entries[i].getValue());
	}
}




#endif // !ARRAY_DICTIONARY_H