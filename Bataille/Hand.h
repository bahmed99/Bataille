#pragma once
#include <iostream>

#include"Card.h"
#include<stack>
using namespace std;


class Hand
{
	 
public : 
	stack <Card> handPlayer;
	Hand(void); 
	void ajouterCards(Hand); 
	void setHandPlayer(Card[]); 
	
	~Hand(void); 


};

