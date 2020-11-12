#ifndef OFFENCE_H
#define OFFENCE_H

#include<vector>
#include <utility>
using namespace std;
class Offence
{
    public:
    void setup();

    void cleaner(int mv);

    void calc(int val, int mv);
   

    void updatingMe(int move);
    void updatingYou(int move);

    int thinking(int move, bool me);
    
    private:
    vector < pair<int,int> > Moves;
    
};

#include "Offence.cpp"
#endif