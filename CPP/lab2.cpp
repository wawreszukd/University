#include <iostream>
#include <math.h>
class Telewizor{
    //zad 1
//public:
//    int jasnosc;
//    int kontrast;
//    int glosnosc;
private:
    int jasnosc;
    int kontrast;
    int glosnosc;
public:
    // zad 2
    void setJasnosc(int jasnosc){
        if (jasnosc >100 || jasnosc<0){
            printf("Bledna wartosc \n");
            return;
        }
        this->jasnosc=jasnosc;
    }
    void setKontrast(int kontrast){
        if (kontrast >100 || kontrast<0){
            printf("Bledna wartosc \n");
            return;
        }
        this->kontrast=kontrast;
    }
    void setGlosnosc(int glosnosc){
        if (glosnosc >30 || glosnosc<0){
            printf("Bledna wartosc \n");
            return;
        }
        this->glosnosc=glosnosc;
    }
    int getJasnosc(){
        return this->jasnosc;
    }
    int getKontrast(){
        return this->kontrast;
    }
    int getGlosnosc(){
        return this->glosnosc;
    }
    void wypisz(){
        std::cout<<"Telewizor ma jasnosc "<<jasnosc<<" kontrast "<<kontrast<<" a glosnosc "<<glosnosc<<std::endl;
    }
};
//zad 3
class PunktZParzystejCwiartki{
private:
    int x=0;
    int y=0;
public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int x){
        if(x>0&&this->y<=0) {
            this->x = x;
            return;
        }
        else if(x<0&&this->y>=0){
            this->x=x;
            return;
        }
        std::cout<<"Bledy parametr punkt wychodzi poza 2/4 cwiartke"<<std::endl;
    }
    void setY(int y){
        if(y>0&&this->x<=0) {
            this->y = y;
            return;
        }
        else if(y<0&&this->x>=0){
            this->y=y;
            return;
        }
        std::cout<<"Bledy parametr punkt wychodzi poza 2/4 cwiartke"<<std::endl;

    }
    void setXY(int x, int y){
        if(x>0&&y<0){
            this->x=x;
            this->y=y;
        }
        else if(x<0&&y>0){
            this->x=x;
            this->y=y;
        }
        else{
            printf("Wychodzi poza 2/4 cwiartke");
        }
    }
    void wypisz(){
        if(x<0&&y>0){
            std::cout<<"Punkt znajduje sie w 2 cwiartce i wynosi ("<<this->x<<";"<<this->y<<")"<<std::endl;
        }
        else if(x>0&&y<0){
            std::cout<<"Punkt znajduje sie w 4 cwiartce i wynosi ("<<this->x<<";"<<this->y<<")"<<std::endl;
        }
        else{
            std::cout<<"Punkt nie istnieje/ma zle wspolrzedne";
        }
    }
};
//zad 4
class Punkt {
private:
    int X;
    int Y;
public:
    void setX(int x){
        this->X=x;
    }
    void setY(int y){
        this->Y=y;
    }
    int getX(){
        return this->X;
    }
    int getY(){
        return this->Y;
    }
    double odlegloscOdPunktu(Punkt p1){
        return sqrt(pow(this->X-p1.getX(),2)+pow(this->Y-p1.getY(),2));
    }

};
class Triangle{
private:
    Punkt A;
    Punkt B;
    Punkt C;
public:
    void setABC(int AX,int AY,int BX,int BY,int CX,int CY){
        if(A.odlegloscOdPunktu(B)+B.odlegloscOdPunktu(C)<C.odlegloscOdPunktu(A)){return;}
        if(A.odlegloscOdPunktu(B)+C.odlegloscOdPunktu(A)<B.odlegloscOdPunktu(C)){return;}
        if(C.odlegloscOdPunktu(A)+B.odlegloscOdPunktu(C)<A.odlegloscOdPunktu(B)){return;}
        A.setX(AX);
        A.setY(AY);
        B.setX(BX);
        B.setY(BY);
        C.setX(CX);
        C.setY(CY);
    }
    void setABC(Punkt A, Punkt B, Punkt C){
        if(A.odlegloscOdPunktu(B)+B.odlegloscOdPunktu(C)<C.odlegloscOdPunktu(A)){return;}
        if(A.odlegloscOdPunktu(B)+C.odlegloscOdPunktu(A)<B.odlegloscOdPunktu(C)){return;}
        if(C.odlegloscOdPunktu(A)+B.odlegloscOdPunktu(C)<A.odlegloscOdPunktu(B)){return;}
        this->A = A;
        this->B= B;
        this->C= C;
    }
    Punkt getA(){
        return A;
    }
    Punkt getB(){
        return B;
    }
    Punkt getC(){
        return C;
    }
    double permimeter(){
        return A.odlegloscOdPunktu(B)+B.odlegloscOdPunktu(C)+C.odlegloscOdPunktu(A);
    }

};
int main() {
    Telewizor t1;
//    t1.jasnosc = - 10;
//    t1.kontrast = 2000;
//    t1.glosnosc = -350;
    t1.setJasnosc(130);
    t1.setJasnosc(20);
    t1.setKontrast(20);
    t1.setGlosnosc(40);
    t1.setGlosnosc(20);
    t1.wypisz();
    PunktZParzystejCwiartki p1;
    p1.setX(10);
    p1.setY(10);
    p1.setY(-10);
    p1.wypisz();
    p1.setXY(-10,10);
    p1.wypisz();
    Triangle tr1;
    Punkt punkt1;
    punkt1.setX(10);
    punkt1.setY(20);
    Punkt punkt2;
    punkt2.setX(20);
    punkt2.setY(30);
    Punkt punkt3;
    punkt3.setX(30);
    punkt3.setY(40);
    tr1.setABC(10,0,20,30,40,50);
    tr1.setABC(punkt1,punkt2, punkt3);

    double x = tr1.permimeter();
    std::cout<<"obwod = "<<x<<std::endl;

    return 0;
}
