/**
 * CS 2336 - 002
 * assignment1.cpp
 * Purpose: Finds all the possible words that are in the word puzzle
 * from a list of words.
 *
 * @author	Mike Xie
 * @version 9/18/2018
*/

//Do not mess with the header files
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

//All possible directions a word can be found in the puzzle
enum direction {LEFT_RIGHT, RIGHT_LEFT, DOWN, UP, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};

//Maximum and minimum values of rows and columns.
const int MAX = 50;
const int MIN = 1;

//The puzzle data will be inputed in this structure
struct wordGame
{
	int version = 2;											//Do not touch this, very important
	int numberRows;												//Number of rows of the puzzle
	int numberColumns;											//Number of columns of the puzzle
	char puzzle[MAX][MAX];										//2D array of the puzzle
};

//Word to be found, if it is found, where it is found and direction of where it is found will be inputed in this structure
struct wordFind
{
	string word = "";											//String of the puzzle
	bool found = false;											//Determines if the puzzle is found
	int row = 0;												//What row the puzzle is found in
	int column = 0;												//What column the puzzle is found in
	direction where;											//What direction the puzzle is found in
};

/**
 * Reads in the puzzle file.
 *
 * @param &game contains number of rows, number of columns and the 2D puzzle
 * will be stored.
 *
 * @param inputFileName the file of the puzzle to be used.
 *
 * @return whether or not the file can be opened.
 */
bool readPuzzle(wordGame &game, string inputFileName);

/*
 * Outputs the puzzle
 *
 * @param &game contains the puzzle.
 */
void displayPuzzle(wordGame &game);

/*
 * Finds where the word is in the puzzle
 * and tells the direction.
 *
 * @param &game contains the version, number of rows and columns and the puzzle.
 *
 * @param &theFind contains the word to be found, whether or not the word was found
 * where it was found and the direction.
 */
void findWord(wordGame &game, wordFind &theFind);

// Controls operation of the program.
int main()
{

	//Instantiates wordGame
	wordGame firstGame;

	//Instantiates wordFind
	wordFind find;
	find.where = LEFT_RIGHT;

	string puzzleName;      //file variable name for word puzzle.
	string wordsInput;      //file variable name for words to be found.
	cin >> puzzleName;      //user input of the word puzzle file.

	/**
	 * if readPuzzle cannot find the word puzzle file or word puzzle file does not work, then returns false and program terminates
	 *
	 * if readPuzzle finds a proper word puzzle file, then return true and firstGame stores the 2D word puzzle
	*/
	if(!readPuzzle(firstGame, puzzleName))
	{
		cout << "The puzzle file \"" << puzzleName << "\" could not be opened or is invalid" << endl;
		return 0;
	}
	else
	{
		cout << "The puzzle from file \"" << puzzleName << "\"" << endl;
	}

	//Displays word puzzle from firstGame.
	displayPuzzle(firstGame);

	//User input for the file that has the words to be searched
	cin >> wordsInput;

	//Checks to see if words file is found, if not then terminate program.
	ifstream ifs(wordsInput);
	if(!ifs)
	{
		cout << "The puzzle file \"" << wordsInput << "\" could not be opened or is invalid" << endl;
		return 0;
	}

	//Looks at the first line of the file that has words
	ifs >> find.word;

	/*
	* Until the end of the file, search for the words in words file.
	* If the word is found, output the word, where the word was found and the direction.
	* If the word cannot be found, output the word and that it cannot be found.
	*/
	while(ifs)
	{
		find.found = false;												// find.found is automatically set to false

		//Rewrites the word to upper case.
		string lowerCase = "";											//gets find.word and will be turns it into upper case
		string upperCase = "";											//will finally have all upper case characters when it is done
		int asciiValue = '0';											//ASCII value of lowerCase characters
		lowerCase = find.word;											//lowerCase is same as find.word now
		int index = 0;													//keeps track of the of string index.
		while (lowerCase[index])
		{
		    if ( lowerCase[index] >= 97 && lowerCase[index] <= 122)		//Checks if a lower case character is found
		    {
		    	asciiValue = lowerCase[index];							//Gets the ASCII value of the lower case character
		    	asciiValue = (asciiValue % 97) + 65;					//Converts the ASCII value of the lower case character value to a upper case character value
		    	lowerCase[index] = asciiValue;							//lowerCase gets the upper case character value
		    	upperCase += lowerCase[index];							//upperCase gets the upper Case character value
		    }
		    else
		    {
		    	upperCase += lowerCase[index];							//upperCase gets the upper case character value if lowerCase had an upper case character at the index in the first place
		    }
		    index++;
		}
		find.word = upperCase;											//find.word now has upper case characters

		//determines if the word can be found, where it was found in and what direction it was found in.
		findWord(firstGame, find);
		if(find.found)
		{
			if(find.where == LEFT_RIGHT)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - right" << endl;
			}
			else if(find.where == RIGHT_LEFT)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - left" << endl;
			}
			else if(find.where == DOWN)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - down" << endl;
			}
			else if(find.where == UP)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - up" << endl;
			}
			else if(find.where == RIGHT_DOWN)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - right/down" << endl;
			}
			else if(find.where == RIGHT_UP)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - right/up" << endl;
			}
			else if(find.where == LEFT_DOWN)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - left/down" << endl;
			}
			else if(find.where == LEFT_UP)
			{
				cout << "The word " << find.word << " was found at " << "(" << find.row << ", " << find.column << ")" << " - left/up" << endl;
			}
		}
		else
		{
			cout << "The word " << find.word << " was not found" << endl;
		}

		ifs >> find.word;
	}

	ifs.close();
	return 0;
}

