#pragma once
#ifndef BINARY_NODE_TREE_H
#define BINARY_NODE_TREE_H
#include <memory>
#include <iostream>
#include <algorithm>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
protected:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
    std::shared_ptr<BinaryNode<ItemType>> balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
        std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
    std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
    virtual std::shared_ptr<BinaryNode<ItemType>>
        removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
            const ItemType target, bool& success);
    std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;
    std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
    void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

    void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
    void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

public:
    BinaryNodeTree();
    BinaryNodeTree(const ItemType& rootItem);
    BinaryNodeTree(const ItemType& rootItem,
        const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
        const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
    BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
    virtual ~BinaryNodeTree();

    bool isEmpty() const override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    ItemType getRootData() const override;
    void setRootData(const ItemType& newData) override;
    bool add(const ItemType& newData) override; 
    bool remove(const ItemType& data) override;
    void clear() override;
    ItemType getEntry(const ItemType& anEntry) const override;
    bool contains(const ItemType& anEntry) const override;

    void preorderTraversal(void visit(ItemType&)) const override;
    void inorderTraversal(void visit(ItemType&)) const override;
    void postorderTraversal(void visit(ItemType&)) const override;

    BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
            getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful)
{
    if (subTreePtr == nullptr) {
        isSuccessful = false;
        return subTreePtr;
    }
    if (subTreePtr->getItem() == target) {
        subTreePtr = moveValuesUpTree(subTreePtr);
        isSuccessful = true;
        return subTreePtr;
    }
    else {
        std::shared_ptr<BinaryNode<ItemType>> leftChildPtr = subTreePtr->getLeftChildPtr();
        std::shared_ptr<BinaryNode<ItemType>> rightChildPtr = subTreePtr->getRightChildPtr();
        if (target < subTreePtr->getItem()) {
            leftChildPtr = removeValue(leftChildPtr, target, isSuccessful);
            subTreePtr->setLeftChildPtr(leftChildPtr);
        }
        else {
            rightChildPtr = removeValue(rightChildPtr, target, isSuccessful);
            subTreePtr->setRightChildPtr(rightChildPtr);
        }
        return subTreePtr;
    }
}


template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
    if (subTreePtr->isLeaf()) { 
        subTreePtr.reset(); 
        return nullptr;
    }
    else if (!subTreePtr->getRightChildPtr()) { 
        subTreePtr->detachLeftChild();
        subTreePtr.reset(); 
        return nullptr;
    }
    else if (!subTreePtr->getLeftChildPtr()) { 
        subTreePtr->detachRightChild();
        subTreePtr.reset(); 
        return nullptr;
    }
    else { 
        auto rightTreePtr = subTreePtr->detachRightChild();
        auto tempPtr = subTreePtr->detachLeftChild();
        tempPtr->setLeftChildPtr(subTreePtr->detachLeftChild());
        tempPtr->setRightChildPtr(rightTreePtr);
        subTreePtr.reset(); 
        return nullptr;
    }
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const
{
    if (treePtr == nullptr) {
        return treePtr;
    }
    else if (treePtr->getItem() == target) {
        return treePtr;
    }
    else {
        std::shared_ptr<BinaryNode<ItemType>> leftNodePtr = findNode(treePtr->getLeftChildPtr(), target);
        if (leftNodePtr != nullptr) {
            return leftNodePtr;
        }
        else {
            return findNode(treePtr->getRightChildPtr(), target);
        }
    }
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreePtr) const
{
    std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

    if (oldTreePtr != nullptr)
    {
        newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(oldTreePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(oldTreePtr->getRightChildPtr()));
    }

    return newTreePtr;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        subTreePtr.reset();
    }
}




template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if (treePtr != nullptr)
    {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }  
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    }  
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    } 
}  

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{  }  

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
    :rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{  }  

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
    const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
    const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem,
        copyTree(leftTreePtr->rootPtr),
        copyTree(rightTreePtr->rootPtr)))
{   }  

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
    rootPtr = copyTree(treePtr.rootPtr);
}  

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    destroyTree(rootPtr);
}  



template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
}  

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
}  

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(rootPtr);
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
    destroyTree(rootPtr);
    rootPtr.reset();
}  

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const
{
    if (isEmpty())
        throw PrecondViolatedExcept("getRootData() called with empty tree.");

    return rootPtr->getItem();
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem)
{
    if (isEmpty())
        rootPtr = std::make_shared<BinaryNode<ItemType>>(newItem, nullptr, nullptr);
    else
        rootPtr->setItem(newItem);
}  

template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}  

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}  

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const
{
    bool isSuccessful = false;
    auto binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);

    if (isSuccessful)
        return binaryNodePtr->getItem();
    else
        throw NotFoundException("Entry not found in tree!");
}  

template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{
    bool isSuccessful = false;
    findNode(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraversal(void visit(ItemType&)) const
{
    preorder(visit, rootPtr);
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraversal(void visit(ItemType&)) const
{
    inorder(visit, rootPtr);
}  

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraversal(void visit(ItemType&)) const
{
    postorder(visit, rootPtr);
}  

template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(
    const BinaryNodeTree<ItemType>& rightHandSide)
{
    if (!isEmpty())
        clear();
    this = copyTree(&rightHandSide);
    return *this;
}

#endif