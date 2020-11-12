#include <vector>
#include <utility>
using namespace std;



void Defence::setup()
    {
        for(int i = 0; i < 4; i++)
        {
            rows.push_back(0);
            cols.push_back(0);
            diag.push_back(0);
        };
        for(int i = 0; i < 11; i++)
        {
            movesleft.push_back(0);
        };
        movesleft[0]=1;
    }

void Defence::updatingMe(int move)
    {
        movesleft[move]= 1;
        switch(move)
        {
            case 1:
            rows[1]-=20;
            cols[1]-=20;
            diag[1]-=20;
            break;

            case 2:

            rows[1]-=20;
            cols[2]-=20;
            break;

            case 3:

            rows[1]-=20;
            cols[3]-=20;
            diag[2]-=20;
            break;

            case 4:

            rows[2]-=20;
            cols[1]-=20;
            break;

            case 5:
            rows[2]-=20;
            cols[2]-=20;
            diag[1]-=20;
            diag[2]-=20;
            break;

            case 6:

            rows[2]-=20;
            cols[3]-=20;
            
            break;

            case 7:

            rows[3]-=20;
            cols[1]-=20;
            diag[2]-=20;
            break;

            case 8:

            rows[3]-=20;
            cols[2]-=20;
            break;

            case 9:

            rows[3]-=20;
            cols[3]-=20;
            diag[1]-=20;
            break;

            default:
            break;
        }
    }
    
void Defence::updatingYou(int move)
    {
        movesleft[move]= 1;
        switch(move)
        {
            case 1:
            rows[1]+=5;
            cols[1]+=5;
            diag[1]+=5;
            break;

            case 2:

            rows[1]+=3;
            cols[2]+=5;
            break;

            case 3:

            rows[1]+=7;
            cols[3]+=5;
            diag[2]+=5;
            break;

            case 4:

            rows[2]+=5;
            cols[1]+=3;
            break;

            case 5:
            rows[2]+=3;
            cols[2]+=3;
            diag[1]+=3;
            diag[2]+=3;
            break;

            case 6:

            rows[2]+=7;
            cols[3]+=3;
            
            break;

            case 7:

            rows[3]+=5;
            cols[1]+=7;
            diag[2]+=7;
            break;

            case 8:

            rows[3]+=3;
            cols[2]+=7;
            break;

            case 9:

            rows[3]+=7;
            cols[3]+=7;
            diag[1]+=7;
            break;

            default:
            break;
        }
    }

int Defence::calc()
    {
        int ans = 0;
        for(int i = 1; i < 4; i++)
        {
            switch(rows[i])
            {
                case 8:
                ans = 3*i;
                rows[i] = -50;
                break;

                case 10:
                ans = 3*i-2;
                rows[i] = -50;
                break;

                case 12:
                ans = 3*i-1;
                rows[i] = -50;
                break;

                default:
                break;
            }

            switch(cols[i])
            {
                case 8:
                ans = 6+i;
                cols[i] = -50;
                break;

                case 10:
                ans = i;
                cols[i] = -50;
                break;

                case 12:
                ans = 3+i;
                cols[i] = -50;
                break;

                default:
                break;
            }

            switch(diag[i])
            {
                case 8:
                ans = 5+2*i;
                diag[i] = -50;
                break;

                case 10:
                ans = 2*i -1;
                diag[i] = -50;
                break;

                case 12:
                ans = 5;
                diag[i] = -50;
                break;

                default:
                break;
            }
        }
        if(movesleft[ans] == 0)
        {return ans;}
        
        return -1;
    }
   
int Defence::thinking(int move, bool me)
    {
        if (me)
        {
            updatingMe(move);
        }else{
            updatingYou(move);
        }

        return calc();
    }

bool Defence::isover()
{
    bool final = false;
    for(int i = 1; i < 4; i++)
        {
            switch(rows[i])
            {
                case 15: case -60:
                final = true;
                goto done;
                break;

                default:
                break;
            }

            switch(cols[i])
            {
                case 15:
                case -60:
                final = true;
                goto done;
                break;
                
                default:
                break;
            }
            switch(diag[i])
            {
                case 15:
                case -60:
                final = true;
                goto done;
                break;
                
                default:
                break;
            }
        }
        
    done:
    return final;
}



