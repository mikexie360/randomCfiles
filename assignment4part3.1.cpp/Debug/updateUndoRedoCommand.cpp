/*
 * updateUndoRedoCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "updateUndoRedoCommand.h"

updateUndoRedoCommand::updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry) : bookRef(book)
{
	oldEntryRef = oldEntry;
	newEntryRef = newEntry;
}

void updateUndoRedoCommand::execute()
{
	// Redoing update (insert new entry)
	bookRef.insert(newEntryRef);
}

void updateUndoRedoCommand::unExecute()
{
	// Undoing update (insert old entry)
	bookRef.insert(oldEntryRef);
}
