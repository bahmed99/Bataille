#include "Hand.h"

Hand::Hand(void)
{

}



Hand::Hand(const Hand& h)
{
	handPlayer = h.handPlayer; 
}

void Hand::setHandPlayer(stack<Card> p)
{
	stack <Card> aux; // pile de passage 
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
