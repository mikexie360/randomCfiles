/*
 * insertUndoRedoCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "insertUndoRedoCommand.h"

insertUndoRedoCommand::insertUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry) : bookRef(book)
{
	oldEntryRef = oldEntry;
}

void insertUndoRedoCommand::execute()
{
	// Redoing insertion
	bookRef.insert(oldEntryRef);
}

void insertUndoRedoCommand::unExecute()
{
	// Undoing insertion (erasing)
	bookRef.erase(oldEntryRef.name());
}
