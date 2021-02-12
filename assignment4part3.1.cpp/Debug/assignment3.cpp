/*
 * assignment3.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 *
 */

#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "undoCommand.h"
#include "redoCommand.h"

int main() {

	// Initialize a new Phone Book
	phoneBook book;

	// Initalize a new Menu List
	menuList menu("Phone book menu:");

	// Initialize a new undoRedo object
	undoRedo undoRedoObject;

	// Create Commands to be placed into Menu Items
	addUpdateCommand commandAddUpdate(book, std::cin, std::cout, undoRedoObject);
	eraseCommand commandErase(book, std::cin, std::cout, undoRedoObject);
	printCommand commandPrint(book, std::cin, std::cout);
	undoCommand commandUndo(undoRedoObject);
	redoCommand commandRedo(undoRedoObject);

	// Create Menu Items to be implemented into the Menu List
	menuItem itemAddUpdate('a', "add/update", commandAddUpdate);
	menuItem itemErase('e', "erase", commandErase);
	menuItem itemPrint('p', "print", commandPrint);
	menuItem itemUndo('u', "undo", commandUndo);
	menuItem itemRedo('r', "redo", commandRedo);

	// Add Menu Items to Menu List
	menu.add(itemAddUpdate);
	menu.add(itemErase);
	menu.add(itemPrint);
	menu.add(itemUndo);
	menu.add(itemRedo);
	
	// Start the menu
	std::cout << "Starting the Phone Book" << std::endl << std::endl;
	menu.start();

	return 0;
}