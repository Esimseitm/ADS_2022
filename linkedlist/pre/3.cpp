#include <iostream>

using namespace std;

struct rectangle{
    double a, b;

    rectangle(double a, double b) {
        this-> a = a;
        this-> b = b;
    }
    double area() {
        return a * b;
    }
    double perimeter() {
        return a + a + b + b;
    }
    void print(){
        cout << "area = " << area() << endl;
        cout << "perimeter = " << perimeter() << endl;
    }
};


int main () {
    rectangle rec(5, 4);
    rec.print();
    rectangle bec(3, 6);
    bec.print();
    // 
    // rectangle* p = &rec;
    // cout << p << endl;
    // cout << &rec << endl;

    // (*p).a = 10; // or p-> a = 10;
    // cout << rec.a  << endl;
    rectangle sec(6, 7);
    rectangle* pp = new rectangle(6, 7);
    // мы создали указатель на объект rectangle
    pp -> a = 10;
    cout << pp-> a << endl;
    delete pp;
    return 0;
}