// Reads in the puzzle file.
bool readPuzzle(wordGame &game, string inputFileName)
{
	//Opens the puzzle file
	ifstream ifs(inputFileName);
	if(!ifs)
	{
		ifs.close();
		return false;
	}

	//file inputs the row and col variables
	int row, col;
	ifs >> row >> col;

	//Checks to see if the rows and columns in the file are between the valid integers of 1 through 50.
	if ( (row > MAX || row < MIN) || (col > MAX || col < MIN) )
	{
		ifs.close();
		return false;
	}

	//firstGame stores the rows and columns of the file.
	game.numberRows=row;
	game.numberColumns=col;

	//Writes the 2D puzzle file into firstGame
	for ( int i = 0; i < row; i++)										//i is row number
	{
		for ( int j = 0; j< col; j++)									//j is column number
		{
			ifs >> game.puzzle[i][j];									//game.puzzle gets a character from ifs
		}
	}

	//Checks if the puzzle has the correct amount of elements from row and columns
	int countOfElements = 0;											//Counter for number of elements in game.puzzle
	for ( int i = 0; i < row; i++)										//i is row number
	{
		for ( int j = 0; j < col; j++)									//j is column number
		{
			if ( game.puzzle[i][j] >=65 && game.puzzle[i][j] <= 122)	//ASCII values of game.puzzle element must be between values of 65 and 122 to be a valid element
			{
				countOfElements++;
			}
		}
	}
	if ( row * col != countOfElements)									//Checks to see if all rows and columns in game.puzzle is correctly inputted.
	{
		return false;
	}

	//Rewrites the puzzle to upper case
	for( int i = 0; i < row; i++)										//i is the row number
	{
		for ( int j = 0; j < col; j++)									//j is the column number
		{
			if(game.puzzle[i][j] >= 97 && game.puzzle[i][j] <= 122)		//Checks to see if a character in the puzzle is lower case
			{
				int asciiValue = game.puzzle[i][j];						//asciiValue gets the ASCII value of a lower case char value of game.puzzle
				asciiValue = (asciiValue % 97) + 65;					//ASCII value is converted to upper case char value
				game.puzzle[i][j] = asciiValue;							//game.puzzle gets the upper case char value
			}
		}
	}

	ifs.close();
	return true;
}

//Outputs the puzzle
void displayPuzzle(wordGame &game)
{
	//Outputs the file from firstGame line by line
	for (int i = 0; i < game.numberRows; i++)						//i is the row number
	{
		for( int j = 0; j < game.numberColumns; j++)				//j is the column number
		{
			cout << game.puzzle[i][j];								//Outputs the puzzle one by one
		}
		cout << endl;
	}
}

