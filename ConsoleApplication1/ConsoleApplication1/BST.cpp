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


