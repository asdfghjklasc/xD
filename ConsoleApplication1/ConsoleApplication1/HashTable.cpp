#include "stdafx.h"
#include "iostream"
#include <string>
#include "HashTable.h"
#include "country.h"
using namespace std; 

HashTable::HashTable()  // intialise the hash table array
{
	for (int i = 0; i < tableSize; i++)  // to run through every index in the hash table 
	{
		table[i] = new hItem;
		table[i]->name = "empty"; 
		table[i]->description = "empty"; 
		table[i]->price = 0;
		table[i]->hit_count = 0;
		table[i]->next = NULL;
	}
}

int HashTable::hash(string key)  // hash algorithm 
{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize; 
	return index; 
}

void HashTable::addItem(itemType2 item)  // insert an item into the hash table 
{
	int index = hash(item.getName());  // hold the location in the hash table to store this info
	if (table[index]->name == "empty")  // if the hash table bucket/index is empty 
	{
		table[index]->name = item.getName();
		table[index]->description = item.getDescription();
		table[index]->price = item.getPrice();
		table[index]->hit_count = item.getHit_count();
	}

	else
	{
		hItem* ptr = table[index];  // point to the first index in the hash table
		hItem* newPtr = new hItem;  // point to the new item 
		newPtr->name = item.getName();
		newPtr->description = item.getDescription();
		newPtr->price = item.getPrice(); 
		newPtr->hit_count = item.getHit_count(); 
		newPtr->next = NULL;

		while (ptr->next != NULL)  
		{
			ptr = ptr->next;
		}
		ptr->next = newPtr; 
	}
}

int HashTable::numberOfItemsInIndex(int index)  // count the number of items in a hash bucket/index
{
	int count = 0;
	if (table[index]->name == "empty")
	{
		return 0;
	}

	else
	{
		count++;
		hItem* ptr = table[index];
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count; 
}

void HashTable::printTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfItemsInIndex(i);
		cout << "------------" << endl; 
		cout << "index = " << i << endl;
		cout << "Name : " << table[i]->name << endl;
		cout << "Hit_count : " << table[i]->hit_count << endl; 
		cout << "No. of items = " << number << endl;
		cout << "------------" << endl;
	}
}

void HashTable::printItemsInIndex(int index)
{
	hItem* ptr = table[index]; 
	if (ptr->name == "empty")
	{
		cout << "index = " << index << "is empty";
	}

	else
	{
		cout << "index" << index << "contains the following items" << endl;
		while (ptr != NULL)
		{
			cout << "------------" << endl;
			cout << ptr->name << endl;
			cout << ptr->hit_count << endl;
			cout << "------------" << endl;
			ptr = ptr->next;
		}
	}
}

void HashTable::sortAndPrintByName()
{
	string countryArray[30] = {};  // array to store the names of the countries 
	int a = 0;  // counter for the array 

	for (int i = 0; i < tableSize; i++)
	{
		countryArray[a] = table[i]->name; 
		a++; 
	}

	for (int i = 0; i < 30; i++)
	{
		cout << countryArray[i] << endl; 
	}
}


	
			//countryArray[a] = table[index]->name;
			//a++;
		


	/*for (int i = 0; i <= 30; i++)
	{ 
		cout << countryArray[i] << endl; 
	}*/


