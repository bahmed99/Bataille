#include "Player.h"



Player::Player():prenom("")
{
}

void Player::setPrenom(string prenom)
{
	prenom = prenom; 
}

string Player::getPrenom()
{
	return prenom;
}

Player::~Player(void)
{
}
