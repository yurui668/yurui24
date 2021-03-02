#pragma once
#include "Cunit.h"
#include"ctime"
class MagicFood :
    public Cunit
{
public:
    MagicFood(int x = 0, int y = 0, char pic = '#');
    //virtual ~Food();
    void ShowMFood();
    bool CreateMPos();
    void CreateM1Pos();
    void color(int x);
    void starttime();
    int endtime();
    int time1();
    int time2();
public:
    clock_t start;
    clock_t end;
    clock_t f_start;
    clock_t f_end;
    static const int KLEFT = 0;
    static const int KRIGHT = 60;
    static const int KUP = 0;
    static const int KHEIGHT = 30;
    int box1;
    int box2;
    int box3;
    int box4;
    int box5;
    int box6;
    int box7;
    int box8;
    int box9;
    int box10;
    int box11;
    int box12;
    int box13;
    int box14;
    int box15;
    int box16;
    int box17;
    int box18;
    int box19;
    int box20;
    int time3 = 10;
    int flag=0;  //判断特殊食物是否存在标志
    int x;  //  随机生成不同功能的食物 
};

