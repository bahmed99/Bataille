#include "Game.h"
#include "Hand.h"
#include <windows.h> 
#include <ostream>

Game::Game(const Package& pq):P(pq)
{
}



void Game::Jeux(Player &j1, Player& j2)
{
	bool test1 = false;
	Hand h1=j1.getHand(); 
	Hand h2=j2.getHand(); 
	string nom1 = j1.getPrenom();
	string nom2 = j2.getPrenom();
	int index = 1; 
	do {
		Card ct1, ct2;
		bool testBataille = false;
		stack <Card> aux; //table 
		cout << "             " << endl;
		cout << "joueur 1: " << h1.getHandPlayer().size() << endl;
		cout << "joueur 2: " << h2.getHandPlayer().size() << endl;

		ct1 = h1.getHandPlayer().top(); //sommet 
		cout <<nom1 <<":"<<"  "<< ct1.getValeur()<<ct1.getSymbole()<< endl;
		h1.tirerCard();
		ct2 = h2.getHandPlayer().top();
		cout <<nom2<<":"<<"  " << ct2.getValeur()<<ct2.getSymbole()<< endl;
		h2.tirerCard();
		aux.push(ct1);
		aux.push(ct2);


			if (ct1.comparer(ct2) == 1) // premier joueur rbah 
			{
				h1.setHandPlayer(aux);
				cout << nom1 << " a emporté la manche" << "  " << index<< endl;
				index++;
			}
			else if (ct1.comparer(ct2) ==2) {
				h2.setHandPlayer(aux);
				cout << nom2 << " a emporté la manche" << "  " << index <<endl;
				index++;
			}
		
		else {
			
			cout << "BATTAILE" << endl;
			cout << "             " << endl;
			
			if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0) { 

				if (h1.getHandPlayer().size() == 0) {
					h2.setHandPlayer(aux);
					test1 = true;
				}
				else {
					h1.setHandPlayer(aux);
					test1 = true;
				}
			}
			else if (h1.getHandPlayer().size() == 1 || h2.getHandPlayer().size() == 1) { 

					if (h1.getHandPlayer().size() == 1) {
						aux.push(h1.getHandPlayer().top());
						h1.tirerCard();
						h2.setHandPlayer(aux);
						test1 = true;
					}
					else {
						aux.push(h2.getHandPlayer().top());
						h2.tirerCard();
						h1.setHandPlayer(aux);
						test1 = true;
					}
			}
			else {
			do { 
				Card ct3, ct4, ct5, ct6;
				ct3 = h1.getHandPlayer().top();
				h1.tirerCard();
				ct4 = h2.getHandPlayer().top();
				h2.tirerCard();
				aux.push(ct3);
				aux.push(ct4);
				if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0)
				{ 
					if (h1.getHandPlayer().size() == 0) 
					{
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << "  " << index << endl;
						testBataille = true;
					}
					else 
					{
						h1.setHandPlayer(aux);
						cout << nom1 << " a emporte la manche" << "  " << index << endl;
						testBataille = true;
					}
				}
				else 
				{
					ct5 = h1.getHandPlayer().top();
					h1.tirerCard();
					ct6 = h2.getHandPlayer().top();
					h2.tirerCard();
					aux.push(ct5);
					aux.push(ct6);
					cout << nom1 << ":" << "  " << ct1.getValeur() <<ct1.getSymbole() << "  " << "*" << "  " << ct5.getValeur() << ct5.getSymbole() << endl;
					cout << nom2 << ":" << "  " << ct2.getValeur() <<ct2.getSymbole() << "  " << "*" << "  " << ct6.getValeur() << ct6.getSymbole() << endl;

					if (ct5.comparer(ct6) == 1)
					{
						h1.setHandPlayer(aux);
				
						cout << nom1 << " a emporte la manche" << index << endl;
						index++;
						
						testBataille = true;
					}
					else if (ct5.comparer(ct6) == 2) {
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << index << endl;
						index++;
						
						testBataille = true;
					}
					else { //bataille fi wist bataille 
						cout << "BATTAILE" << endl;
						cout << "             "<< endl;
					}
				
				}

			} while (testBataille == false);}
			}

			
	}while (h1.getHandPlayer().empty()==false && h2.getHandPlayer().empty()==false && test1 ==false);
	Beep(523, 500);
	
	j1.setHand(h1); 
	j2.setHand(h2); 
	cout << " " << endl;
	if (h1.getHandPlayer().empty()==true) { cout << nom2 << " a ganger" << endl; }
	else { cout << nom1 << " a gange" << endl; }
	
} 

Game::~Game(void)
{
}
