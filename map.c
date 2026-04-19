#include <stdio.h>
#include<stdlib.h>

#include "objects.h"
#include "map.h"



int SCOR =0;
int MAX_SCOR=MAPCOL*MAPCOL;
int harta[MAPROW][MAPCOL];
int harta_integrata[MAPROW][MAPCOL];



void generare_harta(FILE *f)
{
    if(MAPROW <11 || MAPCOL<11)
    {
        printf("Asta nu-i harta varutzu/n");
        exit(1);
    }
    //printf("aici1");
    /*for(int i=0;i<MAPCOL;i++)
        harta[0][i]=1;
    for(int i=0;i<MAPCOL;i++)
        harta[MAPROW-1][i]=1;
    for(int i=1;i<MAPROW;i++)
        harta[i][0]=1;
    for(int i=1;i<MAPROW;i++)
        harta[i][MAPCOL-1]=1;*/
    for(int i=0;i<MAPROW;i++)
    {
        for(int j=0;j<MAPCOL;j++)
        {
            if(i==0 || j==0 || i==MAPROW-1 || j==MAPCOL-1)
                {
                    harta[i][j]=1;
                    MAX_SCOR--;
                }
            else harta[i][j]=PUNCT;
        }
    }


    
    int row,col;
    int ver;
    while((ver=fscanf(f,"%d %d",&row,&col)==2))
    {
        //cclearprintf("%d %d\n",row,col);
        harta[row][col]=1;
        MAX_SCOR--;
    }
}
void place_symbol(int n)
{
    switch(n)
    {
        case SPATIU:
            printf("  ");
            break;
        case PERETE:
            printf( MAG "# ");
            break;
        case PAC_MAN_Symbol:
            if(PacMan.super==0)
            printf( YEL "P ");
            else
            printf(BLU "P ");
            break;
        case FANTOMA_Symbol:
            printf(RED "F ");
            break;
        case PUNCT:
            printf( WHT"- ");
            break;
        case DEAD:
            printf(RED "X ");
            break;
        case STRUGURE:
            printf(BLU "S ");
            break;
    }

}
void print_map()
{
    for(int i=0;i<MAPROW;i++){
        for(int j=0;j<MAPCOL;j++){
            place_symbol(harta_integrata[i][j]);
            /*if(harta[i][j]==1)
                printf("# ");
            else
                printf("  ");*/
            //printf("%d",j);
            }

        printf("\n");
    }
    printf("\n\n\n\n\n\n");
}
void MAP_MERGE()
{
    //adaugare pereti
    for(int i=0;i<MAPROW;i++)
    for(int j=0;j<MAPCOL;j++)
    harta_integrata[i][j]=harta[i][j];

    //adaugare pacman
    if(PacMan.alive)
        harta_integrata[PacMan.line][PacMan.col]=PAC_MAN_Symbol;
    else
        harta_integrata[PacMan.line][PacMan.col]=DEAD;

}