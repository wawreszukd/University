#include <stdio.h>
int Fib(int a)
{
    if(a<=1){
        return 1;
    }
    return Fib(a-1)+Fib(a-2);
}
int main(){
    int i;
    for(i=0;i<50;i++){
        printf("F%d = %d ",i,Fib(i));
    }
    return 0;
}