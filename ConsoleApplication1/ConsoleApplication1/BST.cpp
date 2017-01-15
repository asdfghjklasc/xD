#include "stdafx.h"
#include "iostream"
#include "fstream"  // stream class to both read and write from/to files.
using namespace std; 
#include "BinaryNode.h"
#include "country.h"
#include "BST.h"

// default constructor 
BST::BST()  
{
	root = NULL; 
}

// add an item to the binary search tree
void BST::insert(itemType item)
{
	insert(root, item); 
}

void BST::insert(BinaryNode* &t, itemType item)
{
	if (t == NULL)  // check if the tree is empty
	{
		BinaryNode* newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}

	else
	{
		if (item.getHit_count() > t->item.getHit_count())  // insert in the right sub-tree 
		{
			insert(t->left, item);
		}

		else  // insert in the left sub-tree 
		{
			insert(t->right, item);
		}
	}
}

// search an item in the binary search tree
void BST::search(string item)
{
	search(root, item); 
}

void BST::search(BinaryNode* t, string item)
{
	if (item == t->item.getName()) 
	{
		cout << t->item.getName() << " " << t->item.getDescription() << " " << "The price to travel there would be" << " " << "S$" << t->item.getPrice() << "." << endl; 
		t->item.setHit_count(t->item.getHit_count() + 1);
	}

	else if (item > t->item.getName())  // search for the target in the right sub-tree 
	{
		search(t->right, item);
	}

	else if (item < t->item.getName())  // search for the target in the left sub-tree 
	{
		search(t->left, item); 
	}
}

// delete an item from the binary search tree
void BST::remove(string item)
{
	remove(root, item);
}

void BST::remove(BinaryNode* &t, string item)
{
	BinaryNode* temp = t;
	BinaryNode* parent = NULL;
	bool Left = false;
	bool found = false;
	while ((!found) && (temp != NULL))
	{
		if (item == (temp->item).getName())
		{
			found = true;
		}

		else
		{
			parent = temp;
			if (item < (temp->item).getName())
			{
				temp = temp->left;	
				Left = true;
			}
			else
			{
				temp = temp->right;	
				Left = false;
			}
		}
	}

	if (found)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			if (temp == t)
				t = NULL;
			else
				if (Left)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		else
			if (temp->left == NULL)
			{
				if (Left)
					parent->left = temp->right;
				else
					parent->right = temp->right;;
			}
			else
				if (temp->right == NULL)
				{
					if (Left)
						parent->left = temp->left;
					else
						parent->right = temp->left;;
				}
				else
				{
					BinaryNode* successor = temp->left;
					while (successor->right != NULL)
						successor = successor->right;
					string item = (successor->item).getName();
					ItemType successoritem = successor->item;
					remove(t, item);
					temp->item = successoritem;
				}
	}
}

// check if the binary search tree is empty
bool BST::isEmpty() 
{
	if (root == NULL)
	{
		return true; 
	}

	else
	{
		return false; 
	}
}

// inorder traversal 
void BST::inorder()
{
	if (isEmpty())
	{
		cout << "Error : The country respository is empty. " << endl;
	}
		
	else
	{
		inorder(root);
	}
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item.getName() << endl;
		inorder(t->right);
	}
}

// save data to a file
void BST::saveData()
{
	if (isEmpty())
	{
		cout << "Error: The country respository is empty. " << endl;
	}

	else
	{
		string fileName;
		cout << "Enter the file name : ";
		cin >> fileName;

		ofstream myfile;
		myfile.open(fileName);
		saveData(root, myfile);
	}
}

void BST::saveData(BinaryNode* t, ofstream& fileName)
{
	if (t != NULL)
	{
		saveData(t->left, fileName);
		fileName << t->item.getName() << ";" << t->item.getDescription() << ";" << t->item.getPrice() << endl; 
		saveData(t->right, fileName);
	}
}

// count the number of countries in the world 
int BST::countCountry()
{
	return countCountry(root);
}

int BST::countCountry(BinaryNode* t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + countCountry(t->left) + countCountry(t->right);
	}
}

// display the number of hits of an item
void BST::searchforHit(string target)
{
	return searchforHit(root, target);
}

void BST::searchforHit(BinaryNode* t, string target)
{
	if (t == NULL)
	{
		cout << "Error : Country not found." << endl;
	}
	else
	{
		if ((t->item).getName() == target)
		{
			cout << "The number of search hits is " << t->item.getHit_count() << ".";
		}

		else if (target > (t->item).getName())
		{
			searchforHit(t->right, target);
		}

		else
		{
			searchforHit(t->left, target);
		}
	}
}
