/**
 * CS 2336 - 002
 * addUpdateCommand.h
 * Purpose: Updates the phone book or adds a new entry to the phone book
 * has the undo redo functionality.
 *
 * @author	Mike Xie
 * @version 10/28/2018
*/

//Don't touch
#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "undoRedo.h"
#include "updateUndoRedoCommand.h"
#include "insertUndoRedoCommand.h"

/*
 * addUpdateCommand class adds or updates phone book entries
 * public inherits bookCommand
*/
class addUpdateCommand : public bookCommand
{
private:
	phoneBook &theBook;
	undoRedo &undoRedoReference;
public:
	/*
	 * Constructor
	 *
	 * @param &phoneBookReference we will add or update in this phone book
	 *
	 * @param &input will be passed into bookCommand class. Takes in user input
	 *
	 * @param &output will be passed into bookCommand class. outputs a string
	 */
	addUpdateCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output, undoRedo &undoRedoObject);

	/*
	* inherited from command.h
	* how we will add or update a phone book entry
	*/
	virtual void execute();
};

#endif /* ADDUPDATECOMMAND_H_ */
