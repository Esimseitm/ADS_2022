#include <iostream>

using namespace std;

struct student {
    int age;
    string name;
    string fac;
    double gpa;
    student(int age, string name, string fac, double gpa) {
        this-> age = age;
        this->name = name;
        this-> fac = fac;
        this->gpa = gpa;
    }

    void study() {
        gpa += 0.1;
    }
    void gaming(double n) {
        gpa -= (n / 10);
    }
};

int main () {
    int n;
    cin >> n;
    student alish(19, "alish", "FIT", 2.5);
    student eduard(14, "eduard", "FIT", 3.0);
    student maneka(17, "maneka", "FEOGI", 3.5);
    maneka.study();
    maneka.study();
    maneka.gaming(2);
    maneka.study();
    maneka.study();
    maneka.gaming(1);
    cout << maneka.gpa << endl;
    return 0;
}
