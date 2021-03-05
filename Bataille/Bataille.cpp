#include "Package.h"
#include"Hand.h"
#include"Player.h"
#include"Game.h"
#include <ostream>

int main()
{
    Package pq;
    Game P =pq;
    Player p1, p2;
    string a, b;
    cout << "taper nom joueur 1" << endl; 
    cin >> a;
    p1.setPrenom(a);
    cout << "taper nom joueur 2" << endl;
    cin >> b;
    p2.setPrenom(b);
    Hand hand1, hand2; 
    pq.distribuer(hand1,hand2); 
    p1.setHand(hand1); 
    p2.setHand(hand2);
    P.Jeux(p1, p2);
    return 0;
}

