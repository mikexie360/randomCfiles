/**
 * CS 2336 - 002
 * stack.h
 * Purpose: creates a stack with a stackEntry to be stacked
 *
 *  @author Mike Xie
 *  @version 10/28/2018
 */

//don't touch
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <cstddef>
#include "command.h"


class command;

class stack;

//the stackEntry is to be stacked in Stack
class stackEntry
{
	//stackEntry and stack are friends
	friend class stack;
private:
	//points to the command
	command* ptrCommand = nullptr;
	//points to the next command down
	stackEntry* ptrNextStackEntry = nullptr;
protected:
	/*
	 * Constructor
	 *
	 * @param *theCommand pointer to the command
	 *
	 * @param *pNext pointer to the next command down in the stack
	 */
	stackEntry(command *theCommand, stackEntry *pNext = nullptr);

	//destructor
	virtual ~stackEntry();

	//mutator and changes where the stack points to next
	virtual void next (stackEntry *pNext);

	//gets the pointer of the command the stackEntry is pointing to
	virtual command* data();

	//gets the pointer of the command the stackEntry is pointing to
	virtual const command* data() const;

	//gets the pointer of the next command the stackEntry is pointing down to
	virtual stackEntry* next();
};

//stack contains a stack of stackEntry
class stack
{
private:
	//points to whatever stackEntry is at the top of the stack
	stackEntry* ptrTopOfStack = nullptr;
	//keeps track of the number of stackEntries is in the stack
	std::size_t numberOfEntries = 0;
public:
	//default constructor
	stack();

	stack(const stack &from) = delete;
	stack& operator=(const stack &from) = delete;

	//destructor
	virtual ~stack();

	//returns the command pointer that points to the top of the stack
	command* top();

	//returns the command pointer that points to the top of the stack
	const command* top() const;

	//returns true if empty, returns false if not empty
	bool empty() const;

	//returns size of the stack
	std::size_t size() const;

	//adds a new stackEntry to the top of the stack
	virtual void push(command *newCommand);

	//delete the top of the stack
	virtual void pop();

	//helps debugs the program
	virtual void debug() const;
	virtual void debug(std::ostream &out) const;
};

#endif /* STACK_H_ */
