/*Racy Halterman
* Data Structures Spring 2021
* Due: March 19th
* Lab 5: Binary Tree
* A Binary Tree lab, in which the program creates a binary tree of website names, and is able to display the list in alphabetical order, and reverse
* alphabetical order.
*/

#include "BiTree.h"

BiTree::BiTree()
{
	root = NULL; //simple and easy.
}

BiTree::~BiTree()
{
	Destroy(root); //destroys the tree with the root as the base.
}

void BiTree::AddPrivate(node* r, string u)
{
	if (r == NULL)
	{
		root = CreateNewNode(u); //creates the node with the input
	}
	else if(u < r->URL) //if it is less than, meaning if it comes before the current node, alphabetically.
	{
		if (r->left != NULL)
		{
			AddPrivate(r->left, u); //recursive.
		}
		else
		{
			r->left = CreateNewNode(u); //creates the node if it belongs here.
		}
	}

	else if (u > r->URL) //if it comes after the current node alphabetical;y.
	{
		if (r->right != NULL)
		{
			AddPrivate(r->right, u); //same as before. recursive. adds it to the right if the right is null and it comes after that url
		}
		else
		{
			r->right = CreateNewNode(u);
		}
	}
	else
	{
		cout << u << " already exists in the tree.\n"; //if it already exists in the tree.
	}

}

BiTree::node* BiTree::RemovePrivate(node* root, string u)
{
	if (root == NULL) { return root; } //returns the node if it is null.
	else if (u < root->URL) { RemovePrivate(root->left, u); } //recursive. calls itself back until it returns something equal to input
	else if(u > root->URL) { RemovePrivate(root->right, u); } //recursive.
	else
	{
		if (root->left == NULL && root->right == NULL) //if the node returns as null for both right and left
		{
			delete root; //deletes root, sets it to null, and returns null as value.
			root = NULL;
			return root;
		}
		else if (root->left == NULL) //if there is nothing on the left
		{
			node* temp = root; //creates new node, sets it to the inputted node, sets the inputted node to the one next to it. deletes temp, returns the new node. moves things up.
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL) //nothing on the right.
		{
			node* temp = root;//i don't think i need to go through all of this.
			root = root->left;
			delete temp;
			return root;
		}
		else
		{
			node* temp = FindMin(root->right); //goes through, finds the smallest object on the right, looks to delete that node.
			root->URL = temp->URL;
			RemovePrivate(root->right, temp->URL);
		}
	}
}

void BiTree::PrintPrivate(node* ptr) //a lot of these are private, because you cannot call nodes from the main function.
{
	if (root == NULL) //tree is empty.
	{
		cout << "This tree is empty.\n";
		cout << "Yeet!\n";//as per Mina's request
		return;//I showed Mina this code, she asked me to put it in, "Yeet!" is now in the code.
	}
	else if(root != NULL) //If there is something in the tree.
	{
		if (ptr->left != NULL)
		{
			PrintPrivate(ptr->left); //recursive
		}
		cout << ptr->URL << ' '; //outputs the left hand side of the branch before the right.
		if (ptr->right != NULL)
		{
			PrintPrivate(ptr->right);
		}
	}
}

void BiTree::TPrintPrivate(node* ptr)
{
	if (root == NULL) //same as beginning of last print function.
	{
		cout << "This tree is empty.\n";
		cout << "Yeet!\n";
		return;
	}
	int h = height(ptr); //finds height of the bottom of the tree to the root
	for (int i = 0; i <= h; i++)
	{
		printGiven(ptr, i); //prints the URLs of the pointers in the given level
	}
}

void BiTree::RPrintPrivate(node* ptr) //Complete opposite of the Print function
{
	if (root == NULL)//empty tree
	{
		cout << "This tree is empty.\n";
		cout << "Yeet!\n";
		return;
	}
	else if (root != NULL)//not empty tree.
	{
		if (ptr->right != NULL)
		{
			PrintPrivate(ptr->right);//recursive. opposite of the print function. prints right side of the tree first.
		}
		cout << ptr->URL << ' ';
		if (ptr->left != NULL)
		{
			PrintPrivate(ptr->left);
		}
	}
}

BiTree::node* BiTree::CreateNewNode(string data) //creates new node, returns new node to the add function.
{
	node* temp1 = new node; //new node is saved in a temp node, then returned to the tree.
	temp1->URL = data;
	temp1->left = NULL;
	temp1->right = NULL;

	return temp1;
}

bool BiTree::SearchPrivate(node* root, string u) //searches in the tree for the inputted string
{
	if (root == NULL) return false; //tree is empty
	if (root->URL == u) return true; //returns if it is found
	else if (u > root->URL) return SearchPrivate(root->right, u); //returns whether it is true or false if its in the right side of the tree
	else return SearchPrivate(root->left, u); //left side of the tree
}

BiTree::node* BiTree::FindMin(node* root)//finds the minimum value. used in the delete function.
{
	if (root == NULL) //empty tree.
	{
		return root;
	}
	while (root->left != NULL)
	{
		root = root->left; //only needs the minimum value, so only looks from the left side of the inputted node
	}
	return FindMin(root->left);
}

void BiTree::printGiven(node* r, int level) //helps to print the tree.
{
	if (r == NULL)//empty tree. returns void if it is empty.
		return;
	else if (level == 0) //iterates over tree, printing the tree.
		cout << r->URL << ' ';
	else // level > 0  
	{
		cout << endl; //enter between the different levels.
		printGiven(r->left, level - 1);
		printGiven(r->right, level - 1);
	}
}

int BiTree::height(node* r) //finds height of the node.
{
	if (r == NULL)
	{
		return -1;
	}
	int lheight = height(r->left);
	int rheight = height(r->right);
	if (lheight >= rheight) //if they are equal, this bad boy would hit the fritz. so this little >= sign saved the day.
	{
		return (lheight + 1);
	}
	else //between these two, returns the greates height of the sides of the tree.
	{
		return (rheight + 1);
	}
}

void BiTree::Destroy(node* r) //goes through and deletes all of the nodes involved.
{
	if (r != NULL)
	{
		if (r->left != NULL)
		{
			Destroy(r->left);
		}
		if (r->right != NULL)
		{
			Destroy(r->right);
		}
		delete r;
	}
}