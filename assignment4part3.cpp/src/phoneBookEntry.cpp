/**
 * CS 2336 - 002
 * phoneBookEntry.cpp
 * Purpose: The phone book entry.
 * Holds name, phone number and e-mail.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#include "phoneBookEntry.h"

#include <iostream>
#include <string>
#include <cstring>

//default constructor
phoneBookEntry::phoneBookEntry()
{
	personName = "";
	phoneNumber_ = "";
	personEmail = "";
}

/*
 * constructor for name and phone number
 *
 * @param &name name of the person to add
 *
 * @param &number phone number of the person
 */
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number)
{
	personName = name;
	phoneNumber_ = number;
	personEmail = "";
}

/*
 * constructor for name and phone number and e-mail
 *
 * @param &name name of the person to add
 *
 * @param &number phone number of the person
 *
 * @param &email e-mail of the person
 */
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email)
{
	//name of the person
	personName = name;

	//phone number of the person
	phoneNumber_ = number;

	//e-mail of the person
	personEmail = email;
}

//copy constructor
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from)
{
	personName = from.personName;
	phoneNumber_ = from.phoneNumber_;
	personEmail = from.personEmail;
}

//accessor for name
std::string phoneBookEntry::name() const
{
	return personName;
}

//accessor for phone number
std::string phoneBookEntry::phoneNumber() const
{
	return phoneNumber_;
}

//accessor for e-mail
std::string phoneBookEntry::email() const
{
	return personEmail;
}

//sets a new phone number
void phoneBookEntry::phoneNumber(const std::string &newNumber)
{
	phoneNumber_ = newNumber;
}

//sets a new e-mail
void phoneBookEntry::email(const std::string &newEmail)
{
	personEmail = newEmail;
}

bool phoneBookEntry::operator==(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) == 0 ;
}

bool phoneBookEntry::operator!=(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) !=0;
}

bool phoneBookEntry::operator<(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) < 0;
}

bool phoneBookEntry::operator<=(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) <= 0;
}

bool phoneBookEntry::operator>(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) > 0;
}

bool phoneBookEntry::operator>=(const phoneBookEntry &entry) const
{
	return this->personName.compare(entry.name()) >= 0;
}

std::ostream& operator <<(std::ostream &out, const phoneBookEntry &entry)
{
	if (entry.email() != "")
	{
		out << entry.name() << ", " << entry.phoneNumber() << ", " << entry.email();
	}
	else
	{
		out << entry.name() << ", " << entry.phoneNumber();
	}
	return out;
}
















