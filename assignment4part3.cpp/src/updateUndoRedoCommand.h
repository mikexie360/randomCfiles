/**
 * CS 2336 - 002
 * updateUndoRedoCommand.h
 * Purpose: command added to undoRedo to
 * allow undo and redo of an update operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#ifndef UPDATEUNDOREDOCOMMAND_H_
#define UPDATEUNDOREDOCOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"

//command to added to allow an update operation
class updateUndoRedoCommand : public command
{
private:
	//we need this for the phoneBook methods and to keep track of the phoneBookEntry variables
	phoneBook &phone_Book;
	phoneBookEntry oldPhoneEntry;
	phoneBookEntry newPhoneEntry;
public:
	/*
	 * Constructor
	 *
	 * @param &book stores the phoneBook for its member functions
	 *
	 * @param oldEntry stores the variables for the phoneBookEntry that was already entered
	 *
	 * @param newEntry stores the variables for the phoneBookEntry that the user just entered
	 */
	updateUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry, phoneBookEntry newEntry);

	//will execute the insert method of phoneBook member function to update the phoneBookEntry with the new PhoneBookEntry
	virtual void execute();

	//will execute the insert method of phoneBook member function to update the phoneBookEntry with the old PhoneBookEntry
	virtual void unExecute();
};



#endif /* UPDATEUNDOREDOCOMMAND_H_ */
