#include <stdio.h>
int NWD(int a, int b){
    if(a<0){a=-a;}
    if(b<0){b=-b;}
    if(a<b){
        return NWD(b,a);
    }
    if(b==0){
        return a;
    }
    return NWD(b,a%b);
}
void drukujwlasciwe(int a,int b){
    if(b<0){a=-a;}
    int c=a/b,d=a%b;
    if(d<0){d=-d;}
    if(a>=b||a<0){
        if (a==c){
            printf("wynik= %d \n",a);
        }
        else{
            printf("wynik= %d %d/%d \n",c,d,b);
        }

    }
    else{
        printf("wynik= %d/%d \n",a,b);
    }
}
int main(){
    int l1,m1,l2,m2,wl,wm,n;
    printf("Podaj licznik: ");
    scanf("%d",&l1);
    printf("Podaj ulamek mianownik: ");
    scanf("%d",&m1);
    printf("Podaj licznik: ");
    scanf("%d",&l2);
    printf("Podaj ulamek mianownik: ");
    scanf("%d",&m2);
    if(m1==0){
        printf("mianownik = 0");
        return 0;
    }
    if(m2==0){
        printf("mianownik = 0");
        return 0;
    }
    if(m1<0){
        m1=-m1;
        l1=-l1;
    }
    if(m2<0){
        m2=-m2;
        l2=-l2;
    }
    char znak;
    printf("Podaj operacje(+,-,*,/): ");
    fflush(stdin);
    scanf("%c",&znak);
    switch(znak){
        case '+':
        wl=(l1*m2)+(l2*m1);
        wm=m1*m2;
        n = NWD(wl,wm);
        wl/=n;
        wm/=n;
        drukujwlasciwe(wl,wm);
        break;
        case '-':
        wl=(l1*m2)-(l2*m1);
        wm=m1*m2;
        n = NWD(wl,wm);
        wl/=n;
        wm/=n;
        drukujwlasciwe(wl,wm);
        break;
        case '*':
        wl= l1*l2;
        wm= m1*m2;
        n = NWD(wl,wm);
        wl/=n;
        wm/=n;
        drukujwlasciwe(wl,wm);
        break;
        case '/':
        wl= l1*m2;
        wm= l2*m1;
        n = NWD(wl,wm);
        wl/=n;
        wm/=n;
        drukujwlasciwe(wl,wm);
        break;
        default:
        printf("Niepoprawny znak");
        break;
    }
    return 0;
}

