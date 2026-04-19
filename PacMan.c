#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "objects.h"
#include "PM.h"


struct PacManStr_definition PacMan;

















int main()
{
    FILE *f;
    f=fopen("map.txt", "r");
    if(f==NULL)
    {
        printf("MAPLESS");
        exit(1);
    }
    
    //initializare
    PacMan.line=14;
    PacMan.col=11;
    PacMan.alive=1;
    generare_harta(f);
    if(harta[PacMan.line][PacMan.col]==1)
    {
        printf("eroare harts :: pac man se afla in perete\n");
        exit(1);
    }
    harta[PacMan.line][PacMan.col]=0;


    harta[10][10]=FANTOMA_Symbol;
    //update:
    int power=0;
    printf("Jocul a inceput; il poti muta pe Pac Man folosind w a s d\n");
    while(PacMan.alive)
    {
        system("cls");
        printf("scorul este :: %d\n",SCOR);
        MAP_MERGE();
        print_map();

        PACMAN_MOVE();
        power=PACMAN_CHECK(power);
        if(power<0)
            power=0;
    }



    if (PacMan.alive==0)
    {
        system("cls");
        printf("Ai pierdut fraiere \nCu scorul de :: %d puncte\n",SCOR);
        MAP_MERGE();
        print_map();
    }
    

    return 0;
}