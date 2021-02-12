/**
 * CS 2336 - 002
 * eraseUndoRedoCommand.h
 * Purpose: command added to undoRedo to
 * allow undo and redo of an erase operation
 *
 * @author Mike Xie
 * @version 10/28/2018
 */

//don't touch
#pragma once
#ifndef ERASEUNDOREDOCOMMAND_H_
#define ERASEUNDOREDOCOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"

/*
 * eraseUndoRedoCommand should be keeping track of the old phoneBookEntry for undoRedo
 * public inherits from command
 */
class eraseUndoRedoCommand : public command
{
private:
	//we need this for the phoneBook methods and to keep track of the phoneBookEntry variables
	phoneBook &phone_Book;
	phoneBookEntry phoneEntry;
public:
	/*
	 * Constructor
	 *
	 * @param &book is needed for the phoneBook methods
	 *
	 * @param oldEntry will be stored and kept track of
	 */
	eraseUndoRedoCommand(phoneBook &book, phoneBookEntry oldEntry);

	//will execute the erase command
	virtual void execute();

	//will unexecute the erase command
	virtual void unExecute();
};



#endif /* ERASEUNDOREDOCOMMAND_H_ */
