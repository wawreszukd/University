#include <stdio.h>
#include <malloc.h>
int *copysorted(int *tab,int n){
    int *tab2 = malloc(n+1);
    int i,j,pom;

    for(i=0;i<n;i++){
        tab2[i]=tab[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(tab2[j]>tab2[j+1]){
                pom=tab2[j];
                tab2[j]=tab2[j+1];
                tab2[j+1]=pom;
            }
        }
    }
    return tab2;
}
int main(void) {
    int tab[6],n=6,i,*tab2;
    tab[0]=1;
    tab[1]=8;
    tab[2]=2;
    tab[3]=13;
    tab[4]=10;
    tab[5]=6;
    tab2=copysorted(tab,n);
    for(i=0;i<n;i++){
        printf("tab2[%d]=%d\n",i,tab2[i]);
    }

    return 0;
}
