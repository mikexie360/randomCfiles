/**
 * CS 2336 - 002
 * phoneBook.cpp
 * Purpose: Our phone book with a bunch of functions to add, update, erase and print entries of the phone book.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch

#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "orderedLinkedList.h"

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <iterator>

/*
 * erases a phone book entry
 * the user must provide a name from the phone book entry or the phone book entry will be erased.
 *
 * @param name the name of the phone book entry to be erased
 */
bool phoneBook::erase(std::string name)
{
	if (find(name))
	{
		phoneEntry.erase(ptr);
		return true;
	}
	return false;
}

/*
 * finds a phone book entry with the same name
 *
 * @param name finds if there is that name in the phone book
 */
bool phoneBook::find(std::string name)
{
	for (ptr = begin(); ptr != end(); ptr++)
	{
		if(ptr->name() == name)
		{
			return true;
		}
	}
	return false;
}

//returns the phone book size
std::size_t phoneBook::size() const
{
	return phoneEntry.size();
}

/*
 * adds a new phone book entry
 *
 * @param &entry new phone book entry to be added
 */
void phoneBook::insert(const phoneBookEntry &entry)
{
	if(find(entry.name()))
	{
		*ptr = entry;
	}
	else
	{
		phoneEntry.insert(phoneBookEntry(entry));
	}
}

/*
 * adds a new phone book entry or updates the existing phone book entry
 *
 * @param &name new person to be added or updates the person's information if the name already exists.
 *
 * @param &number phone number to be associated with the name
 *
 * @param &email e-mail to be associated with the name
 */
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
{
	if (find(name))
	{
		ptr->phoneNumber(number);
		ptr->email(email);
	}
	else
	{
		phoneEntry.insert(phoneBookEntry(name, number, email));
	}
}

/*
 * adds a new phone book entry or updates the existing phone book entry
 *
 * @param &name new person to be added or updates the person's information if the name already exists.
 *
 * @param &number phone number to be associated with the name
 */
void phoneBook::insert(const std::string &name, const std::string &number)
{
	if(find(name))
	{
		ptr->phoneNumber(number);
	}
	else
	{
		phoneEntry.insert(phoneBookEntry(name,number));
	}
}

//prints the phone book
void phoneBook::print() const
{
	print(std::cout);
}

/*
 * prints the phone book
 *
 * @param &out outputs the phone book
 */
void phoneBook::print(std::ostream &out) const
{
	//use this variable to do arithmetic against other integers
	int phoneBookListSize = static_cast<int>(phoneEntry.size());

	//checks to see if the phoneBookList is empty
	if(phoneBookListSize!=0)
	{
		//prints it out using a for loop
		out << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
		for(phoneBookEntry entry : phoneEntry)
		{
			out << std::left << std::setw(31) << entry.name() << std::setw(16) << entry.phoneNumber() << entry.email() << std::endl;
		}
	}
	else
	{
		//what it prints out if the phoneBookList is empty
		out << "The phone book is empty" << std::endl;
	}
}

//helps the programmer debug the program
void phoneBook::debug(std::ostream &out) const
{
	out << std::left << std::setw(31) << "Name:" << std::setw(16) << "Phone Number:" << "E-Mail:" << std::endl;
	for(phoneBookEntry entry : phoneEntry)
	{
		out << std::left << std::setw(31) << entry.name() << std::setw(16) << entry.phoneNumber() << entry.email() << std::endl;
	}
}

//begin iterator
phoneBook::iterator phoneBook::begin()
{
	return phoneEntry.begin();
}

//end iterator
phoneBook::iterator phoneBook::end()
{
	return phoneEntry.end();
}

