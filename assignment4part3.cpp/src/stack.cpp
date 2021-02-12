/**
 * CS 2336 - 002
 * stack.cpp
 * Purpose: creates a stack with a stackEntry to be stacked
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#include "stack.h"
#include "command.h"

#include <iomanip>
#include <iostream>
#include <cstddef>

/*
 * Constructor
 *
 * @param *theCommand pointer to the command
 *
 * @param *pNext pointer to the next command down in the stack
 */
stackEntry::stackEntry(command *theCommand, stackEntry *pNext)
{
	ptrCommand = theCommand;
	ptrNextStackEntry = pNext;
}

//destructor
stackEntry::~stackEntry()
{ }

//mutator and changes where the stack points to next
void stackEntry::next(stackEntry *pNext)
{
	ptrNextStackEntry = pNext;
}

//gets the pointer of the command the stackEntry is pointing to
command* stackEntry::data()
{
	return ptrCommand;
}

//gets the pointer of the command the stackEntry is pointing to
const command* stackEntry::data() const
{
	return ptrCommand;
}

//gets the pointer of the next command the stackEntry is pointing down to
stackEntry* stackEntry::next()
{
	return ptrNextStackEntry;
}

//default constructor
stack::stack()
{
	ptrTopOfStack = nullptr;
	numberOfEntries = 0;
}

//destructor
stack::~stack()
{
	//keeps on poping the top off until empty
	while(!empty())
	{
		pop();
	}
}

//returns the command pointer that points to the top of the stack
command* stack::top()
{
	return (*ptrTopOfStack).data();
}

//returns the command pointer that points to the top of the stack
const command* stack::top() const
{
	return (*ptrTopOfStack).data();
}

//returns true if empty, returns false if not empty
bool stack::empty() const
{
	if(numberOfEntries == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns the size of the stack
std::size_t stack::size() const
{
	return numberOfEntries;
}

//adds a new stackEntry to the top of the stack
void stack::push(command *newCommand)
{
	//How we add to the stack
	ptrTopOfStack = new stackEntry( newCommand, ptrTopOfStack);

	//when we add to the stack we must increment the numberOfEntries
	numberOfEntries++;
}

//delete the top of the stack
void stack::pop()
{
	if(!empty())
	{
		//*ptrSecondTopOfStack will hold the second top of the stack
		stackEntry *ptrSecondTopOfStack = (*ptrTopOfStack).next();
		delete ptrTopOfStack;

		//ptrTopOfStack is now the ptrSecondTopOfStack because we are trying to get rid of the TopOfStack
		ptrTopOfStack = ptrSecondTopOfStack;

		//numberOfEntries decrement when we take away from the stack
		numberOfEntries--;
	}
}

//helps debugs the program
void stack::debug() const
{
	std::cout << "numberOfEntries" << numberOfEntries << std::endl;
	std::cout << "Address of stackEntry" << ptrTopOfStack << std::endl;
	std::cout << "address of the command pointer" << (*ptrTopOfStack).data() << std::endl;
	std::cout << "Address of the next stackEntry" << (*ptrTopOfStack).next() << std::endl;
}
void stack::debug(std::ostream &out) const
{
	out << "numberOfEntries" << numberOfEntries << std::endl;
	out << "Address of stackEntry" << ptrTopOfStack << std::endl;
	out << "address of the command pointer" << (*ptrTopOfStack).data() << std::endl;
	out << "Address of the next stackEntry" << (*ptrTopOfStack).next() << std::endl;
}





