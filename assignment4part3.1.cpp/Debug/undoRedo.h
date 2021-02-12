/*
 * undoRedo.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "stack.h"

class command;

class stack;

class undoRedo
{
public:
	// Constructor/Destructor
	undoRedo();
	virtual ~undoRedo();

	// Add Command
	virtual void addCommand(command *newCommand);

	// Manipulation
	virtual void undo();
	virtual void redo();
	
private:
	stack *undoOps;
	stack *redoOps;
};