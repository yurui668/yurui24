#include "CSnake.h"
CSnake::CSnake(int x, int y, int length, Directions direction, int speed, char pic)
{
	m_HeadX = x;
	m_HeadY = y;
	m_Length = length;
	m_Speed = speed;
	m_pic = pic;
	m_direction = direction;

	for (int i = 0; i < m_Length; i++)
	{
		Cunit myunit(m_HeadX, m_HeadY, m_pic);//这里为什么要将点的实例放在循环里面
		MySnake.push_back(myunit);
		switch (m_direction)
		{
		case UP:MySnake[i].m_y += i;
			break; 
		case DOWN:MySnake[i].m_y -= i;
			break; 
		case LEFT:MySnake[i].m_x +=i;
			break;
		case RIGHT:MySnake[i].m_x-= i;
			break;
		default:
			break;
		}
	}
}
void CSnake::color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);

}
void CSnake::ShowCSnake()
{
	color(c);
	for (int i = 0; i < m_Length; i++)
	{
		MySnake[i].show();
	}
}
void CSnake::eraseSnake()
{

	for (int i = 0; i < m_Length; i++)
	{
		MySnake[i].erase();
	}
}
void CSnake::Move()
{
	Sleep(m_Speed);
	eraseSnake();
	for (int i = m_Length - 1; i > 0; i--)
	{
		MySnake[i].m_x = MySnake[i - 1].m_x;
		MySnake[i].m_y = MySnake[i - 1].m_y;
	}
	switch (m_direction)
	{
	case UP:
		MySnake[0].m_y -= 1;
		ShowCSnake();
		break;
	case DOWN:
		MySnake[0].m_y += 1;
		ShowCSnake();
		break;
	case LEFT:
		MySnake[0].m_x -= 1;
		ShowCSnake();
		break;
	case RIGHT:
		MySnake[0].m_x += 1;
		ShowCSnake();
		break;
	default:
		break;
	}
}
void CSnake::changeDirection(int vkValue)
{
	switch (vkValue)
	{
	    case'w':
		case'W':
			if (m_direction == LEFT || m_direction == RIGHT)
			{
				m_direction = UP;
			}
			break;
		case's':
		case'S':
			if (m_direction == LEFT || m_direction == RIGHT)
			{
				m_direction = DOWN;
			}
			break;
		case'a':
		case'A':
			if (m_direction == UP || m_direction == DOWN)
			{
				m_direction = LEFT;
			}
			break;
		case'd':
		case'D':
			if (m_direction == UP || m_direction == DOWN)
			{
				m_direction = RIGHT;
			}
			break;
		default:
			break;
	}
}
bool CSnake::eatfood(Food * Sfood)
{
	if (MySnake[0].m_x == Sfood->m_x && MySnake[0].m_y == Sfood->m_y)
	{
		int x = 1;
		while (x)
		{
			Sfood->erase();
			Sfood->CreatePos();
			for (int i = 0; i < m_Length; i++)
			{
				if (MySnake[i].m_x == Sfood->m_x && MySnake[i].m_y == Sfood->m_y)
				{
					break;
				}
				else
				{
					if (i == m_Length - 1 && MySnake[m_Length - 1].m_x != Sfood->m_x && MySnake[i].m_y != Sfood->m_y) // 最后一个蛇身节点不等于食物坐标
					{
						x = 0;
					}
				}
			}
		}
		Sfood->show();
		return 1;
	}
	else
		return 0;
}
bool CSnake::eatMfood(MagicFood* Mfood)
{
	if (MySnake[0].m_x == Mfood->m_x && MySnake[0].m_y == Mfood->m_y)
	{
		Mfood->erase();
		if (Mfood->CreateMPos());
		int x = 1;
		while (x)
		{
			for (int i = 0; i < m_Length; i++)
			{
				if (MySnake[i].m_x == Mfood->m_x && MySnake[i].m_y == Mfood->m_y)
				{
					Mfood->erase();
					Mfood->CreateM1Pos();
					break;
				}
				else
				{
					if (i == m_Length - 1 && MySnake[m_Length - 1].m_x != Mfood->m_x && MySnake[i].m_y != Mfood->m_y) //判断食物重现的位置是否与蛇身重合
					{
						x = 0;
					}
				}
			}
		}
		return 1;
	}
	else
		return 0;
}
void CSnake::growup()
{
	m_Length += 1;
	Cunit addSnake;
	MySnake.push_back(addSnake);
}
void CSnake::speedup()
{
	m_Speed -= 50;
}
void CSnake::speedminus()
{
	m_Speed -= 100;
}
void CSnake::minus()
{
	m_Length -= 1;
}
void CSnake::test()
{
	Cunit::gotoxy(1, 1);
}