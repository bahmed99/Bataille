#include "Package.h"
#include"Card.h"

#include<algorithm>
#include<random>

string const Symboles[4] = {"carreau","trefle","pique","coeur"}; 

Package::Package(void)
{
    int i = 0;
    Card C; 
    for (int symb = 0; symb < 4; symb++) {
        for (int val = 1; val <= 13; val++)
        {
            Pack[i].setValeur(val);
            Pack[i].setSymbole(Symboles[symb]);
            i++;
            
        }
    }
 
    for (int j = 0; j < 52; j++) {
        int random = rand() % 52;
        C.echange(Pack[j]);
        Pack[j].echange(Pack[random]); 
        Pack[random].echange(C); 
    }

}

void Package::distribuer(Hand &h1, Hand &h2)
{
    Card hand1[26], hand2[26];
    int cpt = 0;
    for (int i = 0; i < 26; i++)
    {
        hand1[i] = Pack[cpt];
        cpt++;
        hand2[i] = Pack[cpt];
        cpt++;
    }
    h1.setHandPlayer(hand1);
    h2.setHandPlayer(hand2);
}


Package::~Package(void)
{
}

