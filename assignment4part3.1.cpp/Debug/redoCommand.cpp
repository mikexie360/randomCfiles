/*
 * redoCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "redoCommand.h"

redoCommand::redoCommand(undoRedo & undoRedoObject) : undoRedoRef(undoRedoObject) {}

void redoCommand::execute()
{
	undoRedoRef.redo();
}
