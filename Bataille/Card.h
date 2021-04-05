#pragma once
#include <iostream>
#include <string>
using namespace std;


class Card
{
	int valeur;
	string symbole; 
public : 

	Card(void);

	Card(const Card& ct);

	int getValeur()const; 
	string getSymbole()const; 
	void setValeur(int); 
	void setSymbole(string); 
	int comparer(Card&);

	void operator=(const Card&); 
	~Card(void); 
};

