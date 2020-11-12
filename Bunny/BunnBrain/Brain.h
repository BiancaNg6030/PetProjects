#ifndef BRAIN_H
#define BRAIN_H

#include "Offence.h"
#include "Defence.h"
#include "Screen/Display.h"
#include <vector>

class Brain
{
    public:
    void setup();

    void thinking(int move, bool me);

    bool isover();
    bool islegal(int mv);
    private:
    int movecount;
    vector<int> moves;    
    Defence MygameD;
    Offence MygameO;
    Display screen;
};

#include "Brain.cpp"
#endif