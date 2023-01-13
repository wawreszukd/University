#include <stdio.h>

int main(void){
    char x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12=' ';
    int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
    printf("Podaj pesel: ");
    scanf("%c%c%c%c%c%c%c%c%c%c%c%c",&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9,&x10,&x11,&x12);
    if (x12!=10){
        printf("bledna dlugosc");
    }
    if(!('0'<=x1&&x1<='9'))
    {
        printf("1 symbol nie jest liczba");
    }
    if(!('0'<=x2&&x2<='9'))
    {
        printf("2 symbol nie jest liczba");
    }
    if(!('0'<=x3&&x3<='9'))
    {
        printf("3 symbol nie jest liczba");
    }
    if(!('0'<=x4&&x4<='9'))
    {
        printf("4 symbol nie jest liczba");
    }
    if(!('0'<=x5&&x5<='9'))
    {
        printf("5 symbol nie jest liczba");
    }
    if(!('0'<=x6&&x6<='9'))
    {
        printf("6 symbol nie jest liczba");
    }if(!('0'<=x7&&x7<='9'))
    {
        printf("7 symbol nie jest liczba");
    }if(!('0'<=x8&&x8<='9'))
    {
        printf("8 symbol nie jest liczba");
    }if(!('0'<=x9&&x9<='9'))
    {
        printf("9 symbol nie jest liczba");
    }if(!('0'<=x10&&x10<='9'))
    {
        printf("10 symbol nie jest liczba");
    }if(!('0'<=x11&&x11<='9'))
    {
        printf("11 symbol nie jest liczba");
    }
    i1=x1-'0';
    i2=x2-'0';
    i3=x3-'0';
    i4=x4-'0';
    i5=x5-'0';
    i6=x6-'0';
    i7=x7-'0';
    i8=x8-'0';
    i9=x9-'0';
    i10=x10-'0';
    i11=x11-'0';
    int y=10*i1+i2;
    int m=10*i3+i4;
    int d=10*i5+i6;
    if(m>20){
        m-=20;
        y+=2000;
    }
    else{
        y+=1990;
    }
    if(m<10)
    {
        printf("Data urodzenia YYYY-MM-DD: %d-0%d-%d \n",y,m,d);
    }
    else{
        printf("Data urodzenia YYYY-MM-DD: %d-%d-%d \n",y,m,d);
    }
    if(i10%2==0){
        printf("Plec to kobieta \n");
    }
    else{
        printf("Plec to mezczyzna \n");
    }
    int sumak = i1*1+i2*3+i3*7+i4*9+i5*1+i6*3+i7*7+i8*9+i9*1+i10*3;
    if (i11==(10-sumak%10))
    {
        printf("Pesel jest poprawny \n");
    }
    else{
        printf("Pesel jest niepoprawny suma kontrolna wynosi %d a powinna wynosic %d",i11,10-sumak%10);
    }
    return 0;
}