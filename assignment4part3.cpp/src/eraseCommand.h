/**
 * CS 2336 - 002
 * eraseCommand.h
 * Purpose: User will input a name and the program attempts to erase the phone book entry that has the same name.
 * has undo and redo functionality
 *
 * @author	Mike Xie
 * @version 10/7/2018
*/

//don't touch
#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"
#include "undoRedo.h"
#include "eraseUndoRedoCommand.h"

/*
 * eraseCommand class erases phone book entries
 * public inherits bookCommand
*/
class eraseCommand : public bookCommand
{
private:
	//we will erase something from this phone book
	phoneBook &phoneBookReference;
	undoRedo &undoRedoReference;
public:
	/*
	 * Constructor
	 *
	 * @param &phoneBookReference we will erase from this phone book
	 *
	 * @param &input will be passed into bookCommand class. Takes in user input
	 *
	 * @param &output will be passed into bookCommand class. outputs a string
	 */
	eraseCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output, undoRedo &undoRedoObject);

	/*
	* inherited from command.h
	* how we will erase a book entry
	*/
	virtual void execute();
};



#endif /* ERASECOMMAND_H_ */
