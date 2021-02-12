/*
 * undoCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include "command.h"
#include "undoRedo.h"

class undoCommand : public command {
public:
	// Constructor
	undoCommand(undoRedo &undoRedoObject);

	// Execute
	virtual void execute();

private:
	// undoRedo reference
	undoRedo &undoRedoRef;
};