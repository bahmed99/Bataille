#pragma once
#include <iostream>

#include "Hand.h"  
using namespace std;

class Package
{
	Card Pack[52];
public : 

	Package(void); 
	void distribuer(Hand&, Hand&);
	Card getcarte(int);
	~Package(void); 
};

