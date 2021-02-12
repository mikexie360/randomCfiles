/*
 * eraseUndoRedoCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "command.h"

#include "phoneBook.h"
#include "undoRedo.h"

class eraseUndoRedoCommand : public command {
public:
	// Constructor
	eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry);

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