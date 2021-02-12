/*
 * updateUndoRedoCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "command.h"

#include "phoneBook.h"
#include "undoRedo.h"

class updateUndoRedoCommand : public command {
public:
	// Constructor
	updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry);

	// Execute
	virtual void execute();

	// Unexecute
	virtual void unExecute();
	
private:
	// phoneBook reference
	phoneBook &bookRef;

	// old phoneBookEntry reference
	phoneBookEntry oldEntryRef;

	// new phoneBookEntry reference
	phoneBookEntry newEntryRef;
};