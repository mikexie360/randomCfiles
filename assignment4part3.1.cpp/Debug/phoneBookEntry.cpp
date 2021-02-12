/*
 * phoneBookEntry.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "phoneBookEntry.h"

// Constructors
phoneBookEntry::phoneBookEntry()
{
	sName = "";
	sPhoneNumber = "";
	sEmail = "";
}

phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number)
{
	sName = name;
	sPhoneNumber = number;
	sEmail = "";
}

phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number, const std::string &email)
{
	sName = name;
	sPhoneNumber = number;
	sEmail = email;
}

phoneBookEntry::phoneBookEntry(const phoneBookEntry &from)
{
	sName = from.name();
	sPhoneNumber = from.phoneNumber();
	sEmail = from.email();
}

bool phoneBookEntry::operator==(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) == 0;
}

bool phoneBookEntry::operator!=(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) != 0;
}

bool phoneBookEntry::operator<(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) < 0;
}

bool phoneBookEntry::operator<=(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) <= 0;
}

bool phoneBookEntry::operator>(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) > 0;
}

bool phoneBookEntry::operator>=(const phoneBookEntry &entry) const
{
	return this->sName.compare(entry.name()) >= 0;
}

// Accessors
std::string phoneBookEntry::name() const
{
	return sName;
}

std::string phoneBookEntry::phoneNumber() const
{
	return sPhoneNumber;
}

std::string phoneBookEntry::email() const
{
	return sEmail;
}

// Mutators
void phoneBookEntry::phoneNumber(const std::string &newNumber)
{
	sPhoneNumber = newNumber;
}

void phoneBookEntry::email(const std::string &newEmail)
{
	sEmail = newEmail;
}

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry)
{
	// Bob Smith, 555-123-2222, bob@example.com
	if (entry.email() != "") {
		out << entry.name() << ", " << entry.phoneNumber() << ", " << entry.email();
	} else {
		out << entry.name() << ", " << entry.phoneNumber();
	}
	return out;
}
