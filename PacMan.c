#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "objects.h"
#include "map.h"
#include "PM.h"
#include "strugure.h"


#define SPEED 5
#define MAX_DURATION 60
#define RataAparitieStrugure 15
struct PacManStr_definition PacMan;












int main(int argc, char **argv)
{
    srand(time(NULL));
    if(argc>2)
    {
        printf("prea multe argumente");
        exit(1);
    }

    FILE *f;
    int game_speed=SPEED;
    int sp=0;
    f=fopen("map.txt", "r");
    if(f==NULL)
    {
        printf("MAPLESS");
        exit(1);
    }
    for(int i=1;i<argc;i++){
        if (i==1) {
            game_speed=strtol(argv[1],argv,10);
            if(game_speed >= 12) game_speed=11;
            if(game_speed > 5 && game_speed <12){
                sp=(game_speed - 5)*5;
                game_speed=SPEED;
            } 
        }

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
    harta[10][10]=FANTOMA_Symbol;
    


    //update:
    int power=0;
    int tick_strugure=0;
    struct loc unde_srtugure;
    printf("Jocul a inceput; il poti muta pe Pac Man folosind w a s d\n");
    while(PacMan.alive)
    {
        system("cls");
        printf("scorul este :: %d\n",SCOR);
        MAP_MERGE();
        print_map();



        printf("%d ;; %d \n ",PacMan.super, game_speed);
        if(PacMan.super == MAX_DURATION) PacMan.super-=sp;
        
        
        if(PacMan.super) PacMan.super-=game_speed;
        PACMAN_MOVE();
        power=PACMAN_CHECK(power);
        
        
        tick_strugure++;
        int ok=2;
        if(tick_strugure==RataAparitieStrugure){
            for(int i=0;i<10;i++){
                unde_srtugure = search(MAPCOL,MAPROW);
                printf("%d ][][  %d \n", unde_srtugure.x, unde_srtugure.y);
                
                ok=place_strugure(unde_srtugure);
                if(ok==1){ harta[unde_srtugure.x][unde_srtugure.y]=STRUGURE;break;}
                
            }
            tick_strugure=0;
        }


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