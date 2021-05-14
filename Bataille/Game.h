#pragma once
#include <iostream>
#include "Player.h"
#include "Package.h"

using namespace std;

class Game
{
	Package P; 
	Player p1, p2; 
	int round; 

public :
	Game(const Package& pq,const Player&,const Player&);


	void Jeux(); // gérer une partie


	~Game(void); 

};

