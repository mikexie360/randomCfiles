/*
 * phoneBook.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "phoneBook.h"

phoneBook::iterator phoneBook::begin()
{
	return vEntries.begin();
}

phoneBook::iterator phoneBook::end()
{
	return vEntries.end();
}


// Accessors
std::size_t phoneBook::size() const
{
	return vEntries.size();
}

// Insert Functions
void phoneBook::insert(const phoneBookEntry &entry)
{
	// Update if entry exists, create new one if it does not.
	if (find(entry.name()))
	{
		*ptr = entry;
	}
	else 
	{
		vEntries.insert(phoneBookEntry(entry));
	}
}

void phoneBook::insert(const std::string &name, const std::string &number)
{
	// Update if entry exists, create new one if it does not.
	if (find(name))
	{
		(*ptr).phoneNumber(number);
	}
	else
	{
		vEntries.insert(phoneBookEntry(name, number));
	}
}

void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
{
	// Update if entry exists, create new one if it does not.
	if (find(name))
	{
		(*ptr).phoneNumber(number);
		(*ptr).email(email);
	}
	else
	{
		vEntries.insert(phoneBookEntry(name, number, email));
	}
}

// Erase/Find
bool phoneBook::erase(std::string name)
{
	// Check if specified entry is found
	if (find(name)) {
		// If found, delete and return true.
		// Erase deletes the entry within vector at pointer.
		// This erase method also moves all elements back to fill the new size.
		vEntries.erase(ptr);
		return true;
	}
	// If specified entry not found, return false.
	return false;
}

bool phoneBook::find(std::string name)
{
	// Loop through entries looking for specified entry
	for (ptr = begin(); ptr != end(); ptr++) {
		// Check if current pointer matches specified entry
		if ((*ptr).name() == name) {
			// If found, return true.
			return true;
		}
	}
	// If specified entry not found, return false.
	return false;
}

// Print functions
void phoneBook::print() const
{
	print(std::cout);
}

void phoneBook::print(std::ostream &out) const
{
	// Print out book header
	out << "Name:                          Phone Number:   E-Mail:" << std::endl;

	// Loop through every value in the book entries
	for (phoneBookEntry value : vEntries) {
		// Print out name
		out << value.name();

		// Subtract length of name from amount of characters needed to hit 31
		std::size_t iCharsNeeded = 31 - value.name().length();
		// Loop through and output the remaining characters required to meet the format
		for (std::size_t index = 0; index < iCharsNeeded; index++) {
			out << " ";
		}

		// Print out Phone Number 
		out << value.phoneNumber();

		// Subtract length of name from amount of characters needed to hit 31
		iCharsNeeded = 16 - value.phoneNumber().length();
		// Loop through and output the remaining characters required to meet the format
		for (std::size_t index = 0; index < iCharsNeeded; index++) {
			out << " ";
		}

		// Print out email and endline
		out << value.email() << std::endl;
	}
}

void phoneBook::debug(std::ostream &out) const
{
	for (phoneBookEntry value : vEntries) {
		out << value.name() << " " << value.phoneNumber() << " " << value.email() << std::endl;
	}
}
