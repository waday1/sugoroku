#ifndef GameMain_h
#define GameMain_h

#include <iostream>
#include <string>
#include <random>
#include <time.h>

#include "Reversi.h"
#include"Com.h"

using namespace std;

class GameMain {

public:
	Reversi reversi;
	Com com;
	string inputX, inputY;
	int x = 0, y = 0;
	int oldInputX = 0, oldInputY = 0; 
	bool isSkip=false;
	int endCount = 0;
	int whiteCount = 0, blackCount = 0;

public:
	GameMain();

	bool update();

	void playerInput();

	void reslut();

	bool checkSkip();

	bool checkEnd();
};
#endif