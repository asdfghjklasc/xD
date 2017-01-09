#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"


// Basic Features of the application 
// 1. search for an item 
// 2. display the items in ascending order (of name) 
// 3. save data to a file 
// 4. load data from a file 

// Additional features 
// 1. Able to add / remove item
// 2. Able to display items in descending order of hit count
// 3. Algorithm optimisation
// 4. Graphical User Interface
// 5. User validation

int main()
{
	BST tree;

	country a1("d", "fff", 10.00, 1); 
	country a2("a", "fff", 10.00, 5);
	country a3("c", "fff", 10.00, 7);
	country a4("e", "fff", 10.00, 2);
	country a5("z", "fff", 10.00, 4);

	tree.insert(a1);
	tree.insert(a2);
	tree.insert(a3);
	tree.insert(a4);
	tree.insert(a5);

	tree.inorder();
	system("pause"); 
}




