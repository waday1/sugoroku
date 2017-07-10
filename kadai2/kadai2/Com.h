#ifndef Com_h
#define Com_h

#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "Reversi.h"
using namespace std;

class Com 
{

public:
	int x, y;
	Com();
	bool Input(bool isSet[8][8],Stone stone[8][8]);

};
#endif