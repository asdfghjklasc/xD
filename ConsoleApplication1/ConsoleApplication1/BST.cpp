#include "stdafx.h"
#include "iostream"
using namespace std; 
#include "BinaryNode.h"
#include "country.h"
#include "BST.h"

BST::BST()  // default constructor 
{
	root = NULL; 
}

BinaryNode* BST::search(BinaryNode* t, itemType target)  // search an item in the binary search tree
{
	if (t == NULL)
	{
		cout << "The binary search tree is empty."; 
	}

	else
	{
		if (t->item == target)
		{
			cout << "The item is found."; 
		}

		else
		{
			if (t-> item < target)  // search in left sub tree 
			{
				return search(t->left, target); 
			}

			else if (t->item > target)  // search in right sub tree 
			{
				return search(t->right, target);
			}
		}
	}
}

void BST::insert(BinaryNode* &t, itemType item)  // add an item to the binary search tree
{
	if (t == NULL)  // root is empty 
	{
		BinaryNode* newNode = new BinaryNode; 
		BinaryNode* item = item; 
		BinaryNode* left = NULL;
		BinaryNode* right = NULL; 
	}

	else
	{
		if (item < t->item)  // insert in left subtree 
		{
			insert(t->left, item); 
		}

		else  // insert in right subtree 
		{
			insert(t->right, item); 
		}
	}
}

void BST::remove(BinaryNode* &t, itemType item) {} // delete an item from the binary search tree

bool BST::isEmpty(BinaryNode* t)  // check if the binary search tree is empty
{
	if (t == NULL)
	{
		return true; 
	}

	else
	{
		return false; 
	}
}

bool BST::isBalanced(BinaryNode* t)  // check if the binary search tree is balanced
{

}