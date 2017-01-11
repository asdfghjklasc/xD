#include "stdafx.h"
#include <iostream>
#include "fstream"  // stream class to both read and write from/to files.
#include <sstream>
#include <string>
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"
BST tree;

// Miscellaneous features 
// 1. to fill the tree 
void fillTree()
{
	country c7("Denmark", "is a Scandinavian country in Europe.", 969.00, 9);
	country c2("Austria", "is a federal republic and a landlocked country of over 8.7 million people in Central Europe", 870.00, 10);
	country c35("United Kingdom", " is a sovereign country in western Europe.", 700.00, 7);
	country c3("Bahamas", "is an archipelagic state within the Lucayan Archipelago", 2114.00, 5);
	country c5("Canada", "Country in the northern half of North America", 838.00, 2);
	country c17("Iceland", "is a Nordic island country in the North Atlantic Ocean.", 1952.00, 7);
	country c1("Australia", "is a country comprising the mainland of the Australian continent, the island of Tasmania and numerous smaller islands.", 257.00, 4);
	country c8("Dominica", "is a sovereign island country.", 1103.00, 1);
	country c10("El Salvador", "is the smallest and the most densely populated country in Central America. El Salvador's capital and largest city is San Salvador.", 2108.00, 10);
	country c11("Finland", "is a sovereign state in Northern Europe", 944.00, 4);
	country c16("Hungary", "is a unitary parliamentary republic in Central Europe.", 1294.00, 8);
	country c6("China", "is a unitary sovereign state in East Asia", 203.00, 3);
	country c13("Great Britain", " is a large island in the north Atlantic Ocean off the northwest coast of continental Europe.", 697.00, 4);
	country c33("Singapore", "is a sovereign city-state in Southeast Asia, and the world's only island city-state.", 0.00, 10);
	country c15("Haiti", "is a sovereign state located on the island of Hispaniola in the Greater Antilles archipelago of the Caribbean Sea.", 1861.00, 5);
	country c4("Brazil", "is the largest country in both South America and Latin America.", 1472.00, 10);
	country c18("India", "is a country in South Asia.", 254.00, 7);
	country c14("Greece", "is a country in southeastern Europe", 334.00, 4);
	country c21("Korea, South", " is a sovereign state in East Asia, constituting the southern part of the Korean Peninsula.", 351.00, 6);
	country c19("Japan", "is an island nation in East Asia.", 368.00, 8);
	country c23("Laos", " is a landlocked country in the heart of the Indochinese peninsula of Mainland Southeast Asia, bordered by Myanmar (Burma) and China to the northwest, Vietnam to the east, Cambodia to the southwest, and Thailand to the west and southwest.", 194.00, 5);
	country c25("Malaysia", "is a federal constitutional monarchy located in Southeast Asia.", 1414.00, 3);
	country c22("Kosovo", "is a disputed territory and partially recognised state in Southeast Europe that declared independence from Serbia in February 2008 as the Republic of Kosovo. ", 992.00, 2);
	country c24("Lebanon", "is a sovereign state in Western Asia.", 1103.00, 1);
	country c9("Egypt", "is a transcontinental country spanning the northeast corner of Africa and southwest corner of Asia by a land bridge formed by the Sinai Peninsula.", 928.00, 4);
	country c26("Madagascar", " is an island country in the Indian Ocean, off the coast of Southeast Africa.", 608.00, 8);
	country c27("New Zealand", "is an island nation in the southwestern Pacific Ocean.", 676.00, 10);
	country c20("Jordan", "is an Arab kingdom in Western Asia, on the East Bank of the Jordan River.", 968.00, 3);
	country c29("Oman", "is an Arab country on the southeastern coast of the Arabian Peninsula.", 112.00, 6);
	country c31("Poland", "is a country in Central Europe, situated between the Baltic Sea in the north and two mountain ranges (the Sudetes and Carpathian Mountains) in the south.", 10.00, 8);
	country c32("Russia", "is a federal state in Eurasia.", 680.00, 10);
	country c37("Taiwan", "is a state in East Asia.", 197.00, 9);
	country c34("Switzerland", "is a federal republic in Europe.", 1128.00, 10);
	country c36("United States", "is a federal republic composed of 50 states, a federal district, five major self-governing territories, and various possessions.", 631.00, 6);
	country c30("Philippines", "is a sovereign island country in Southeast Asia situated in the western Pacific Ocean.", 810.00, 4);
	country c38("Thailand", "is a country at the centre of the Indochinese peninsula in Southeast Asia.", 84.00, 4);
	country c12("France", "is a country consisting of territory in western Europe and several overseas regions and territories.", 1080.00, 3);
	country c39("Vietnam", "is the easternmost country on the Indochina Peninsula in Southeast Asia.", 197.00, 2);
	country c28("Norway", "is a sovereign and unitary monarchy whose territory comprises the western portion of the Scandinavian Peninsula plus the island Jan Mayen and the archipelago of Svalbard.", 433.00, 10);

	tree.insert(c1);
	tree.insert(c4);
	tree.insert(c13);
	tree.insert(c30);
	tree.insert(c35);
	tree.insert(c24);
	tree.insert(c2);
	tree.insert(c15);
	tree.insert(c22);
	tree.insert(c32);
	tree.insert(c3);
	tree.insert(c38);
	tree.insert(c25);
	tree.insert(c11);
	tree.insert(c21);
	tree.insert(c18);
	tree.insert(c5);
	tree.insert(c37);
	tree.insert(c14);
	tree.insert(c20);
	tree.insert(c28);
	tree.insert(c6);
	tree.insert(c31);
	tree.insert(c33);
	tree.insert(c7);
	tree.insert(c8);
	tree.insert(c17);
	tree.insert(c9);
	tree.insert(c29);
	tree.insert(c23);
	tree.insert(c10);
	tree.insert(c19);
	tree.insert(c12);
	tree.insert(c26);
	tree.insert(c16);
	tree.insert(c34);
	tree.insert(c27);
	tree.insert(c36);
	tree.insert(c39);
}

