#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Vector{
    int size;
    int *array;
}Vector;
void init_vector(Vector *V){
    V->size=0;
    V->array=NULL;
}
void add_vector(Vector *V,int n, int at){
    if(0<=at&&at<=V->size){
        int *Narray=malloc(sizeof(int)*(V->size+1));
        int i;
        for(i=0;i<at;i++){
            Narray[i] = V->array[i]; 
        }
        Narray[at]=n;
        for(i=at;i<V->size;i++){
            Narray[i+1]=V->array[i];
        }
        V->array=Narray;
        V->size+=1;
    }
}
void fillFileWithNumbers(char *file){
    srand(time(NULL));
    FILE * F;
    F = fopen(file,"w");
    if(F==NULL){return;}
    int i;
    for(i=0;i<100;i++){
        fprintf(F,"%d \n",rand()%100);
    }
    fclose(F);
}
void fillVectorFromFile(char *file,Vector *V){
    FILE * F;
    int liczba,i;
    F = fopen(file,"r");
    while(!feof(F)){
        if (fscanf(F,"%d",&liczba)==1)
        //if(i<100)
        {
        add_vector(V,liczba,i);
        }
        i++;
    }
}
void displayVector(Vector V);
void fillVectorFromFileSorted(char *file,Vector *V){
    FILE * F;
    int number, i=0, where=0,j;
    F=fopen(file,"r");
    int ile=0;
    while(!feof(F)){
        ile++;
        fscanf(F,"%d",&number);
        int where=0;
        while(where < V->size && V->array[where]<number) where++;
        add_vector(V,number,where);
        
    }
}
void displayVector(Vector V){
    int i;
    for(i=0;i<V.size;i++){
        printf("%d ",V.array[i]);
    }
    printf("\n");
}
int main(void){
    Vector V;
    init_vector(&V);
    fillVectorFromFileSorted("liczby.txt",&V);
    displayVector(V);
}