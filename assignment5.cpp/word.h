/*
 * word.h
 *
 *  Created on: Dec 7, 2018
 *      Author: Mike Xie
 *      Purpose: word will help keep track of the answer keys for matching
 */

#ifndef WORD_H_
#define WORD_H_

#include <algorithm>
#include <vector>
#include <string>

class word
{
public:
	//holds the key
	std::string data;
	//holds the key
	std::vector<std::string> dataList;
	//default Constructor
	word();
	//constructor that adds stuff to the dataList
	word(std::string word);
	//checks if it is found
	static void found(const word &item);
	//converts data to something that can be stored in a binary search tree
	std::string dataConverter(std::string word);

	//adds in new answers
	static void wordUpdate(word &existing, const word &newWord);

	//compares words and data
	bool operator<(const word other) const
	{
		return data < other.data;
	}
	//compares words and data
	bool operator>(const word other) const
	{
		return data > other.data;
	}
	//compares words and data
	bool operator==(const word other)const
	{
		return data == other.data;
	}
	//outputs word
	friend std::ostream& operator<<(std::ostream &out, const word &outputWord);
	//adds new word to the dataList
	void update(const word other);
};



#endif /* WORD_H_ */
