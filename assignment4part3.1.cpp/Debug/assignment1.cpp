/*
 * assignment1.cpp
 *
 * Author: Aliaksei Novikau
 * Contact: axn174430@utdallas.edu
 * Description: This program reads in a word puzzle, creates a puzzle, 
 * reads in a list of words and looks for the words within the puzzle.
 * It then prints out if, and where, it finds the words within the puzzle.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

// Directions enum.
enum direction {
	LEFT_RIGHT,
	RIGHT_LEFT,
	DOWN,
	UP,
	RIGHT_DOWN,
	RIGHT_UP,
	LEFT_DOWN,
	LEFT_UP
};

// Max rows and columns.
const int MAX = 50;

// Define wordGame struct.
struct wordGame
{
	int version;
	int numberRows;
	int numberColumns;
	char puzzle[50][50];
};

// Define wordFind struct.
struct wordFind
{
	string word;
	bool found;
	int row;
	int column;
	direction where;
};

// Define a constant directions array so we can reference it in the output through the enum values.
const string directions[] = { "right", "left", "down", "up", "right/down", "right/up", "left/down", "left/up" };

// This function will search in every direction from found point
// and will return true/false depending on if it finds the full word in any direction.
bool fromPoint(wordGame &game, wordFind &theFind, int row, int column)
{
	// Immediately we have to check if the first point matches the first character of the word.
	if (game.puzzle[row][column] != theFind.word[0]) { return false; } // I love using this type of format for ifs that are short. I hope it doesn't 'break' my formatting in your eyes.

	// We define an integer for the size of the word here so we don't have to run the size() function multiple times.
	int size = theFind.word.length();

	// Here we define two arrays that we will use within our directional search.
	// These values define the direction we go in our searches.
	// A negative one means we will be going left one for rows and up one for columns.
	// A positive one means we will be going right one for rows and down one for columns.
	// A zero means that we will not move that row or column at all during that particular direction search.
	// As you can see, there is no point where a zero occurs on both rows and columns because we would be stuck in place if it did.
	// The order of these is the same order as the enum direction.
	int rowDirArray[] = { 0, 0, 1, -1, 1, -1, 1, -1};
	int colDirArray[] = { 1, -1, 0, 0, 1, 1, -1, -1};

	// We will search through all 8 directions
	for (int i = 0; i < 8; i++)
	{
		theFind.where = (direction) i;

		int j; // This is the starting point for the current direction. 
			   // We initialize this outside of the following for loop because we need to use it outside of it.

		// We immediately apply the arguments set within the arrays because we are starting from the second character.
		int rowDir = row + rowDirArray[i], colDir = column + colDirArray[i];

		// Since we already checked the first character (at 0), we look through all other ones.
		for (j = 1; j < size; j++)
		{
			// Break if the position is out of bounds.
			if (rowDir < 0 || rowDir >= game.numberRows || colDir < 0 || colDir >= game.numberColumns) { break; }

			// Break if the character at the cell doesn't match the corresponding character in the word.
			if (game.puzzle[rowDir][colDir] != theFind.word[j]) { break; }

			// Move further into this direction if we have not broken at this point.
			rowDir += rowDirArray[i], colDir += colDirArray[i];
			
		}

		// At this point we check if we reached the end of the loop or broken out of it.
		// If at the end, this if succeeds and we return true. If we broke out, it fails and we resume.
		if (j == size) { 
			return true; 
		}
	}
	return false;
}

// Find the word that is part of the wordFind structure inside the wordGame structure. 
// if the word is found the wordFind structure will be updated.
void findWord(wordGame &game, wordFind &theFind)
{
	// We search for every position in the puzzle that could be our starting point for the word.
	// Iterate through every row.
	for (int row = 0; row < game.numberRows; row++)
	{
		if (theFind.found) { break; } // We break if the word is found so that the program doesn't continue searching.

		// Iterate through every column.
		for (int column = 0; column < game.numberColumns; column++)
		{
			// At this point, we pass the point into our other function fromPoint.
			// fromPoint does the dirty work of checking every direction for us.
			// We update theFind.found every time so that it will be false if we never do find it.
			theFind.found = fromPoint(game, theFind, row, column);
			if (theFind.found)
			{
				// If theFind.found returns true (meaning we found the word), we update theFind wordFind with the point values.
				theFind.row = row;
				theFind.column = column;

				// The direction used gets updated within the fromPoint function so we do not need to repeat it in here.

				// We break out of the program so that it doesn't continue after we've already found the word.
				break;
			}
		}
	}
}

// read the puzzle from the input file and update the wordGame structure.
bool readPuzzle(wordGame &game, string inputFileName)
{
	// Create an ifstream so that we can read from the file.
	ifstream puzzleFile;
	// Open our file so that we can read it.
	puzzleFile.open(inputFileName); 

	game.version = 2; // Set game version.

	if (puzzleFile.is_open()) // Confirm that the file is open to see if we can resume operations.
	{
		// We create these variables in here because it would be a waste of memory doing so outside of this clause.
		string line; // Create line string that we can manipulate it during iterations.
		int row = 0; // Create row int so that we know which row to place letters on and update it as we iterate.
		int maxRow, maxColumn = MAX; // Create maxRow int so we can check for the max row set in file.
									 // Create maxColumn int so we can check for the max column set in file.
		unsigned int i; // We creaete this here so that we can reference it outside of the loop.

		// Get the first line of the file that is supposed to determine rows and columns.
		puzzleFile >> maxRow >> maxColumn;
		// Check that the files present rows and columns that are within our valid range.
		if (!(maxRow > 0 && maxRow < 51) || !(maxColumn > 0 && maxColumn < 51)) 
		{
			// Return false if the range is invalid.
			return false;
		}

		// Iterate through each line in the file
		while (puzzleFile >> line) //(getline(puzzleFile, line))
		{
			// Iterate through each character in the line.
			for (i = 0; i < line.size(); i++)
			{
				//Convert character to uppercase ASCII value, then back to a character.
				// This is kinda a 'hacky' solution because I cannot use global :toupper due to defined 'using namespace std.'
				char upperLetter = toupper(line[i]);

				// Place character into array.
				game.puzzle[row][i] = upperLetter;
			}
			if (i != (unsigned)maxColumn) // Check if i is not equal to the defined range.
			{
				return false; // End program since we're outside of the defined range.
			}
			row++; // Increment the row so that we can place letters into the correct row upon next iteration of loop.
		}

		if (row != maxRow) // Check if current row is not equal to the defined range.
		{
			return false; // End program since we're outside of the defined range.
		}

		game.numberRows = maxRow; // Set rows used.
		game.numberColumns = maxColumn; // Set columns used.

		puzzleFile.close(); // Close the file since we're done using it.
		return true;
	}
	else // If the file failed to open return false.
	{
		return false;
	}
}

// display the contents of the puzzle.
void displayPuzzle(wordGame &game)
{
	// Iterate through each row.
	for (int i = 0; i < game.numberRows; i++)
	{	
		// Iterate through each column.
		for (int j = 0; j < game.numberColumns; j++)
		{
			// Print out the individual character.
			cout << game.puzzle[i][j];
		}
		// End line at the end of each row.
		cout << endl;
	}
}

// Main driver function of the program.
int main()
{
	wordGame wordPuzzle; // Initiate a new wordGame.
	string inputFileName; // We will store, and later push, this value to readPuzzle after the input.

	// Ask for an input puzzle. Mainly for debugging purposes (and it's cleaner).
	//cout << "Please enter your puzzle file name: " << endl;

	// Read an input that looks for the file name for the puzzle.
	cin >> inputFileName; 

	// Read in the puzzle directing the work through the readPuzzle function.
	// Check if it failed to open or not an do operations based on result.
	if (!readPuzzle(wordPuzzle, inputFileName))
	{
		// If failed to open file, output error message.
		cout << "The puzzle file \"" << inputFileName << "\" could not be opened or is invalid" << endl;
	}
	else // readPuzzle succeeded and we can resume with operations.
	{
		// Print out that the puzzle was read.
		cout << "The puzzle from file \"" << inputFileName << "\"" << endl;
		// Run displayPuzzle function to do the operation of displaying the puzzle.
		displayPuzzle(wordPuzzle);

		// Ask for an input for the wordslist. Mainly for debugging purposes (and it's cleaner).
		//cout << "Please enter your wordslist file name: " << endl;

		// Read an input that looks for the file name for the wordslist.
		// We never use inputFileName to display the old inputFileName, thus, we can modify it rather than making a new variable.
		cin >> inputFileName;

		// Create an ifstream so that we can read from the file.
		ifstream wordsFile;
		// Open our file so that we can read it.
		wordsFile.open(inputFileName);

		if (wordsFile.is_open()) // Confirm that the file is open to see if we can resume operations.
		{
			// We create these variables in here because it would be a waste of memory doing so outside of this clause.
			string line; // Create line string that we can manipulate it during iterations.

			// Iterate through each line in the file.
			while (wordsFile >> line) // (getline(wordsFile, line))
			{
				// Convert line to uppercase (This one wasn't fun).
				// I am forced to use std:toupper rather than the global :toupper because of the defined 'using namespace std' which sucks!
				// There might've been another, better, way to do this but I do not have enough C++ experience to know one.
				for (unsigned int i = 0; i < line.size(); i++)
				{
					line.at(i) = toupper(line.at(i)); // Man, this is soooo gross. 
													  // I could've used a transform but I am not too familiar with them just yet.
													  // But how does that old saying go? If it ain't broke, don't fix it!
				}
										  
				wordFind wordToFind; // Initialize a new wordFind.
				wordToFind = {}; // Clear our struct since we're done with it.
				wordToFind.word = line; // Set the word of wordToFind to the uppercase line

				// Call findWord() to attempt to find the word
				findWord(wordPuzzle, wordToFind);

				// Check if the word was found
				if (wordToFind.found)
				{
					cout << "The word " << wordToFind.word << " was found at (" << (wordToFind.row + 1) << ", " << (wordToFind.column + 1) << ") - " << directions[wordToFind.where] << endl;
				}
				else
				{
					cout << "The word " << wordToFind.word << " was not found" << endl;
				}
			}

			wordsFile.close(); // Close the file since we're done using it.
		}
		else
		{
			// If failed to open file, output error message.
			// I think saying "The words file" would be better than "The puzzle file" but that's not up to me to decide.
			cout << "The puzzle file \"" << inputFileName << "\" could not be opened or is invalid" << endl;
		}

	}

	// End program.
	return 0;
}

/* 
* I hope this is enough commentary :)
* It really helps myself, and everyone, understand what is happening.
* I do have to say that it does slow down the development process a fair bit.
* I am actually so happy someone gets to read all of this. 
* There are so many comments that I make while programming and am saddened that no one gets to hear them.
* That saddness is no more! (pls read I beg)
*
* Also, you said that you have to use meaningful variables. For loops, I used i, j, k. I hope that's fine?
* I find loops not needing to use meaningful variables unless there are a lot of things happening within them.
* 
* Also, I sometimes say 'We do this' and 'We do that' because I'm used to commenting within professional team environments.
* I mean 'I' when I say 'We' within this context, it's just a force of habit. Sorry!
*/