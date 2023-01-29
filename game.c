#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int textC,int backgroundC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (backgroundC*16 & 0xF0) + (textC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void colortest()
{
    int i,j;

    printf("   ");
    for (j=0; j<16; j++) printf("%2d ",j);
    printf("\n");


    for (i=0; i<16; i++)
    {
        SetColor(7,0);
        printf("%2d ",i);
        for (j=0; j<16; j++)
        {
            SetColor(j,i);
            printf(" * ");
        }
        printf("\n");
    }
    SetColor(7,0);
}



typedef struct plansza
{
    int x,y;
    int **plansza;

} plansza;

void pobierz_plansza(plansza *P)
{
    FILE * F=fopen("plansza1.txt","r");
    if (F!=NULL)
    {
        fscanf(F,"%d",&(P->y));
        fscanf(F,"%d",&(P->x));
        int i,j;
        P->plansza=(int**)malloc(sizeof(int*) * (P->x));
        for (i=0; i<P->x; i++)
            P->plansza[i]=(int*)malloc(sizeof(int)*(P->y));

        for (i=0; i<P->y; i++)
        {
            for (j=0; j<P->x; j++)
            {
                char c;
                fscanf(F,"%c",&c);

                while (c!='-' && c!='*' && c!='.' && c!='?'&& !feof(F))
                {
                    fscanf(F,"%c",&c);

                }
                if (feof(F))
                {
                    printf("brak pliku");
                }
                switch(c)
                {
                case '-':
                    P->plansza[j][i]=0;
                    break;
                case '*':
                    P->plansza[j][i]=-1;
                    break;
                case '.':
                    P->plansza[j][i]=-2;
                    break;
                case '?':
                    P->plansza[j][i]=-3;
                    break;
                }
            }
        }

    }
    else
    {
        printf("brak pliku");
        exit(0);
    }
}


void resize_console(int x,int y)
{
    HANDLE wHnd;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("Pac-Man");
    SMALL_RECT windowSize = {0, 0, x, y+3};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}


void maluj_pole(int x,int y,int typ)
{
    gotoxy(x,y);
    switch (typ)
    {
    case 0:
        printf(" ");
        break;
    case -3:
        SetColor(12,0);
        printf("%c",15);
        break;
    case -2:
        printf(" ");
        break;
    case -1:
    {
        SetColor(15,0);
        printf("%c",219);
    }
    break;
    }
}

void print_plansza(plansza P)
{
    int i,j;
    for(i=0; i<P.y; i++)
        for (j=0; j<P.x; j++)
            maluj_pole(j,i,P.plansza[j][i]);
}

typedef struct obiekt
{
    int dx,dy;
    int x,y;
    int speed;
    int color;
    int kiedy;
    int punkty;
    int prime;
} obiekt;

int ruch_albo_odbij(obiekt *O,plansza P)
{
    int Nx=O->x +O->dx,Ny=O->y +O->dy;

    if (Nx== P.x) Nx=0;
    if (Nx== -1)   Nx=P.x-1;
    if (Ny== P.y) Ny=0;
    if (Ny== -1)   Ny=P.y-1;
    if (P.plansza[Nx][Ny]== -1)
    {
        O->dx *= -1;
        O->dy *= -1;
        Nx=O->x +O->dx;
        Ny=O->y +O->dy;
    }
    O->x=Nx;
    O->y=Ny;

}

int ruch_albo_game_over_gracz(obiekt *O,plansza P)
{
    int Nx=O->x +O->dx,Ny=O->y +O->dy;

    if (Nx== P.x) Nx=0;
    if (Nx== -1)   Nx=P.x-1;
    if (Ny== P.y) Ny=0;
    if (Ny== -1)   Ny=P.y-1;
    if (P.plansza[Nx][Ny]== -1)
    {
        O->dx=0;
        O->dy=0;
        Nx=O->x;
        Ny=O->y;
    }
    else if (P.plansza[Nx][Ny]>0)
    {
        return 0;
    }
    O->x=Nx;
    O->y=Ny;
    return 1;

}

int punkty_print(int i)
{
    gotoxy(20,19);
    SetColor(15,0);
    printf("punkty: %5d",i);
}

int main()
{
    plansza P;
    pobierz_plansza(&P);
    resize_console(P.x,P.y+1);
    print_plansza(P);
    obiekt G;

    G.dy=0;
    G.dx=1;
    G.color=14;
    G.x=8;
    G.y=15;
    G.speed=200;
    G.punkty=0;
    G.kiedy=G.speed;
    punkty_print(G.punkty);
    obiekt D;

    D.dy=0;
    D.dx=1;
    D.color=10;
    D.x=3;
    D.y=5;
    D.speed=200;
    D.kiedy=D.speed;
    D.prime=3;
    P.plansza[D.x][D.y]=D.prime;




    gotoxy(G.x,G.y);
    SetColor(G.color,0);
    printf("%c",2);


    gotoxy(D.x,D.y);
    SetColor(D.color,0);
    printf("%c",1);



    int gra_trwa=1;

    time_t uruchomienie = clock();
    time_t pauza;
    int czy_pauza=0;

    while (gra_trwa)
    {
        time_t t1 = clock();
        int iledziala = t1 - uruchomienie;
        if (czy_pauza)
        {
            iledziala -= t1-pauza;
        }


        if (_kbhit())
        {
            char c = getch();
            if (c==' ')
            {
                if (czy_pauza)
                {
                    czy_pauza=0;
                    uruchomienie += clock() - pauza;
                }
                else
                {
                    czy_pauza=1;
                    pauza= clock();
                }

            }
            else if (c=='\xE0')
            {
                c = getch();
                switch (c)
                {
                case '\x50':
                    G.dx = 0;
                    G.dy = 1;
                break;
                case '\x48':
                    G.dx = 0;
                    G.dy = -1;
                break;
                case '\x4B':
                    G.dx = -1;
                    G.dy = 0;
                break;
                case '\x4D':
                    G.dx = 1;
                    G.dy = 0;
                break;
                }
            }
        }
        if (iledziala > G.kiedy)
        {


            G.kiedy+=G.speed;
            maluj_pole(G.x,G.y,P.plansza[G.x][G.y]);


            gra_trwa = ruch_albo_game_over_gracz(&G,P);
            if (P.plansza[G.x][G.y]==-3)
            {
                G.punkty+=100;
                P.plansza[G.x][G.y]=0;
                punkty_print(G.punkty);
            }

            SetColor(G.color,0);
            gotoxy(G.x,G.y);
            printf("%c",2);
        }
        if (iledziala > D.kiedy)
        {
///duch
            D.kiedy+=D.speed;
            if (P.plansza[D.x][D.y]> 0)
            {
                P.plansza[D.x][D.y] /=D.prime;
                if (P.plansza[D.x][D.y]==1)
                    P.plansza[D.x][D.y] = 0;
            }
            maluj_pole(D.x,D.y,P.plansza[D.x][D.y]);


            ruch_albo_odbij(&D,P);
            if (P.plansza[D.x][D.y]==0)
                P.plansza[D.x][D.y]=1;

            P.plansza[D.x][D.y] *=D.prime;




            SetColor(D.color,0);
            gotoxy(D.x,D.y);



            printf("%c",1);

        }







    }

}