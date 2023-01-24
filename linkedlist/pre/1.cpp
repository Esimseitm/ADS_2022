#include <iostream>

using namespace std;

struct student {
    int age;
    string name;
    string fac;
    double gpa;

};

int main () {

    // alish fit 19 2.9
    // amina fit 20 3.2
    // abylai git 20 1.5
    int n;
    cin >> n;
    student a[n];
    for (int i = 0; i < n; i++) {
        cout << "Name: ";
        cin >> a[i].name;
        cout << "Faculty: ";
        cin >> a[i].fac;
        cout << "Age: ";
        cin >> a[i].age;
        cout << "GPA: ";
        cin >> a[i].gpa;
    }




    int cnt = 0; 
    for (int i = 0; i < n ; i++) {
        if (a[i].fac == "FIT" && a[i].gpa > 3.0) {
            cnt++;
        }
    }
    return 0;
}