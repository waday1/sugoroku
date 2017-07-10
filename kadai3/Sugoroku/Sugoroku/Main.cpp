#include <iostream>
#include"SugorokuDll.h"


using namespace std;

void main()
{
	int squareMax;
	while (true)
	{
		cout << "マス数を表示してください。";
		if (cin >> squareMax)
		{
			if (squareMax > 0)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "１以上の整数を入力してください。" << endl<<endl;
			}
		}

		else
		{
			cin.clear();
			cin.ignore();
			cout << "１以上の整数を入力してください。"<<endl<<endl;
		}
		
	}

	CSugorokuDll sugoroku(squareMax);

	while (sugoroku.update())
	{

	}
}
