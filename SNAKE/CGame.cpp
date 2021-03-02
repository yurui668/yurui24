#include "CGame.h"
CGame::CGame(int Score, int Level,Food * MyFood,CSnake * Snake1,MagicFood * MaFood)
{
    m_Score = Score;
    m_Level = Level;
    m_pFood= MyFood;
    m_pSnake = Snake1;
    m_pMFood = MaFood;
}
void CGame::run()
{
    int keydown = 0;
    while (1)
    {
        while (_kbhit())
        {
            keydown = _getch();
            if (keydown == ' ')
            {
                system("pause");
            }
            if (keydown == 27)
            {
                return;
            }
            if (keydown == 0x3B)
            {
                m_pSnake->speedup();
            }
            else
            {
                m_pSnake->changeDirection(keydown);
                m_pSnake->Move();
            }
            if (m_pSnake->eatfood(m_pFood))
            {
                m_pSnake->growup();
                m_Score += 10;
                n += 1;
                if (n % 2 == 0)
                {
                    m_Level += 1;
                    m_pSnake->speedup();
                }
                Cunit::gotoxy(63, 7);
                Map::color(5);
                cout << " * 当前得分:" << m_Score<<" *";
               /* Cunit::gotoxy(63, 8);
                cout << "当前速度:" << m_pSnake->m_Speed;
                Cunit::gotoxy(80, 8);
                cout << "当前长度:" << m_pSnake->m_Length;*/
            }
            if (CheckFailed() || m_Level== KLEVEL_OFFSET|| m_Score==KSCORE_OFFSET)
            {
                return;// endgame();
            }
        }
        m_pSnake->Move();
        if (m_pSnake->eatfood(m_pFood))
        {
            m_pSnake->growup();
            m_Score += 10;
            n += 1;
            if (n % 5 == 0)
            {
                m_Level += 1;
                m_pSnake->speedup();
            }
            Cunit::gotoxy(63, 7);
            Map::color(5);
            cout << " * 当前得分:" << m_Score<<" *";
            Cunit::gotoxy(63, 8);
           /* cout << "当前速度:" << m_pSnake->m_Speed;
            Cunit::gotoxy(80, 8);
            cout << "当前长度:" << m_pSnake->m_Length;*/
        }
        if (CheckFailed())
        {
            return ;//endgame();
        }
    }
}
void CGame::run2()
{
    int keydown = 0;
    while (1)
    {
        if (m_pMFood->CreateMPos())
        {
            m_pMFood->ShowMFood();
        }
        while (_kbhit())
        {
            keydown = _getch();
            if (keydown == ' ')
            {
                system("pause");
            }
            else
            {
                m_pSnake->changeDirection(keydown);
                m_pSnake->Move();
            }
            if (m_pSnake->eatfood(m_pFood))
            {
                m_pSnake->growup();
                m_Score += 10;
                n += 1;
                if (n % 2 == 0)
                {
                    m_Level += 1;
                    m_pSnake->speedup();
                }
                Cunit::gotoxy(63, 7);
                Map::color(5);
                cout << " * 当前得分:" << m_Score << " *";
                /* Cunit::gotoxy(63, 8);
                 cout << "当前速度:" << m_pSnake->m_Speed;
                 Cunit::gotoxy(80, 8);
                 cout << "当前长度:" << m_pSnake->m_Length;*/
            }
            if (m_pSnake->eatMfood(m_pMFood))
            {
                m_pMFood->flag = 0;
                switch (m_pMFood->x)
                {
                case1:
                    m_pSnake->growup();
                    m_Score += 30;
                    n += 1;
                    break;
                case2:
                    m_pSnake->growup();
                    m_pSnake->growup();
                    n += 1;
                    break;
                case3:
                    m_pSnake->growup();
                    m_pSnake->speedminus();
                    n += 1;
                    break;
                case4:
                    m_pSnake->minus();
                    n += 1;
                    break;
                case5:
                    PlaySound(TEXT("C:\\Windows\\Media\\Ring09"), NULL, SND_FILENAME | SND_ASYNC);
                    break;
                case6:
                    m_pSnake->c = 6;
                    break;
                /*case7:
                    break;
                case8:

                    break;*/
                default:
                    break;
                }
                if (n % 2 == 0)
                {
                    m_Level += 1;
                    m_pSnake->speedup();
                }
                Cunit::gotoxy(63, 7);
                Map::color(5);
                cout << " * 当前得分:" << m_Score << " *";
            }
            if (CheckFailed() || m_Level == KLEVEL_OFFSET || m_Score == KSCORE_OFFSET)
            {
                return;
            }
        }
        m_pSnake->Move();
        if (m_pSnake->eatfood(m_pFood))
        {
            m_pSnake->growup();
            m_Score += 10;
            n += 1;
            if (n % 5 == 0)
            {
                m_Level += 1;
                m_pSnake->speedup();
            }
            Cunit::gotoxy(63, 7);
            Map::color(5);
            cout << " * 当前得分:" << m_Score << " *";
            Cunit::gotoxy(63, 8);
            /* cout << "当前速度:" << m_pSnake->m_Speed;
             Cunit::gotoxy(80, 8);
             cout << "当前长度:" << m_pSnake->m_Length;*/
        }
        if (m_pSnake->eatMfood(m_pMFood))
        {
            m_pMFood->flag = 0;
            m_pSnake->growup();
            m_Score += 20;
            n += 1;
            if (n % 2 == 0)
            {
                m_Level += 1;
                m_pSnake->speedup();
            }
            Cunit::gotoxy(63, 7);
            Map::color(5);
            cout << " * 当前得分:" << m_Score << " *";
        }
        if (CheckFailed())
        {
            return;  // endgame();
        }
    }
}
int CGame::endgame()
{
    system("cls");
    Cunit::gotoxy(40, 13);
    getchar();   //  清除按任意键继续字体
    cout << "Game Over";
    gotoxy(30, 15);
    cout << "我要重新玩一局------1";
    gotoxy(60, 15);
    cout << "不玩啦 退出吧-------2";
    gotoxy(40, 21);
    cout << "你的选择[1 2]:[ ]\b\b";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        system("cls");
        /*Map GameMap;
        GameMap.DrawGameArea();
        CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // 解决光标问题
        DrawGameInfo();
        m_pFood->color(5);
        m_pFood->CreatePos();
        m_pFood->ShowFood();
        m_pSnake->ShowCSnake();
        run();*/
        return 1;
        break;
    }
    case 2:
    {
        system("cls");
        //welcometogame();
        return 0;
        break;
    }
    /*case 3:
    {
        exit(0);
        break;
    }*/
    }
}
bool CGame::CheckFailed()  // bool类似函数默认返回值为1 如果for循环外层不加return 0 会出现蛇初始化就死的情况
{
    // if(m_pSnake->HeadX == 0 || m_pSnake->HeadX == 29)
    if (m_pSnake->MySnake[0].m_y == KUP || m_pSnake->MySnake[0].m_y == KDOWN || m_pSnake->MySnake[0].m_x == KLEFT+1 || m_pSnake->MySnake[0].m_x == KRIGHT)
    {
        return 1;
    }
    for (int i = 4; i < m_pSnake->m_Length; i++)
    {  
        if ((m_pSnake->MySnake[0].m_x == m_pSnake->MySnake[i].m_x) && (m_pSnake->MySnake[0].m_y == m_pSnake->MySnake[i].m_y))
        {
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
void CGame::DrawGameInfo()
{
    Cunit::gotoxy(63, 7);
    Map::color(5);
    cout << " * 当前得分:" <<m_Score<<" "<<"*";
    Cunit::gotoxy(63, 9);
    cout << " 小提示 ";
    Cunit::gotoxy(63, 12);
    cout << "-------------------";
    Cunit::gotoxy(63, 15);
    cout << " 每个食物得分：10分";
    Cunit::gotoxy(63, 17);
    cout << " 不能撞墙，不能咬到自己";
    Cunit::gotoxy(63, 19);
    cout << " 用 w s a d 分别控制上下左右";
    Cunit::gotoxy(63, 21);
    cout << " F1加速";
    Cunit::gotoxy(63, 23);
    cout << "空格键暂停游戏 ESC键退出游戏";
}
void CGame::welcometogame()
{
    gotoxy(40, 10);
    cout << "欢迎来到贪吃蛇小游戏";
    gotoxy(40, 13);
    cout << "请选择你的游戏模式:";
    gotoxy(40, 16);
    cout << "1:一般模式";
    gotoxy(60, 16);
    cout << "2;神秘事件模式";
    gotoxy(50, 19);
    cout << "3:退出游戏";
    gotoxy(45, 22);
    cout << "你的选择[1 2 3]:[ ]\b\b";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        system("cls");
        Map GameMap;
        GameMap.DrawGameArea();
        CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // 解决光标问题
        DrawGameInfo();
        m_pFood->color(5);
        m_pFood->CreatePos();
        m_pFood->ShowFood();
        m_pSnake->ShowCSnake();
        run();
        break;
    }
    case 2:
    {
        system("cls");
        Map GameMap;
        GameMap.DrawGameArea();
        CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); // 解决光标问题
        DrawGameInfo();
        m_pFood->color(5);
        m_pFood->CreatePos();
        m_pFood->ShowFood();
        m_pSnake->ShowCSnake();
        run2();
        break;
    }
    case 3:
        {
            exit(0);
            break;
        }
    }
}
void CGame::gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}