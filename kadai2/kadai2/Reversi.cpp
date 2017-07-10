#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <Windows.h>

#include "Reversi.h"
#include"ConstColor.h"

using namespace std;

Reversi::Reversi()
{
	for (int i = 0; i < sizeof(stone) / sizeof(stone[0]); i++)
	{
		for (int j = 0; j < sizeof(stone[0]) / sizeof(stone[0][0]); j++)
		{
			stone[i][j] = Stone::None;
			isSet[i][i] = false;
		}
	}
	/*
	srand((unsigned int)time(NULL));
	int random;
	for (int i = 1; i < sizeof(stone) / sizeof(stone[0])-1; i++)
	{
	for (int j = 1; j < sizeof(stone[0]) / sizeof(stone[0][0])-1; j++)
	{
	random = rand();
	if (random % 2 == 0)
	stone[i][j] = Stone::Black;
	else if (random % 2 == 1)
	stone[i][j] = Stone::White;

	}
	}*/

	stone[3][3] = Stone::White;
	stone[3][4] = Stone::Black;
	stone[4][3] = Stone::Black;
	stone[4][4] = Stone::White;
}

void Reversi::show()
{
	setColor(COL_WHITE, COL_GREEN);

	cout << "┏━┳━┳━┳━┳━┳━┳━┳━┳━┓\n";
	cout << "┃　";
	for (int i = 0; i < sizeof(stone) / sizeof(stone[0]); i++)
	{
		setColor(COL_WHITE, COL_GREEN);
		cout << "┃ ";
		setColor(COL_BLACK, COL_GREEN);
		cout << i + 1;
	}
	setColor(COL_WHITE, COL_GREEN);
	cout << "┃\n";
	cout << "┣━╋━╋━╋━╋━╋━╋━╋━╋━┫\n";
	for (int i = 0; i < sizeof(stone) / sizeof(stone[0]); i++)
	{
		setColor(COL_WHITE, COL_GREEN);
		cout << "┃ ";
		setColor(COL_BLACK, COL_GREEN);
		cout << i + 1;
		for (int j = 0; j < sizeof(stone[0]) / sizeof(stone[0][0]); j++)
		{
			setColor(COL_WHITE, COL_GREEN);
			cout << "┃";
			if (stone[i][j] == Stone::Black)
			{
				setColor(COL_BLACK, COL_GREEN);
				cout << "●";
				setColor(COL_WHITE, COL_GREEN);
			}
			else if (stone[i][j] == Stone::White)
			{
				setColor(COL_WHITE, COL_GREEN);
				cout << "●";
			}
			else
			{
				cout << "　";
			}
		}

		cout << "┃";
		cout << "\n";
		if (i == (sizeof(stone) / sizeof(stone[0])) - 1)
		{
			setColor(COL_WHITE, COL_GREEN);
			cout << "┗━┻━┻━┻━┻━┻━┻━┻━┻━┛\n";
		}
		else
		{
			setColor(COL_WHITE, COL_GREEN);
			cout << "┣━╋━╋━╋━╋━╋━╋━╋━╋━┫\n";
		}
	}
	setColor(COL_WHITE, COL_BLACK);
}

void Reversi::isSetUpdate(Stone stoneColor)
{
	for (int i = 0; i < sizeof(isSet) / sizeof(isSet[0]); i++)
	{
		for (int j = 0; j < sizeof(isSet[0]) / sizeof(isSet[0][0]); j++)
		{
			isSet[i][j] = Reversi::isSetCheck(i, j, stoneColor);
		}
	}
}

