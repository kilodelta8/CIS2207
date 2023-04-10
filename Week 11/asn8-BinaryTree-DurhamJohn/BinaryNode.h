#pragma once
#ifndef BINARY_NODE_H
#define BINARY_NODE_H
#include <memory>

template<class ItemType>
class BinaryNode
{
private:
    ItemType              item;
    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;

public:
    BinaryNode();
    BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
        std::shared_ptr<BinaryNode<ItemType>> rightPtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;

    std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
    std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
};

template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
{ }  // end default constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
    : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
    std::shared_ptr<BinaryNode<ItemType>> leftPtr,
    std::shared_ptr<BinaryNode<ItemType>> rightPtr)
    : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{ }  // end constructor

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}  // end setItem

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}  // end getItem

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    leftChildPtr = leftPtr;
}  // end setLeftChildPtr

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    rightChildPtr = rightPtr;
}  // end setRightChildPtr

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}  // end getLeftChildPtr		

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}  // end getRightChildPtr


#endif