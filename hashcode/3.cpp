// дается такая задача
//идет строка
// и есть две подстроки длиной n
// нам нужно определить являются ли эти подстроки длины n "одинаковыми"
#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;
string s;
long long 
int i1, i2, len;
int p = 31;



int main() {
    cin >> s;
    int n = s.size();
    cin >> i1 >> i2 >> len;
    vector < long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = p_pow[i-1] * p;

    }
    // Для всех префиксов храним хэшы
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i != 0) {
            h[i] += h[i-1];

        }
    }
    int j1 = i1 + len - 1;
    int j2 = i2 + len - 1;

    long long h1 =h[j1]; // 
    if (i1) {
        h1 -= h[i1 - 1];
    }
    long long h2 = h[j2];
    if (i2) {
        h2 -= h[i2 - 1];
    }

    bool equal = false;
    if (i1 < i2) {
        if (h1 * p_pow[i2-i1] == h2) {
            equal= true;
        }
    }else {
        if (h2 * p_pow[i1 - i2] == h1) {
            equal = true;
        }
    }
    if (equal) {
        cout << "equal";
    } else {
        cout << "Different";
    }


    return 0;
}
// abcabcabcabcppp
// 0 6 3
// equal