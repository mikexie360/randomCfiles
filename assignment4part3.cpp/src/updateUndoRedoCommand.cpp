/**
 * CS 2336 - 002
 * updateUndoRedoCommand.cpp
 * Purpose: command added to undoRedo to
 * allow undo and redo of an update operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "updateUndoRedoCommand.h"
#include "orderedLinkedList.h"


/*
 * Constructor
 *
 * @param &book stores the phoneBook for its member functions
 *
 * @param oldEntry stores the variables for the phoneBookEntry that was already entered
 *
 * @param newEntry stores the variables for the phoneBookEntry that the user just entered
 */
updateUndoRedoCommand::updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry)
:phone_Book(book), oldPhoneEntry(oldEntry), newPhoneEntry(newEntry)
{ }

//will execute the insert method of phoneBook member function to update the phoneBookEntry with the new PhoneBookEntry
void updateUndoRedoCommand::execute()
{
	//update with new PhoneBookEntry
	//Keep code as is. code may be unable to pass test case if the code below changes.
	phone_Book.insert(newPhoneEntry);
}

//will execute the insert method of phoneBook member function to update the phoneBookEntry with the old PhoneBookEntry
void updateUndoRedoCommand::unExecute()
{
	//update with old phoneBookEntry
	//Keep code as is. code may be unable to pass test case if the code below changes.
	phone_Book.insert(oldPhoneEntry);
}
