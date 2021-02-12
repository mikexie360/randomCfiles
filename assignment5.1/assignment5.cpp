/*
 * assignment5.cpp
 *
 *  Created on: Dec 7, 2018
 *      Author: Mike Xie
 *      Purpose: sees if the random letters will make a word if you rearange theletters
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string>

#include "BinarySearchTree.h"
#include "word.1.h"

//This is called to perform the necessary tests on the Binary Search Tree
void testBinarysearchtree();

int main()
{
    testBinarysearchtree();
}

void testBinarysearchtree()
{
    BinarySearchTree<Word> english;
    std::string currentlined;
    std::ifstream dictionary;
    dictionary.open("english_words.txt");//going to be used to create the binary search tree


    // Runs the loop as many times as there are lines in the input.txt file
    while (getline(dictionary, currentlined))
    {
        Word nextinline(currentlined);
        english.insert(nextinline, &english.update);//This should create a BinarySearchTree entry
    }


    //At this point I should have a fully qualified Binary Search Tree
    //Next I will begin to test all of the necessary functionality to ensure that the functions work as specified
    std::cout << "Test of find words " << std::endl;
    std::cout << "The dictionary has been built with 32194 keys in the dictionary"<< std::endl;


    //In this segment we will allow for the user to search for an entry by entering in what will become a key
    std:: string theirchoice;
    std::cout<<"If you want to search for some item by key enter y"<<std::endl;
    std::cin>>theirchoice;
    while(theirchoice=="y")
    {
        std::string uword;
        std::cout << "Enter in a key for the word you are looking for" << std::endl;
        std::cin >> uword;
        const Word userword(uword);
        english.find(userword, &english.processFound);
        std::cout<< "skey size: "<< userword.skey.size() << "\n";
        std::cout<< "value size: "<< userword.value.size() << "\n";
        std::cout<<"Search again? Enter y"<<std::endl;
        std::cin>>theirchoice;
    }


    //Now we can erase absolutely everything
    english.~BinarySearchTree();


    //This will prove that nothing is left
    english.print();
    dictionary.close();
}
