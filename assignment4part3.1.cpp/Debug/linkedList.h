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
 * listNode<DataType>,
 *
 * listNodeIterator<DataType>
 *
 * and
 *
 * linkedList<DataType>
 *
 * The listNodeIterator is the iterator for the new linked list class. 
 * 
 */
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
		class linkedListIterator
		{
			typedef DataType 								value_type;
			typedef DataType& 								reference;
			typedef const DataType& 						const_reference;
			typedef DataType* 								pointer;
			typedef const DataType* 						const_pointer;
			typedef std::bidirectional_iterator_tag			iterator_category;
			typedef std::ptrdiff_t 							difference_type;
			typedef std::size_t								size_type;
			typedef linkedListIterator						iterator;
			typedef const linkedListIterator	  			const_iterator;

			friend class linkedList<DataType>;
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
				return this->current == other.current;
			}

			bool operator!=(const_iterator &other) const
			{
				return this->current != other.current;
			}
			
			private:
				listNode<DataType> *current;
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
		std::size_t nodeCount;
		listNode<DataType>* firstNode;
		listNode<DataType>* lastNode;

	public:
		// default constructor
		linkedList();
		// copy constructor
		linkedList(const linkedList &other);
		// assignment operator
		const linkedList& operator=(const linkedList &other)
		{
			linkedList list(other);
			return list;
		}
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
			return size() == 0;
		}
		// display the contents of the list to std::cout
		void print() const
		{
			print(std::cout);
		}
		// display the contents of the list to the ostream&
		void print(std::ostream &out) const;

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

		// dump the contents in debug format to passed in 
		// ostream - usage to cout would be:
		//   list.debug(std::cout);
		void debug(std::ostream &out) const;
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
		// remove the node by address existingNode
		virtual iterator erase(iterator iter);
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem);
		// return the iterator for the last node
		virtual iterator back()
		{
			return linkedListIterator(lastNode);
		}
		virtual const_iterator back() const
		{
			return linkedListIterator(lastNode);
		}
	protected:
	private:
		virtual void eraseAll();
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
template<class DataType>
void linkedList<DataType>::debug(std::ostream &out) const
{
	print(out);
}

// Add item to the front of the list
template<class DataType>
void linkedList<DataType>::push_front(const DataType &newItem)
{
	// Increment node count
	nodeCount++;

	// Create new node
	listNode<DataType> *newNode = new listNode<DataType>(newItem);

	// Set previous value to nullptr (since there's nothing there)
	newNode->previous(nullptr);
	
	// Check if any value exists in the list
	if (firstNode == nullptr) 
	{
		// Set following value to nullptr (since nothing's there)
		newNode->next(nullptr);

		// Set first and last values equal to the new Node (since it's the only value in list)
		firstNode = lastNode = newNode;
	} else {
		// If not empty, do set operations

		// Set next node to current firstNode
		newNode->next(firstNode);

		// Set previous node of current firstNode to new Node
		firstNode->previous(newNode);

		// Set current firstNode to the new firstNode
		firstNode = newNode;
	}
}

// Add an item to the back of the list
template<class DataType>
void linkedList<DataType>::push_back(const DataType &newItem)
{
	// Increment node count
	nodeCount++;

	// Create new node
	listNode<DataType> *newNode = new listNode<DataType>(newItem);

	// Set following value to nullptr (since, in the back, nothing's there)
	newNode->next(nullptr);

	// Check if any value exists in the list
	if (firstNode == nullptr)
	{
		// Set previous value to nullptr (since there's nothing there)
		newNode->previous(nullptr);

		// Set first and last values equal to the new Node (since it's the only value in list)
		firstNode = lastNode = newNode;
	} else {
		// If not empty, do set operations 

		// Set current lastNode's next node to the new lastNode
		lastNode->next(newNode);

		// Set the new node's previous node to lastNode
		newNode->previous(lastNode);

		// Set current lastNode to the new lastNode
		lastNode = newNode;
	}
}

