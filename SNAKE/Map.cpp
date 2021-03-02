#include "Map.h"
void Map::color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
Map::Map(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_Pic = pic;
}
void Map::DrawGameArea()
{
	for (int i = KLEFT; i <= KRIGHT; i += 2) //  上下边界
	{
		gotoxy(i, KUP);
		color(5);
		cout << "□";
		gotoxy(i, KDOWN);
		cout << "□";
	}
	for (int j = 1; j < KDOWN; j++)// 左右墙,这里为什么j只能小于30
	{
		gotoxy(KLEFT, j);
		color(2);
		cout << "□";
		gotoxy(KRIGHT, j);
		cout << "□";
	}

	/*for (int i = 2; i < 58; i += 2)
	{
		for (int j = 1; j < 30; j++)
		{
			gotoxy(i, j);
			color(5);
			cout << "■";
		}
	}
	*/
}

