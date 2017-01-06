#include "stdafx.h"
#include "tourist_attraction.h"
#include <string>
using namespace std; 

tourist_attraction::tourist_attraction()  // default constructor 
{
	setName("");
	setDescription("");
	setPrice(1);
	setHit_count(1);
} 

tourist_attraction::tourist_attraction(string Name, string Description, double Price, int Hit_Count)  // parameterised constructor 
{
	setName(Name);
	setDescription(Description);
	setPrice(Price);
	setHit_count(Hit_Count);
}

void tourist_attraction::setName(string Name)  // set the name of the tourist attraction 
{
	name = Name; 
}


string tourist_attraction::getName()  // get the name of the tourist attraction 
{
	return name; 
}

void tourist_attraction::setDescription(string Description)  // set the description of the tourist attraction 
{
	description = Description;
}

string tourist_attraction::getDescription()  // get the description of the tourist attraction 
{
	return description; 
}

void tourist_attraction::setPrice(double Price)  // set the price 
{
	price = Price;
}

double tourist_attraction::getPrice()  // get the price 
{
	return price;
}

void tourist_attraction::setHit_count(int Hit_Count)  // set the hit count
{
	hit_count = Hit_Count; 
}

int tourist_attraction::getHit_count()  // get the hit count
{
	return hit_count; 
}
 