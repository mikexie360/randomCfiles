/*
 * eraseCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "eraseCommand.h"

// Constructor
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) : bookCommand(inStream, outStream), book(bookIn), undoRedoRef(undoRedoObject) {}

// Execute
void eraseCommand::execute()
{
	// Send prompt and take input for all info that we need
	prompt = "Enter name to erase";
	// Take hold of the name so we can use it later
	std::string sName = helperIn(prompt);

	// Try to erase name from our book. 
	// Change prompt based on if successful or not.
	if (book.erase(sName))
	{
		// Create eraseUndoRedo with erased phoneBookEntry
		eraseUndoRedoCommand* eraseUndoRedo = new eraseUndoRedoCommand(book, phoneBookEntry(sName, book.ptr->phoneNumber(), book.ptr->email()));

		// Add eraseUndoRedo to undoRedo object
		undoRedoRef.addCommand(eraseUndoRedo);

		prompt = "Phone book entry " + sName + " was erased";
	}
	else
	{
		prompt = "Phone book entry " + sName + " was not erased";
	}

	// Send final prompt message to indicate that entry has or has not been erased.
	
	helperOut(prompt);
}
