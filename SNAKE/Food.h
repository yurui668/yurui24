#pragma once
#include "Cunit.h"
#include"ctime"
class Food :
    public Cunit
{
public:
    Food(int x = 0, int y = 0, char pic = '$');
    //virtual ~Food();
    void ShowFood();
    void CreatePos();
    void color(int x);
    static const int KLEFT = 0;
    static const int KRIGHT = 60;
    static const int KUP = 0;
    static const int KHEIGHT = 30;
};

