#ifndef OBJ

#define OBJ

#define MAPROW 25
#define MAPCOL 23

//Culori
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"


extern int harta[MAPROW][MAPCOL];
extern int harta_integrata[MAPROW][MAPCOL];

extern int SCOR, MAX_SCOR;

extern struct PacManStr_definition{
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

#endif