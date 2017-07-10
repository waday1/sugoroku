#include"GameMain.h"
#include<conio.h>
#include "size.h"

GameMain::GameMain()
{

}

bool GameMain::update()
{
	reversi.show();
	if (endCount >= 4||checkEnd())
	{
		reslut();
		cout << "どこにも置けなくなりました"<<endl;
		cout << "黒は"<<blackCount<<endl;
		cout << "白は" << whiteCount << endl;
		if (blackCount > whiteCount)
		{
			cout << "黒の勝ちです"<< endl;
		}
		else if (blackCount < whiteCount)
		{
			cout << "白の勝ちです" << endl;
		}
		else
		{
			cout << "引き分けです" << endl;
		}
		cout << "何かキーを押してください";
		_getch();

		return false;
	}

	if (isSkip == false)
	{
		oldInputX = com.x;
		oldInputY = com.y;

		if (oldInputX != 0)
		{
			cout << "前回の入力は[" << oldInputX << "," << oldInputY << "]でした。\n";
		}
	}
	else
	{
		cout << "相手はスキップしました。\n";
		cout << "何かキーを押してください";
		endCount++;
	}

	reversi.isSetUpdate(Stone::Black);

	isSkip = checkSkip();

	if (isSkip == false)
	{
		endCount = 0;
		playerInput();

		reversi.update(x - 1, y - 1, Stone::Black);
	}
	else
	{
		_getch();
	}

	system("cls");

	reversi.show();

	if (isSkip == false)
	{
		oldInputX = x;
		oldInputY = y;

		if (oldInputX != 0)
		{
			cout << "前回の入力は[" << oldInputX << "," << oldInputY << "]でした。\n";
			cout << "敵の番です。" << endl;
			cout << "何かキーを押してください";
			_getch();
		}
	}
	else
	{
		cout << "どこにも置けないのでスキップします。"<<endl;
		cout << "何かキーを押してください";
		endCount++;
		_getch();
	}

	reversi.isSetUpdate(Stone::White);

	isSkip=com.Input(reversi.isSet,reversi.stone);

	if(isSkip==false)
	{
		endCount = 0;
		reversi.update(com.x - 1, com.y - 1, Stone::White);
	}

	system("cls");
	return true;
}

void GameMain::playerInput()
{
	cout << "あなたの番です。\n";
	while (true)
	{
		cout << "1～8の範囲を入力してください\n";
		cout << "縦 横";
		cin >> inputX >> inputY;
		x = inputX[0] - '0';
		y = inputY[0] - '0';
		cout << "\n";
		//石が既定の範囲内ならばturuでbreak
		if ((x > 0 && x <= sizeof(reversi.stone) / sizeof(reversi.stone[0])) && (y > 0 && y <= sizeof(reversi.stone[0]) / sizeof(reversi.stone[0][0])) && inputX.length() == 1 && inputY.length() == 1)
		{
			if (reversi.isSet[x - 1][y - 1] == true)
			{
				if (reversi.stone[x - 1][y - 1] == Stone::None)
				{
					break;
				}
				else
				{
					cout << "その場所にはすでに石が置いてあります。";
				}
			}
			else
			{
				cout << "その場所に置けません。";
			}
		}
		cout << "もう一度入力してください\n";
	}

}

void GameMain::reslut()
{
	int count = 0;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (reversi.stone[i][j] == Stone::White)
			{
				whiteCount++;
			}
			if (reversi.stone[i][j] == Stone::Black)
			{
				blackCount++;
			}
		}
	}

}

bool GameMain::checkSkip()
{
	int count = 0;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (reversi.isSet[i][j] == true && reversi.stone[i][j] == Stone::None)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	return false;
	
}

bool GameMain::checkEnd()
{

	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if ( reversi.stone[i][j] == Stone::None)
			{
				return false;
			}
		}
	}
	return true;
}