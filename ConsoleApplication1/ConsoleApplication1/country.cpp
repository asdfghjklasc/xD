#include "stdafx.h"
#include "country.h"
#include <string>
using namespace std;

// default constructor 
country::country()  
{
	setName("");
	setDescription("");
	setPrice(1);
	setHit_count(1);
}

// parameterised constructor
country::country(string Name, string Description, double Price, int Hit_Count)  
{
	setName(Name);
	setDescription(Description);
	setPrice(Price);
	setHit_count(Hit_Count);
}

// set the name of the tourist attraction
void country::setName(string Name)   
{
	name = Name;
}

// get the name of the tourist attraction
string country::getName()  
{
	return name;
}

// set the description of the tourist attraction 
void country::setDescription(string Description) 
{
	description = Description;
}

// get the description of the tourist attraction 
string country::getDescription()  
{
	return description;
}

// set the price
void country::setPrice(double Price)  
{
	price = Price;
}

// get the price 
double country::getPrice() 
{
	return price;
}

// set the hit count
void country::setHit_count(int Hit_Count)  
{
	hit_count = Hit_Count;
}

// get the hit count
int country::getHit_count()  
{
	return hit_count;
}