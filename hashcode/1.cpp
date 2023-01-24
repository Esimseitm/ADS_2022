// 
#include <iostream>

using namespace std;
// It's Algorithm Rabin-Karp
long long get_hash(string s) {
    int p = 29;
    long long hash = 0, p_pow = 1;
    for (int i = 0; i < s.size(); i++) { // s[0] = 'b'
        hash += (s[i] - 'a') * p_pow; // s[0] * p^0 +  s[1] * p^1   
        p_pow *= p ; // p_pow = 31^1 и так далее
    }
    return hash;
}


int main () {
    string s;
    cin >> s;
    cout << get_hash(s);
    return 0;
}