#include "Game.h"
#include "Hand.h"

#include <ostream>

Game::Game(void)
{
}

Game::Game(const Package& pq)
{
	P = pq;
}

void Game::Jeux(Player &j1, Player& j2)
{
	Hand h1=j1.getHand(); 
	Hand h2=j2.getHand(); 
	string nom1 = j1.getPrenom();
	string nom2 = j2.getPrenom();
	int index = 1; 
	do {
		Card ct1, ct2;
		int iter=0; 
		bool test = false;
		stack <Card> aux; 
		ct1 = h1.handPlayer.top();
		std::cout <<nom1 <<":"<<"  "<< ct1.getValeur()<<ct1.getSymbole()<< endl;
		h1.handPlayer.pop();
		ct2 = h2.handPlayer.top();
		std::cout <<nom2<<":"<<"  " << ct2.getValeur()<<ct2.getSymbole()<< endl;
		h2.handPlayer.pop();
		aux.push(ct1);
		aux.push(ct2);


			if (ct1.comparer(ct2) == 1)
			{
				h1.updateHand(aux);
				std::cout << nom1 << " a emporter la manche" << "  " << index<< endl;
				index++;
			}
			else if (ct1.comparer(ct2) ==2) {
				h2.updateHand(aux);
				std::cout << nom2 << " a emporter la manche" << "  " << index <<endl;
				index++;
			}
		
		else {
			
			std::cout << "BATTAILE" << endl;
			do {
				Card ct3, ct4, ct5, ct6;
				if (iter % 2 != 0) {
					
					ct5 = h1.handPlayer.top();
					h1.handPlayer.pop();
					ct6 = h2.handPlayer.top();
					h2.handPlayer.pop();
					aux.push(ct5);
					aux.push(ct6);
					cout << nom1 << ":" << "  " << ct1.getValeur() <<ct1.getSymbole() << "  " << "*" << "  " << ct5.getValeur() << ct5.getSymbole() << endl;
					std::cout << nom2 << ":" << "  " << ct2.getValeur() <<ct2.getSymbole() << "  " << "*" << "  " << ct6.getValeur() << ct6.getSymbole() << endl;

					if (ct5.comparer(ct6) == 1)
					{
						h1.updateHand(aux);
				
						std::cout << nom1 << " a emporter la manche" << index << endl;
						index++;
						test = true;
					}
					else if (ct5.comparer(ct6) == 2) {
						h2.updateHand(aux);
						std::cout << nom2 << " a emporter la manche" << index << endl;
						index++;
						
						test = true;
					}
					else {
						std::cout << "BATTAILE" << endl;
						iter++;
					}
				}
				else {
					
					ct3 = h1.handPlayer.top();
					h1.handPlayer.pop();
					ct4 = h2.handPlayer.top();
					h2.handPlayer.pop();
					aux.push(ct3);
					aux.push(ct4);
					iter++; 
				}



			} while (test == false);} 
		
	}while (h1.handPlayer.empty()==false && h2.handPlayer.empty()==false); 
	
	
	j1.setHand(h1); 
	j2.setHand(h2); 
	if (h1.handPlayer.empty()==true) { std::cout << nom2 << " a ganger" << endl; }
	else { std::cout << nom1 << " a ganger" << endl; }
	
} 

Game::~Game(void)
{
}
