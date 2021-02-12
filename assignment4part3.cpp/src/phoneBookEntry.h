/**
 * CS 2336 - 002
 * phoneBookEntry.h
 * Purpose: The phone book entry.
 * Holds name, phone number and e-mail.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <iostream>
#include <string>


class phoneBookEntry
{
private:
	//name of person
	std::string personName;

	//phone number of person
	std::string phoneNumber_;

	//e-mail of person
	std::string personEmail;
public:
	//default constructor
	phoneBookEntry();

	/*
	 * constructor for name and phone number
	 *
	 * @param &name name of the person to add
	 *
	 * @param &number phone number of the person
	 */
	phoneBookEntry(const std::string &name, const std::string &number);

	/*
	 * constructor for name and phone number and e-mail
	 *
	 * @param &name name of the person to add
	 *
	 * @param &number phone number of the person
	 *
	 * @param &email e-mail of the person
	 */
	phoneBookEntry(const std::string &name, const std::string &number,  const std::string &email);

	//copy constructor
	phoneBookEntry(const phoneBookEntry &from);


	//accessor for name
	std::string name() const;

	//accessor for phone number
	std::string phoneNumber() const;

	//accessor for e-mail
	std::string email() const;


	//sets a new phone number
	void phoneNumber(const std::string &newNumber);

	//sets a new e-mail
	void email(const std::string &newEmail);

	//comparison operators
	bool operator==(const phoneBookEntry &entry) const;
	bool operator!=(const phoneBookEntry &entry) const;
	bool operator<(const phoneBookEntry &entry) const;
	bool operator<=(const phoneBookEntry &entry) const;
	bool operator>(const phoneBookEntry &entry) const;
	bool operator>=(const phoneBookEntry &entry) const;
};

std::ostream& operator<<(std::ostream &out, const phoneBookEntry &entry);



#endif /* PHONEBOOKENTRY_H_ */
