#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"
BST tree;

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

// fills up the tree with data 
void fillTree()
{
	country c1("Australia", "fff", 10.00, 5);
	country c2("Austria", "fff", 10.00, 4);
	country c3("Bahamas", "fff", 10.00, 4);
	country c4("Brazil", "fff", 10.00, 4);
	country c5("Canada", "fff", 10.00, 4);
	country c6("China", "fff", 10.00, 4);
	country c7("Denmark", "fff", 10.00, 4);
	country c8("Dominica", "fff", 10.00, 4);
	country c9("Egypt", "fff", 10.00, 4);
	country c10("El Salvador", "fff", 10.00, 4);
	country c11("Finland", "fff", 10.00, 4);
	country c12("France", "fff", 10.00, 4);
	country c13("Great Britain", "fff", 10.00, 4);
	country c14("Greece", "fff", 10.00, 4);
	country c15("Haiti", "fff", 10.00, 4);
	country c16("Hungary", "fff", 10.00, 4);
	country c17("Iceland", "fff", 10.00, 4);
	country c18("India", "fff", 10.00, 4);
	country c19("Japan", "fff", 10.00, 4);
	country c20("Jordan", "fff", 10.00, 4);
	country c21("Korea, South", "fff", 10.00, 4);
	country c22("Kosovo", "fff", 10.00, 4);
	country c23("Laos", "fff", 10.00, 4);
	country c24("Lebanon", "fff", 10.00, 4);
	country c25("Malaysia", "fff", 10.00, 4);
	country c26("Madagascar", "fff", 10.00, 4);
	country c27("New Zealand", "fff", 10.00, 4);
	country c28("Norway", "fff", 10.00, 4);
	country c29("Oman", "fff", 10.00, 4);
	country c30("Philippines", "fff", 10.00, 4);
	country c31("Poland", "fff", 10.00, 4);
	country c32("Russia", "fff", 10.00, 4);
	country c33("Singapore", "fff", 10.00, 4);
	country c34("Switzerland", "fff", 10.00, 4);
	country c35("United Kingdom", "fff", 10.00, 4);
	country c36("United States", "fff", 10.00, 4);
	country c37("Taiwan", "fff", 10.00, 4);
	country c38("Thailand", "fff", 10.00, 4);
	country c39("Vietnam", "fff", 10.00, 4);

	tree.insert(c1);
	tree.insert(c2);
	tree.insert(c3);
	tree.insert(c4);
	tree.insert(c5);
	tree.insert(c6);
	tree.insert(c7);
	tree.insert(c8);
	tree.insert(c9);
	tree.insert(c10);
	tree.insert(c11);
	tree.insert(c12);
	tree.insert(c13);
	tree.insert(c14);
	tree.insert(c15);
	tree.insert(c16);
	tree.insert(c17);
	tree.insert(c18);
	tree.insert(c19);
	tree.insert(c20);
	tree.insert(c21);
	tree.insert(c22);
	tree.insert(c23);
	tree.insert(c24);
	tree.insert(c25);
	tree.insert(c26);
	tree.insert(c27);
	tree.insert(c28);
	tree.insert(c29);
	tree.insert(c30);
	tree.insert(c31);
	tree.insert(c32);
	tree.insert(c33);
	tree.insert(c34);
	tree.insert(c35);
	tree.insert(c36);
	tree.insert(c37);
	tree.insert(c38);
	tree.insert(c39);
}

// main program 
int main()
{
	fillTree();

	system("pause"); 
}


