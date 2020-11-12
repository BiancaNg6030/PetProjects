
#include<iostream>
using namespace std;

void Display::stringPush(int x, int y, string str)
{
    for(int i = y; i < y+str.length(); i++)
    {
        screen[x][i] = str.at(i-y);
    };
}

void Display::setup()
{
    for(int i = 0; i < 12 ; i++)
    {
        vector<char> temp;
        for(int j = 0; j < 25; j++)
        {
            temp.push_back(32);
        };
        screen.push_back(temp);
    };

    string temp = "Bunn:x         1 | 2 | 3 ";
    stringPush(0,0,temp);

    temp ="You:o   Moves:-----------";
    stringPush(1,0,temp);

    temp = "(\\ /)   Left : 4 | 5 | 6";
    stringPush(2,0,temp);

    temp = "(o o)         -----------";
    stringPush(3,0,temp);

    temp = "c(\")(\")        7 | 8 | 9";
    stringPush(4,0,temp);

    temp = "   |   |";
    stringPush(6,0,temp);
    temp = "-----------  Your Turn";
    stringPush(7,0,temp);
    temp = "   |   |     Enter a";
    stringPush(8,0,temp);
    temp = "-----------  number to";
    stringPush(9,0,temp);
    temp = "   |   |     play";
    stringPush(10,0,temp);
}

void Display::BunMoves(int coord)
{
    switch(coord)
    {
        case 1: screen[6][1] = 120;
                screen[0][15] = 32;
        break;

        case 2:screen[6][5] = 120 ;
               screen[0][19] = 32;
        break;

        case 3:screen[6][9] = 120 ;
        screen[0][23] = 32;
        break;

        case 4:screen[8][1] = 120 ;
        screen[2][15] = 32;
        break;

        case 5:screen[8][5] = 120 ;
        screen[2][19] = 32;
        break;

        case 6:screen[8][9] = 120 ;
        screen[2][23] = 32;
        break;

        case 7:screen[10][1] = 120 ;
        screen[4][15] = 32;
        break;

        case 8:screen[10][5] = 120 ;
        screen[4][19] = 32;
        break;

        case 9:screen[10][9] = 120 ;
        screen[4][23] = 32;
        break;
    };
}

void Display::PMoves(int coord)
{
    switch(coord)
    {
        case 1: screen[6][1] = 111;
                screen[0][15] = 32;
        break;

        case 2:screen[6][5] = 111 ;
               screen[0][19] = 32;
        break;

        case 3:screen[6][9] = 111 ;
        screen[0][23] = 32;
        break;

        case 4:screen[8][1] = 111 ;
        screen[2][15] = 32;
        break;

        case 5:screen[8][5] = 111 ;
        screen[2][19] = 32;
        break;

        case 6:screen[8][9] = 111;
        screen[2][23] = 32;
        break;

        case 7:screen[10][1] = 111 ;
        screen[4][15] = 32;
        break;

        case 8:screen[10][5] = 111 ;
        screen[4][19] = 32;
        break;

        case 9:screen[10][9] = 111 ;
        screen[4][23] = 32;
        break;
    };
}

void Display::gg(bool ohnos)
{
    screen[3][1] = 32;
    screen[3][2] = 62;
    screen[3][3] = 60;
}

void Display::yaas(bool yes)
{
    screen[3][1] = 94;
    screen[3][2] = 32;
    screen[3][3] = 94;
}

void Display::render()
{
    for(int i = 0; i < screen.size(); i++)
    {
        for(int j = 0; j<screen[0].size();j++)
        {
            cout<<screen[i][j];
        };
        cout<<endl;
    };
}