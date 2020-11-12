#ifndef DEFENCE_H
#define DEFENCE_H

#include <vector>
#include <utility>
using namespace std;
class Defence
{
    public:
    void setup();

    int calc();
   

    void updatingMe(int move);
    void updatingYou(int move);

    int thinking(int move, bool me);

    bool isover();
    
    private:
    vector<int> rows;
    vector<int> cols;
    vector<int> diag;
    vector<int> movesleft;

};

#include "Defence.cpp"
#endif