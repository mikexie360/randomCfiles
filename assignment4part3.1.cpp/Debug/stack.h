/*
 * stack.h
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#pragma once

#include <cstddef>
#include <iostream>
#include <iomanip>

#include "command.h"
#include "memoryLeak.h"

class stackEntry
{
public:
	friend class stack;

protected:
	// Constructors/Destructors
	stackEntry(command *theCommand, stackEntry *pNext = nullptr);
	virtual ~stackEntry();

	// Next 
	virtual void next(stackEntry *pNext);
	virtual stackEntry* next();

	// Command Data
	virtual command* data();
	virtual command* data() const;

private:
	command* ptrCommand;
	stackEntry* ptrNext;
};

class stack
{
public:
	// Constructors/Destructors
	stack();
	stack(const stack &from) = delete;
	stack& operator=(const stack &from) = delete;
	virtual ~stack();

	// Top Pointers
	command* top();
	command* top() const;

	// Stack Sizes
	std::size_t size() const;
	bool empty() const;

	// Stack Manipulation
	void push(command *newCommand);
	void pop();

	// Debugging
	void debug() const;
	void debug(std::ostream &out) const;

private:
	stackEntry* ptrStackTop;
	std::size_t stEntries;

};