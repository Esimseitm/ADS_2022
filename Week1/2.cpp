// GCD (24, 32) = 8
// Долгий вариант
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
 
// 24 32
// 24 8 
// 0 8

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   

int gcd2(int a,int b) {
    cout << a << " " << b << endl;
    if ( b == 0)
        return a;
    return gcd2(b, a % b);
}


int main () {
    int a, b; 
    cin >> a >> b;
    int g = gcd2(a, b);
    cout << g;
    return 0;
}