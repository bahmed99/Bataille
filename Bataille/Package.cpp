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
    Card list1[26], list2[26];
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        list1[i] = this->Pack[j];
        j++;
        list2[i] = this->Pack[j];
        j++;
    }
    h1.setHandPlayer(list1);
    h2.setHandPlayer(list2);
}


Package::~Package(void)
{
}

