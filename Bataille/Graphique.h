#pragma once
#include <stdio.h>
#include<amp_graphics.h>
using namespace std;
class Graphique

{
public:
    // class constructor
    Graphique()
    {
        int gdriver = VGA, gmode = VGAHI, errorcode;
        initgraph(&gdriver, &gmode, "");
        cleardevice();
        moveto(15, 5);
        setcolor(2);
        outtext("Université");
        moveto(5, 20);
        outtext("Moulay Ismail");
        moveto(500, 5);
        setcolor(2);
        outtext("Faculté des Sciences");
        moveto(540, 20);
        outtext("Meknès");
        moveto(0, 40);
        lineto(650, 40);
        moveto(250, 45);
        setcolor(3);
        outtext("Jeux de Carte Bataille");
        moveto(60, 60);
    }
    void add(int x, int y, int couleur, char* message)
    {
        moveto(x, y);
        setcolor(couleur);
        outtext(message);
    }
    void printcarte(int, int, int, int, Carte&);
};
