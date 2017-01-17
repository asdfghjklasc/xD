#include "stdafx.h"
#include <iostream>
#include "fstream"  // stream class to both read and write from/to files.
#include <sstream>
#include <string>
#include "libxl.h" 
using namespace libxl;
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"
#include "BST_Hits.h"
#include "BinaryNodeHits.h"
BST tree;
BST_Hits hit_tree; 

// Miscellaneous features 
// 1. to print the menu of the application 
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
	cout << "------------------------------------------------------" << endl;
	cout << " 1. Search for an item" << endl;
	cout << " 2. Display the items in ascending order (of name)" << endl;
	cout << " 3. Display items in descending order of hit count" << endl;
	cout << " 4. Display the number of hits of an country." << endl;
	cout << " 5. Display the most searched country." << endl;
	cout << " 6. Display the total number of countries in the world" << endl;
	cout << " 7. Save data to a file" << endl;
	cout << " 8. Load data from a file" << endl;
	cout << " 9. Add a new country" << endl;
	cout << "10. Remove an existing country" << endl << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// search for an item
void choice1()
{
	try
	{
		if (tree.isEmpty())
		{
			cout << "Error : The country respository is empty." << endl;
		}

		else
		{
			char c;
			string target;
			cout << "Enter the name of the country: ";
			cin >> target;

			for (int i = 0; i < target.length(); i++)
			{
				c = target.at(i);
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z' || c == '_'))
				{
					throw 0;
				}
			}
			hit_tree.search(tree.displayHits(target));
			country country(tree.displayHits(target).getName(), tree.displayHits(target).getDescription(), tree.displayHits(target).getPrice(), tree.displayHits(target).getHit_count() + 1);
			hit_tree.remove(tree.displayHits(target)); 
			tree.remove(target);
			tree.insert(country, hit_tree);
		}
	}

	catch (...)
	{
		cout << "Invalid input" << endl;
	}
}

// display the items in ascending order (of name)
void choice2()
{
	tree.inorder();
}

// display items in descending order of hit count
void choice3()
{
	hit_tree.printinorderofhits();
}

// display the number of hits of an country (Ryan)
void choice4()
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		string target;
		cout << "Enter the name of the country: ";
		cin >> target;
		tree.displayHits(target);
	}
}

// display the most searched country
void choice5()
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		hit_tree.displayMaxHits();
	}
}

// display the total number of countries in the world
void choice6()
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		cout << "There are" << " " << tree.countCountry() << " " << "countries in the world today." << endl;
	}
}

// save data to a file
void choice7()
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		int choice = -1;
		cout << "Would you like to save the data to a txt or xlsx file?" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "1. txt file" << endl;
		cout << "2. xlsx file" << endl << endl;
		cout << "Please enter your choice : ";
		cin >> choice;

		if (choice == 1)
		{
			tree.saveData();
		}

		else if (choice == 2)
		{
			/*string input;
			cout << "Enter new Excel file name:" << endl;
			cin >> input;
			Book* book = xlCreateBook();
			if (book)
			{
				int row = 0;
				Sheet* sheet = book->addSheet("CountrySheet");
				while (BinaryNode* t != NULL);
				{	
					if (sheet)
					{
						//write string value
						sheet->writeStr(row, 0, //name);
						sheet->writeStr(row + 1, 0, //description);

						//write numeric value
						sheet->writeNum(row + 2, 0, //price);
						sheet->writeNum(row + 3, 0, //hit_count);
						row = row + 4;
					}
				}

				if (book->save(input))
				{
					cout << "\nFile has been created." << endl;
				}
				book->release();
			}*/

			//tree.saveExcelData();
		}
	}
}

