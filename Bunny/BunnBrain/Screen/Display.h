#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <vector>
#include<stdlib.h>

class Display{
    public:
    void setup();

    void stringPush(int x, int y, string str);

    void BunMoves(int coord);

    void PMoves(int coord);

    void gg(bool ohnos);
    
    void yaas(bool yes);

    void render();

    private:
    std::vector<vector<char>> screen;
};
#include "Display.cpp"
#endif
