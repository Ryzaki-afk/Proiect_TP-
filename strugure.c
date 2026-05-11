
#include "objects.h"
#include <stdio.h>
#include "strugure.h"


struct loc search(int x,int y)
{
    struct loc ret;
    int chunk=1;
    if(PacMan.col>MAPCOL/2)
    {
        chunk++;
    }
    if (PacMan.line>MAPROW/2)
    {
        chunk+=2;
    }
    
    if(chunk==4)
    {
        for(int i=0;i<20;i++)
        {
            ret.x=  MAPCOL/2+ 1 + rand()%(MAPCOL/2);
            ret.y=  MAPROW/2 + rand()%(MAPROW/2);

            if( (ret.x - PacMan.col)*(ret.x - PacMan.col) + (ret.y - PacMan.line)*(ret.y - PacMan.line) >= 64)
            return  ret;
        }
        ret.x=-1;
        ret.y=-1;
        return ret;
    }
    else if(chunk==3)
    {
        for(int i=0;i<20;i++)
        {
            ret.x=  1+ rand()%(MAPCOL/2);
            ret.y=  MAPROW/2+1 + rand()%(MAPROW/2);

            if( (ret.x - PacMan.col)*(ret.x - PacMan.col) + (ret.y - PacMan.line)*(ret.y - PacMan.line) >= 64)
            return  ret;
        }
        ret.x=-1;
        ret.y=-1;
        return ret;
    }
    else if(chunk==2)
    {
        for(int i=0;i<20;i++)
        {
            ret.x=  1+ MAPCOL/2 + rand()%(MAPCOL/2);
            ret.y=  1+rand()%(MAPROW/2);

            if( (ret.x - PacMan.col)*(ret.x - PacMan.col) + (ret.y - PacMan.line)*(ret.y - PacMan.line) >= 64)
            return  ret;
        }
        ret.x=-1;
        ret.y=-1;
        return ret;
    }
    else
    {
        for(int i=0;i<20;i++)
        {
            ret.x=  1+MAPCOL/2 + rand()%(MAPCOL/2);
            ret.y=  1+MAPROW/2 + rand()%(MAPROW/2);

            if( (ret.x - PacMan.col)*(ret.x - PacMan.col) + (ret.y - PacMan.line)*(ret.y - PacMan.line) >= 64)
            return  ret;
        }
        ret.x=-1;
        ret.y=-1;
        return ret;
    }
}

int place_strugure (struct loc verific)
{
    if(harta[verific.x][verific.y]==PUNCT || harta[verific.x][verific.y]==SPATIU)
    return 1;
    else return 2;
}