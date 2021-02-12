/**
 * CS 2336 - 002
 * eraseCommand.cpp
 * Purpose: User will input a name and the program attempts to erase the phone book entry that has the same name.
 * has undo and redo functionality
 *
 * @author	Mike Xie
 * @version 10/28/2018
*/

//don't touch
#include "eraseCommand.h"

#include <iostream>
#include <string>
#include <cstring>

/*
 * Constructor
 *
 * @param &phoneBookReference we will erase a phone book entry from this phone book
 *
 * @param &input will be passed into bookCommand class. Takes in user input
 *
 * @param &output will be passed into bookCommand class. outputs a string
 */
eraseCommand::eraseCommand(phoneBook &phoneBookReference, std::istream &input, std::ostream &output, undoRedo &undoRedoObject)
	:bookCommand(input,output), phoneBookReference(phoneBookReference), undoRedoReference(undoRedoObject)
{ }

//will erase a phone book entry
void eraseCommand::execute()
{
	//user inputs a name to erase
	std::string nameInput = inputFunction("Enter name to erase");

	//variables for the old phoneBookEntry
	std::string phoneNumber = "";
	std::string email = "";

	//finds the old phoneBookEntry and finds the variables for it
//	for(int index = 0; index < static_cast<int>(phoneBookReference.size()); index++)
//	{
//		if(phoneBookReference.phoneEntry.at(index).name() == nameInput)
//		{
//			phoneNumber = phoneBookReference.phoneBookList.at(index).phoneNumber();
//			email = phoneBookReference.phoneBookList.at(index).email();
//		}
//	}
	//old phoneBookEntry is created with the old variables
	phoneBookEntry oldPhoneBookEntry(nameInput, phoneNumber, email);

	//program erases the phone entry
	if(phoneBookReference.erase(nameInput))
	{
		//confirms that the phone entry was erased
		outputFunction("Phone book entry " + nameInput + " was erased");

		eraseUndoRedoCommand *eraseUndoRedo = new eraseUndoRedoCommand(phoneBookReference, phoneBookEntry(nameInput, phoneBookReference.ptr->phoneNumber(), phoneBookReference.ptr->email()));

		//adds the eraseUndoRedoCommand on the undo stack
		undoRedoReference.addCommand(eraseUndoRedo);
	}
	else
	{
		//confirms that the phone entry was not erased
		outputFunction("Phone book entry " + nameInput + " was not erased");
	}
}
