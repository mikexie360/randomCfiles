/*
 * printCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "printCommand.h"

// Constructor
printCommand::printCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream) : bookCommand(inStream, outStream), book(bookIn) {}

// Execute
void printCommand::execute()
{
	// Check if phoneBook is empty
	if (book.size() > 0) {
		// Print out phoneBook if it has values
		book.print(out);
	}
	else 
	{
		// Print out prompt saying it's empty if no entires in it
		prompt = "The phone book is empty";

		helperOut(prompt);
	}
}
