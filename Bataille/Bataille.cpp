#include "Package.h"
#include"Hand.h"
#include"Player.h"
#include"Game.h"
#include <ostream>



// Une partie du jeu
void bataille() {
    
    Package pq;
    
    Player p1, p2;
    string a, b;
    cout << "taper nom joueur " << endl;
    cin >> a;
    p1.setPrenom(a);
    
    p2.setPrenom("Robot");

    Game P(pq,p1,p2);
    
   
    cout << "***************Bataille****************" << endl;
    P.Jeux();
}


//menu du jeu
void Menu() {
    cout << "*******************************Bataille*******************************" << endl;
    cout <<"                                 " <<"MENU" <<"                            "<<endl; 
    cout << "-1- Jouer" << endl;
    cout << "-2- Quitter" << endl; 
    cout<< ""<<endl;
}



int main()
{
    string choix;

    do {
       
        srand((int)time(0));
        Menu();
        cout << " taper votre choix " << endl;
        cin >> choix;

        if(choix=="1")
        {
            bataille();
            
        
        }
    
    
    } while (choix!="2");
   


   
    return 0;
}

