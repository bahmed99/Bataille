#include "Hand.h"

Hand::Hand(void)
{

}


void Hand::setHandPlayer(stack<Card> p)   // on va utiliser 2 piles("aux" et "p ") afin de remplir la pile initiale (handPlayer)de bas vers haut .
{
	stack <Card> aux; // pile de passage


	//Remplir la pile "aux" avec les �l�ments de handPlayer 
	while (handPlayer.empty() == false) {
		aux.push(handPlayer.top());
		handPlayer.pop();
	}



	//Ajouter les �lements de la pile "p" dans handPlayer
	while (p.empty() == false) {
		handPlayer.push(p.top());
		p.pop();
	}


	//Remplir les �l�ments de aux dans handPlayer
	while (aux.empty() == false) {
		handPlayer.push(aux.top());
		aux.pop();
	}
}


stack<Card> Hand::getHandPlayer()
{
	return handPlayer;
}

void Hand::tirerCard()
{
	handPlayer.pop();
}




Hand::~Hand(void)
{
}
