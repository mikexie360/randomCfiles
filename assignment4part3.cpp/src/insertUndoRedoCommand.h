/**
 * CS 2336 - 002
 * insertUndoRedoCommand.h
 * Purpose: command added to undoRedo to
 * allow undo and redo of an insert operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#ifndef INSERTUNDOREDOCOMMAND_H_
#define INSERTUNDOREDOCOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"

/*
 * insertUndoRedoCommand should be keeping track of the new phoneBookEntry for undoRedo
 * public inherits from command
 */
class insertUndoRedoCommand : public command
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
	 * @param newEntry will be stored and kept track of
	 */
	insertUndoRedoCommand(phoneBook &book, phoneBookEntry newEntry);

	//will execute the addUpdate command
	virtual void execute();

	//will unexecute the addUpdate command
	virtual void unExecute();
};

#endif /* INSERTUNDOREDOCOMMAND_H_ */
