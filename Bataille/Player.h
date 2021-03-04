#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
using namespace std;

class Player
{
	string prenom; 
	Hand hand;
public :
	Player(void);
	void setPrenom(string);
	string getPrenom(); 
	~Player(void); 
};


