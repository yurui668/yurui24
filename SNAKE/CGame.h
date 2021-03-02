#pragma once
#include"Food.h"
#include"Map.h"
#include"CSnake.h"
#include<windows.h>
#include"Cunit.h"
#include"Map.h"
#include"cmath"
#include"MagicFood.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
class CGame
{
public:
	CGame(int Score,int Level,Food * MyFood,CSnake * Snake1, MagicFood* MaFood);
	//virtual ~CGame();
	void run();
	void run2();
	bool CheckFailed();
	void DrawGameInfo();
	//BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
	void welcometogame();
	int endgame();
	void gotoxy(int x, int y);
public:
	static const int KUP=0;
	static const int KDOWN=30;
	static const int KLEFT=0;
	static const int KRIGHT=60;
	static const int KSCORE_OFFSET=1000;
	static const int KLEVEL_OFFSET=10;
public:
	Food* m_pFood;
	CSnake* m_pSnake;
	int m_Score=0;
	int m_Level=1;
	int m_MaxScore = 0;
	int n=0;
	MagicFood* m_pMFood;
};

