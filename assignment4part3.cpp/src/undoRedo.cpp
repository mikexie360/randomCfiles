/**
 * CS 2336 - 002
 * undoRedo.cpp
 * Purpose: implements the ability to undo and redo commands
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "undoRedo.h"

#include <iostream>

//default constructor
undoRedo::undoRedo()
{
	undoStack = new stack();
	redoStack = new stack();
}

//destructor
undoRedo::~undoRedo()
{
	while (!undoStack->empty())
	{
		command *topCmd = undoStack->top();
		undoStack->pop();
		delete topCmd;
	}
	delete undoStack;

	while(!redoStack->empty())
	{
		command *topCmd = redoStack->top();
		redoStack->pop();
		delete topCmd;
	}
	delete redoStack;
}

//adds the command to the undoStack
void undoRedo::addCommand(command *newCommand)
{
	undoStack->push(newCommand);
}

//undo what has just been done
void undoRedo::undo()
{
	if(!undoStack->empty())
	{
		command *topEntry = undoStack->top();
		topEntry->unExecute();
		redoStack->push(topEntry);
		undoStack->pop();
	}
}

//redo what has just been undone
void undoRedo::redo()
{
	if(!redoStack->empty())
	{
		command *topEntry = redoStack->top();
		topEntry->execute();
		undoStack->push(topEntry);
		redoStack->pop();
	}
}
