#include "Game.h"
#include "Hand.h"
#include <windows.h> 
#include <iostream>
using namespace std;


Game::Game(const Package& pq, const Player& j1, const Player& j2):P(pq),p1(j1),p2(j2),round(1)
{
}



void Game::Jeux()
{

	
	Hand h1; 
	Hand h2; 
	P.distribuer(h1, h2);
	string nom1 = p1.getPrenom();
	string nom2 = p2.getPrenom();

	

	


	do {

		Card ct1, ct2;
		bool testBataille = false; 
		stack <Card> aux; //table 


		cout << "                 " << endl;
		cout << "joueur 1: " << h1.getHandPlayer().size() << endl;
		cout << "joueur 2: " << h2.getHandPlayer().size() << endl;
		cout << "**********************" << endl;
		cout << "             " << endl;


		ct1 = h1.getHandPlayer().top(); //sommet 
		cout <<nom1 <<":"<<"  "<< ct1.getValeur()<<ct1.getSymbole()<< endl;
		h1.tirerCard();
		ct2 = h2.getHandPlayer().top();
		cout <<nom2<<":"<<"  " << ct2.getValeur()<<ct2.getSymbole()<< endl;
		h2.tirerCard();
		aux.push(ct1);
		aux.push(ct2);


			if (ct1.comparer(ct2) == 1) // premier joueur remporte la manche
			{
				h1.setHandPlayer(aux);
				cout << nom1 << " a emporte la manche" << "  " << round<< endl;
				round++;
			}

			else if (ct1.comparer(ct2) ==2) // 2éme joueur remporte la manche
			{
				h2.setHandPlayer(aux);
				cout << nom2 << " a emporte la manche" << "  " << round <<endl;
				round++;
			}

		//Egalite
		else {
			cout << "             " << endl;
			cout << "BATTAILE" << endl;
			cout << "             " << endl;
			
			// Si un de joueurs ne possede plus de carte 
			if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0) { 

				if (h1.getHandPlayer().size() == 0) {
					h2.setHandPlayer(aux);
					
				}
				else {
					h1.setHandPlayer(aux);
					
				}
			}

			// Si un de joueurs possede une seule carte qui ne le permete pas de continuer la bataille
			else if (h1.getHandPlayer().size() == 1 || h2.getHandPlayer().size() == 1) { 

					if (h1.getHandPlayer().size() == 1) {
						aux.push(h1.getHandPlayer().top());
						h1.tirerCard();
						h2.setHandPlayer(aux);
						
					}
					else {
						aux.push(h2.getHandPlayer().top());
						h2.tirerCard();
						h1.setHandPlayer(aux);
			
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

				// si un de joueurs ne possede plus de carte
				if (h1.getHandPlayer().size() == 0 || h2.getHandPlayer().size() == 0)
				{ 
					if (h1.getHandPlayer().size() == 0) 
					{
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << "  " << round << endl;
						testBataille = true;
					}
					else 
					{
						h1.setHandPlayer(aux);
						cout << nom1 << " a emporte la manche" << "  " << round << endl;
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


					// premier joueur remporte la manche
					if (ct5.comparer(ct6) == 1)
					{
						h1.setHandPlayer(aux);
				
						cout << nom1 << " a emporte la manche" << round << endl;
						round++;
						
						testBataille = true;
					}

					// 2éme joueur remporte la manche
					else if (ct5.comparer(ct6) == 2) {
						h2.setHandPlayer(aux);
						cout << nom2 << " a emporte la manche" << round << endl;
						round++;
						
						testBataille = true;
					}

					//égalite
					else 
					{ 
						cout << "BATTAILE" << endl;
						cout << "             "<< endl;
					}
				
				}

			} while (testBataille == false);}
			}

		

	}while (h1.getHandPlayer().empty()==false && h2.getHandPlayer().empty()==false);
	Beep(523, 500); //sonorie 
	
	p1.setHand(h1); 
	p2.setHand(h2); 

	cout << "             " << endl;

	cout << "              " << endl;
	if (h1.getHandPlayer().empty()==true) { cout << nom2 << " a ganger" << endl; }
	else { cout << nom1 << " a gange" << endl; }
	
} 

Game::~Game(void)
{
}
