#include "Package.h"
#include"Hand.h"
#include <iostream>

int main()
{
    Package p; 
    Hand h1, h2; 

    p.distribuer(h1, h2); 


    string x = h1.handPlayer.top().getSymbole(); 
    string y = h2.handPlayer.top().getSymbole(); 
    int x1 = h1.handPlayer.top().getValeur(); 
    int x2  = h2.handPlayer.top().getValeur(); 
    cout<< x << endl; 
    cout<< y << endl;
    cout<< x1 << endl;
    cout<< x2 << endl;
    
    return 0; 
}

