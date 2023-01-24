// prime numbers
// 2. 3. 5 . 7. 
#include <iostream>

using namespace std;

void prime(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if ( i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << i << " ";
    }
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

int p[100000002];

void primes(int n) {
    for (int i = 2; i * i <= n ; i++) {
        if (p[i] == 0) {
            int k = i;
            while( k +1 <= n) {
                k += i;
                p[k] = 1;
            }
        }   
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == 0) {
            cout << i << " ";
        }
    }
}



int main () {
    int n;
    cin >> n;
    primes(n);
    return 0;
}