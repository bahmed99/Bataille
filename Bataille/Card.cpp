#include "Card.h"

Card::Card()
{
	valeur = 0; 
	symbole = ""; 
}

Card::Card(const Card& ct)
{
	valeur = ct.valeur;
	symbole = ct.symbole;
}

int Card::getValeur() const
{
	return valeur;
}

string Card::getSymbole() const
{
	return symbole;
}

void Card::setValeur(int a)
{
	this->valeur = a; 
}

void Card::setSymbole(string c)
{
	this->symbole = c; 
}



int Card::comparer(Card &c2) {
	
	if (valeur > c2.valeur) { return 1; }
	else if (valeur < c2.valeur) { return 2; }
	else { return 0; }
}

void Card::echange(Card& ct)
{
	Card aux = *this;
	valeur = ct.valeur;
	symbole = ct.symbole;
	ct = aux;
}

Card::~Card(void)
{
}



