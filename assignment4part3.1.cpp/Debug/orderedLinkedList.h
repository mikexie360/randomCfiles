/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#pragma once

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
	public:
		typedef linkedList<DataType>              unorderedLinkedList;
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t 					      difference_type;
		typedef std::size_t						      size_type;
		typedef typename unorderedLinkedList::iterator  iterator;
		typedef const iterator	  	               const_iterator;
	private:
		// we are making use of the DoubleLinkedList class
		unorderedLinkedList list;
	public:
		// default constructor
		orderedLinkedList()
		{
		}
		// copy constructor
		orderedLinkedList(const orderedLinkedList &other);
		// assignment operator
		const orderedLinkedList& operator=(const orderedLinkedList &other)
		{
			orderedLinkedList list(other);
			return list;
		}
		// destructor
		virtual ~orderedLinkedList();
		// iterators
		iterator begin()
		{
			return list.begin();
		}
		
		iterator end()
		{
			return list.end();
		}

		const_iterator begin() const
		{
			return list.begin();
		}

		const_iterator end() const
		{
			return list.end();
		}
		
		// number of items in the list
		virtual std::size_t size() const
		{
			return list.size();
		}
		// is the list empty (true) or does it have entries (false)
		virtual bool empty() const
		{
			return list.empty();
		}
		// print the items in the list
		virtual void print() const
		{
			print(std::cout);
		}
		// display the contents of the list to the ostream&
		virtual void print(std::ostream &out) const
		{
			list.print(out);
		}
		// display debug information on the passed in ostream
		virtual void debug(std::ostream &out) const
		{
			list.debug(out);
		}
		// find the element and return an interator for it
		virtual iterator find(const DataType &existingItem)
		{
			return list.find(existingItem);
		}
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem)
		{
			return list.erase(currentItem);
		}
		// remove the node by address existingNode
		virtual iterator erase(iterator iter)
		{
			return list.erase(iter);
		}
		// insert the new item into the list (in sorted order)
		// a duplicate entry will be ignored
		virtual void insert(const DataType &newItem);
		// get the last entry
		iterator back() 
		{
		   return list.back();
		}
		
		const_iterator back() const
		{
		   return list.back();
		}
};

template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList(const orderedLinkedList &other)
{
	// Do a while loop erasing every item if list isn't empty
	iterator iter = back();
	while (!empty())
	{
		erase(iter);
		iter--;
	}

	// Do copy operations
	bool done = false;
	for (auto iter = other.back(); !done; iter--)
	{
		if (iter != other.end())
		{
			// Push every iter to the front of new list
			list.push_front(*iter);
			if (iter == other.begin())
			{
				done = true;
			}
		}
	}
}

template<class DataType>
orderedLinkedList<DataType>::~orderedLinkedList()
{
	// Do a while loop erasing every item
	iterator iter = back();
	while (!empty())
	{
		erase(iter);
		iter--;
	}
}

template<class DataType>
void orderedLinkedList<DataType>::insert(const DataType & newItem)
{
	// Check if list is empty else check to see if item exists in list
	if (empty())
	{
		// Add item to the front if list is currently empty
		list.push_front(newItem);
	} else if (find(newItem) == nullptr) {
		// Loop through list until done with all items
		bool done = false;
		for (auto iter = begin(); !done; iter++)
		{
			if (iter != end())
			{
				// Check if newItem is smaller than the first item
				if (iter == begin() && (*iter > newItem))
				{
					// Set loop to done, since we're going to insert item.
					done = true;

					// Push new item to the front if smaller
					list.push_front(newItem);
				}
				// Check if item is smaller than current place
				else if(*iter > newItem)
				{
					done = true;

					// Insert item before the iterator
					list.insert_before(iter, newItem);
				}
				// Check if we've reached the back of the list
				else if (iter == back())
				{
					done = true;

					// Push item to the end if we haven't added it by this point
					list.push_back(newItem);
				}
			}
		}
	}
}
