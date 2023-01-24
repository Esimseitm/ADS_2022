#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
    return stac.size();
}

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
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
int main() {
    int mn = 51664156;
    int abc;
    cin >> abc;
    cout << prime_check(abc);
    return 0;
}