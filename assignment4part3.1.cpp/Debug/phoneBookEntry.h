/*
 * phoneBookEntry.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include <string>
#include <iostream>

class phoneBookEntry {
public:
	// Constructors
	phoneBookEntry();
	phoneBookEntry(const std::string &name, const std::string &number);
	phoneBookEntry(const std::string &name, const std::string &number, const std::string &email);
	phoneBookEntry(const phoneBookEntry &from);

	// Comparison Operators
	bool operator==(const phoneBookEntry &entry) const;
	bool operator!=(const phoneBookEntry &entry) const;
	bool operator<(const phoneBookEntry &entry) const;
	bool operator<=(const phoneBookEntry &entry) const;
	bool operator>(const phoneBookEntry &entry) const;
	bool operator>=(const phoneBookEntry &entry) const;

	// Accessors
	std::string name() const;
	std::string phoneNumber() const;
	std::string email() const;

	// Mutators
	void phoneNumber(const std::string &newNumber);
	void email(const std::string &newEmail);

private:
	// Variables
	std::string sName;
	std::string sPhoneNumber;
	std::string sEmail;
};

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry);