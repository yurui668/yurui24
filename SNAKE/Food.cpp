#include "Food.h"
Food::Food(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_Pic = pic;
}
void Food::CreatePos()
{
	srand((int)time(0));
	m_x = KLEFT + 2 + rand() % (KRIGHT - KLEFT - 2);
	m_y = KUP + 1 + rand() % (KHEIGHT - KUP - 2);
}
void Food::ShowFood()
{
	show();
}
void Food::color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
