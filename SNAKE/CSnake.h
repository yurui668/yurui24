#pragma once
#include"Food.h"
#include"Cunit.h"
#include<vector>
#include"conio.h"
#include"MagicFood.h"
using namespace std;
typedef enum Directions
{UP,DOWN,LEFT,RIGHT};
class CSnake
{
public :
	CSnake(int x = 40, int y = 10, int length = 4,Directions direction=RIGHT,int speed = 350,char pic= '*');
	//virtual ~CSnake();
	void ShowCSnake();
	void Move();
	void eraseSnake();
	void changeDirection(int vkValue); //wsad
	bool eatfood(Food * Sfood);
	bool eatMfood(MagicFood* Mfood);
	void growup();
	void minus();
	void speedup();
	void speedminus();
	void color(int x);
	void test();
public :
	vector<Cunit> MySnake;
	int m_Length;
	int m_HeadX;
	int m_HeadY;
	int m_Speed;
	int m_pic;
	Directions m_direction;
	int c = 5;  // 蛇身的颜色
};

