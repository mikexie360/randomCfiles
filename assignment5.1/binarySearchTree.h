/*
 * binarySearchTree.h
 *
 * Created on: Dec 9, 2018
 * 		Author: Mike Xie
 * 		Purpose: A binary search tree to more easily search for answer keys or matches
 *
 * 		Some of the functions were borrowed from the textbook on Cengage
 */

#ifndef PROJECT5EC_BINARYSEARCHTREE_H
#define PROJECT5EC_BINARYSEARCHTREE_H
#include <string>
#include <iostream>
#include<algorithm>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>

// forward declaration of the template class BinarySearchTree
template<class DataType>
class BinarySearchTree;

// TreeNode classe
template <class DataType>
class TreeNode
{
    friend class BinarySearchTree<DataType>;
private:
    // Data members
    DataType key;         // Binary search tree data item
    TreeNode <DataType>*left;//Pointer to the left node
    TreeNode <DataType>*right;//Pointer to the right node
// the rest of the TreeNode classs declaration goes here
public:
    //Default Constructor
    inline TreeNode ()
    {
        //key;
        left=nullptr;
        right=nullptr;
    }
    //Copy Constructor
    inline TreeNode ( const DataType &nodeDataItem, TreeNode *leftPtr, TreeNode *rightPtr )
    {
        key= nodeDataItem;
        left=leftPtr;
        right=rightPtr;
    }

};



// BinarySearchTree class
template <class DataType>
class BinarySearchTree
{
// Your BinarySearchTree goes here
private:
    int numberNodes;
    TreeNode<DataType>*root;//Root pointer
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &other);
    virtual ~BinarySearchTree();
    void destroy(TreeNode<DataType>* &p);
    bool empty() const;
    std::size_t size() const;
    void print() const;
    void debug(std::ostream &out) const;
    bool find(const DataType &searchItem, void (*foundNode)(const DataType&));
    static void processFound(const DataType &item);
    bool erase(const DataType &deleteItem);
    void insert(const DataType &newItem);
    void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem));
    static void update(DataType &exsitingItem, const DataType &newItem);
    void traverse(void (*itemFound)(const DataType& foundItem)) const;
    void printTree(TreeNode<DataType>* node) const;
    void copyTree(TreeNode<DataType>* &copiedTreeRoot, TreeNode<DataType>* otherTreeRoot);
    void deleteFromTree (TreeNode<DataType>* &p);
    void inorder(TreeNode<DataType> *p) const;
    void inorder2(TreeNode<DataType> *p) const;
};

template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree()//Default Constructor
{
    root = nullptr;
    numberNodes=0;
}

template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree &other)//Copy Constructor
{
    if (other.root == nullptr) //otherTree is empty
    {
    	root = nullptr;
    	numberNodes++;
    }
    else
        copyTree(root, other.root);
}

template <class DataType>
BinarySearchTree<DataType>::~BinarySearchTree()//This is the destructor
{
    destroy(root);
}

template <class DataType>
void BinarySearchTree<DataType>::processFound(const DataType &item)//Static function to use with find function
{
    std::cout << "The word/words found are: "<<std::endl;
}

template <class DataType>
void BinarySearchTree<DataType>::destroy(TreeNode<DataType>* &p)//This will destroy an entire Binary Search Tree
{
    if (p != nullptr)
    {
        numberNodes--;
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}

//Pretty self explanatory. Does a deep copy of the tree that is being passed in.
template <class DataType>
void BinarySearchTree<DataType>::copyTree(TreeNode<DataType>* &copiedTreeRoot, TreeNode<DataType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new TreeNode<DataType>;
        copiedTreeRoot->key = otherTreeRoot->key;
        numberNodes= numberNodes+2;
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
    }
} //end copyTree

//This goes ahead and checks if the BinarySearchTree is empty or not
template <class DataType>
bool BinarySearchTree<DataType>::empty() const //WORKS
{
    if(root== nullptr)
        return true;
    else
        return false;
}

//Gives us the size of the Binary Search Tree
template <class DataType>
std::size_t BinarySearchTree<DataType>::size() const
{
    return numberNodes;
}

template <class DataType>
void BinarySearchTree<DataType>::print() const//Prints the entire content of the Binary Search Tree
{
    if (root == nullptr)
        return;
    else
    {
        printTree(root);
    }
}

template <class DataType>
void BinarySearchTree<DataType>::printTree(TreeNode<DataType>* node) const//Prints one of the entries
{
    if (node == nullptr) return;
    printTree(node->left);
    std::cout<< node->key<<std::endl;
    printTree(node->right);
}


template <class DataType>
void BinarySearchTree<DataType>::debug(std::ostream &out) const//Prints certain information of the Binary Search Tree
{
    out << "START DEBUG" << std::endl;
    out << "# nodes=" << size() << std::endl;
    inorder2(root);
    //print();
    out << "END DEBUG" << std::endl;
}

//Tries to find the entry in the binary search tree
template <class DataType>
bool BinarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType&))
{
    TreeNode<DataType> *current;
    int count=0;
    bool found = false;
    if (root == nullptr)
        std::cout << "Cannot search an empty tree." << std::endl;
    else
    {
        current = root;
        while ((current != nullptr && !found ))//
        {
            if (current->key >= searchItem)//I want this to test the keys not names
            {

                found = true;
                foundNode(searchItem);
                std::cout << current->key << std::endl;
            }
            else if (current->key > searchItem)
                current = current->left;
            else
                current = current->right;
            count++;
        }//end while
    }//end else
    return found;
}//end


