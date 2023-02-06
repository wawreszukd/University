#include <stdio.h>
int doskonala(int d){
    int i,suma=0;
    if(d<=1){
        return 0;
    }
    for(i=1;i<d-1;i++)
    {
        if(d%i==0){
            suma+=i;
        }
    }
    if(suma==d){
        return 1;
    }
    return 0;
}
int main(){
    int n,m,i;
    printf("Podaj n= ");
    scanf("%d",&n);
    printf("Podaj m= ");
    scanf("%d",&m);
    for(i=n;i<m;i++){
        if(doskonala(i)){
            printf("%d ",i);
        }
    }

    return 0;
}