// load data from a file
void choice8()
{
	int choice = -1;
	cout << "Would you like to load the data from a txt or xlsx file?" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "1. txt file" << endl;
	cout << "2. xlsx file" << endl << endl;
	cout << "Please enter your choice : ";
	cin >> choice;

	if (choice == 1)
	{
		string line;
		ifstream myfile;
		string input;
		cout << "Enter the file name : ";
		cin >> input;
		myfile.open(input);
		cout << "Progress...." << endl;
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
			country country(name, description, stof(price), atoi(hit_count.c_str()));
			tree.insert(country, hit_tree);
			cout << "Item successfully loaded." << endl;
		}
		myfile.close();
	}

	/*else if (choice == 2)
	{
		Book* book = xlCreateBook();
		if (book)
		{
			int row = 0;
			string name;
			string description;
			double price;
			int hit_count;
			if (book->load(L"example.xls"))
			{
				Sheet* sheet = book->getSheet(0);
				while (price != NULL)
				{
					if (sheet)
					{
						//read string value
						name = sheet->readStr(row, 0);
						description = sheet->readStr(row + 1, 0);

						//read numeric value
						price = sheet->readNum(row + 2, 0);
						hit_count = sheet->readNum(row + 3, 0);

						country country(name, description, price, hit_count);
						tree.insert(country);
						row = row + 4;
					}
				}
			}

			book->release();
		}
	}*/
}

// add a new country
void choice9()
{
	try
	{
		string name;
		string description;
		string price;  // will be converted to double after it is validated 
		int hit_count = 0;

		cout << "Enter the name of the country : ";
		cin >> name;
		char c;  // for the try-catch 
		for (int i = 0; i < name.length(); i++)
		{
			c = name.at(i);
			if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z'))
			{
				throw 0;
			}
		}

		cout << "Enter the description of the country : ";
		cin >> description;

		cout << "Enter the price to travel to the country : ";
		cin >> price;
		char c1;  // for the try-catch 
		for (int i = 0; i < price.length(); i++)
		{
			c1 = price.at(i);
			if (!(c1 >= '1' &&  c1 <= '9'))
			{
				throw 0;
			}
		}

		country country(name, description, stof(price), hit_count);
		tree.insert(country, hit_tree);
		
	}

	catch (...)
	{
		cout << "Error : Invalid input entered." << endl;
	}
}

// remove an existing country
void choice10()
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		try
		{
			string item;
			cout << "Enter the name of the country : ";
			cin >> item;

			char c;  // for the try-catch 
			for (int i = 0; i < item.length(); i++)
			{
				c = item.at(i);
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z' || c == '_'))
				{
					throw 0;
				}
			}
			tree.remove(item);
			//hit_tree.remove(item);
		}

		catch (...)
		{
			cout << "Error : Invalid input entered. " << endl;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main program 
int main()
{
	cout << "Please load a file containing the list of countries" << endl; 
	int choice; 
	displayMenu();
	cout << "Please enter your choice : ";
	cin >> choice; 
	
	while (choice >= 1 && choice <= 10)
	{
		// search for an item 
		if (choice == 1)  
		{
			choice1(); 
		}

		// display the items in ascending order (of name) 
		else if (choice == 2)  
		{
			choice2();
		}

		// display the number of hits of an item.
		else if (choice == 3)
		{
			choice3();
		}

		// count the number of countries in the world 
		else if (choice == 4)
		{
			choice4();
		}

		else if (choice == 5)  // save data to a file  
		{
			choice5();
		}

		else if (choice == 6)  // load data from a file 
		{
			choice6();
		}

		else if (choice == 7)  // Able to add 
		{
			choice7();
		}

		else if (choice == 8)  // Able to remove item
		{
			choice8();
		}

		else if (choice == 9)  // Able to display items in descending order of hit count
		{
			choice9();
		}

		else if (choice == 10)
		{
			choice10();
		}

		cout << endl << endl << endl << endl;
		displayMenu();
		cout << "Please enter your choice : ";
		cin >> choice;
	}
	cout << "Invalid input entered. Program terminated." << endl; 
	system("pause"); 
}


