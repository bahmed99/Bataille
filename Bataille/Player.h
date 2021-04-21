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


	void setPrenom(string); // affectuer pr�nom du joueur


	string getPrenom(); // retoruner pr�nom du joueur


	Hand& getHand(); // retourner "hand" du joueur


	void setHand(Hand& h); //modifier "hand" 


	~Player(void); 
};


