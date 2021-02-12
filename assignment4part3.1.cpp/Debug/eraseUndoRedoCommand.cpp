/*
 * eraseUndoRedoCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "eraseUndoRedoCommand.h"

eraseUndoRedoCommand::eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry) : bookRef(book)
{
	oldEntryRef = oldEntry;
}

void eraseUndoRedoCommand::execute()
{
	// Redoing Erase (erasing entry)
	bookRef.erase(oldEntryRef.name());
}

void eraseUndoRedoCommand::unExecute()
{
	// Undoing Erase (inserting back entry)
	// This doesn't work in the best way because it inserts to the end rather than where it was
	bookRef.insert(oldEntryRef);
}
