#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
bool status;
const int length = 20;
const int width = 50;
int x,y,FruitX,FruitY,score;
enum eDirection {STOP = 0, LEFT,RIGHT,UP,DOWN};
eDirection dir;
int tailX[100],tailY[100];
int ntail;
void Setup()
{
    status = false;
    dir = STOP;
    x = width / 2;
    y = length / 2;
    FruitX = rand() % width;
    FruitY = rand() % length;

    score = 0;
}
void Print()
{
    system("cls");
    for(int i = 0;i < width +2;i++)
    {
        cout << "#";
    }
     cout << endl;
     for(int i = 0;i < length;i++)
    {
    for(int j = 0;j < width;j++)
    {
       if(j == 0 )
        cout << "#";

        if(i == y && j == x)
            cout << "O";
        else if (i == FruitY && j == FruitX)
            cout << "*";
        else
        {
            bool print = false;
            for(int k = 0; k < ntail; k++)
            {
                if(tailX[k] == j && tailY[k] == i)
                {
                    cout << "o";
                    print = true;
                }
            }
            if(!print)
             cout << " ";

        }

        if(j == (width - 1))
            cout << "#";
    }
        cout << endl;
    }

     for(int i = 0;i < width +2;i++)
    {
        cout << "#";
    }

    cout << endl <<  "Score : " <<score;

}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'w' :
            dir = UP;
            break;
        case 's' :
            dir = DOWN;
            break;
        case 'a' :
            dir = LEFT;
            break;
        case 'd' :
            dir = RIGHT;
            break;
        case 'x' :
            status = true;
            break;

        }


    }

}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < ntail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;
    }

    //if(x > width || x < 0 || y > length || y < 0)
      //  status = true;
    if(x >= width) x = 0; else if(x < 0 ) x = width -1;
    if(y >= length) y = 0; else if(y < 0 ) y = length -1;

    for(int i = 0;i < ntail; i++)
    {
        if(tailX[i] == x && tailY[i] == y)
            status = true;
    }

    if(x == FruitX && y == FruitY)
    {
    score = score + 10;
    FruitX = rand() % width;
    FruitY = rand() % length;
    ntail++;

    }

}
int  main()
{
    Setup();
    while(!status)
    {
        Print();
        Input();
        Logic();
        Sleep(50);

    }
}
