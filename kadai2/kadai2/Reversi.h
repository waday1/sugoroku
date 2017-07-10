#ifndef Revarsi_h
#define Revarsi_h


enum class Stone {
	None, Black, White
};

class Reversi
{
public:
	int Wide = 8, Height = 8;
	Stone stone[8][8];
	bool isSet[8][8];


public:
	Reversi();
	void show();

	void isSetUpdate(Stone stoneColor);
	bool isSetCheck(int x, int y, Stone stoneColor);

	void changeStone(int x, int y, Stone stoneColor);

	void update(int x, int y, Stone stoneColor);

	void setColor(int fg, int bg);
};
#endif 