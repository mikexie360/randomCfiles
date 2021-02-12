/**
 * CS 2336 - 002
 * assignment3.cpp
 * Purpose: A phone book in which a user can store their phone book contact information.
 * The user can add an entry, update an entry to store a name, phone number and e-mail.
 * The user can also erase and delete phone book entries and print out the phone book.
 * The user can also undo the commands
 * The user can also redo the commands that was undone.
 *
 * Phone book is deleted when the user quits the program and must re enter their phone book entries.
 *
 * @author	Mike Xie
 * @version 10/28/2018
*/

//Don't touch

#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"
#include "undoCommand.h"
#include "redoCommand.h"

#include <vector>
#include <iostream>

//controls the operation of the program
int main()
{
	//creates a phone book class to store the phone book entries
	phoneBook mainPhoneBook;

	//creates the ability to undo and redo commands
	undoRedo* undoRedoFunction = new undoRedo();

	//tells the user that the program is starting
	std::cout << "Starting the Phone Book" << std::endl;
	std::cout << std::endl;

	//tells the user that they are in the phone book menu part of the program and the user can access the program's commands
	menuList mainMenuList("Phone book menu:");

	//if the user enters an 'a', then they can add or update a phone book entry
	addUpdateCommand addUpdate(mainPhoneBook, std::cin, std::cout, *undoRedoFunction);
	menuItem menuAddUpdate('a', "add/update", addUpdate);

	//if the user enters an 'e', then they can erase a phone book entry
	eraseCommand eraseCommand(mainPhoneBook, std::cin, std::cout, *undoRedoFunction);
	menuItem menuErase('e', "erase", eraseCommand);

	//if the user enters a 'p', then the program will print out the phone book
	printCommand printCommand(mainPhoneBook, std::cin, std::cout);
	menuItem menuPrint('p', "print", printCommand);

	//if the user enters a 'u', then the program will undo a command from the undo stack
	undoCommand undoCommand(*undoRedoFunction);
	menuItem menuUndo('u', "undo", undoCommand);

	//if the user enters a 'r', then the program will redo a command from the redo stack
	redoCommand redoCommand(*undoRedoFunction);
	menuItem menuRedo('r', "redo", redoCommand);

	//program adds the addUpdateCommand, eraseCommand, and printCommand to the program
	mainMenuList.add(menuAddUpdate);
	mainMenuList.add(menuErase);
	mainMenuList.add(menuPrint);
	mainMenuList.add(menuUndo);
	mainMenuList.add(menuRedo);

	//program will then start and show the menu
	mainMenuList.start();

	return 0;
}
