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
	void updateHand(stack<Card>);
	Hand(const Hand& h);
	void setHandPlayer(Card[]); 



	~Hand(void); 


};

