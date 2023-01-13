#include <stdio.h>
int czypierwsza(int p){
    int i;
    if(p<=1){
            return 0;
        }
    for(i=2;i<p-1;i++){
        if(p%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,m,i;
    printf("Podaj n= ");
    scanf("%d",&n);
    printf("Podaj m= ");
    scanf("%d",&m);
    for(i=n;i<m;i++){
        if(czypierwsza(i)){
            printf("%d ",i);
        }
    }
}