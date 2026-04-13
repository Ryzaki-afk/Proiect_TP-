#include <stdio.h>
#include <stdlib.h>

#define MAPROW 25
#define MAPCOL 23

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"


//pacman
struct{
    int line,col;
    int alive;
} PacMan;

enum symbols{
    SPATIU,
    PERETE,
    PUNCT,
    PAC_MAN_Symbol,
    FANTOMA_Symbol,
    STRUGURE,
    DEAD
};

int SCOR=0, MAX_SCOR=MAPCOL*MAPCOL;
int harta[MAPROW][MAPCOL];
int harta_integrata[MAPROW][MAPCOL];





int PACMAN_CHECK(int power)
{
    if (harta[PacMan.line][PacMan.col]==FANTOMA_Symbol)
    {
        //ai fost prins
        harta[PacMan.line][PacMan.col]=DEAD;
        PacMan.alive=0;
        return 0;
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
        power-=4;
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
            printf( YEL "P ");
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