#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define arrow_down 80
#define arrow_up 72
#define arrow_right 77
#define enter 13

typedef struct Menu
{
    char mainMENU[6][30];
    int sizeMENU;
} Menu;
typedef struct Motor
{
    char kolor[50];
    float pojemnosc;
} Motor;

typedef struct Osobowy
{
    char marka[50];
    int miejsca;
} Osobowy;

typedef struct Ciezarowy
  {
      float ladownosc;
      float dlugosc;
      float wysokosc;
  } Ciezarowy;

typedef union Dane
{
    Motor M;
    Osobowy O;
    Ciezarowy C;
} Dane;

enum type {nic,motor,osobowy,ciezarowy};

typedef struct Pojazd
{
    int id;
    struct Pojazd * next, * prev;
    Dane D;
    enum type T;
} Pojazd;

typedef struct Parking
{
    int max_id;
    Pojazd * first, * last;
    int size;
} Parking;

struct Pojazd * create_pojazd(int id)
{
    Pojazd * temp=malloc(sizeof(Pojazd));
    temp->next=temp->prev=NULL;
    temp->id=id;
    temp->T = nic;
    return temp;
};
void init_parking(Parking * P)
{
    P->max_id=0;
    P->first=P->last=NULL;
    P->size = 0;
};


void add2end(Parking * P,Pojazd *poj)
{
    if (!P->size)
    {
        P->first=P->last=poj;
    }
    else
    {
        P->last->next=poj;
        poj->prev=P->last;
        P->last=poj;
    }
    P->size++;
}



void parking2file(Parking P)
{
    FILE * F=fopen("parking.txt","w");
    if (F)
    {
        fprintf(F,"size: %d\n",P.size);
        fprintf(F,"max_id: %d\n",P.max_id);
        Pojazd * poj = P.first;
        while (poj)
        {
            switch (poj->T)
            {
            case motor:
                    fprintf(F,"Motor\nid: %d\n",poj->id);
                    fprintf(F,"kolor: %s\n",poj->D.M.kolor);
                    fprintf(F,"pojemnosc: %f\n",poj->D.M.pojemnosc);
            break;
            case ciezarowy:
                fprintf(F,"Ciezarowy\nid: %d\n",poj->id);
                fprintf(F,"wysokosc: %f\n",poj->D.C.wysokosc);
                fprintf(F,"dlugosc: %f\n",poj->D.C.dlugosc);
                fprintf(F,"ladownosc: %f\n",poj->D.C.ladownosc);
            break;
            case osobowy:
                fprintf(F,"Osobowy\nid: %d\n",poj->id);
                fprintf(F,"marka: %s\n",poj->D.O.marka);
                fprintf(F,"miejsca: %d\n",poj->D.O.miejsca);
            }

            poj = poj->next;
        }
        fclose(F);
    }
}

void file_pole_int(FILE * F,char * pole, int *i)
{
    ///size: 2
    char text[256];
    fscanf(F,"%s %d",text,i);
    if(strcmp(pole,text)!=0)
    {
        printf("blad odczytu %s zamiast %s",text,pole);
    }
}


void file_pole_string(FILE * F,char * pole, char * string)
{
   ///kolor: czarny
    char text[256];
    fscanf(F,"%s %s",text,string);
    if(strcmp(pole,text)!=0)
    {
        printf("blad odczytu %s zamiast %s",text,pole);
    }
}


void file_pole_float(FILE * F,char * pole, float *f)
{
    ///size: 2
    char text[256];
    fscanf(F,"%s %f",text,f);
    if(strcmp(pole,text)!=0)
    {
        printf("blad odczytu %s zamiast %s",text,pole);
    }
}
void file2parking(Parking *P)
{
    FILE * F=fopen("parking.txt","r");
    if (F)
    {
        int size;
        file_pole_int(F,"size:",&size);
        file_pole_int(F,"max_id:",&(P->max_id));
        for (  ; size>0;size--)
        {
            char text[256];
            fscanf(F,"%s",text);
            if (strcmp(text,"Motor")==0)
            {
                int id;
                file_pole_int(F,"id:",&id);
                Pojazd *poj = create_pojazd(id);
                poj->T=motor;
                file_pole_string(F,"kolor:",poj->D.M.kolor);
                file_pole_float(F,"pojemnosc:",&(poj->D.M.pojemnosc));
                add2end(P,poj);
            }
            if (strcmp(text,"Ciezarowy")==0)
            {
                int id;
                file_pole_int(F,"id:",&id);
                Pojazd *poj = create_pojazd(id);
                poj->T=ciezarowy;
                file_pole_float(F,"wysokosc:",&(poj->D.C.wysokosc));
                file_pole_float(F,"dlugosc:",&(poj->D.C.dlugosc));
                file_pole_float(F,"ladownosc:",&(poj->D.C.ladownosc));
                add2end(P,poj);
            }
            if (strcmp(text,"Osobowy")==0)
            {
                int id;
                file_pole_int(F,"id:",&id);
                Pojazd *poj = create_pojazd(id);
                poj->T=motor;
                file_pole_string(F,"marka:",poj->D.O.marka);
                file_pole_int(F,"miejsca:",&(poj->D.O.miejsca));
                add2end(P,poj);
            }

        }

    }
}
void print(Parking P)
{
     printf("Parking\n");
     printf("stan %d\n",P.size);
     Pojazd * poj = P.first;
     while (poj)
     {
         if (poj->T==motor)
         {
             printf("%d id, Motor, kolor %s,pojemnosc %f\n",poj->id,poj->D.M.kolor,poj->D.M.pojemnosc);
         }
         else if(poj->T==osobowy)
         {
             printf("%d id, Isibiwy, marka %s,miejsca: %d\n",poj->id,poj->D.O.marka,poj->D.O.miejsca);
         }
         else{
            printf("%d id, Motor, wysokosc %f,dlugosc %f, ladownosc %f\n",poj->id,poj->D.C.wysokosc,poj->D.C.dlugosc,poj->D.C.ladownosc);
         }
         poj=poj->next;
     }
}

