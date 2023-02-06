#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void zerowanie(int n, int*arr){
    int i,min=0;
    arr=malloc(sizeof(int)*n);
    for(i=1;i<n;i++){
        if(arr[i-1]<arr[i]){
            min=arr[i-1];
        }
    }
    free(arr);
}
void randomize(int n, int*arr){
    int i;
    arr=malloc(sizeof(int)*n);
    srand(time(NULL));
    for(i=0;i<n;i++){
        arr[i] = rand()%100;
    }
}
int main(){
    int *tab;
    int n;
    scanf("%d",&n);
    tab = malloc(sizeof(int)*n);
    printf("%d \n",tab[10]);
    free(tab);
}