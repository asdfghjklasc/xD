#include "stdafx.h"
#include "iostream"
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
	if (t == NULL)
	{
		BinaryNode* newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}

	else
	{
		if (item.getName() > t->item.getName())  // insert in the right sub-tree 
		{
			insert(t->right, item);
		}

		else                                     // insert in the left sub-tree 
		{
			insert(t->left, item);
		}
	}
}

// delete an item from the binary search tree
void BST::remove(itemType item)
{
	if (isEmpty())
	{
		cout << "The tree is empty. " << endl; 
	}
	
	else
	{
		remove(root, item); 
	}
}

void BST::remove(BinaryNode* &t, ItemType item)
{
	BinaryNode* temp = t;
	BinaryNode* Parent = NULL;
	bool right = false;
	bool found = false;
	while (!found && (temp != NULL))
	{
		if (item.getName() == (temp->item).getName())
		{
			found = true;
		}
		else
		{
			Parent = temp;
			if (item.getName() > temp->item.getName())
			{
				temp = temp->left;
				right = false;
			}
			else
			{
				temp = temp->right;
				right = true;
			}
		}
		if (found = true)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				if (temp = t)
				{
					t = NULL;
				}
				else if (right)
				{
					Parent->right = NULL;
				}
				else
				{
					Parent->left = NULL;
				}
			}
			else if (temp->left)
			{
				if (right)
				{
					Parent->right = temp->right;
				}
				else
				{
					Parent->left = temp->right;
				}
			}
			else
			{
				BinaryNode* successor = temp->left;
				while (successor->right != NULL)
				{
					successor = successor->right;
				}
				ItemType item = successor->item;
				remove(t, item);
				temp->item = item;
			}
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
		cout << "No item found" << endl;
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


