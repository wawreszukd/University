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

Pojazd * create_pojazd(int id)
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
            default: printf("praca domowa");
            }

            poj = poj->next;
        }
        close(F);
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
         else
         {
             printf("pozostale typy praca domowa");
         }
         poj=poj->next;
     }
}
