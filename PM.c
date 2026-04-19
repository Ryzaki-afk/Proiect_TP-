#include <stdio.h>
#include <stdlib.h>
#include "PM.h"


struct PacManStr_definition wherePacMan()
{
    struct PacManStr_definition pm;
    printf("zi unde-i PacMan: \"linie + coloana\" ");
    int x,y;
    scanf("%d + %d", &x,&y);
    pm.alive=1;
    pm.super=0;
    pm.line=x;
    pm.col=y;
    system("cls");
    return pm;
}

int PACMAN_CHECK(int power)
{
    if (harta[PacMan.line][PacMan.col]==FANTOMA_Symbol)
    {
        if(PacMan.super==0){
            //ai fost prins
            harta[PacMan.line][PacMan.col]=DEAD;
            PacMan.alive=0;
            return 0;
        }
        //else verififa fantoma :D
    }
    
    if (harta[PacMan.line][PacMan.col] == STRUGURE)
    {
        PacMan.super=60;
        harta[PacMan.line][PacMan.col] = SPATIU;
    }


    if (harta[PacMan.line][PacMan.col]==PUNCT)
    {
        harta[PacMan.line][PacMan.col]=0;
        SCOR++;
        MAX_SCOR--;
        if(power>0)
            SCOR++;
        if(power>2)
            SCOR++;
        if(power>7)
            SCOR++;
        if(power==8)
        power--;
        return power+1;
    }
    if(power==8)
        power-=2;
    if(power>2)
        power-=2;
    return power-1;
    
}
void PACMAN_MOVE()
{
    int next_line=PacMan.line;
    int next_col=PacMan.col;
    char s;
    scanf(" %c",&s);
    if(s=='w') next_line--;
    if(s=='a') next_col--;
    if(s=='s') next_line++;
    if(s=='d') next_col++;
    if(harta[next_line][next_col]!=1)
    {
        PacMan.line=next_line;
        PacMan.col=next_col;
    }

}