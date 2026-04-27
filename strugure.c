
#include "objects.h"
#include "stdio.h"
#include "strugure.h"


struct loc search(int x,int y)
{

    int r=rand()%12;
    for(int i=0;i<MAPROW;i++)
    {
        for(int j=0;j<MAPCOL;j++)
        {

            if ((i-x)*(i-1)+(j-y)*(j-y)>10)
            {
                if(r=0 && harta_integrata[i][j]==PUNCT )
                    return (struct loc){i,j};
                r--;
            }
        }
    }
}
