/**
 * CS 2336 - 002
 * undoCommand.h
 * Purpose: command to undo an operation
 *
 *  @author Mike Xie
 *  @version 10/28/18
 */

//don't touch
#ifndef UNDOCOMMAND_H_
#define UNDOCOMMAND_H_

#include "command.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "undoRedo.h"

/*
 * undoCommand should undo an operation
 * public inherits command
 */
class undoCommand : public command
{
private:
	//member functions are needed to be executed
	undoRedo &undoRedoReference;
public:
	/*
	 * Constructor
	 *
	 * @param &undoRedoObject implements the ability to undo commands
	 */
	undoCommand(undoRedo &undoRedoObject);

	//undo a command
	virtual void execute();
};



#endif /* UNDOCOMMAND_H_ */
