#include "Hand.h"

Hand::Hand(void)
{

}

void Hand::updateHand(stack<Card> p)
{
	stack <Card> aux;
	while (handPlayer.empty() == false) {
		aux.push(handPlayer.top());
		handPlayer.pop();
	}
	while (p.empty() == false) {
		handPlayer.push(p.top());
		p.pop();
	}
	while (aux.empty() == false) {
		handPlayer.push(aux.top());
		aux.pop();
	}
}


Hand::Hand(const Hand& h)
{
	this->handPlayer = h.handPlayer; 
}

void Hand::setHandPlayer(Card ct[])
{
	for (int i = 0; i < 26; i++)
	{
		this->handPlayer.push(ct[i]);
	}
}




Hand::~Hand(void)
{
}
