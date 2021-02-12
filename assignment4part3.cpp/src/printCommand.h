/**
 * CS 2336 - 002
 * printCommand.h
 * Purpose: prints the phone book entries
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#ifndef PRINTCOMMAND_H_
#define PRINTCOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"

/*
 * printCommand class prints the phone book
 * public inherits bookCommand
*/
class printCommand : public bookCommand
{
private:
	//we will print this phone book
	phoneBook &phoneBookReference;
public:
	/*
	 * Constructor
	 *
	 * @param &phoneBookReference we will print this phone book
	 *
	 * @param &input will be passed into bookCommand class. Takes in user input
	 *
	 * @param &output will be passed into bookCommand class. outputs a string
	 */
	printCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output);

	/*
	* inherited from command.h
	* how we will print the phone book
	*/
	virtual void execute();
};



#endif /* PRINTCOMMAND_H_ */
