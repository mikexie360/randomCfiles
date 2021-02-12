/*
 * eraseCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "bookCommand.h"
#include "eraseUndoRedoCommand.h"
#include "memoryLeak.h"

class eraseCommand : public bookCommand {
public:
	// Constructor
	eraseCommand(phoneBook &bookIn, std::istream &in, std::ostream &out, undoRedo &undoRedoObject);

	// Execute
	virtual void execute();

private:
	// Variables for execute
	std::string prompt;

	// phoneBook reference
	phoneBook &book;

	// undoRedo reference
	undoRedo &undoRedoRef;
};