/**
 * CS 2336 - 002
 * addUpdateCommand.cpp
 * Purpose: Updates the phone book or adds a new entry to the phone book
 * has the undo redo functionality
 *
 * @author	Mike Xie
 * @version 10/28/2018
*/

//Don't mess with the header files
#include "addUpdateCommand.h"

#include <iostream>
#include <string>
#include <cstring>

/*
 * Constructor
 *
 * @param &phoneBookReference we will add or update this phone book
 *
 * @param &input will be passed into bookCommand class. Takes in user input
 *
 * @param &output will be passed into bookCommand class. outputs a string
 */
addUpdateCommand::addUpdateCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output, undoRedo &undoRedoObject)
	:bookCommand(input,output), theBook(phoneBookReference), undoRedoReference(undoRedoObject)
{ }

/*
 * User will enter a name, phone number and email address and
 * addUpdateCommand::execute() will either add a new phone book entry or update the phone book entry.
 */
void addUpdateCommand::execute()
{
	//user inputs a name
	std::string nameInput = inputFunction("Enter name to add/update");

	//user inputs a phone number
	std::string phoneInput = inputFunction("Enter phone number");

	//user inputs an e-mail address
	std:: string emailInput = inputFunction("Enter e-mail address");


	//adds a new entry or updates the entry
	if(theBook.find(nameInput))
	{
		//updates the entry
		outputFunction("Updating phone book entry for " + nameInput);
		theBook.insert(nameInput, phoneInput, emailInput);

		updateUndoRedoCommand *updateUndoRedo = new updateUndoRedoCommand(theBook, phoneBookEntry(theBook.ptr->name(), theBook.ptr->phoneNumber(), theBook.ptr->email()), phoneBookEntry(nameInput, phoneInput, emailInput));
		//adds the updateUndoRedoCommand on the undo stack
		undoRedoReference.addCommand(updateUndoRedo);
	}
	else
	{
		if(emailInput == "")
		{
			theBook.insert(nameInput, phoneInput);
		}
		else
		{
			theBook.insert(nameInput, phoneInput, emailInput);
		}
		//adds a new entry
		outputFunction("Adding phone book entry for " + nameInput);
		theBook.insert(nameInput, phoneInput, emailInput);

		//adds the insertUndoRedo on the undo stack
		insertUndoRedoCommand *insertUndoRedo = new insertUndoRedoCommand(theBook, phoneBookEntry(nameInput, phoneInput, emailInput));
//		undoRedoReference.addCommand(new insertUndoRedoCommand(theBook, phoneBookEntry(nameInput,phoneInput,emailInput)));
		undoRedoReference.addCommand(insertUndoRedo);
	}
}


