bool Reversi::isSetCheck(int x, int y, Stone stoneColor)
{
	int count = 0;
	int i = 0, j = 0;

	//左上
	j = y - 1;
	for (int i = x - 1; i >= 0; i--)
	{
		if (j < 0 || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
		j--;
	}
	//上
	for (int i = x - 1; i >= 0; i--)
	{
		if (stone[i][y] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][y] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
	}
	//右上
	j = y + 1;
	for (int i = x - 1; i >= 0; i--)
	{
		if (j >= sizeof(stone[0]) / sizeof(stone[0][0]) || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
		j++;
	}

	//左
	for (int j = y - 1; j >= 0; j--)
	{
		if (stone[x][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[x][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (j == 0)
		{
			count = 0;
			break;
		}
		count++;
	}
	//右
	for (int j = y + 1; j <sizeof(stone[0]) / sizeof(stone[0][0]); j++)
	{
		if (stone[x][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[x][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (j == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
	}
	//左下
	j = y - 1;
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (j <0 || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
		j--;
	}
	//下
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (stone[i][y] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][y] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
	}
	//右下
	j = y + 1;
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (j >= sizeof(stone[0]) / sizeof(stone[0][0]) || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			if (count != 0)
				return true;
			else
			{
				count = 0;
				break;
			}
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
		j++;
	}
	return false;
}

void Reversi::changeStone(int x, int y, Stone stoneColor)
{
	stone[x][y] = stoneColor;
}

void Reversi::update(int x, int y, Stone stoneColor)
{
	changeStone(x, y, stoneColor);
	int count = 0;
	int i = 0, j = 0;

	//左上
	j = y - 1;
	for (int i = x - 1; i >= 0; i--)
	{
		if (j < 0 || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			break;
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
		j--;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x - 1 - i, y - 1 - i, stoneColor);
	}
	count = 0;
	//上
	for (int i = x - 1; i >= 0; i--)
	{
		if (stone[i][y] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][y] == stoneColor)
		{
			break;
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x - 1 - i, y, stoneColor);
	}
	count = 0;
	//右上
	j = y + 1;
	for (int i = x - 1; i >= 0; i--)
	{
		if (j >= sizeof(stone[0]) / sizeof(stone[0][0]) || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			break;
		}
		if (i == 0)
		{
			count = 0;
			break;
		}
		count++;
		j++;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x - 1 - i, y + 1 + i, stoneColor);
	}
	count = 0;
	//左
	for (int j = y - 1; j >= 0; j--)
	{
		if (stone[x][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[x][j] == stoneColor)
		{
			break;
		}
		if (j == 0)
		{
			count = 0;
			break;
		}
		count++;
	}
	for (int j = 0; j < count; j++)
	{
		changeStone(x, y - 1 - j, stoneColor);
	}
	count = 0;
	//右
	for (int j = y + 1; j <sizeof(stone[0]) / sizeof(stone[0][0]); j++)
	{
		if (stone[x][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[x][j] == stoneColor)
		{
			break;
		}
		if (j == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
	}
	for (int j = 0; j < count; j++)
	{
		changeStone(x, y + 1 + j, stoneColor);
	}
	count = 0;
	//左下
	j = y - 1;
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (j <0 || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			break;
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
		j--;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x + 1 + i, y - 1 - i, stoneColor);
	}
	count = 0;
	//下
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (stone[i][y] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][y] == stoneColor)
		{
			break;
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x + 1 + i, y, stoneColor);
	}
	count = 0;
	//右下
	j = y + 1;
	for (int i = x + 1; i <sizeof(stone) / sizeof(stone[0]); i++)
	{
		if (j >= sizeof(stone[0]) / sizeof(stone[0][0]) || stone[i][j] == Stone::None)
		{
			count = 0;
			break;
		}
		if (stone[i][j] == stoneColor)
		{
			break;
		}
		if (i == sizeof(stone[0]) / sizeof(stone[0][0]) - 1)
		{
			count = 0;
			break;
		}
		count++;
		j++;
	}
	for (int i = 0; i < count; i++)
	{
		changeStone(x + 1 + i, y + 1 + i, stoneColor);
	}
	count = 0;
}

void Reversi::setColor(int fg, int bg)
{
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr = 0;
	if (fg & COL_INTENSITY)
		attr |= FOREGROUND_INTENSITY;
	if (fg & COL_RED_MASK)
		attr |= FOREGROUND_RED;
	if (fg & COL_GREEN_MASK)
		attr |= FOREGROUND_GREEN;
	if (fg & COL_BLUE_MASK)
		attr |= FOREGROUND_BLUE;

	if (bg & COL_INTENSITY)
		attr |= BACKGROUND_INTENSITY;
	if (bg & COL_RED_MASK)
		attr |= BACKGROUND_RED;
	if (bg & COL_GREEN_MASK)
		attr |= BACKGROUND_GREEN;
	if (bg & COL_BLUE_MASK)
		attr |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(hCons, attr);
}