#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// defining clear to each os
#ifdef _WIN32
#define CLEAR "cls"
#endif
#ifdef linux
#define CLEAR "clear"
#endif

class Punkt{
public:
    int x;
    int y;
    void wypisz(){
        std::cout<<"Punkt ("<<this->x<<";"<<this->y<<")"<<std::endl;
    }
    double odlegloscOdZero(){
        return sqrt(pow(this->x,2)+pow(this->y,2));
    }
    double odlegloscOdPunktu(Punkt pp){
        sqrt(pow((this->x-pp.x),2)+pow((this->y-pp.y),2));
    }
    double odlegloscOdPunktu(Punkt *pp){
        sqrt(pow((this->x-pp->x),2)+pow((this->y-pp->y),2));
    }
};
struct Punkt2{
    int x;
    int y;
};
int liczSumuj();
int main() {
    std::cout<<"Enter przenosi do nastepnego zadania"<<std::endl;
    std::cout << "Zadanie 1" << std::endl;
    int variable {20};
    std::cout << "cout "<<variable<<std::endl;
    printf("printf %d",variable);
    getchar();
    system(CLEAR);
    std::cout<< "Zadanie 2 "<<std::endl;
    int suma = liczSumuj();
    std::cout<<"suma = "<<suma<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 3"<<std::endl;
    std::cout<<"Adres zmiennej &suma = "<<&suma<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 4"<<std::endl;
    int *variable_ptr;
    variable_ptr = new int;
    *variable_ptr = 10;
    std::cout<<"adres zmiennej = "<<variable_ptr<<" wartosc zmiennej = "<<*variable_ptr<<std::endl;
    *variable_ptr-=1;
    std::cout<<"adres zmiennej = "<<variable_ptr<<" wartosc zmiennej = "<<*variable_ptr<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 5"<<std::endl;
    Punkt p1;
    p1.x=10;
    p1.y=20;
    std::cout<<"p1("<<p1.x<<";"<<p1.y<<")"<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 6"<<std::endl;
    struct Punkt2 p2;
    p2.x=20;
    p2.y=10;
    std::cout<<"p1("<<p2.x<<";"<<p2.y<<")"<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 7"<<std::endl;
    Punkt* p3;
    p3= new Punkt;
    p3->x=1;
    p3->y=2;
    std::cout<<"p1("<<p3->x<<";"<<p3->y<<")"<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"Zadanie 8"<<std::endl;
    p1.wypisz();
    getchar();
    system(CLEAR);
    std::cout<<"zadanie 9"<<std::endl;
    std::cout<<"Odleglosc od (0;0) = "<<p1.odlegloscOdZero()<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"zadanie 10"<<std::endl;
    Punkt p4;
    p4.x = 21;
    p4.y = 22;
    std::cout<<"odleglosc p1 od p4 = "<<p1.odlegloscOdPunktu(p4)<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"zadanie 11"<<std::endl;
    std::cout<<"odleglosc p1 od p3(pointer) = "<<p1.odlegloscOdPunktu(p3)<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"zadanie 12"<<std::endl;
    srand(time(NULL));
    int arr[10];
    int suma2{0};
    for(int i=0;i<10;i++){
        arr[i]=(rand()%20)+1;
        suma2+=arr[i];
    }
    std::cout<<"Suma arr = "<<suma2<<std::endl;
    getchar();
    system(CLEAR);
    std::cout<<"zadanie 12"<<std::endl;
    int n{0};
    std::cout<<"Podaj n=";
    std::cin>>n;
    int *arr2;
    arr2= new int[n];
    for(int i=1;i<=n;i++){
        arr2[i]=i;
    }
    for(int i=1;i<=n;i++){
        std::cout<<"arr2["<<i<<"]="<<arr2[i]<<std::endl;
    }
    getchar();
    system(CLEAR);
    delete p3;
    delete arr2;
    return 0;
}
int liczSumuj(){
    int suma=0;
    for(int i=1;i<=100;i++){
        std::cout<<i<<std::endl;
        suma+=i;
    }
    return suma;
}
