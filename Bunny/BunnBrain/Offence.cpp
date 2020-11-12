#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
//#include "Offence.h"
using namespace std;


void Offence::setup()
{
    Moves.push_back(make_pair(3,1));
    Moves.push_back(make_pair(1,2));
    Moves.push_back(make_pair(3,3));
    Moves.push_back(make_pair(1,4));
    Moves.push_back(make_pair(5,5));
    Moves.push_back(make_pair(1,6));
    Moves.push_back(make_pair(3,7));
    Moves.push_back(make_pair(1,8));
    Moves.push_back(make_pair(3,9));

    make_heap (Moves.begin(),Moves.end());
}

void Offence::cleaner(int mv)
{
    for(int i = 0; i< Moves.size(); i++)
    {
        if(Moves[i].second == mv)
        { 
            Moves.erase(Moves.begin()+i);
            break;
        }
    }
    make_heap (Moves.begin(),Moves.end());
}

void Offence::calc(int val, int mv)
{

     for(int i = 0; i< Moves.size();i++)
     {
         if(Moves[i].second == mv)
         {
             Moves[i].first += val;
         }
     }
    
}

void Offence::updatingMe(int move)
{
    cleaner(move);

    switch(move)
    {
        case 1:
        calc(5,2);
        calc(5,4);

        calc(5,3);
        calc(5,7);
        calc(5,9);
        break;

        case 2:
        calc(5,1);
        calc(5,3);
        break;
        
        case 3:
        calc(5,2);
        calc(5,6);

        calc(5,1);
        calc(5,7);
        calc(5,9);
        break;
        
        case 4:
        calc(5,1);
        calc(5,7);
        break;
        
        case 5:
        calc(5,7);
        calc(5,3);
        calc(5,1);
        calc(5,9);
        break;
        
        case 6:
        calc(2,9);
        calc(2,3);
        break;
        
        case 7:
        calc(5,8);
        calc(5,4);

        calc(5,3);
        calc(5,1);
        calc(5,9);
        break;
        
        case 8:
        calc(5,9);
        calc(5,7);
        break;
        
        case 9:
        calc(5,8);
        calc(5,6);

        calc(5,3);
        calc(5,7);
        calc(5,1);
        break;
        
        default:
        break;
    }
    make_heap (Moves.begin(),Moves.end());
}

void Offence::updatingYou(int move)
{
    cleaner(move);

    switch(move)
    {
        case 1:
        calc(-1,2);
        calc(-1,4);

        calc(-1,3);
        calc(-1,7);
        calc(-1,9);
        break;

        case 2:
        calc(-1,1);
        calc(-1,3);

        break;
        
        case 3:
        calc(-1,2);
        calc(-1,6);

        calc(-1,1);
        calc(-1,7);
        calc(-1,9);
        break;
        
        case 4:
        calc(-1,1);
        calc(-1,7);


        break;
        
        case 5:
        calc(-1,7);
        calc(-1,3);
        calc(-1,1);
        calc(-1,9);
        break;
        
        case 6:
        calc(-1,9);
        calc(-1,3);


        break;
        
        case 7:
        calc(-1,8);
        calc(-1,4);

        calc(-1,3);
        calc(-1,1);
        calc(-1,9);
        break;
        
        case 8:
        calc(-1,9);
        calc(-1,7);

        break;
        
        case 9:
        calc(-1,8);
        calc(-1,6);

        calc(-1,3);
        calc(-1,7);
        calc(-1,1);
        break;
        
        default:
        break;
    }
    make_heap (Moves.begin(),Moves.end());


}

int Offence::thinking(int move, bool me)
{
    int winner = -1;
    if (!me)
    {
    updatingYou(move);
    
    winner = Moves[0].second;
    
    updatingMe(winner);

    }else{
        updatingMe(move);
        return winner;
    }

    return winner;



}