/*
 * assignment5.cpp
 *
 *  Created on: Dec 7, 2018
 *      Author: Mike Xie
 *      Purpose: tells the user what the answers are to the scrambled words.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "binarySearchTree.h"
#include "word.h"

int main()
{
	//creates a binary search tree
	binarySearchTree<word> answerKey = binarySearchTree<word>();

	//opens files to read and write into
	std::ifstream input("english_words.txt");

	std::string in;

	//reads in all the words with the answerKey
	while(input>>in)
	{
		answerKey.insert(word(in), update);
	}
	//if unable to read file, program will end
	if(!input.eof())
	{
		std::cout<<"Unable to read files.\n";
		return 0;
	}

	//introduction to the program for the user
	std::cout<<"Test of find words\n";
	std::cout <<"\n";
	std::cout<<"The dictionary has been built with "<< answerKey.size() <<" keys in the dictionary\n";
	//loops until "quit-now"
	while(true)
	{
		//program's instructions to user.
		std::cout<<"Word to unscramble (quit-now to stop): \n";
		//get input from user
		std::cin>>in;
		std::cout <<"\n";
		//ends the program if user inputs "quit-now"
		if(in.compare("quit-now")==0)
		{
			break;
		}

		//program's output in response to the user
		std::cout << "Scrambled word ";
		std::cout <<in;

		bool foundIt = answerKey.find(word(in), &word::found);

		//if word was not found. if found then output it
		if(!answerKey.find(word(in), output))
		{
			std::cout<<" was not found";
		}
		std::cout<<"\n";
	}
	answerKey.print();
	return 0;
}
