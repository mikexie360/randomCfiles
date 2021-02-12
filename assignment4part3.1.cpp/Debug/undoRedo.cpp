/*
 * undoRedo.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas->edu
 *
 */

#include "undoRedo.h"
#include "memoryLeak.h"
// Constructor
undoRedo::undoRedo()
{
	undoOps = new stack();
	redoOps = new stack();
}

// Destructor
undoRedo::~undoRedo()
{
	// Delete all entries and then the undo stack itself
	while (!undoOps->empty()) {
		command *topCmd = undoOps->top();
		undoOps->pop();
		delete topCmd;
	}
	
	// Delete undoOps
	delete undoOps;

	// Delete all entries and then the redo stack itself
	while (!redoOps->empty()) {
		command *topCmd = redoOps->top();
		redoOps->pop();
		delete topCmd;
	}

	// Delete redoOps
	delete redoOps;
}

// Pushes command into undo stack
void undoRedo::addCommand(command *newCommand)
{
	undoOps->push(newCommand);
}

// Undo function
void undoRedo::undo()
{
	if (!undoOps->empty()) {
		// Get top entry from undo stack
		command* topEntry = undoOps->top();
		
		// Run unExecute
		topEntry->unExecute();

		// Push to redo stack
		redoOps->push(topEntry);

		// Pop current entry
		undoOps->pop();
	}
}

// Redo function
void undoRedo::redo()
{
	if (!redoOps->empty()) {
		// Get top entry from redo stack
		command* topEntry = redoOps->top();

		topEntry->execute();

		// Push to undo stack
		undoOps->push(topEntry);

		// Pop current entry
		redoOps->pop();
	}
}
