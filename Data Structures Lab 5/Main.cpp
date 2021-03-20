/*Racy Halterman
* Data Structures Spring 2021
* Due: March 19th
* Lab 5: Binary Tree
* A Binary Tree lab, in which the program creates a binary tree of website names, and is able to display the list in alphabetical order, and reverse
* alphabetical order.
*/
#include "BiTree.h"

void menu();
void addurl();
void deleteitem();
void printreg();
void printrev();
void printtree();
void searchtree();

BiTree tree1;

int main()
{
	char item;

	system("cls"); //clears the screen.

	menu();
	cin >> item;
	switch (item)
	{
	case 'A': addurl();
		break;
	case 'a': addurl();
		break;
	case 'D': addurl();
		break;
	case 'd': addurl();
		break;
	case 'P': printreg();
		break;
	case 'p': printreg();
		break;
	case 'R': printrev();
		break;
	case 'r': printrev();
		break;
	case 'T': printtree();
		break;
	case 't': printtree();
		break;
	case 'S': printtree();
		break;
	case 's': printtree();
		break;
	case 'E': cout << "Thank you for choosing Vault-Tec, have a nice day!\n";
		return 0;
		break;
	case 'e': cout << "Thank you for choosing Vault-Tec, have a nice day!\n";
		return 0;
		break;
	default: cout << "There was an error.\n";
		break;
	}
	main();//did not need to do this. but I did anyway.
}

/*
*Preconditions - Requires iostream.
*Postconditions - Outputs the menu items to the screen so that the user has a menu to choose from.
*/
void menu()
{
	cout << "...\n";
	cout << "Welcome to Vault-Tec's very own Binary Tree sorting system.\n";//little bit of humor for you. Don't tell Bethesda or Microsoft..
	cout << "View the Menu below, and choose the letter corresponding to the action you would like to take.\n\n";
	cout << "Add Item\tA\n";
	cout << "Delete Item\tD\n";
	cout << "Print List\tP\n";
	cout << "Print Reverse\tR\n"; //simple menu to traverse.
	cout << "Print Tree\tT\n";
	cout << "Search Tree\tS\n";
	cout << "Exit Program\tE\n";
}

/*
*Preconditions - Requires std and iostream. Requires "BiTree.h" to be loaded, and Add functions to be working correctly.
*Postconditions - Outputs a basic message, asking what the user wants to add to the tree, then adds it.
*/
void addurl()
{
	string url;
	char ex;
	cout << "Type in the URL you would like to add.\n";
	cout << "Remember that URL's do not have spaces in them.\n"; //easy to use.
	cin >> url;
	tree1.Add(url);
	cout << "The URL has been added correctly, if it did not already exist.\n";//user-friendly
	cout << "Press any letter, followed by enter, to exit.\n";
	cin >> ex;
}

/*
*Preconditions - Requires std and iostream. Requires "BiTree.h" to be loaded, and Delete functions to be working correctly.
*Postconditions - Outputs a message, asking the user what they would like to delete. Then removes that item from the tree.
*/
void deleteitem()
{
	string url;
	char ex;
	cout << "Type in the URL you would like to delete.\n";
	cout << "Remember that URL's do not have spaces in them.\n";//delete the item you want
	cin >> url;
	tree1.Remove(url);//gonna have to figure this out
	cout << "The URL has been deleted.\n";
	cout << "Press any letter, followed by enter, to exit.\n";
	cin >> ex;
}

/*
*Preconditions - Requires iostream, "BiTree.h", and std to be loaded.
*Postconditions - Outputs the list in alphabetical order on the screen.
*/
void printreg()
{
	char ex;
	tree1.Print();
	cout << endl << "Press any letter, followed by enter, to exit.\n"; //print the tree in alphabetical order.
	cin >> ex;
}

/*
*Preconditions - Requires iostream, "BiTree.h", and std to be loaded.
*Postconditions - Outputs the list in reverse alphabetical order on the screen.
*/
void printrev()
{
	char ex;
	tree1.RPrint();
	cout << endl << "Press any letter, followed by enter, to exit.\n"; //anarchy.
	cin >> ex;
}

/*
*Preconditions - Requires iostream, "BiTree.h", and std to be loaded.
*Postconditions - Outputs the tree onto the screen in a level by level display. That way, the tree goes root, enter, then it's children, enter,
* their children, etc.
*/
void printtree()
{
	char ex;
	tree1.TPrint();
	cout << endl << "Press any letter, followed by enter, to exit.\n";//uhuh. shows the craziness of computers, and the ingenuity of mankind
	cin >> ex;
}

/*
*Preconditions - Requires iostream, "BiTree.h", and std to be loaded.
*Postconditions - Prompts the user for an input, then uses that input to find if the item has been found or not.
*/
void searchtree() //Got tired of writing comments. This code is pretty straight forward I think
{
	string url;
	char ex;
	cout << "Type in the URL you would like to search for.\n";
	cout << "Remember that URL's do not have spaces in them.\n"; //"These are not the droids you are looking for."
	cin >> url;
	if (tree1.Search(url))
	{
		cout << url << " has been found in the tree.\n";
	}
	else
	{
		cout << url << " was not found in the tree.\n";
	}
	cout << endl << "Press any letter, followed by enter, to exit.\n";
	cin >> ex;
}