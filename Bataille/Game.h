#pragma once
#include <iostream>
#include "Player.h"
#include "Package.h"

using namespace std;

class Game
{
	Package P; 

public :
	Game(const Package& pq);


	void Jeux(Player &j1, Player &j2); // g�rer une partie


	~Game(void); 

};

