/*
 * printCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "bookCommand.h"
#include "phoneBook.h"

class printCommand : public bookCommand {
public:
	// Constructor
	printCommand(phoneBook &bookIn, std::istream &in, std::ostream &out);

	// Execute
	virtual void execute();

private:
	// Variables for execute
	std::string prompt;

	// phoneBook reference
	phoneBook &book;
};