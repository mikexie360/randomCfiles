/**
 * CS 2336 - 002
 * undoRedo.h
 * Purpose: implements the ability to undo and redo commands
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#ifndef UNDOREDO_H_
#define UNDOREDO_H_

#include "command.h"
#include "stack.h"

#include <iostream>
#include <cstddef>

//implements the ability to undo and redo commands
class undoRedo
{
public:
	//default constructor
	undoRedo();

	//destructor
	virtual ~undoRedo();

	//adds the command to the undoStack
	virtual void addCommand(command *newCommand);
		// note that undoRedo will delete the command in its destructor

	//undo what has just been done
	virtual void undo();

	//undo what has just been undone
	virtual void redo();
private:
	//the two stacks to know what to undo and redo
	stack *undoStack;
	stack *redoStack;
};



#endif /* UNDOREDO_H_ */
