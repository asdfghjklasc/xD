#include "stdafx.h"
#include "country.h"
#include <string>
using namespace std;

country::country()  // default constructor 
{
	setName("");
	setDescription("");
	setPrice(1);
	setHit_count(1);
}

country::country(string Name, string Description, double Price, int Hit_Count)  // parameterised constructor 
{
	setName(Name);
	setDescription(Description);
	setPrice(Price);
	setHit_count(Hit_Count);
}

void country::setName(string Name)  // set the name of the tourist attraction 
{
	name = Name;
}


string country::getName()  // get the name of the tourist attraction 
{
	return name;
}

void country::setDescription(string Description)  // set the description of the tourist attraction 
{
	description = Description;
}

string country::getDescription()  // get the description of the tourist attraction 
{
	return description;
}

void country::setPrice(double Price)  // set the price 
{
	price = Price;
}

double country::getPrice()  // get the price 
{
	return price;
}

void country::setHit_count(int Hit_Count)  // set the hit count
{
	hit_count = Hit_Count;
}

int country::getHit_count()  // get the hit count
{
	return hit_count;
}