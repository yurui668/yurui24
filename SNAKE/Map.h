#pragma once
#include "Cunit.h"
#include<iostream>
using namespace std;
class Map :
    public Cunit
{
public:
    Map(int x = 0, int y = 0, char pic = '*');
    void DrawGameArea();
    void DrawGameInfo();
    static void color(int x);
public:
    static const int KUP = 0;
    static const int KDOWN = 30;
    static const int KLEFT = 0;
    static const int KRIGHT = 60;
    static const int KSCORE_OFFSET = 500;
    static const int KLEVEL_OFFSET = 10;
};

