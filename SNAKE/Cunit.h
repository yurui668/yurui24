#pragma once
#include<windows.h>
#include<iostream>
class Cunit
{
public:
	int m_x;
	int m_y;
	char m_Pic;
public:
	Cunit(int x = 0, int y = 0, char pic = '*');
	//virtual ~cunit();
	void erase();
	static void gotoxy(int x, int y);
	void show();
};

