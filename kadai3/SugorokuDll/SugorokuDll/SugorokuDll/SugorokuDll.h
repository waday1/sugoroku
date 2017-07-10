// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SUGOROKUDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SUGOROKUDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SUGOROKUDLL_EXPORTS
#define SUGOROKUDLL_API __declspec(dllexport)
#else
#define SUGOROKUDLL_API __declspec(dllimport)
#endif

enum SquareType
{
	Start, Goal, Back, Forward, Pass, Normal
};
// This class is exported from the SugorokuDll.dll
class SUGOROKUDLL_API CSugorokuDll {
private:
	SquareType *squares;
	int squareMax;
	int playerPos;
	bool isGool;
	bool isPass;
	int input;
	int totalRoll;

public:
	CSugorokuDll(int squareMax);
	~CSugorokuDll();
	void squaresInitialize();
	bool update();
	void show();
	void rollDice();
	void squareEffect();
};

extern SUGOROKUDLL_API int nSugorokuDll;

SUGOROKUDLL_API int fnSugorokuDll(void);
