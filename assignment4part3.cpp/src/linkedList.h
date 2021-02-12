/*
 * linkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually three classes here:
 *
 * listNode<DataType>
 *
 * listNodeIterator<DataType>

 * and
 *
 * linkedList<DataType>
 *
 * The listNodeIterator is the iterator for the new linked list class.
 *
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#pragma once

#include "memoryLeak.h"

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <iterator>

// forward declaration of the template class linkedList
template<class DataType>
class linkedList;
// forward declaration of iterator
template<class DataType>
class linkedListIterator;

// listNode class
template<class DataType>
class listNode
{
	// make DoubleLinkedList<DataType> a friend class
	friend class linkedList<DataType>;
	friend class linkedListIterator<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the next item in the list or nullptr
		// if at the end
		listNode<DataType>* pNext;
		// pointer to the previous item in the list or nullptr
		// if at the start
		listNode<DataType>* pPrevious;
	public:
		// default constructor
		listNode();

		// constructor with data
		listNode(const DataType &newItem);
	protected:
		// get the next node
		listNode* next() const
		{
			return pNext;
		}

		// get the previous node
		listNode* previous() const
		{
			return pPrevious;
		}

		// return the data stored in the node as a const
		const DataType& data() const
		{
			return dataType;
		}
		// return the data stored in the node
		DataType& data()
		{
			return dataType;
		}
		// update the next node
		void next(listNode *nextNode)
		{
			pNext = nextNode;
		}
		// update the previous node
		void previous(listNode *previousNode)
		{
			pPrevious = previousNode;
		}
};

// linkedList class
template<class DataType>
class linkedList
{
	public:
	   // the linkedListIterator is defined as a nested class inside linkedList.
	   //
	   // most of this code has been provided for you.
	   // the exceptions are the operator--() operator--(int) member fuctions and
	   // and the operator== and operator!= member functions.
		class linkedListIterator
		{
			typedef DataType 								   value_type;
			typedef DataType& 								reference;
			typedef const DataType& 						const_reference;
			typedef DataType* 								pointer;
			typedef const DataType* 						const_pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t 							difference_type;
			typedef std::size_t								size_type;
			typedef linkedListIterator						iterator;
			typedef const linkedListIterator	  			const_iterator;

			friend class linkedList<DataType>;
			private:
				listNode<DataType> *current;
			public:
				linkedListIterator() {}
				linkedListIterator(listNode<DataType> *current)
					: current(current)
				{
				}

				virtual ~linkedListIterator()
				{
				}

				reference operator*()
				{
					return current->data();
				}

				const_reference operator*() const
				{
					return current->data();
				}

				pointer operator->()
				{
					return &(current->data());
				}

				const_pointer operator->() const
				{
					return &(current->data());
				}

				iterator operator++()
				{
					if (current != nullptr)
					{
						current = current->next();
					}
					return *this;
				}

				iterator operator++(int)
				{
					iterator it = *this;
					if (current != nullptr)
					{
						current = current->next();
					}
					return it;
				}

            // you need to implement the following - they can be inlined if you want
				iterator operator--()
				{
					if (current != nullptr)
					{
						current = current->previous();
					}
					return *this;
				}
				iterator operator--(int)
				{
					iterator it = *this;
					if (current != nullptr)
					{
						current = current->previous();
					}
					return it;
				}
				bool operator==(const_iterator &other) const
				{
//					if (other == nullptr)
//					{
//						return false;
//					}
					return (this->current == other.current);
				}
				bool operator!=(const_iterator &other) const
				{
//					if(other == nullptr)
//					{
//						return false;
//					}
					return (this->current != other.current);
				}
		};
		typedef DataType 								value_type;
		typedef DataType& 								reference;
		typedef const DataType& 						const_reference;
		typedef DataType* 								pointer;
		typedef const DataType* 						const_pointer;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef std::ptrdiff_t 							difference_type;
		typedef std::size_t								size_type;
		typedef linkedListIterator 						iterator;
		typedef const linkedListIterator	  			const_iterator;

	private:
		// your instance data goes here. Think like the pointers to the first and last nodes
		listNode<DataType>* firstNode;
		listNode<DataType>* lastNode;
		//  as well as the count of nodes
		int nodeCount;
	public:
		// default constructor
		linkedList();
		// copy constructor (Deep Copy)
		linkedList(const linkedList &other);
		// assignment operator
		const linkedList& operator=(const linkedList &other);
		// destructor
		virtual ~linkedList();
		// return the number of nodes in the list
		std::size_t size() const
		{
			return nodeCount;
		}
		// return true if the list is empty
		bool empty() const
		{
			return (firstNode == nullptr);
		}
		// display the contents of the list to std::cout
		void print() const
		{
			print(std::cout);
		}
		// display the contents of the list to the ostream&
		void print(std::ostream &out) const
		{
			//pointer to traverse the list
			listNode<DataType> *current;

			//set current to point to the first node
			current = firstNode;

			while (current != nullptr)
			{
				//output info
				out << current << std::endl;
				current = current->next();
			}
		}

		// iterators
		iterator begin()
		{
			return iterator(firstNode);
		}

		const_iterator begin() const
		{
			return iterator(firstNode);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator end() const
		{
			return iterator(nullptr);
		}

		// dump the contends in debug format to passed in
//		 ostream - usage to cout would be:
		void debug(std::ostream &out) const
		{
			print(out);
		}
	public:
		// add an item to the front of the list
		virtual void push_front(const DataType &newItem);
		// add an item to the back of the list
		virtual void push_back(const DataType &newItem);
		// remove an item from the front of the list
		virtual void pop_front();
		// remove an item from the back of the list
		virtual void pop_back();
		// insert newItem before the node specified by the iterator
		virtual void insert_before (iterator iter, const DataType &newItem);
		// insert newItem after the node specified by the iterator
		virtual void insert_after (iterator iter, const DataType &newItem);
		// find the node and return the iterator for that element.
		// Return end() if not found
		virtual iterator find(const DataType &existingItem);
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem);
		// remove the node by address existingNode
		virtual iterator erase(iterator iter);
		// return the iterator for the last node
		virtual iterator back()
		{
			return linkedListIterator(lastNode);
		}
		virtual const_iterator back() const
		{
			return linkedListIterator(lastNode);
		}

		void test()
		{
			std::cout << (begin() != end()) << std::endl;
		}

	protected:

	private:

	   // any helper functions you need should eithee be protected or private

//		//searches the list and return true if searchItem is found
//		virtual bool search(const DataType& searchItem) const;
};

// the constructors for the listNode class are included here
// default constructor
template <class DataType>
listNode<DataType>::listNode()
	: dataType(), pNext(nullptr), pPrevious(nullptr)
{
}

// constructor with data
template <class DataType>
listNode<DataType>::listNode(const DataType &newItem)
	: dataType(newItem), pNext(nullptr), pPrevious(nullptr)
{
}

// note the code for the debug() function is included
// display a debug version of the list
//template<class DataType>
//void linkedList<DataType>::debug(std::ostream &out) const
//{
//
//	const unsigned int ADDRWIDTH = 10;
//	out << "START DEBUG" << std::endl;
//	out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
//	out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
//	out << ", # nodes=" << size() << std::endl;
//	unsigned int count = 1;
//
//	for (auto current=firstNode; current!= nullptr; current=current->next())
//	{
//		out << "node " << std::setw(2) << count;
//		out << "=" << std::setw(ADDRWIDTH) << current;
//		out << ", next=" << std::setw(ADDRWIDTH)
//			<< current->next();
//		out << ", previous=" << std::setw(ADDRWIDTH)
//			<< current->previous();
//		out << ", value=" << current->data() << std::endl;
//		count++;
//	}
//	out << "END DEBUG" << std::endl;
//}

// I have included a few function headers and bodies here where the syntax is odd
// Your implementation of non-inlined member funcctions needs to go there.
// default constructor
template <class DataType>
linkedList<DataType>::linkedList()
	: firstNode(nullptr), lastNode(nullptr), nodeCount(0)
{
}

//copy constructor
template <class DataType>
linkedList<DataType>::linkedList(const linkedList &other)
{
	nodeCount = other.nodeCount;
	//if "&other" is empty then the new list is also empty
	if (other.firstNode == nullptr)
	{
		firstNode = lastNode = nullptr;
	}
	//allocate head and copy the data
	else
	{
		//allocates the next element and copy data
		firstNode = new listNode<DataType>(other.firstNode);
		listNode<DataType> *tempOther = other.firstNode->next;
		listNode<DataType> *temp = firstNode;
		while (tempOther != nullptr)
		{
			temp->next = new listNode<DataType>(tempOther, nullptr, temp);
			temp = temp->next;
			//step to the next one
			tempOther = tempOther->next;
		}
		lastNode = temp;
	}
}
//assignment operator
template <class DataType>
const linkedList<DataType>& linkedList<DataType>::operator=(const linkedList &other)
{
	if ( this != &other)
	{
		~linkedList();
	}
	return linkedList(other);
}
//destructor
template <class DataType>
linkedList<DataType>::~linkedList()
{
	while (!empty())
	{
		pop_front();
	}
	firstNode = nullptr;
	lastNode = nullptr;
	nodeCount = 0;
}
// this is one where the C++ stynax gets very odd. Since we are returning back an interator we
// need to qualify it with the class it is in (linkedList<DataType>::iterator and we
// have ot include the typename so the C++ comiler knows this is a typename and not some other
// template class usage.
// find the node and return the address to the node. Return
// nullptr if not found
template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::find(const DataType &existingItem)
{
	bool found = false;
	for (auto loopingIter = back(); !found; loopingIter--)
	{
		if (loopingIter != end())
		{
			if (loopingIter == begin())
			{
				found = true;
			}
			if (*loopingIter == existingItem)
			{
				return loopingIter;
			}
		}
		else
		{
			return end();
		}
	}
	return nullptr;
}

// remove the node equal to currentItem
template<class DataType>
bool linkedList<DataType>::erase(const DataType &currentItem)
{
	iterator eraseIter = nullptr;
	bool found = false;
	//loop to find iterator
	for (auto iter = back(); !found; iter--)
	{
		if (iter != end())
		{
			//found nothing to do erase
			if (iter == begin())
			{
				found = true;
			}
			if (*iter == currentItem)
			{
				eraseIter = iter;
			}
		}
		else
		{
			eraseIter = nullptr;
		}
	}

	if (erase(eraseIter) == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// remove the node by iterator
template<class DataType>
typename linkedList<DataType>::iterator  linkedList<DataType>::erase(linkedList<DataType>::iterator iter)
{
	//does the iterator exist?
	if (iter == nullptr)
	{
		return nullptr;
	}
	else
	{
		listNode<DataType> *tempNode = iter.current;
		if(tempNode->previous() == nullptr && tempNode->next() == nullptr)
		{
			lastNode = firstNode = nullptr;

			delete tempNode;
			nodeCount--;
		}
		else
		{
			if (tempNode->previous() == nullptr)
			{
				pop_front();
			}
			else if (tempNode->next() == nullptr)
			{
				pop_back();
			}
			else
			{
				tempNode->next()->previous(tempNode->previous());
				tempNode->previous()->next(tempNode->next());

				delete tempNode;
				nodeCount--;
			}
		}
		return iter;
	}
}

// add an item to the front of the list
template<class DataType>
void linkedList<DataType>::push_front(const DataType &newItem)
{
	nodeCount++;

	listNode<DataType> *pushFrontNode = new listNode<DataType>(newItem);

	//if List is empty
	if (firstNode == nullptr)
	{
//		firstNode->next(pushFrontNode);
//		lastNode->previous(pushFrontNode);
		firstNode = pushFrontNode;
		lastNode = pushFrontNode;
	}
	else
	{
		pushFrontNode->next(firstNode);
		firstNode->previous(pushFrontNode);
		firstNode = pushFrontNode;
	}
}

// add an item to the back of the list
template<class DataType>
void linkedList<DataType>::push_back(const DataType &newItem)
{
	nodeCount++;

	listNode<DataType> *pushBackNode = new listNode<DataType>(newItem);

	//if list is empty
	if (firstNode == nullptr)
	{
		firstNode = pushBackNode;
		lastNode = pushBackNode;
	}
	else
	{
		pushBackNode->next(nullptr);
		pushBackNode->previous(lastNode);
		lastNode->next(pushBackNode);
		lastNode = pushBackNode;
	}
}

// remove an item from the front of the list
template<class DataType>
void linkedList<DataType>::pop_front()
{
	if(!empty())
	{
		listNode<DataType> *popFrontNode = (firstNode);
		if(popFrontNode->next() == nullptr)
		{
//			firstNode->next(nullptr);
//			firstNode->previous(nullptr);
			firstNode = nullptr;
			lastNode = nullptr;
		}
		else
		{
			firstNode = firstNode->next();
			firstNode->previous(nullptr);
		}
		delete popFrontNode;
		nodeCount--;
	}
}

// remove an item from the back of the list
template<class DataType>
void linkedList<DataType>::pop_back()
{
	if(firstNode != nullptr)
	{
		listNode<DataType> *popBackNode = lastNode;
		if(popBackNode->previous() == nullptr)
		{
			firstNode = nullptr;
			lastNode = nullptr;
		}
		else
		{
			lastNode = lastNode->previous();
			lastNode->next(nullptr);
		}
		delete popBackNode;
		nodeCount--;
	}
}

// insert newItem before the node specified by the iterator
template<class DataType>
void linkedList<DataType>::insert_before (iterator iter, const DataType &newItem)
{
	listNode<DataType> *nodePtr= new listNode<DataType>(newItem);
	//check if list is empty
	if( firstNode == nullptr)
	{
		firstNode = lastNode = nodePtr;
		nodeCount++;
	}
	//if not empty
	else
	{
		//check if iterator is == to end()
		if (iter == end())
		{
			//nodePtr won't actually be used
			delete nodePtr;
			push_front(newItem);
		}
		else
		{
			nodeCount++;
			nodePtr->previous((iter.current)->previous());
			nodePtr->next(iter.current);
			if(iter.current->previous() != nullptr)
			{
				(iter.current)->previous()->next(nodePtr);
			}
			else
			{
				firstNode = nodePtr;
			}

			(iter.current)->previous(nodePtr);
		}
	}

//	if(iter == firstNode)
//	{
//		nodePtr->previous(nullptr);
//		nodePtr->next(firstNode);
//		firstNode->previous(nodePtr);
//		firstNode = nodePtr;
//	}
//	if(iter != firstNode && iter != lastNode)
//	{
//		iter.current->previous(nodePtr);
//		nodePtr->previous(iter.current->previous());
//		nodePtr->next(iter.current);
//		iter.current->previous()->next(nodePtr);
//	}
//	if(iter == lastNode)
//	{
//		nodePtr->next(lastNode);
//		nodePtr->previous(lastNode->previous());
//		lastNode->previous(nodePtr);
//		lastNode->previous()->next(nodePtr);
//	}
}

// insert newItem after the node specified by the iterator
template<class DataType>
void linkedList<DataType>::insert_after (iterator iter, const DataType &newItem)
{
	listNode<DataType> *nodePtr = new listNode<DataType>(newItem);
	if(firstNode == nullptr)
	{
		nodeCount++;
		firstNode = lastNode = nullptr;
	}
	else
	{
		if (iter == end())
		{
			delete nodePtr;
			push_back(newItem);
		}
		else
		{
			nodeCount++;
			nodePtr->previous(iter.current);
			nodePtr->next(iter.current->next());

			if(iter.current->next() != nullptr)
			{
				iter.current->next()->previous(nodePtr);
			}
			else
			{
				lastNode = nodePtr;
			}
			iter.current->next(nodePtr);
		}
	}
//	if(iter == lastNode)
//	{
//		nodePtr->next(nullptr);
//		nodePtr->previous(lastNode);
//		lastNode->next(nodePtr);
//		lastNode = nodePtr;
//	}
//	if(iter != firstNode && iter != lastNode)
//	{
//		iter.current->next(nodePtr);
//		iter.current->next()->previous(nodePtr);
//		nodePtr->next(iter.current->next());
//		nodePtr->previous(iter.current);
//	}
//	if(iter == firstNode)
//	{
//		nodePtr->previous(firstNode);
//		nodePtr->next(firstNode->next());
//		firstNode->next(nodePtr);
//		firstNode->next()->previous(nodePtr);
//	}



	//	//pointer to create a node
	//	listNode<DataType> *newNode;
	//	//create the node
	//	newNode = new listNode<DataType>(newItem);
	//	//store the new item in the node
	//	newNode->next(nullptr);
	//	newNode->previous(nullptr);
		//	else
		//	{
		//		nodeCount++;
		//		newNode->next(iter.current);
		//		iter.current->previous(newNode);
		//		iter = iter--;
		//		newNode->previous(iter.current);
		//		iter.current->next(newNode);
		//	}



	//	//pointer to create a node
	//	listNode<DataType> *newNode;
	//	//create the node
	//	newNode = new listNode<DataType>(newItem);
	//	//store the new item in the node
	//	newNode->next(nullptr);
	//	newNode->previous(nullptr);
//	if(iter == lastNode)
//	{
//		nodePtr->next(nullptr);
//		nodePtr->previous(lastNode);
//		lastNode->next(nodePtr);
//		lastNode = nodePtr;
//	}
//	else
//	{
//		nodeCount++;
//		newNode->previous(iter.current);
//		iter.current->next(newNode);
//		iter = iter++;
//		newNode->next(iter.current);
//		iter.current->previous(newNode);
//	}
}

////searches the list and return true if searchItem is found
//template<class DataType>
//bool linkedList<DataType>::search(const DataType& searchItem) const
//{
//	bool found = false;
//
//	//pointer to traverse the list
//	listNode<DataType> *current;
//
//	current = firstNode;
//
//	while (current != nullptr && !found)
//	{
//		if ( current->data() == searchItem)
//		{
//			found = true;
//		}
//		else
//		{
//			current = current->next();
//		}
//	}
//	return found;
//}
// all of your member function need to be before the #endif
#endif /* DOUBLELINKEDLIST_H_ */
