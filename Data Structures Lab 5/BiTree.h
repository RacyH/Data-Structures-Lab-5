/*Racy Halterman
* Data Structures Spring 2021
* Due: March 19th
* Lab 5: Binary Tree
* A Binary Tree lab, in which the program creates a binary tree of website names, and is able to display the list in alphabetical order, and reverse
* alphabetical order, and in the order that the tree is.
*/

/***********************
*Just a random note. The required doc says that it should be able to sort in reverse alphabetical order. I was not sure if that meant
*it should print in that order, as one of the methods dictated it should be, or if I should have made a reverse order method that would
* reverse the sorting of the list. I just went with my instinct, which told me that being able to print in reverse alphabetical order
*was enough to qualify.
************************/

#ifndef BITREE_H
#define BITREE_H
#include <iostream>
//#include <queue> was going to use a queue implementation i found to help print, but the way i used was much easier.

using namespace std;

class BiTree
{
private:

	struct node
	{
		node* left;
		node* right;
		string URL;
	};

	node* root;

/*
*Preconditions - Requires iostream and std to be loaded. node needs to be created and passed in. Requires input of a string.
*Postconditions - Returns if the string specified is found inside of the tree.
*/
	bool SearchPrivate(node* root, string u);

/*
*Preconditions - Requires Add() function, iostream, and std to be loaded correctly. Input from where it was called, including a node 
*and a string to add. Requires node struct to be working.
*Postconditions - Adds the string to the correct node so that it is in the correct place.
* Note** Cannot add the same item more than once.
*/
	void AddPrivate(node* root, string u);

/*
*Preconditions - Requires Remove(), iostream, and std to be loaded. Input from where it is called, including a node and a string.
* Also requires the FindMin() to be working correctly. node struct needs to be working.
*Postconditions - Removes the requested string from the tree, and returns the removed node.
*/
	node* RemovePrivate(node* root, string u);

/*
*Preconditions - Requires Print(), iostream, and std. node needs to be working.
*Postconditions - Prints an error statement if there is no item in the list, or prints the list in alphabetical order.
*/
	void PrintPrivate(node* ptr);

/*
*Preconditions - Requires RPrint(), iostream, and std. node needs to be working
*Postconditions - Prints an error statement if there is no item in the list, or prints the list in reverse alphabetical order.
*/
	void RPrintPrivate(node* ptr);

/*
*Preconditions - Requires TPrint(), iostream, and std. node needs to be working.
*Postconditions - Prints an error message if there is no item in the list, or prints the tree in level by level order.
*/
	void TPrintPrivate(node* ptr);

public:

/*
*Preconditions - Requires iostream. Requires node be created, and root node has been created.
*Postconditions - Sets the root node to be null.
*/
	BiTree();

/*
*Preconditions - Requires iostream. also requires Destroy() has been loaded.
*Postconditions - Destructs the tree before leaving the program.
*/
	~BiTree();

/*
*Preconditions - Requires iostream. Root needs to have been created under the struct node.
*Postconditions - Forces PrintPrivate to run, with the input of root.
*/
	void Print() { PrintPrivate(root); };

/*
*Preconditions - Requires iostream and std. Root needs to be created, and an input needs to be given.
*Postconditions - Forces AddPrivate to run, with the input from the user and root as a node.
*/
	void Add(string (data)) { AddPrivate(root, data); };

/*
*Preconditions - Requires iostream and std. Root needs to be created, and an input to be given.
*Postconditions - Forces RemovePrivate to run, with the input from the user and root as a node.
*/
	void Remove(string data) { RemovePrivate(root, data); };

/*
*Preconditions - Requires iostream. Root needs to be created.
*Postconditions - Forces TPrintPrivate to run, with the input of root as a node.
*/
	void TPrint() { TPrintPrivate(root); };

/*
*Preconditions - Requires iostream. Root needs to be created.
*Postconditions - Forces RPrintPrivate to run, with the input of root as a node.
*/
	void RPrint() { RPrintPrivate(root); };

/*
*Preconditions - Requires iostream and std. Requires node to be loaded,and an input from the user.
*Postconditions - Returns a new node containing the input from the user.
*/
	node* CreateNewNode(string data);

/*
*Preconditions - Requires iostream and std. Requires nood to be loaded, and root to be created. Requires an input from the user. Requires SearchPrivate.
*Postconditions - Runs the SearchPrivate function, and returns what that function returns.
*/
	bool Search(string u) { return SearchPrivate(root, u); };

/*
*Preconditions - Requires iostream and node to be loaded.
*Postconditions - Returns the node that is the lowest in the specified side of the tree.
*/
	node* FindMin(node* root);

/*
*Preconditions - Requires iostream. Requires node to be created, and a node to be passed into it. Also requires a number to be passed in.
*Postconditions - Prints the level that is being indicated by the inputted number. Assists with the TPrint functions.
*/
	void printGiven(node* r, int level);

/*
*Preconditions - Requires iostream. Requires node to be created, and a node to be passed in.
*Postconditions - Returns the height of the tree from the root down.
*/
	int height(node* r);

/*
*Preconditions - Requires iostream. node needs to be created, and a node to be passed in.
*Postconditions - iterates through the list, deleting things as it goes. assists the destructor.
*/
	void Destroy(node* r);
};

#endif //BITREE_H