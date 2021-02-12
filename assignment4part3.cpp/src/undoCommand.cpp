/**
 * CS 2336 - 002
 * undoCommand.cpp
 * Purpose: command to undo an operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "undoCommand.h"

/*
 * Constructor
 *
 * @param &undoRedoObject implements the ability to undo commands
 */
undoCommand::undoCommand(undoRedo &undoRedoObject)
:undoRedoReference(undoRedoObject)
{ }

//undo a command
void undoCommand::execute()
{
	//execute the undo member function of undoRedoReference
	undoRedoReference.undo();
}
