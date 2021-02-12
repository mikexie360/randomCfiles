/*
 * binarySearchTree.h
 *
 *  Created on: Dec 7, 2018
 *      Author: Mike Xie
 *      Purpose: A binary search tree to more easily search for possible answer keys or matches
 *
 *      Many parts of the code were copied from the textbook with some modification
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "memoryLeak.h"
#pragma once

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <iterator>

//forward declaration of the template class binarySearchTree
template<class DataType>
class binarySearchTree;

//nodes for the binary tree
template<class DataType>
class treeNode
{
	friend class binarySearchTree<DataType>;

public:
	//default constructor
	treeNode()
	{
	lLink = nullptr;
	rLink = nullptr;
	}
	//constructor for dataType
	treeNode(DataType data)
	{
		dataType = data;
		lLink = nullptr;
		rLink = nullptr;
	}
	DataType getData() const
	{
		return dataType;
	}
	//output a dataType
	template<typename type> friend void output(type data);
protected:
	//holds data
	DataType dataType;
	//points to the left node
	treeNode<DataType> *lLink;
	//points to the right node
	treeNode<DataType> *rLink;
};

//operator for treeNode
template<class DataType>
std::ostream& operator<<(std::ostream& out, const treeNode<DataType>* node)
{
	out << node->getData();
	return out;
}

//update a node
template <typename type>
void update(type &existingItem, const type &newItem)
{
	existingItem.update(newItem);
}

//output a dataType
template <typename type>
void output(type word)
{
	std::cout << word << std::endl;
}

//binarySearchTree class
template<class DataType>
class binarySearchTree
{
protected:
	//points to first node;
	treeNode<DataType> *root;

	//number of Nodes
	long long int nodeCount;
public:

	//copy constructor
	binarySearchTree(const binarySearchTree<DataType>& otherTree);

	//constructor
	binarySearchTree();

	//destructor
	virtual ~binarySearchTree();

	//assignment operator overload
	const binarySearchTree<DataType>& operator=(const binarySearchTree<DataType>&);

	//checks if the binary tree is empty
	bool empty() const;

	//returns the number of items in the binary tree
	std::size_t size() const
	{
		return nodeCount;
	}

	//prints node in order
	void print() const;

	//needed to find a function
	static void processFound(const DataType &item);

	//debug function
	void debug(std::ostream &out) const;

	//find function
	bool find(const DataType &searchItem);
	//find function for printing
	bool find(const DataType &searchItem, void (*foundNode)(const DataType&));

	//deletes a node
	bool erase(const DataType &deleteItem);

	//insert a new node
	void insert(const DataType &newItem);
	//insert a new node
	void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem));

	//for traversal
	void traverse(void (*itemFound)(const DataType& foundItem)) const;
	void traverseOut (treeNode<DataType>* node, std::ostream&output) const;
	//for traversing though the binary search tree
	void inorder(treeNode<DataType>* node, void(*visit)(const DataType& item)) const;
	//for traversing through the binary search tree
	void inorder (treeNode<DataType>* p, std::ostream &outstream, void (*visit) (const treeNode<DataType>* node, std::ostream &out)) const;
	//makes a copy of a binary tree
	void copyTree(treeNode<DataType>* &copiedTreeRoot, treeNode<DataType>* otherTreeRoot);

	//delete a node that the node points to is deleted
	void deleteFromTree(treeNode<DataType>* &node);

	//destroy the binary tree to which node points to
	void destroy(treeNode<DataType>* &node);

	//bonus parts------------------------------------------------------------------------------------------------------------------------------
	//print to ostream
	void print(std::ostream &out) const;
	//traverse preorder
	void traversePreOrder(void (*itemFound) (const DataType& foundItem)) const;
	//for traversing
	void preorder(treeNode<DataType>* node, void(*visit) (const DataType& item)) const;

	//traverse postorder
	void traversePostOrder(void (*itemFound) (const DataType& foundItem)) const;
	//for traversing
	void postorder(treeNode<DataType>* node, void(*visit) (const DataType& item)) const;
};

//assignment operator overload.
template <class DataType>
const binarySearchTree<DataType>& binarySearchTree<DataType>::operator=(const binarySearchTree<DataType>& otherTree)
{
	if (this != &otherTree)
	{
		if (root != nullptr)
		{
			destroy(root);
		}
		if(otherTree.root == nullptr)
		{
			root = nullptr;
		}
		else
		{
			nodeCount = otherTree.nodeCount;
			copyTree(root, otherTree.root);
		}
	}
	return *this;
}

//destroy the binary tree to which node points to
template <class DataType>
void binarySearchTree<DataType>::destroy(treeNode<DataType>* &node)
{
	//if not empty then start deleting the tree
	if (node != nullptr)
	{
		destroy(node->lLink);
		destroy(node->rLink);
		delete node;
		node = nullptr;
	}
}

//default constructor
template <class DataType>
binarySearchTree<DataType>::binarySearchTree()
{
	root = nullptr;
	nodeCount = 0;
}

//copy binary search tree and make a deep copy
template <class DataType>
void binarySearchTree<DataType>::copyTree
								(treeNode<DataType>* &copiedTreeRoot,
								treeNode<DataType>* otherTreeRoot)
{
	//if empty
	if (otherTreeRoot == nullptr)
	{
		copiedTreeRoot = nullptr;
	}
	//else copy every node
	else
	{
		copiedTreeRoot = new treeNode<DataType>;
		copiedTreeRoot->dataType = otherTreeRoot->dataType;

		copyTree (copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree (copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}

//copy constructor
template <class DataType>
binarySearchTree<DataType>::binarySearchTree
							(const binarySearchTree<DataType>& otherTree)
{
	//if empty
	if (otherTree.root == nullptr)
	{
		root = nullptr;
		nodeCount = 0;
	}
	//if not empty then make a deep copy
	else
	{
		nodeCount = otherTree.nodeCount;
		copyTree(root, otherTree.root);
	}
}

//destructor
template <class DataType>
binarySearchTree<DataType>::~binarySearchTree()
{
	while(!empty())
	{
		deleteFromTree(root);
	}
}

//check to see if empty
template <class DataType>
bool binarySearchTree<DataType>::empty() const
{
	return (root == nullptr);
}

//used to find a function. i did not use this function in my program
template <class DataType>
void binarySearchTree<DataType>::processFound(const DataType &item)
{
    std::cout << "The word/words found are: "<<std::endl;
}

//insert a new data
template <class DataType>
void binarySearchTree<DataType>::insert(const DataType& newItem)
{
	//if there is no root, a new node is set as root
	if (root == nullptr)
	{
		root = new treeNode<DataType>(newItem);
		nodeCount++;
		return;
	}
	treeNode<DataType> *node = root;
	//through out the tree
	while (node!=nullptr)
	{
		//go right if the current value is greater than the current node
		if (newItem > node->dataType)
		{
			//if the right node is empty, set it as a new node
			if (node->rLink == nullptr)
			{
				node->rLink = new treeNode<DataType>(newItem);
				nodeCount++;
				break;
			}
			node = node->rLink;
		}
		//go left if the current value is less than the current node
		else if(newItem < node->dataType)
		{
			//if the left node is empty, set it as a new node
			if (node->lLink == nullptr)
			{
				node->lLink = new treeNode<DataType>(newItem);
				nodeCount++;
				break;
			}
			node = node->lLink;
		}
		//if current value is equal to the current node, replace the node's value
		else if (newItem == node->dataType)
		{
			node->dataType = newItem;
			break;
		}
	}
}

//insert new data
template <class DataType>
void binarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem))
{
	//if there is no root, make a node out of newItem and set it as the root
	if (root == nullptr)
	{
		root = new treeNode<DataType>(newItem);
		nodeCount++;
		return;
	}
	treeNode<DataType> *node = root;
	//loop through the tree
	while (node != nullptr)
	{
		//go right if current value is greater than the node
		if(newItem > node->dataType)
		{
			//replace the right node if there is no right node
			if(node->rLink == nullptr)
			{
				node->rLink = new treeNode<DataType>(newItem);
				nodeCount++;
				break;
			}
			//go right
			node = node->rLink;
		}
		//go left if the current value is less than the node
		else if(newItem < node->dataType)
		{
			//replace the left node if there is no left node
			if ( node->lLink == nullptr)
			{
				node->lLink = new treeNode<DataType>(newItem);
				nodeCount++;
				break;
			}
			//go left
			node = node->lLink;
		}
		//replace the current node if the current node is equal to the current value;
		else if (newItem == node->dataType)
		{
			(*duplicateItemFound)(node->dataType, newItem);
			break;
		}
	}
}

//finds a node and returns true if it exists in the binary tree
template <class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem)
{
	treeNode<DataType> *node = root;
	while (node != nullptr)
	{
		//go right if the searchItem is greater than node
		if (searchItem > node->dataType)
		{
			//if there is no right link then it is not found
			if (node->rLink == nullptr)
			{
				return false;
			}
			//move right
			node = node->rLink;
		}
		//go left if the searchItem is less than the node
		else if ( searchItem < node->dataType)
		{
			//if there is no left link then it is not found
			if ( node->lLink == nullptr)
			{
				return false;
			}
			//move left
			node = node->lLink;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//finds a node and returns true if it exists in the binary tree
template <class DataType>
bool binarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType&))
{
	treeNode<DataType> *node = root;
	while (node != nullptr)
	{
		//go right if the searchItem is greater than node
		if (searchItem > node->dataType)
		{
			//if there is no right link then it is not found
			if (node->rLink == nullptr)
			{
				return false;
			}
			//move right
			node = node->rLink;
		}
		//go left if the searchItem is less than the node
		else if ( searchItem < node->dataType)
		{
			//if there is no left link then it is not found
			if ( node->lLink == nullptr)
			{
				return false;
			}
			//move left
			node = node->lLink;
		}
		else
		{
			(*foundNode)(node->dataType);
			return true;
		}
	}
	return false;
}

//debug function
template <class DataType>
void binarySearchTree<DataType>::debug(std::ostream &out) const
{
	out << "DEBUG" << std::endl;
	out << "number of nodes" << size() << std::endl;
	print();
	out << "END DEBUG" << std::endl;
}

//delete a node
template <class DataType>
void binarySearchTree<DataType>::deleteFromTree (treeNode<DataType>* &node)
{
    treeNode<DataType> *current;
    treeNode<DataType> *trailCurrent;
    treeNode<DataType> *temp;
    if (node == nullptr)
    {
    	return;
    }
    //if left and right link does not exist
    else if (node->lLink == nullptr && node->rLink == nullptr)
    {
        temp = node;
        node = nullptr;
        delete temp;
        nodeCount--;
    }
    //if left link does not exist
    else if (node->lLink == nullptr)
    {
        temp = node;
        node = temp->rLink;
        delete temp;
        nodeCount--;
    }
    //if right link does not exist
    else if (node->rLink == nullptr)
    {
        temp = node;
        node = temp->lLink;
        delete temp;
        nodeCount--;
    }
    //both links exist
    else
    {
    	//go one link left
        current = node->lLink;
        trailCurrent = nullptr;
        //keep going right until unable
        while (current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }
        //replace the node
        node->dataType= current->dataType;
        //if there was no right link, set the node's left link
        if (trailCurrent == nullptr)
        {
            node->lLink = current->lLink;
        }
        //switcharoo
        else
        {
        	trailCurrent->rLink = current->lLink;
        }
        delete current;
        nodeCount--;
    }
}

//traverse through the binarySearchTree
template <class DataType>
void binarySearchTree<DataType>::traverse(void (*itemFound)(const DataType& foundItem)) const
{
	inorder(root, itemFound);
}

//allows for inorder traverse
template <class DataType>
void binarySearchTree<DataType>::inorder(treeNode<DataType>* node, void (*visit) (const DataType& item)) const
{
	if (node != nullptr)
	{
		inorder(node->lLink, *visit);
		(*visit)(node->dataType);
		inorder(node->rLink, *visit);
	}
}

//inorder traversal for printing
template <class DataType>
void binarySearchTree<DataType>::inorder(treeNode<DataType>* p, std::ostream &outstream, void (*visit) (const treeNode<DataType>* node, std::ostream &out)) const
{
	if (p!= nullptr)
	{
		inorder(p->lLink, outstream, *visit);
		(*visit)(p, outstream);
		inorder(p->rLink, outstream, *visit);
	}
}

//deletes a node
template <class DataType>
bool binarySearchTree<DataType>::erase(const DataType &deleteItem)
{
	treeNode<DataType> *current;
	bool found = false;

	if (empty())
	{
		return false;
	}
	else
	{
		//start at root
		current = root;

		//loop until node has been found
		while(current != nullptr && !found)
		{
			//if the data is equal to the item we want to delete
			if (current->dataType == deleteItem)
			{
				found = true;
			}
			else
			{
				//if the node is greater than the item, go left
				if (current->dataType > deleteItem)
				{
					current = current->lLink;
				}
				//if the node is less than the item, go right
				else
				{
					current = current->rLink;
				}
			}
		}
		//we have reached the end of the tree, so the item was not found
		if ( current == nullptr)
		{
			return false;
		}
		else if (found)
		{
			//delete whatever current is pointing to.
			deleteFromTree(current);
			return true;
		}
		return false;
	}
}

//prints nodes. calls the traverse function to print out nodes.
template <class DataType>
void binarySearchTree<DataType>::print() const
{
	traverse(output);
}

//bonus parts--------------------------------------------------------------------
////print to ostream. No, this code does not work and results in compilation errors.
template <class DataType>
void binarySearchTree<DataType>::print(std::ostream &out) const
{
	if ( root != nullptr)
	{
		traverseOut(root, out);
	}
}

template <class DataType>
void binarySearchTree<DataType>::traverseOut(treeNode<DataType>* node,std::ostream& output) const
{
	if ( node != nullptr)
	{
		traverseOut(node->lLink,output);
		output << node << "\n";
		traverseOut(node->rLink,output);
	}
}

//traverse preorder. code that I got the idea from the text book and youtube. this code is similar to my inorder function.
template <class DataType>
void binarySearchTree<DataType>::traversePreOrder(void (*itemFound) (const DataType& foundItem)) const
{
	preorder(root, itemFound);
}
template <class DataType>
void binarySearchTree<DataType>::preorder(treeNode<DataType>* node, void(*visit) (const DataType& item)) const
{
	if (node != nullptr)
	{
		(*visit)(node->dataType);
		preorder(node->lLink, *visit);
		preorder(node->rLink, *visit);
	}
}

//traverse postorder. code that I got the idea from the text book and youtube. this code is similar to my inorder function.
template <class DataType>
void binarySearchTree<DataType>::traversePostOrder(void (*itemFound) (const DataType& foundItem)) const
{
	postorder(root, itemFound);
}
template <class DataType>
void binarySearchTree<DataType>::postorder(treeNode<DataType>* node, void(*visit) (const DataType& item)) const
{
	if (node != nullptr)
	{
		postorder(node->lLink, *visit);
		postorder(node->rLink, *visit);
		(*visit)(node->dataType);
	}
}

#endif /* BINARYSEARCHTREE_H_ */
