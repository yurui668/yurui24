#include "Cunit.h"
#include"iostream"
using namespace std;
Cunit::Cunit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_Pic = pic;
}
void Cunit::show()
{
	gotoxy(m_x, m_y);
	cout << m_Pic;
}
void Cunit::gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Cunit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}
