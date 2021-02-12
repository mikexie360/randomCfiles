/**
 * CS 2336 - 002
 * insertUndoRedoCommand.cpp
 * Purpose: command added to undoRedo to
 * allow undo and redo of an insert operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "insertUndoRedoCommand.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"

/*
 * Constructor
 *
 * @param &book stores the phoneBook for its member functions
 *
 * @param newEntry stores the variables for the phoneBookEntry that the user just entered
 */
insertUndoRedoCommand::insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry)
:phone_Book(book), phoneEntry(newEntry)
{ }

//will execute the insert method of phoneBook member function
void insertUndoRedoCommand::execute()
{
	//will insert the phoneBookEntry
	phone_Book.insert(phoneEntry);
}

//will undo the insert method by erasing the newEntry using the phoneBook member function
void insertUndoRedoCommand::unExecute()
{
	//will erase the phoneBookEntry
	phone_Book.erase(phoneEntry.name());
}
