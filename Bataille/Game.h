#pragma once
#include <iostream>
#include "Player.h"
#include "Package.h"

using namespace std;

class Game
{
	Package P; 
	Player p1, p2; 

public :
	Game(const Package& pq,const Player&,const Player&);


	void Jeux(); // g�rer une partie


	~Game(void); 

};