// 2. to print the menu of the application 
// 
// MENU 
// Basic Features of the application 
// 1. search for an item 
// 2. display the items in ascending order (of name) 
// 3. display the number of hits of an item.
// 4. count the number of countries in the world 
// 5. save data to a file 
// 6. load data from a file 

// Additional features 
// 1. Able to add 
// 2. Able to remove item
// 3. Able to display items in descending order of hit count
// 4. Algorithm optimisation
// 5. Graphical User Interface
// 6. User validation

void displayMenu() 
{
	cout << "MENU" << endl;
	cout << "=======================================================" << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Display the items in ascending order (of name)" << endl;
	cout << "3. Display the number of hits of an item." << endl; 
	cout << "4. Display the total number of countries in the world" << endl; 
	cout << "5. Save data to a file" << endl;
	cout << "6. Load data from a file" << endl;
	cout << "7. Add an item" << endl;
	cout << "8. Remove an item" << endl;
	cout << "9. Display items in descending order of hit count" << endl << endl;
}
int gethits(string Name)
{
	return(tree.searchforobj(Name)).getHit_count();
}

// main program 
int main()
{
	fillTree(); 
	int choice; 
	displayMenu();
	cout << "Please enter your choice : ";
	cin >> choice; 
	
	while (choice >= 1 && choice <= 7)
	{
		// search for an item 
		if (choice == 1)  
		{
			string target;
			cout << "Enter the name of the country: ";
			cin >> target;
			tree.search(target);
		}

		// display the items in ascending order (of name) 
		else if (choice == 2)  
		{
			tree.inorder();
		}

		// display the number of hits of an item.
		else if (choice == 3)
		{
			string input;
			cout << "Enter the name of the country : "; 
			cin >> input;
			cout << gethits(input) << endl;
		}

		// count the number of countries in the world 
		else if (choice == 4)
		{
			cout << tree.countCountry() << endl; 
		}

		else if (choice == 5)  // save data to a file  
		{
			tree.saveData();
		}

		else if (choice == 6)  // load data from a file 
		{
			string line;
			ifstream myfile;
			string input;
			cout << "Enter the file name : "; 
			cin >> input;
			myfile.open(input);
			while (getline(myfile, line))
			{
				stringstream linestream(line);
				string name;
				string description;
				string price;
				string hit_count;
				getline(linestream, name, ';');
				getline(linestream, description, ';');
				getline(linestream, price, ';');
				getline(linestream, hit_count, ';');
				country c1(name, description, stof(price), atoi(hit_count.c_str()));
				tree.insert(c1);
			}
			myfile.close();
		}

		else if (choice == 7)  // Able to add 
		{
		}

		else if (choice == 8)  // Able to remove item
		{
			string item;
			cout << "Enter the name of the country : ";
			cin >> item;
			tree.remove(item);
		}

		else if (choice == 9)  // Able to display items in descending order of hit count
		{
		}

		cout << endl << endl << endl << endl;
		displayMenu();
		cout << "Please enter your choice : ";
		cin >> choice;
	}
	system("pause"); 
}


