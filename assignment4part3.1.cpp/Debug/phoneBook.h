/*
 * phoneBook.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include <iostream>
#include "phoneBookEntry.h"
#include "orderedLinkedList.h"

class phoneBook {
public:
	// Constructors
	phoneBook() {};

	// Accessors
	std::size_t size() const;

	// Insert Functions
	void insert(const phoneBookEntry &entry);
	void insert(const std::string &name, const std::string &number);
	void insert(const std::string &name, const std::string &number, const std::string &email);

	// Erase/Find
	bool erase(std::string name);
	bool find(std::string name);	

	// Print
	void print() const;
	void print(std::ostream &out) const;

	// Debug
	void debug(std::ostream &out) const;

	// Iterators
	typedef orderedLinkedList<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;

	iterator begin();
	iterator end();
	
	// Class-scoped ptr so that find() can be used in multiple functions
	iterator ptr;

private:
	// Column Widths
	std::string sNameColumn;
	std::string sPhoneNumberColumn;

	// Define our linkedList class
	phoneBook::phoneBookEntryList vEntries;

};