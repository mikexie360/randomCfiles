/**
 * CS 2336 - 002
 * bookCommand.cpp
 * Purpose: called by addUpdateCommand, eraseCommand and printCommand.
 * It is supposed to tell the user what to input and returns the user's input.
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//Don't touch
#include "bookCommand.h"

#include <iostream>
#include <string>
#include <cstring>

/*
 * Constructor
 *
 * @param &in Takes in user input
 *
 * @param &out outputs a string
 */
bookCommand::bookCommand(std::istream& in, std::ostream& out) : input(in), output(out)
{ }

/*
 * outputs the parameter
 *
 * @param &theOutput is what the program will output
 */
void bookCommand::outputFunction(const std::string &theOutput)
{
	output << theOutput << std::endl;
}

/*
 * outputs the parameter and returns the user's input
 *
 * @param &theOutput is what the program will output
 */
std::string bookCommand::inputFunction(const std::string &theOutput)
{
	//The user's input
	std::string theInput = "";

	//outputs the parameter
	outputFunction(theOutput);

	//user input and return
	getline(input, theInput);
	return theInput;
}

