/*
 * word.cpp
 *
 *  Created on: Dec 7, 2018
 *      Author: Mike Xie
 *      Purpose: word will help keep track of the answer keys for matching
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "word.h"

//default constructor
word::word()
{
		data = "";
		dataList = std::vector<std::string>();
}

//constructor that takes in stuff for dataList. word will be sorted
word::word(std::string word)
{
	dataList.push_back(word);
	data = dataConverter(word);
}

//converts data into something that can be used to find the answers
std::string word::dataConverter(std::string word)
{
	//turns a word into a word with lower case letter
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	//sorts the word in order
	std::sort(word.begin(), word.end());
	//returns a sorted word
	return word;
}

//checks if there is more than one solution and outputs what it needs
void word::found(const word &item)
{
	//if there is more than one answer
	if(item.dataList.size() > 1)
	{
		std::cout <<" maps to words: ";
	}
	//if there is only one answer
	else if (item.dataList.size() == 1)
	{
		std::cout <<" maps to word: ";
	}
	//if there is no answer
	//hopefully this will never happen
	else
	{
		std::cout << " nothing ";
	}
}

//adds a new solution to the vector
void word::wordUpdate(word &existing, const word &newWord)
{
	existing.dataList.push_back(newWord.dataList[0]);
}

//Searches a vector for the specified value:
//returns true if found otherwise false.
//is needed for the update function.
bool inray(std::vector<std::string> v, std::string x)
{
	return (std::find(v.begin(), v.end(), x) != v.end());
}

//adds new value to the dataList vector if not already in the vector
void word::update(const word other)
{
	for(std::string val : other.dataList)
	{
		if(!inray(dataList, val))
			dataList.push_back(val);
	}
	std::sort(dataList.begin(),dataList.end());
}

//outputs the Word in the format specified
std::ostream& operator<<(std::ostream &out, const word &outputWord)
{
	for(std::string val : outputWord.dataList)
		out << val << " ";
	return out;
}
