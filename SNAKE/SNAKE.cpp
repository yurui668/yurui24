﻿// SNAKE.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"Cunit.h"
#include <iostream>
#include"Food.h"
#include"Map.h"
#include"CSnake.h"
#include"CGame.h"
#include"windows.h"
#include"ctime"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
int main()
{
	int x = 1;
	while (x)
	{
		Food MyFood1;
		MagicFood MaFood1;
		MaFood1.starttime();
		CSnake Snake1;
		CGame CGame1(0, 1, &MyFood1, &Snake1, &MaFood1);
		PlaySound(TEXT("C:\\Windows\\Media\\Ring09"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		CGame1.welcometogame();
		x=(CGame1.endgame());
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始F调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
