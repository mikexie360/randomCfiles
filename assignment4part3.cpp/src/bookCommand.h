/**
 * CS 2336 - 002
 * bookCommand.h
 * Purpose: called by addUpdateCommand, eraseCommand and printCommand.
 * It is supposed to tell the user what to input and returns the user's input.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//Don't touch
#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include <iostream>
#include "command.h"

/*
 * bookCommand simply outputs what's in the parameter and returns input from the user.
 * public inherits command
*/
class bookCommand: public command
{
protected:
	std::istream &input;
	std::ostream &output;

	/*
	 * outputs what is inside the parameter.
	 *
	 * @param &theOutput is what the program will output
	 */
	void outputFunction( const std::string &theOutput);

	/*
	 * outputs the parameter and returns the user's input
	 *
	 * @param &theOutput is what the program will output
	 */
	std::string inputFunction(const std::string &theOutput);

public:
	/*
	 * Constructor
	 *
	 * @param &in Takes in user input
	 *
	 * @param &out outputs a string
	 */
	bookCommand(std::istream &in, std::ostream &out);
};



#endif /* BOOKCOMMAND_H_ */
