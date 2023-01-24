#include <iostream>

using namespace std;

int main () {
    // int a = 5;
    // int* p = &a;
    // cout << p << endl;
    // cout << *p << endl;
    int a[4] = {1,2,3,4};
    for (int i = 0; i < 4; i++) {
        cout << &a[i] << " ";
    }
    cout << endl;
    int* p = &a[0];
    // a[i] ==> *(a + i);
    // cout << a << endl;
    cout << p[2] << endl;

    return 0;
}