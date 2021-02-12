/*
 * bookCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "bookCommand.h"

// Constructor
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream) : in(inStream), out(outStream) {}

// Helper functions
void bookCommand::helperOut(std::string prompt)
{
	// Output prompt
	out << prompt << std::endl;
}

std::string bookCommand::helperIn(std::string prompt)
{
	// Output prompt
	out << prompt << std::endl;

	// Retrieve user input
	std::string input;
	std::getline(in, input);

	return input;
}
