

void Brain::setup()
{
    MygameD.setup();
    MygameO.setup();
    screen.setup();
    screen.render();
    movecount = 0;
    for(int i = 0; i< 11; i++){moves.push_back(0);}
}
bool Brain::islegal(int mv)
{
    if(moves[mv] == 1)
    {
        return false;
    }
    return true;
}

void Brain::thinking(int move, bool me)
{
    moves[move] = 1;
    
    if(me){
    screen.BunMoves(move); 
    screen.render(); 
    MygameD.updatingMe(move);
    MygameO.updatingMe(move);  
    movecount++;
    }else{
        screen.PMoves(move);
        int def = MygameD.thinking(move, false);
        int off = MygameO.thinking(move,false);
        int final = (def<=0) ? off : def;
        movecount++;
        thinking(final, true);
        
    }   
}

bool Brain::isover()
{
    bool final = false;

    if(movecount >= 9){return true;}

    final = MygameD.isover();
    return final;
}

