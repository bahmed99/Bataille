#pragma once
#include <iostream>

#include"Card.h"
#include<stack>
using namespace std;


class Hand
{
	stack <Card> handPlayer;
public : 

	
	Hand(void); 

	void setHandPlayer(stack<Card>);
	stack<Card> getHandPlayer();
	void tirerCard();
	~Hand(void); 


};

