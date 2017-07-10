// SugorokuDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SugorokuDll.h"
#include<iostream>
#include <iomanip>
#include <random>
#include<conio.h>

using namespace std;

// This is an example of an exported variable
SUGOROKUDLL_API int nSugorokuDll=0;

// This is an example of an exported function.
SUGOROKUDLL_API int fnSugorokuDll(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see SugorokuDll.h for the class definition
CSugorokuDll::CSugorokuDll(int squareMax)
{
	CSugorokuDll::squareMax = squareMax;
	squares = new SquareType[squareMax];
	squaresInitialize();
	playerPos = 0;
	isGool = false;
	isPass = false;
	input = 0;
	totalRoll = 0;
}

CSugorokuDll::~CSugorokuDll()
{
	delete[](squares);
}

void CSugorokuDll::squaresInitialize()
{
	random_device rand;
	mt19937 mt(rand());
	uniform_int_distribution<> squareType(2, 5);
	for (int i = 0; i < squareMax; i++)
	{
		squares[i] = (SquareType)squareType(mt);
	}
	squares[0] = SquareType::Start;
	squares[squareMax - 1] = SquareType::Goal;
}


bool CSugorokuDll::update()
{
	show();
	squareEffect();
	if (isGool == true)
	{
		show();
		cout<<totalRoll<<"回目でゴールしました。おめでとうございます。" << endl;
		return false;
	}
	rollDice();
	
	return true;
}

void CSugorokuDll::show()
{
	system("cls");
	for (int i = 0; i < squareMax; i++)
	{
		if (i % 10 == 0)
		{
			cout << "┏";
		}

		if (i % 10 == 9 || i == squareMax - 1)
		{
			cout << "━┓" << endl;

			for (int j = 0; j <= i % 10; j++)
			{
				if (j % 10 == 0)
				{
					cout << "┃";
				}
				switch (squares[(i / 10) * 10 + j])
				{
				case SquareType::Start:
					cout << "Ｓ┃";
					break;
				case SquareType::Goal:
					cout << "Ｇ┃";
					break;
				case SquareType::Back:
					cout << "-1┃";
					break;
				case SquareType::Forward:
					cout << "+1┃";
					break;
				case SquareType::Pass:
					cout << "休┃";
					break;
				case SquareType::Normal:
					cout << "　┃";
					break;
				default:
					break;
				}
				if (j % 10 == 9 || j == i % 10)
				{
					cout << endl;
				}
			}

			for (int j = 0; j <= i % 10; j++)
			{
				if (j % 10 == 0)
				{
					cout << "┗";
				}
				if (j % 10 == 9 || j == i % 10)
				{
					cout << "━┛" << endl;
					for (int k = 0; k <= i % 10; k++)
					{
						if (playerPos == (i / 10) * 10 + k || isGool == true && (i / 10) * 10 + k + 1 == squareMax)
						{
							cout << setw(10 + k * 4) << "↑Player" << endl;
							break;
						}
						else if (k == i % 10)
						{
							cout << endl;
							break;
						}
					}
				}
				else
				{
					cout << "━┻";
				}

			}
		}

		else
			cout << "━┳";
	}

	if (input > 0)
	{
		cout << input << "が出ました。" << endl;
	}
}

void CSugorokuDll::rollDice()
{
	random_device rand;
	mt19937 mt(rand());
	uniform_int_distribution<> dice(1, 6);


	cout << "何かキーを入力するとさいころを振ります。";

	_getch();
	totalRoll += 1;

	input = dice(mt);

	if (isPass == false)
	{
		playerPos += input;
	}
}

void CSugorokuDll::squareEffect()
{
	switch (squares[playerPos])
	{
	case SquareType::Forward:
		playerPos += 1;
		cout << "1マス進みます。" << endl;
		input = 0;
		_getch();
		show();
		break;
	case SquareType::Back:
		playerPos -= 1;
		input = 0;
		cout << "1マス戻ります。" << endl;
		_getch();
		show();
		break;
	case SquareType::Pass:
		if (isPass == false)
		{
			isPass = true;
			cout << "一回休みです。" << endl;
		}
		else
		{
			isPass = false;
		}
		break;
	case SquareType::Goal:
		isGool = true;
		break;
	default:
		break;
	}
	if (playerPos >=squareMax-1)
	{
		isGool = true;
	}
}

