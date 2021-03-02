#include "MagicFood.h"
MagicFood::MagicFood(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_Pic = pic;
	srand((int)time(0));
	box1 = 5 + rand() % 10;
	box2 = 15+ rand() % 15;
	box3 = 30 + rand() % 20;
	box4 = 50 + rand() % 25;
	box5 = 75 + rand() % 35;
	box6 = 120 + rand() % 30;
	box7 = 150 + rand() % 30;
	box8 = 180+ rand() % 30;
	box9 = 210 + rand() % 30;
	box10 = 250 + rand() % 30;
	box11 = 280 + rand() % 30;
	box12 = 310 + rand() % 30;
	box13 = 340+ rand() % 30;
	box14 = 370 + rand() % 30;
	box15 = 380 + rand() % 30;
	box16 = 410 + rand() % 30;
}
bool MagicFood::CreateMPos()
{
	/*srand((int)time(0));
	int p = time3 + rand() % 50;
	time3 += 5;*/
	srand((int)time(0));
	x = 1 + rand() % 6;
	endtime();
	if ((box1 ==int(end-start)/CLOCKS_PER_SEC||box2== int(end - start)/CLOCKS_PER_SEC ||box3== int(end - start) / CLOCKS_PER_SEC ||box4== int(end - start) / CLOCKS_PER_SEC ||box5== int(end - start) / CLOCKS_PER_SEC ||box6== int(end - start) / CLOCKS_PER_SEC ||box7== int(end - start) / CLOCKS_PER_SEC ||box8== int(end - start) / CLOCKS_PER_SEC|| box9 == int(end - start) / CLOCKS_PER_SEC || box10 == int(end - start) / CLOCKS_PER_SEC || box11 == int(end - start) / CLOCKS_PER_SEC || box12 == int(end - start) / CLOCKS_PER_SEC || box13 == int(end - start) / CLOCKS_PER_SEC || box14 == int(end - start) / CLOCKS_PER_SEC || box15 == int(end - start) / CLOCKS_PER_SEC || box16 == int(end - start) / CLOCKS_PER_SEC) && flag==0)
	{
		m_x = KLEFT + 2 + rand() % (KRIGHT - KLEFT - 2);
		m_y = KUP + 1 + rand() % (KHEIGHT - KUP - 2);
		flag = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}
void MagicFood::CreateM1Pos()
{
	srand((int)time(0));
	m_x = KLEFT + 2 + rand() % (KRIGHT - KLEFT - 2);
	m_y = KUP + 1 + rand() % (KHEIGHT - KUP - 2);
}
void MagicFood::ShowMFood()
{
	color(x);
	show();
}
void MagicFood::color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
/*int MagicFood::time1()
{


	return int(end - start)/CLOCKS_PER_SEC;
}*/
int MagicFood::time2()
{
	f_start = clock();
	f_end = clock();
	return int(f_end - f_start) / CLOCKS_PER_SEC; //把时间转换成秒
}
void MagicFood::starttime()
{
	start = clock();
}
int MagicFood::endtime()
{
	end = clock();
	return end;
}