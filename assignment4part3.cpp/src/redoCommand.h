/**
 * CS 2336 - 002
 * redoCommand.h
 * Purpose: command to redo and operation
 *
 *  @author Mike Xie
 *  @version 10/28/18
 */

//don't touch
#ifndef REDOCOMMAND_H_
#define REDOCOMMAND_H_

#include "command.h"
#include "phoneBook.h"
#include "phoneBookEntry.h"
#include "undoRedo.h"

/*
 * redoCommand should redo an operation
 * public inherits command
 */
class redoCommand : public command
{
private:
	//member functions are needed to be executed
	undoRedo &undoRedoReference;
public:
	/*
	 * Constructor
	 *
	 * @param &undoRedoObject implements the ability to redo commands
	 */
	redoCommand(undoRedo &undoRedoObject);

	//redo a command
	virtual void execute();
};




#endif /* REDOCOMMAND_H_ */