// Removes the item located at the front of the list
template<class DataType>
void linkedList<DataType>::pop_front()
{
	// Check that list isn't empty before trying to delete
	if (firstNode != nullptr)
	{
		// Create a temp node (so we can delete current node from memory after adjustments)
		listNode<DataType> *tempNode = firstNode;

		// Check if there's a value following the front node (this is a check for only one value in the list)
		if (tempNode->next() == nullptr)
		{
			// Since there's no value following the firstNode, set the it and lastNode to nullptr 
			firstNode = lastNode = nullptr;
		} else {
			// If there is a value following the first one, move it down
			firstNode = firstNode->next();

			// Set its previous to nullptr
			firstNode->previous(nullptr);
		}

		// After operations are complete, delete the node we don't need anymore and decrement nodeCount.
		delete tempNode;
		nodeCount--;
	}
}

// Removes the item located at the back of the list
template<class DataType>
void linkedList<DataType>::pop_back()
{
	// Check that list isn't empty before trying to delete
	if (firstNode != nullptr)
	{
		// Create a temp node (so we can delete current node from memory after adjustments)
		listNode<DataType> *tempNode = lastNode;

		// Check if there's a value before the lastNode node (this is a check for only one value in the list)
		if (tempNode->previous() == nullptr)
		{
			// Since there's no value preceding the lastNode, set the it and firstNode to nullptr 
			lastNode = firstNode = nullptr;
		} else {
			// If there is a value preceding the last one, move it up
			lastNode = lastNode->previous();

			// Set its next to nullptr
			lastNode->next(nullptr);
		}

		// After operations are complete, delete the node we don't need anymore and decrement nodeCount.
		delete tempNode;
		nodeCount--;
	}
}

template<class DataType>
void linkedList<DataType>::insert_before(iterator iter, const DataType &newItem)
{
	// Increment node count
	nodeCount++;

	// Create new node
	listNode<DataType> *newNode = new listNode<DataType>(newItem);

	// Check if any value exists in the list
	if (firstNode == nullptr)
	{
		// Set first and last values equal to the new Node (since it's the only value in list)
		firstNode = lastNode = newNode;
	} else {
		// If not empty, do set operations 

		// Check if the iterator passed is end()
		if (iter == end())
		{
			// Delete newNode because we didn't need it like we thought we did
			delete newNode;
			// Run push_front instead
			push_front(newItem);
		} else {
			// Do a for loop searching for the location matching the iterator we need
			bool done = false;
			for (auto loopIter = back(); !done; loopIter--)
			{
				if (loopIter != end())
				{
					if (loopIter == iter)
					{
						// Set done to true to stop the loop
						done = true;

						// Set previous value of newNode to iterator's previous value
						newNode->previous((loopIter.current)->previous());

						// Set next value of newNode to iterator
						newNode->next(loopIter.current);

						// Set next value of iterator's previous node to newNode
						if (loopIter.current->previous() != nullptr) {
							(loopIter.current)->previous()->next(newNode);
						} else {
							firstNode = newNode;
						}
						
						// Set previous value of iterator to newNode
						(loopIter.current)->previous(newNode);
					}

					if (loopIter == begin()) {
						// Set done to true to stop the loop
						done = true;
					}
				}
			}
		}		
	}
}

template<class DataType>
void linkedList<DataType>::insert_after(iterator iter, const DataType &newItem)
{
	// Increment node count
	nodeCount++;

	// Create new node
	listNode<DataType> *newNode = new listNode<DataType>(newItem);

	// Check if any value exists in the list
	if (firstNode == nullptr)
	{
		// Set first and last values equal to the new Node (since it's the only value in list)
		firstNode = lastNode = newNode;
	} else {
		// If not empty, do set operations 

		// Check if the iterator passed is end()
		if (iter == end())
		{
			// Delete newNode because we didn't need it like we thought we did
			delete newNode;
			// Run push_front instead
			push_back(newItem);
		} else {
			// Do a for loop searching for the location matching the iterator we need
			bool done = false;

			for (auto loopIter = begin(); !done; loopIter++)
			{
				if (loopIter != end())
				{
					if (loopIter == iter)
					{
						// Set done to true to stop the loop
						done = true;

						// Set previous value of newNode to iterator's previous value
						newNode->previous(loopIter.current);

						// Set next value of newNode to iterator
						newNode->next(loopIter.current->next());

						// Set next value of iterator's previous node to newNode
						if (loopIter.current->next() != nullptr) {
							loopIter.current->next()->previous(newNode);
						} else {
							lastNode = newNode;
						}

						// Set previous value of iterator to newNode
						loopIter.current->next(newNode);
					}
					
					if (loopIter == back()) {
						// Set done to true to stop the loop
						done = true;
					}
				}
			}
		}
	}
}

