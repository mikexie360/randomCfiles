/**
 * CS 2336 - 002
 * printCommand.cpp
 * Purpose: prints the phone book entries
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#include "printCommand.h"


#include <iostream>
#include <string>
#include <cstring>

/*
 * Constructor
 *
 * @param &phoneBookReference we will print this phone book
 *
 * @param &input will be passed into bookCommand class. Takes in user input
 *
 * @param &output will be passed into bookCommand class. outputs a string
 */
printCommand::printCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output)
	:bookCommand(input,output), phoneBookReference(phoneBookReference) { }

//prints the phone book entries
void printCommand::execute()
{
	phoneBookReference.print(output);
}


