#include "Package.h"
#include"Card.h"
string const Symboles[4] = {"carreau","trefle","pique","coeur"}; 

Package::Package(void)
{
    int i = 0;
    for (int symb = 0; symb < 4; symb++)
        for (int val = 1; val <= 13; val++)
        {
            Pack[i].setValeur(val);
            Pack[i].setSymbole(Symboles[symb]);
            i++;
        }

}

void Package::distribuer(Hand &h1, Hand &h2)
{
    Card list1[26], list2[26];

    int j = 0;

    int indice;
    int pos = 52;
    for (int k = 0; k < 52; k++)
    {
        indice = rand() % (pos);
        Pack[indice].echange(Pack[pos - 1]);
        pos--;
    }
   

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

Card Package :: getcarte(int pos){
    return Pack[pos];
}
