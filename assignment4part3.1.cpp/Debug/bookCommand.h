/*
 * bookCommand.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include <iostream>
#include <string>

#include "command.h"

class bookCommand : public command {
public:
	// Constructor
	bookCommand(std::istream &in, std::ostream &out);

	// Deconstructor
	virtual ~bookCommand() {};

	// Execute
	virtual void execute() = 0;

protected:
	// Variables for input and output streams
	std::istream &in;
	std::ostream &out;
	
	// Helper functions
	void helperOut(std::string prompt);
	std::string helperIn(std::string prompt);

};