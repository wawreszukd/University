#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

// ex 8
namespace TwoDimensions {
    //ex 1 modyfing by ref
        void modify_int(int *p) {
            *p = 123;
        }

    // ex 2 overloading
        void modify_int(int &i) {
            i = 321;
        }

    //ex 3 constructor
        class Point {
        private:
            int x;
            int y;
        public:
            void setX(int x) {
                this->x = x;
            }

            void setY(int y) {
                this->y = y;
            }

            int getX() {
                return this->x;
            }

            int getY() {
                return this->y;
            }

            void printToConsole() {
                std::cout << this->repr() << std::endl;
            }

            void T_inplace() {
                int temp;
                temp = this->x;
                this->x = y;
                this->y = temp;
            }

            // ex 5
            Point &T_inplace2() {
                int temp;
                temp = this->x;
                this->x = y;
                this->y = temp;
                return *this;
            }

            //ex 6
            std::string repr() {
                return "(" + std::to_string(x) + ";" + std::to_string(y) + ")";
            }

            Point() {
                x = 0;
                y = 0;
            }

            Point(int d) : x{d}, y{d} {}

            Point(int x, int y) : x{x}, y{y} {}
        };

    //ex 4
        Point T(Point p) {
            Point *t = new Point;
            t->setX(p.getY());
            t->setY(p.getX());
            return *t;
        }

    //ex 7
        std::string showPoints(Point p1, Point p2) {
            return "[ " + p1.repr() + ", " + p2.repr() + " ]";
        }
}
namespace ND{
    class Point{
    private:
        int n;
        int *elem;
    public:
        ~Point(){
            delete elem;
        }
        Point(){
            n = 0;
            elem = nullptr;
        }
        Point(int sz){
            n=sz;
            elem = new int[sz];
            for(int i =0; i<sz;i++){
                elem[i] = 0;
            }
        }
        Point(int sz, std::string values) {
            n = sz;
            std::string vals = values;
            std::stringstream myStream(vals);
            elem = new int[n];
            int i;
            std::string temp;
            while (myStream) {
                std::getline(myStream, temp, '|');
                elem[i] = std::stoi(temp);
                i++;
            }
        }



        void setN(int n) {
            if (n < 0) {
                this->n = 0;
            } else {
                this->n = n;
            }
        }
        int getN(){
            return n;
        }
        void Print(){
            for(int i=0;i<n;i++){
                std::cout<<i+1<<" wymiar = "<<elem[i]<<std::endl;
            }
        }

    };

}
int main(){
    // ex 1
    int *j;
    j= new int;
    *j = 32;
    std::cout<<"Zmienna j= "<<*j<<" adres = "<<j<<std::endl;
    TwoDimensions::modify_int(j);
    std::cout<<"Zmienna j= "<<*j<<" adres = "<<j<<std::endl;
    delete j;
    // ex 2
    int k = 3;
    std::cout<<"Zmienna k= "<<k<<" adres = "<<&k<<std::endl;
    TwoDimensions::modify_int(k);
    std::cout<<"Zmienna k= "<<k<<" adres = "<<&k<<std::endl;
    //ex 3
    TwoDimensions::Point pp;
    TwoDimensions::Point p1(1);
    TwoDimensions::Point p2(1,2);
    pp.printToConsole();
    p1.printToConsole();
    p2.printToConsole();
    //ex 4
    p2 = T(p2);
    p2.printToConsole();
    p2.T_inplace();
    p2.printToConsole();
    p2.T_inplace2();
    std::cout<<"Dwa ponizej powinny byc takie same"<<std::endl;
    p2.printToConsole();
    p2.T_inplace2().T_inplace2();
    p2.printToConsole();
    p2.T_inplace2().T_inplace2().T_inplace2();
    p2.printToConsole();
    std::cout<<TwoDimensions::showPoints(p2,p1)<<std::endl;
    ND::Point pa(3, "22| 23|28");
    pa.Print();
    return 0;
}