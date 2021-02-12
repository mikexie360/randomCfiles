/**
 * CS 2336 - 002
 * phoneBook.h
 * Purpose: Our phone book with a bunch of functions to add, update, erase and print entries of the phone book.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#pragma once

#include <iostream>
#include "phoneBookEntry.h"
#include "orderedLinkedList.h"


/*
 * phoneBook class is basically the phone book.
 * This class contains the vector that holds the phone book entries
*/
class phoneBook
{
public:


	//default constructor
	phoneBook() {};


	//accessor methods
	/*
	 * erases a phone book entry
	 * the user must provide a name from the phone book entry or the phone book entry will be erased.
	 *
	* @param name the name of the phone book entry to be erased
	*/
	bool erase(std::string name);

	/*
	 * finds a phone book entry with the same name
	 *
	 * @param name finds if there is that name in the phone book
	 */
	bool find(std::string name);

	//returns the phone book size
	std::size_t size() const;


	//mutator methods
	/*
	 * adds a new phone book entry
	 *
	 * @param &entry new phone book entry to be added
	 */
	void insert(const phoneBookEntry &entry);

	/*
	 * adds a new phone book entry or updates the existing phone book entry
	 *
	 * @param &name new person to be added or updates the person's information if the name already exists.
	 *
	 * @param &number phone number to be associated with the name
	 *
	 * @param &email e-mail to be associated with the name
	 */
	void insert(const std::string &name, const std::string &number, const std::string &email);

	/*
	 * adds a new phone book entry or updates the existing phone book entry
	 *
	 * @param &name new person to be added or updates the person's information if the name already exists.
	 *
	 * @param &number phone number to be associated with the name
	 */
	void insert(const std::string &name, const std::string &number);


	//print functions
	//prints the phone book
	void print() const;

	/*
	 * prints the phone book
	 *
	 * @param &out outputs the phone book
	 */
	void print(std::ostream &out) const;


	//debug
	void debug(std::ostream &out) const;

	//typedef
	typedef orderedLinkedList<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;

	//iterators
	iterator begin();
	iterator end();
	iterator ptr;
private:
	//vector that holds the phone book entries
	phoneBook::phoneBookEntryList phoneEntry;
};

