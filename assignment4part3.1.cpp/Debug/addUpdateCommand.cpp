/*
 * addUpdateCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "addUpdateCommand.h"

// Constructor
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream, std::ostream &outStream, undoRedo &undoRedoObject) : bookCommand(inStream, outStream), book(bookIn), undoRedoRef(undoRedoObject){}

// Execute
void addUpdateCommand::execute()
{
	// Send prompt and take input for all info that we need
	prompt = "Enter name to add/update";
	// Take hold of the name so we can used it later
	std::string sName = helperIn(prompt);

	prompt = "Enter phone number";
	// Take hold of the phone number so we can use it later.
	std::string sPhoneNumber = helperIn(prompt);

	prompt = "Enter e-mail address";
	// Take hold of the email so we can use it later.
	std::string sEmail = helperIn(prompt);

	// Check if adding or updating for prompt (inefficient but I can't think of another way to do so)
	if (book.find(sName))
	{
		// Create updateUndoRedoCommand with old phoneBookEntry and new phoneBookEntry
		updateUndoRedoCommand* updateUndoRedo = new updateUndoRedoCommand(book, phoneBookEntry(book.ptr->name(), book.ptr->phoneNumber(), book.ptr->email()), phoneBookEntry(sName, sPhoneNumber, sEmail));
		
		// Add updateUndoRedoCommand to undoRedo object
		undoRedoRef.addCommand(updateUndoRedo);

		book.insert(sName, sPhoneNumber, sEmail);
		prompt = "Updating phone book entry for " + sName;
	}
	else
	{
		// Check if email is empty and use appropriate insert based on that.
		if (sEmail == "") {
			book.insert(sName, sPhoneNumber);
		}
		else
		{
			book.insert(sName, sPhoneNumber, sEmail);
		}

		// Create insertUndoRedoCommand with new phoneBookEntry
		insertUndoRedoCommand* insertUndoRedo = new insertUndoRedoCommand(book, phoneBookEntry(sName, sPhoneNumber, sEmail));

		// Add insertUndoRedoCommand to undoRedo object
		undoRedoRef.addCommand(insertUndoRedo);

		prompt = "Adding phone book entry for " + sName;
	}

	// Send final prompt message to indicate that entry is being added.
	
	helperOut(prompt);
}
