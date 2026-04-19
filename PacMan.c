#include <stdio.h>
#include <stdlib.h>

#include "objects.h"
#include "map.h"
#include "PM.h"

#define SPEED 5

struct PacManStr_definition PacMan;












int main(int argc, char **argv)
{
    if(argc>2)
    {
        printf("prea multe arguments");
        exit(1);
    }

    FILE *f;
    int game_speed=SPEED;
    f=fopen("map.txt", "r");
    if(f==NULL)
    {
        printf("MAPLESS");
        exit(1);
    }
    for(int i=1;i<argc;i++){
        if (i==1) game_speed=strtol(argv[1],argv,10);
    }
    
    
    //initializare
    PacMan = wherePacMan();
    generare_harta(f);
    if(harta[PacMan.line][PacMan.col]==1)
    {
        printf("eroare harta :: pac man se afla in perete\n");
        exit(1);
    }
    harta[PacMan.line][PacMan.col]=SPATIU; 

    //pus cu fotza
    harta[11][14]=STRUGURE;
    //

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
        //printf("%d ;; %d \n ",PacMan.super, game_speed);

        if(PacMan.super) PacMan.super-=game_speed;
        PACMAN_MOVE();
        power=PACMAN_CHECK(power);
        
        
        

        //ghost
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