// Finds where the word is in the puzzle and tells the direction.
void findWord(wordGame &game, wordFind &theFind)
{

	/*
	 * For the entire rest of this function ---------------------------------------------------------------------------------
	 * |
	 * | i will be the row of the 2D puzzle.
	 * | j will be the column of the 2D puzzle.
	 * | --------------------------------------------------------------------------------------------------------------------
	 * |
	 * | If the first letter of the word to be searched for is found within the puzzle --------------------------------------
	 * | |
	 * | | 'check' string will be created to see if the word that is found is equivalent to the word that is to be searched for
	 * | | m will be the row to be moved if needed according to direction.
	 * | | l will be the column to be moved if needed according to direction.
	 * | | k will limit the 'check' string's length.
	 * ----------------------------------------------------------------------------------------------------------------------
	 */

	//cast a signed int length from theFind.word.length() to do signed arithmetic
	int wordLength = static_cast<int>(theFind.word.length());

	//checks for LEFT_RIGHT
	for(int i = 0; i < game.numberRows; i++)
	{
		for ( int j = 0; j <= game.numberColumns - wordLength; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0, l = j; k < theFind.word.length(); k++, l++)
				{
					check += game.puzzle[i][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = LEFT_RIGHT;
				}
			}
		}
	}

	//checks for RIGHT_LEFT
	for(int i = 0; i < game.numberRows; i++)
	{
		for ( int j = wordLength - 1; j < game.numberRows; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0, l = j; k < theFind.word.length(); k++, l--)
				{
					check += game.puzzle[i][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = RIGHT_LEFT;
				}
			}
		}
	}

	//checks for DOWN
	for(int i = 0; i <= game.numberRows - wordLength; i++)
	{
		for ( int j = 0; j < game.numberColumns; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0, m = i; k < theFind.word.length(); k++, m++)
				{
					check += game.puzzle[m][j];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = DOWN;
				}
			}
		}
	}

	//checks for UP
	for(int i = wordLength - 1; i < game.numberRows; i++)
	{
		for ( int j = 0; j < game.numberColumns; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0, m = i; k < theFind.word.length();k++, m--)
				{
					check += game.puzzle[m][j];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = UP;
				}
			}
		}
	}

	//checks for RIGHT_DOWN
	for(int i = 0; i <= game.numberRows - wordLength; i++)
	{
		for ( int j = 0; j <= game.numberColumns - wordLength; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0, l = j, m = i; k < theFind.word.length();k++, l++, m++)
				{
					check += game.puzzle[m][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = RIGHT_DOWN;
				}
			}
		}
	}

	//checks for RIGHT_UP
	for(int i = wordLength - 1; i < game.numberRows; i++)
	{
		for ( int j = 0; j <= game.numberColumns - wordLength; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0,l = j, m = i; k < theFind.word.length();k++, m--, l++)
				{
					check += game.puzzle[m][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = RIGHT_UP;
				}
			}
		}
	}

	//checks for LEFT_DOWN
	for(int i = 0; i < game.numberRows; i++)
	{
		for ( int j = wordLength - 1; j < game.numberColumns; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0,l = j, m = i; k < theFind.word.length();k++, m++, l--)
				{
					check += game.puzzle[m][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = LEFT_DOWN;
				}
			}
		}
	}

	//checks for LEFT_UP
	for(int i = wordLength - 1; i < game.numberRows; i++)
	{
		for ( int j = wordLength - 1; j < game.numberColumns; j++)
		{

			//found the first letter of the word to be searched for
			if(theFind.word.at(0) == game.puzzle[i][j])
			{

				//instantiates a string to check against the word to be searched for
				string check = "";

				//creates the 'check' string from the 2D puzzle
				for(int k = 0,l = j, m = i; k < theFind.word.length();k++, m--, l--)
				{
					check += game.puzzle[m][l];
				}

				//checks to see if the 'check' string is the same as the word to be searched for
				if ( check == theFind.word)
				{

					//The word was found, where it was found and the direction.
					theFind.found = true;
					theFind.row = i + 1;
					theFind.column = j + 1;
					theFind.where = LEFT_UP;
				}
			}
		}
	}
}

