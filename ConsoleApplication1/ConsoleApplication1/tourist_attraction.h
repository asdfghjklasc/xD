#pragma once
#include <string>
using namespace std; 

class tourist_attraction
{
private:
	string name;  // name of the tourist attraction 
	string description;  // description of the tourist attraction 
	double price;  // price to go to the tourist attraction 
	int hit_count;  // the hit count of the number of times people search for this particular place 

public:
	tourist_attraction();  // default constructor 
	tourist_attraction(string name, string description, double price, int hit_count);  // parameterised constructor 

	string getName();  // get the name of the tourist attraction 
	void setName(string name);  // set the name of the tourist attraction 

	string getDescription();  // get the description of the tourist attraction 
	void setDescription(string description);  // set the description of the tourist attraction 

	double getPrice();  // get the price 
	void setPrice(double price);  // set the price 

	int getHit_count();  // get the hit count
	void setHit_count(int hit_count);  // set the hit count 
}; 