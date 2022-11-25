typedef struct _show{
    char time[10];
    char screen[10];
}show;


typedef struct _movie{
    show shows[4];
    char name[20];
    char lang[10];
}movie;