template <class DataType>
bool BinarySearchTree<DataType>::erase(const DataType &deleteItem)//erases a node from the Binary Search Tree
{
    TreeNode<DataType> *current; //pointer to traverse the tree
    TreeNode<DataType> *trailCurrent; //pointer behind current
    bool found = false;
    if (root == nullptr)
        std::cout << "Cannot delete from an empty tree." << std::endl;
    else
    {
        current = root;
        trailCurrent = root;
        while (current != nullptr && !found)
        {
            if (current->key == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->key > deleteItem)
                    current = current->left;
                else
                    current = current->right;
            }
        }//end while
        if (current == nullptr)
            std::cout << "The item to be deleted is not in the tree."<< std::endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->key > deleteItem)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }
        else
            std::cout << "The item to be deleted is not in the tree." << std::endl;
    }
    return found;
} //end deleteNode


template <class DataType>
void BinarySearchTree<DataType>::deleteFromTree (TreeNode<DataType>* &p)//delete an entry from the Binary Search Tree
{
    TreeNode<DataType> *current; //pointer to traverse the tree
    TreeNode<DataType> *trailCurrent; //pointer behind current
    TreeNode<DataType> *temp; //pointer to delete the node
    if (p == nullptr)
        std::cout << "Error: The node to be deleted does not exist." << std::endl;
    else if (p->left == nullptr && p->right == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->left == nullptr)
    {
        temp = p;
        p = temp->right;
        delete temp;
    }
    else if (p->right == nullptr)
    {
        temp = p;
        p = temp->left;
        delete temp;
    }
    else
    {
        current = p->left;
        trailCurrent = nullptr;
        while (current->right != nullptr)
        {
            trailCurrent = current;
            current = current->right;
        }//end while
        p->key= current->key;
        if (trailCurrent == nullptr) //current did not move;
//current == p->lLink; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;
        delete current;
    }//end else
    numberNodes--;
} //end deleteFromTree

template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem)//Insert an organized item into the Binary Search Tree
{
    TreeNode<DataType> *current; //pointer to traverse the tree
    TreeNode<DataType> *trailCurrent; //pointer behind current
    TreeNode<DataType> *newNode; //pointer to create the node
    newNode = new TreeNode<DataType>;
    newNode->key = newItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (root == nullptr)
    {
        root = newNode;
        numberNodes++;
    }
    else
    {
        current = root;
        while (current != nullptr)
        {
            trailCurrent = current;
            if (current->key == newItem)
            {
                // std::cout << "The item to be inserted is already ";
                // std::cout << "in the tree -- duplicates are not " << "allowed." << std::endl;
                // std::cout << newItem << std::endl;
                update(current->key,newItem);
                return;
            }
            else if (current->key > newItem)
                current = current->left;
            else
                current = current->right;
        }//end while
        if (trailCurrent->key > newItem)
        {
            trailCurrent->left = newNode;
            numberNodes++;
        }
        else
        {
            trailCurrent->right = newNode;
            numberNodes++;
        }
    }
}

//Insert an item into the Binary Search Tree and "update" the given entry if certain qualifications take place
template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem))
{
    TreeNode<DataType> *current; //pointer to traverse the tree
    TreeNode<DataType> *trailCurrent; //pointer behind current
    TreeNode<DataType> *newNode; //pointer to create the node
    newNode = new TreeNode<DataType>;
    newNode->key = newItem;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (root == nullptr)
    {
        root = newNode;
        numberNodes++;
    }
    else
    {
        current = root;
        while (current != nullptr)
        {
            trailCurrent = current;
            if (current->key == newItem)//
            {
                duplicateItemFound(current->key, newItem);
                return;
            }
            else if (current->key > newItem)
                current = current->left;
            else
                current = current->right;
        }//end while
        if (trailCurrent->key > newItem)
        {
            trailCurrent->left = newNode;
            numberNodes++;
        }
        else
        {
            trailCurrent->right = newNode;
            numberNodes++;
        }
    }
}

template <class DataType>
void BinarySearchTree<DataType>::update(DataType &exsitingItem, const DataType &newItem)
{
    exsitingItem<=newItem;
}

//we will find the entries one by one and print them. That in theory is a traversal
template <class DataType>
void BinarySearchTree<DataType>::traverse(void (*itemFound)(const DataType& foundItem)) const
{
    inorder(root);
}

//This prints the tree starting from the given TreeNode
template <class DataType>
void BinarySearchTree<DataType>::inorder(TreeNode<DataType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->left);
        std::cout << p->key;
        inorder(p->right);
    }
}

template <class DataType>
void BinarySearchTree<DataType>::inorder2
        (TreeNode<DataType> *p) const
{
    std::ofstream outputfile;
    outputfile.open("pointerval.txt");
    if (p != nullptr)
    {
        inorder2(p->left);
        outputfile <<"The memory location is: "<< p << " "<< std::endl;
        inorder2(p->right);
    }
    outputfile.close();
}

#endif //PROJECT5EC_BINARYSEARCHTREE_H
