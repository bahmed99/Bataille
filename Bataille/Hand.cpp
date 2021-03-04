#include "Hand.h"

Hand::Hand(void)
{

}

void Hand::ajouterCards(Hand h )
{
	while (h.handPlayer.empty() == false) {
		
	}
}

void Hand::setHandPlayer(Card ct[])
{
	for (int i = 0; i < 26; i++)
	{
		handPlayer.push(ct[i]);
	}
}




Hand::~Hand(void)
{
}
