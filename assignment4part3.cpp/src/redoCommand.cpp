/**
 * CS 2336 - 002
 * redoCommand.cpp
 * Purpose: command to redo an operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "redoCommand.h"

/*
 * Constructor
 *
 * @param &undoRedoObject implements the ability to redo commands
 */
redoCommand::redoCommand(undoRedo &undoRedoObject)
:undoRedoReference(undoRedoObject)
{ }

//redo a command
void redoCommand::execute()
{
	//executes the redo member function of undoRedoReference
	undoRedoReference.redo();
}