// Find the node and return the address to the node. Return nullptr if not found
template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::find(const DataType &existingItem)
{
	// Do a for loop searching for the location matching the item we need
	bool done = false;
	for (auto iter = back(); !done; iter--)
	{
		if (iter != end())
		{
			if (iter == begin())
			{
				done = true;
			}
			if (*iter == existingItem) {
				return iter;
			}
		} else {
			return end();
		}
	}
	return nullptr;
}

// Remove the node by iterator
template<class DataType>
typename linkedList<DataType>::iterator  linkedList<DataType>::erase(linkedList<DataType>::iterator iter)
{
	// Check if value exists
	if (iter == nullptr)
	{
		// Return nullptr if value does not exist
		return nullptr;
	} else {
		// Create a temp node (so we can delete current node from memory after adjustments)
		listNode<DataType> *tempNode = iter.current;

		// Check if there's a value before and after the tempNode node (this is a check for only one value in the list)
		if (tempNode->previous() == nullptr && tempNode->next() == nullptr)
		{
			// Since there's no value preceding and following the tempNode, set the lastNode and firstNode to nullptr 
			lastNode = firstNode = nullptr;

			// After operations are complete, delete the node we don't need anymore and decrement nodeCount.
			delete tempNode;
			nodeCount--;
		} else {
			// If there is a value preceding or following the last one, check if either is null
			if (tempNode->previous() == nullptr) 
			{
				// If previous is null, pop the front.
				pop_front();
			} else if (tempNode->next() == nullptr) {
				// If next is null, pop the back
				pop_back();
			} else {
				// If neither is nullptr, adjust surrounding values to deletion
				tempNode->next()->previous(tempNode->previous());
				tempNode->previous()->next(tempNode->next());

				// After operations are complete, delete the node we don't need anymore and decrement nodeCount.
				delete tempNode;
				nodeCount--;
			}
		}
		
		return iter;
	}
}

// Remove the node equal to currentItem
template<class DataType>
bool linkedList<DataType>::erase(const DataType &currentItem)
{
	// Run iterator erase and pass the iterator returned from find
	iterator result = erase(find(currentItem));
	
	// Check if result was erased and return accordingly
	if (result == nullptr) 
	{
		return false;
	} else {
		return true;
	}
}

template<class DataType>
void linkedList<DataType>::eraseAll()
{
	// Do a while loop erasing every item
	iterator iter = back();
	while(!empty())
	{
		erase(iter);
		iter--;
	}
}

// Default constructor
template<class DataType> 
linkedList<DataType>::linkedList()
{
	nodeCount = 0;
	firstNode = nullptr;
	lastNode = nullptr;
}

// Copy constructor
template<class DataType>
linkedList<DataType>::linkedList(const linkedList &other)
{
	// Check if current list is empty to see if we need to erase it befor copying
	if (!empty()) {
		// Run eraseAll helper function
		eraseAll();
	}

	// Do copy operations
	bool done = false;
	for (auto iter = other.back(); !done; iter--)
	{
		if (iter != other.end())
		{
			// Push every iter to the front of new list
			push_front(*iter);
			if (iter == other.begin())
			{
				done = true;
			}
		}
	}
}

// Destructor
template<class DataType>
linkedList<DataType>::~linkedList()
{
	// Check if list is empty
	if (!empty()) {
		// Run eraseAll helper function
		eraseAll();
	}
	
}

// Print
template<class DataType>
void linkedList<DataType>::print(std::ostream &out) const
{
	// Check if list is empty
	if (empty()) {
		out << "List is empty." << std::endl;
	} else {
		// Loop through list until having printed all values
		bool done = false;
		for (auto iter = begin(); !done; iter++)
		{
			if (iter != end())
			{
				out << *iter << std::endl;
				if (iter == back())
				{
					done = true;
				}
			}
		}
	}
}
