/*
 * addUpdateCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "bookCommand.h"
#include "updateUndoRedoCommand.h"
#include "insertUndoRedoCommand.h"
#include "memoryLeak.h"

class addUpdateCommand : public bookCommand {
public:
	// Constructor
	addUpdateCommand(phoneBook &bookIn, std::istream &in, std::ostream &out, undoRedo &undoRedoObject);
	
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