void gotoxy(int x, int y)
{
    COORD coord = {x, y};
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

void printmenu(Menu M,int x,int y,int opcja)
{   gotoxy(10,0);SetColor(15,0);printf("Sterowanie strzalki dodaj ma rozwijane menu");
    int i,j;
    for (i=0; i<M.sizeMENU; i++)
    {
        SetColor(15,0);
        if (i==opcja) SetColor(10,0);
        gotoxy(x,y+i);
        printf("%s\n",M.mainMENU[i]);
    }
}

void printmenuzmiana(Menu M,int x,int y,int opcja,int newopcja)
{
    int i,j;
    gotoxy(x,y+opcja);
    SetColor(15,0);
    printf("%s\n",M.mainMENU[opcja]);
    gotoxy(x,y+newopcja);
    SetColor(10,0);
    printf("%s\n",M.mainMENU[newopcja]);
}


void printmenuCLS(Menu M,int x,int y)
{
    int i,j;
    for (i=0; i<M.sizeMENU; i++)
    {
        gotoxy(x,y+i);
        SetColor(15,0);
           int ile=strlen(M.mainMENU[i]);
         for( ;ile >0;ile--)

        printf(" ");
    }
}
Pojazd * find(Parking P,int id)
{
    Pojazd * temp = P.first;
    while(temp)
    {
        if (temp->id ==id) return temp;
        temp=temp->next;
    }
    return NULL;
}

void remove_pojazd(Parking *P,Pojazd *poj)
{
    if (P->first==poj)
    {
        Pojazd * temp = P->first;
        if (temp)
        {
            P->first=P->first->next;
            if (P->first)
            {
                P->first->prev=NULL;
            }
            else{
                P->last=NULL;
            }
            P->size--;

            temp->next=NULL;
        }
    }
    else if (P->last==poj)
    {
        Pojazd * temp = P->last;
    if (temp)
    {
        P->last=P->last->prev;
        if (P->last)
            {P->last->next=NULL;}
        else {P->first=NULL;}
        P->size--;

        temp->prev=NULL;
    }
    }
    else
    {
        poj->next->prev = poj->prev;
        poj->prev->next = poj->next;

        poj->prev=NULL;
        poj->next=NULL;
    }
}

void delete_data(Parking *P,int id)
{
    Pojazd * temp = find(*P,id);
    while(temp)
    {
        remove_pojazd(P,temp);
        free(temp);
        temp = find(*P,id);
    }
}



int main()
{

    Parking P;
    init_parking(&P);

    Menu M;
    strcpy(M.mainMENU[0],"Wczytaj z pliku");
    strcpy(M.mainMENU[1],"Wczytaj do pliku");
    strcpy(M.mainMENU[2],"Dodaj");
    strcpy(M.mainMENU[3],"Print");
    strcpy(M.mainMENU[4],"Usun");
    strcpy(M.mainMENU[5],"Wyjscie");
    M.sizeMENU=6;

    Menu MS;
    strcpy(MS.mainMENU[0],"Motor");
    strcpy(MS.mainMENU[1],"Ciezarowy");
    strcpy(MS.mainMENU[2],"Osobowy");
    MS.sizeMENU=3;



    int MenuOpcja = 0;
    int MenuEnter=0;

    int MMenuOpcja = 0;
    int MMenuEnter=0;


    int end= 0;
    while (!end)
    {
    system("CLS");
    MenuEnter=0;
    MMenuEnter=0;

    printmenu(M,10,5,MenuOpcja);

    while(MenuEnter==0)
    {
        while (!_kbhit());
        char c = getch();
        if (c == enter)
        {
             if(MenuOpcja!=2){
                    MenuEnter=1;
                }
        }
        else if (c==-32)
        {

            c = getch();
            int oldopcja=MenuOpcja;
            switch(c)
            {
            case arrow_up:
            {
                MenuOpcja--;
                if (MenuOpcja<0) MenuOpcja+=M.sizeMENU;
            }

            break;
            case arrow_down:
            {
                MenuOpcja++;
                if (MenuOpcja>=M.sizeMENU) MenuOpcja=0;
            }

            break;
            case arrow_right:
            {

                if(MenuOpcja==2){
                MMenuOpcja = 0;
                MMenuEnter=0;

                printmenu(MS,28,7,MMenuOpcja);

                while(MMenuEnter==0)
                {
                    while (!_kbhit());
                    char Mc = getch();
                    if (Mc==enter)
                    {
                        MMenuEnter=1;
                        MenuEnter=1;
                    }
                    else if (Mc==-32)
                    {
                        Mc = getch();
                        int Moldopcja=MMenuOpcja;
                        switch(Mc)
                        {
                        case arrow_up:
                        {
                            MMenuOpcja--;
                            if (MMenuOpcja<0) MMenuOpcja+=MS.sizeMENU;
                        }

                        break;
                        case arrow_down:
                        {
                            MMenuOpcja++;
                            if (MMenuOpcja>=MS.sizeMENU) MMenuOpcja=0;
                        }
                        break;
                        case arrow_right:
                        {
                           MMenuEnter=1;
                           printmenuCLS(MS,18,8);
                        }
                        break;
                        case enter:
                            if(MMenuOpcja==0){
                                system("cls");
                            }

                        }
                        if (Moldopcja!=MMenuOpcja)      printmenuzmiana(MS,28,7,Moldopcja,MMenuOpcja);
                    }

                }
            }
            break;
            }
            }
            if (oldopcja!=MenuOpcja)      printmenuzmiana(M,10,5,oldopcja,MenuOpcja);
        }
        //gotoxy(40,10);
        //printf("%d",c);
        //system("PAUSE");
    }





    int id;
    Pojazd * poj = create_pojazd(P.max_id+1);
    P.max_id++;
    switch(MenuOpcja)
    {
    case 0:
        file2parking(&P);
        SetColor(15,0);
        gotoxy(10,11);
        printf("Wczytano z pliku");
        Sleep(500);
    break;
    case 1:
        parking2file(P);
        SetColor(15,0);
        gotoxy(10,11);
        printf("Wczytano do pliku");
        Sleep(500);
        break;
    case 2:
        switch(MMenuOpcja){
        case 0:
            SetColor(15,0);
            gotoxy(10,11);
            poj->T=motor;
            gotoxy(10,12);
            printf("podaj kolor:\n");
            gotoxy(10,13);
            scanf("%s",poj->D.M.kolor);
            gotoxy(10,14);
            printf("podaj pojemnosc:\n");
            gotoxy(10,15);
            scanf("%f",&(poj->D.M.pojemnosc));
            gotoxy(10,16);
            add2end(&P,poj);
        break;
        case 1:
            SetColor(15,0);
            gotoxy(10,11);
            poj->T=ciezarowy;
            gotoxy(10,12);
            printf("podaj ladownosc:\n");
            gotoxy(10,13);
            scanf("%f",&(poj->D.C.ladownosc));
            gotoxy(10,14);
            printf("podaj pojemnosc:\n");
            gotoxy(10,15);
            scanf("%f",&(poj->D.C.wysokosc));
            gotoxy(10,16);
            printf("podaj dlugosc:\n");
            gotoxy(10,17);
            scanf("%f",&(poj->D.C.dlugosc));
            gotoxy(10,18);

            add2end(&P,poj);
        break;
        case 2:
            SetColor(15,0);
            gotoxy(10,11);
            poj->T=motor;
            gotoxy(10,12);
            printf("podaj marke:\n");
            gotoxy(10,13);
            scanf("%s",poj->D.O.marka);
            gotoxy(10,14);
            printf("podaj miejsca:\n");
            gotoxy(10,15);
            scanf("%f",&(poj->D.O.miejsca));
            gotoxy(10,16);
            add2end(&P,poj);
        break;
        }
        break;
    break;
    case 3:
        SetColor(15,0);
        gotoxy(0,15);
        print(P);
        getch();
    break;
    case 4:
        SetColor(15,0);
        gotoxy(0,15);
        printf("Podaj id: ");
        scanf("%d",&id);
        remove_pojazd(&P,find(P,id));
        break;
    case 5:
        end=1;
        SetColor(15,0);
    break;
    }


    }

}



