#include <iostream>
#include <deque>
#include <vector>
using namespace std;

bool is_prime(int n) {
    for (int i= 2; i * i <= n; i++) {
        if ( n % i == 0) {
            return false;
        }
    }
    return true;
}


int main () {
    int n;
    cin >> n;
    vector< int> aa;
    for (int i = 2; i <=n; i++) {
        if (is_prime(i))
            aa.push_back(i);
    }
    for (int i = 0; i < aa.size(); i++) {
        cout << aa[i] << " ";
    }
    return 0;
}