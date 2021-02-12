/**
 * CS 2336 - 002
 * incrementCommand.h
 * Purpose: command added to undoRedo to
 * allow undo and redo of an add/insert operation
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#ifndef INCREMENTCOMMAND_H_
#define INCREMENTCOMMAND_H_

#include <iostream>
#include  "command.h"


class incrementCommand : public command
{
	private:
		// this a reference to the int we will increment
		int &value;
	public:
		// value is passed by reference to us on the constructor
		incrementCommand(int &value)
			: value(value)
		{
		}
		virtual ~incrementCommand()
		{
		}
		// override the execute member function from class command
		// we simply increment the value and display it on cout
		virtual void execute() override // the override ensures that we have the correct signature for execute()
		{
			value++;
			std::cout << "value: " << value << std::endl;
		}
};

#endif /* INCREMENTCOMMAND_H_ */
