#pragma once
/**  A class of entries to add ot an array based implementation of the ADT Dictionary.
@file Entry.h */

#ifndef ENTRY_H
#define ENTRY_H

template<class KeyType, class ValueType>
class Entry {
private:
	KeyType key;
	ValueType value;

protected:
	void setKey(const KeyType& searchKey)
	{
		key = searchKey;
	}

public:
	Entry();
	Entry(const KeyType& searchKey, const ValueType& newValue);
	ValueType getValue() const;
	KeyType getKey() const;
	void setValue(const ValueType& newValue);

	bool operator==(const Entry<KeyType, ValueType>& rightHandValue) const;
	bool operator>(const Entry<KeyType, ValueType>& rightHandValue) const;
};



template<class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry()
{
}

template<class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry(const KeyType& searchKey, const ValueType& newValue)
{
	key = searchKey;
	value = newValue;
}

template<class KeyType, class ValueType>
ValueType Entry<KeyType, ValueType>::getValue() const
{
	return value;
}

template<class KeyType, class ValueType>
KeyType Entry<KeyType, ValueType>::getKey() const
{
	return key;
}

template<class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setValue(const ValueType& newValue)
{
	value = newValue;
}

template<class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType, ValueType>& rightHandValue) const
{
	return key == rightHandValue.key && value == rightHandValue.value;
}

template<class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType, ValueType>& rightHandValue) const
{
	return key > rightHandValue.key;
}
#endif // !ENTRY_H