/**
 * CS 2336 - 002
 * eraseUndoRedoCommand.cpp
 * Purpose:command added to undoRedo to
 * allow undo and redo of an erase operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "eraseUndoRedoCommand.h"

/*
 * Constructor
 *
 * @param &book stores the phoneBook for its member functions
 *
 * @param oldEntry stores all variables in the phoneBookEntry
 */
eraseUndoRedoCommand::eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry)
:phone_Book(book), phoneEntry(oldEntry)
{ }

//will execute the erase method of phoneBook member function
void eraseUndoRedoCommand::execute()
{
	//will erase the phoneBookEntry
	phone_Book.erase(phoneEntry.name());
}

//will undo the erase command by inserting the oldEntry back using the phoneBook member function
void eraseUndoRedoCommand::unExecute()
{
	//will add back the phoneBookEntry
	phone_Book.insert(phoneEntry);
}
