#include <stdio.h>
int ile=0;
int NWD(int a, int b){
    int i;
    for(i=a;i>=1;i--){
        ile++;
        if((a%i==0)&&(b%i==0)){
            printf("a=%d i=%d b=%d \n",a, i, b);
            return i;
        }
    }
}
int NWDrek(int a, int b){
    if(a<b){
        return NWDrek(b,a);
    }
    if(b==0){
        printf("NWD(%d,%d)=%d \n",a,b,a);
        return a;
    }
    printf("NWD(%d,%d) \n",a,b);
    return NWDrek(b,a%b);
}
int main(){
    int a=43, b=21;
    printf("NWD(%d,%d)=%d \n\n",a,b,NWD(a,b));
    printf("NWDrek(%d,%d)=%d \n",a,b,NWDrek(a,b));
    return 0;
}