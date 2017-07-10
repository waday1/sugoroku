#include"Com.h"
#include"size.h"

Com::Com()
{
	x = 0;
	y = 0;
}

bool Com::Input(bool isSet[8][8], Stone stone[8][8])
{
	int count = 0;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (isSet[i][j] == true&&stone[i][j]==Stone::None)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<int> rand(1, count);
	int input = rand(mt);
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (isSet[i][j] == true && stone[i][j] == Stone::None)
			{
				input--;
				if (input == 0)
				{
					x = i+1;
					y = j + 1;
				}
			}
		}
	}
	return false;
}