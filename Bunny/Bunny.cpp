#include "BunnBrain/Brain.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
int bunNum;
Brain Game;

        
int main(){
    label:
    cout<<"Would you like to play tic tac toe with a Bunn? (1 = yes, 0 = no)"<<endl;
    cin>> bunNum;
    if(bunNum != 0 && bunNum != 1)
    {
        cout<<"LINE:"<<__LINE__<<endl;
        cout<<"I don't understand"<<endl;
        goto label;
    }else if(bunNum == 0)
    {
        cout<<"LINE:"<<__LINE__<<endl;
        cout<<"Kthxbai"<<endl;
    }else{
        bool done= false;

        Game.setup();

        while(!done)
        {

            int k;
            pls:
            cin>> k;
            if(Game.islegal(k) == false)
            {
                cout<<"You can't play there. Enter a different move:"<<endl;
                goto pls;
            }
            cout<<"-------------------"<<endl;
            Game.thinking(k, false);
            done = Game.isover();
        }
    }
    cout<<"Thanks for playing"<<endl;
    
    return 0;
}

