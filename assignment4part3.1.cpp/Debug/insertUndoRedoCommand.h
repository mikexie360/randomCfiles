/*
 * insertUndoRedoCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "command.h"

#include "phoneBook.h"
#include "undoRedo.h"

class insertUndoRedoCommand : public command {
public:
	// Constructor
	insertUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry);

	// Execute
	virtual void execute();

	// Unexecute
	virtual void unExecute();

private:
	// phoneBook reference
	phoneBook &bookRef;

	// old phoneBookEntry reference
	phoneBookEntry oldEntryRef;
};