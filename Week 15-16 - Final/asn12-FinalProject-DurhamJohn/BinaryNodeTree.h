#pragma once
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template <class ItemType>
class BinaryNodeTree : BinaryTreeInterface<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;
	int arrCounter = 0;

protected:
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	void destroyTree(BinaryNode<ItemType>* subTreePtr);

	BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const string& name, bool& success);
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	BinaryNode<ItemType>* findNodeByName(BinaryNode<ItemType>* treePtr, const string& target, bool& success) const;
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

	void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void preorder(BinaryNode<ItemType>* treePtr, ItemType* arr);

public:
	BinaryNodeTree();
	BinaryNodeTree(const BinaryNode<ItemType>* root);
	BinaryNodeTree(const BinaryNode<ItemType>* root, BinaryNode<ItemType>* leftPtr,
		BinaryNode<ItemType>* rightPtr);
	BinaryNodeTree(const BinaryNodeTree& tree);
	virtual ~BinaryNodeTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw (PrecondViolationExcept);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const string& name) throw (NotFoundException);
	void clear();
	ItemType getEntry(const string& anEntry) const throw (NotFoundException);
	bool contains(const string& anEntry) const;

	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	bool isSameTree(BinaryNodeTree<string> other);
	ItemType* createNodeArray();

	BinaryNodeTree<ItemType>& operator=(const BinaryNodeTree<ItemType>& rightHandSide);
};
#endif
template class BinaryNodeTree<string>;



//====================================================================
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNode<ItemType>* root)
{
	rootPtr->setItem(root->getItem());
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNode<ItemType>* root,
	BinaryNode<ItemType>* leftPtr,
	BinaryNode<ItemType>* rightPtr)
{
	rootPtr->setItem(root->getItem());
	rootPtr->setLeftChildPtr(leftPtr);
	rootPtr->setRightChildPtr(rightPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}



template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;
	if (treePtr != nullptr)
	{
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newTreePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}
		return subTreePtr;
	}
}



template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
	const string& name, bool& success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return subTreePtr;
	}
	BinaryNode<ItemType>* toRemove = findNodeByName(subTreePtr, name, success); 
	if (success) 
	{
		moveValuesUpTree(toRemove);
	}
	return subTreePtr;

}




template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr) 
	{
		if (!subTreePtr->isLeaf())
		{
			if (subTreePtr->getLeftChildPtr() != nullptr)
			{
				subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
				if (subTreePtr->getLeftChildPtr()->isLeaf())
				{
					subTreePtr->setLeftChildPtr(nullptr);
					delete subTreePtr->getLeftChildPtr();
				}
				else
				{
					moveValuesUpTree(subTreePtr->getLeftChildPtr());
				}
			}
			else if (subTreePtr->getRightChildPtr() != nullptr)
			{
				subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
				if (subTreePtr->getRightChildPtr()->isLeaf())
				{
					subTreePtr->setRightChildPtr(nullptr);
					delete subTreePtr->getRightChildPtr();
				}
				else
				{
					moveValuesUpTree(subTreePtr->getRightChildPtr());
				}
			}
		}
	}
	return subTreePtr;
}




template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNodeByName(BinaryNode<ItemType>* treePtr,
	const string& target, bool& success) const
{
	BinaryNode<ItemType>* foundPtr;
	if (treePtr == nullptr)
	{
		success = false;
		return treePtr;
	}

	if (treePtr->getItem()._Equal(target)) 
	{
		success = true;
		return treePtr;
	}
	else 
	{
		foundPtr = findNodeByName(treePtr->getLeftChildPtr(), target, success); 
		if (!success)
		{
			foundPtr = findNodeByName(treePtr->getRightChildPtr(), target, success);
		}
	}
	return foundPtr;
}



template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&),
	BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType item = treePtr->getItem();
		visit(item); 
		preorder(visit, treePtr->getLeftChildPtr()); 
		preorder(visit, treePtr->getRightChildPtr()); 
	}
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr, ItemType* arr)
{
	if (treePtr != nullptr)
	{
		ItemType item = treePtr->getItem();
		arr[arrCounter] = item;
		arrCounter++;
		preorder(treePtr->getLeftChildPtr(), arr); 
		preorder(treePtr->getRightChildPtr(), arr); 
	}
}


template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	if (rootPtr == nullptr)
		return true;
	else
		return false;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>();
	newNode->setItem(newData);
	rootPtr = balancedAdd(rootPtr, newNode);
	return true;
}


template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const string& name) throw (NotFoundException)
{
	bool result = false;
	if (!contains(name)) 
	{
		throw NotFoundException("Not Found Exception");
		return false;
	}
	rootPtr = removeValue(rootPtr, name, result);
	return result;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	if (rootPtr != nullptr)
	{
		destroyTree(rootPtr->getLeftChildPtr());
		destroyTree(rootPtr->getRightChildPtr());
		rootPtr = nullptr;
		arrCounter = 0;
	}
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const string& name) const throw (NotFoundException)
{
	bool found = false;
	BinaryNode<ItemType>* node = findNodeByName(rootPtr, name, found);
	if (found)
	{
		return node->getItem();
	}
	else
	{
		throw NotFoundException("Not found in tree");
	}
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const string& anEntry) const
{
	bool found = false;
	findNodeByName(rootPtr, anEntry, found);
	return found;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw (PrecondViolationExcept)
{
	if (rootPtr != nullptr)
		return rootPtr->getItem();
	else
		throw PrecondViolationExcept("Tree is empty");
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	rootPtr->setItem(newData);
}


template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	//inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	//postorder(visit, rootPtr);
}


template <class ItemType>
bool BinaryNodeTree<ItemType>::isSameTree(BinaryNodeTree<string> other)
{
	if (getHeight() != other.getHeight() || getNumberOfNodes() != other.getNumberOfNodes())
	{
		return false;
	}
	int size = getNumberOfNodes();
	ItemType* arr_TreeA = createNodeArray();
	ItemType* arr_TreeB = other.createNodeArray();
	for (int i = 0; i < size; i++)
	{
		bool matchFound = false;
		for (int j = 0; j < size; j++)
		{
			if (arr_TreeA[i] == arr_TreeB[j])
			{
				matchFound = true;
				break;
			}
		}
		if (!matchFound)
		{
			return false;
		}
	}
	return true;
}

template <class ItemType>
ItemType* BinaryNodeTree<ItemType>::createNodeArray()
{
	int size = getNumberOfNodes();
	ItemType* nodes = new ItemType[size];
	preorder(rootPtr, nodes);
	return nodes;
}


template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rightHandSide)
{
	if (!isEmpty())
	{
		clear();
	}
	rootPtr = copyTree(rightHandSide.rootPtr);
	return *this;
}