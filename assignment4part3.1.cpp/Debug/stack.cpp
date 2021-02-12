/*
 * stack.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "stack.h"

// StackEntry Constructor
stackEntry::stackEntry(command *theCommand, stackEntry *pNext)
{
	ptrCommand = theCommand;
	ptrNext = pNext;
}

// StackEntry Destructor
stackEntry::~stackEntry()
{
}

// StackEntry Nexts
void stackEntry::next(stackEntry *pNext)
{
	ptrNext = pNext;
}

stackEntry* stackEntry::next()
{
	return ptrNext;
}

// StackEntry Data
command* stackEntry::data()
{
	return ptrCommand;
}

command* stackEntry::data() const
{
	return ptrCommand;
}

// Stack Constructor
stack::stack()
{
	ptrStackTop = nullptr;
	stEntries = 0;
}

// Stack Destructor
stack::~stack()
{
	while (!empty()) {
		pop();
	}
}

// Stack Top
command* stack::top()
{
	if (ptrStackTop) {
		return ptrStackTop->data();
	}
	return nullptr;
}

command* stack::top() const
{
	if (ptrStackTop) {
		return ptrStackTop->data();
	}
	return nullptr;
}

// Stack Sizes
std::size_t stack::size() const
{
	return stEntries;
}

bool stack::empty() const
{
	return (size() == 0);
}

// Stack Manipulations
void stack::push(command *newCommand)
{	
	// Create new top stackEntry
	ptrStackTop = new stackEntry(newCommand, ptrStackTop);

	// Increment entries counter
	stEntries++;
}

void stack::pop()
{
	// Check if stack is empty before trying to pop
	if (!empty()) {
		// Define new top to move up the entires
		stackEntry* ptrNewTop = ptrStackTop;

		ptrStackTop = ptrStackTop->next();

		// Delete top entry
		delete ptrNewTop;

		// Subtract count
		stEntries--;
	}
}

// Stack Debug
void stack::debug() const
{
	debug(std::cout);
}

void stack::debug(std::ostream &out) const
{
	stackEntry* ptrDebugEntry = ptrStackTop;
	out << size() << std::endl;
	for (std::size_t index = 0; index < size(); index++) {
		out << &ptrDebugEntry << std::endl;
		out << (ptrDebugEntry->data()) << std::endl;
		ptrDebugEntry = ptrDebugEntry->next();
		out << &ptrDebugEntry << std::endl;
	}
}