#pragma once
/** An inteface for an ADT Dictionary.
    @file DictionaryInterface.h*/

#ifndef DICTIONARY_INTERFACE_H
#define DICTIONARY_INTERFACE_H
#include "NotFoundException.h"

template<class KeyType, class ValueType>
class DictionaryInterface {
public:
    /** Sees whether this dictionary is empty.
    @return True if the dictionary is empty;
       otherwis returns false. */
    virtual bool isEmpty() const = 0;


    /**  Gets the number of entries in thsi dictionary.
    @return The number of entries in the dictionary.  */
    virtual int getNumberOfEntries() const = 0;


    /**  Adds a new search key and associated value to the dictionary.
    @pre The new search key differs from all the search eys presently in the dictionary.
    @post If the addition is successful, the new key-value pari is in its proper position within the dictionary.
    @param searchKey The search key associateed with the value to be added.
    @param newValue The value to be added.
    @return True if the entry was successfully added, or false if not. */
    virtual bool add(const KeyType& searchKey, const ValueType& newValue) = 0;


    /**  Removes a key-value pair in this dictionary.
    @post If the entry whose seach key equas searchKey exists in the dictionary, the entry was removed.
    @param searchKey The key of the entry to be removed.
    @return True if the entry was successfully removed, or false if not. */
    virtual bool remove(const KeyType& searchKey) = 0;


    /**  REmoves all the entries from the dictionary. */
    virtual void clear() = 0;


    /**  Retrieves the value in this dictionary whose search key is given.
    @post If the retrieval is successful, the value is returned.
    @param searchKey The search key of the value to be retrieved.
    @return The value associated with the searchKey.
    @throw NotFoundException if the key-value pair doesn't exist. */
    virtual ValueType getValue(const KeyType& searchKey) const throw(NotFoundException) = 0;


    /**  Sees whether the dictionary ca=intains an entry with the given search key.
    @post The dictionary is unchanged.
    @param searchKey The given search key.
    @return True if the entry with the given search key exists in the dictionary. */
    virtual bool contains(const KeyType& searchKey) const = 0;


    /**  Traverses this dictionary and calls a given client function once for each entry.
    @post The given functions action occurs once for each entry in the dictionary and possibly alters the entry.
    @param visit A client function. */
    virtual void traverse(void visit(ValueType)) const = 0;


    /**  Destroys the dictionary and frees the memory */
    virtual ~DictionaryInterface() {}
};

#endif // !DICTIONARYINTERFACE_H
