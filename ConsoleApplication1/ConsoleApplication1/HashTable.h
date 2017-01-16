#pragma once
#ifndef HashTable_h
#define HashTable_h
#include "BST.h"
typedef country itemType2;

class HashTable
{
private:
	static const int tableSize = 101;  // determine the size of the hash table 

	struct hItem  // what items consist of that will be stored in the hash table 
	{
		string name;  // name of the country 
		string description;  // description of the country 
		double price;  // price to travel to the country 
		int hit_count;  // hit_count of the country 
		hItem* next;  // pointer to point to the next item 
	};

	hItem* table[tableSize];  // to create the hash table. The hash table is just going to contain a bunch of pointers and
							 // those pointers have the ability to point to item objects 
							 // The hash table which is an array which have a tableSize no. of buckets and each of those buckets contain a pointer that 
							 // is able to point to another item.
public:
	// default constructor 
	HashTable();  

	// hash algorithm 
	int hash(string key); 

	// insert an item into the hash table 
	void addItem(itemType2 item); 

	// delete an item from the hash table
	void removeItem(string item);    

	// count the number of items in a hash bucket/index (FOR TESTING PURPOSES IGNORE) 
	int numberOfItemsInIndex(int index);  

	// for testing purposes (IGNORE) 
	void printTable();

	// for testing purposes (IGNORE) 
	void printItemsInIndex(int index);

	// display the items in ascending order (of name)
	void sortAndPrintByName(int arraySize);  
};
#endif

