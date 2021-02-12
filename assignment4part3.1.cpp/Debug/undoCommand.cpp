/*
 * undoCommand.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "undoCommand.h"

undoCommand::undoCommand(undoRedo & undoRedoObject) : undoRedoRef(undoRedoObject) {}

void undoCommand::execute()
{
	undoRedoRef.undo();
}
