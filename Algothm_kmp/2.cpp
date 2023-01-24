// prefix function
// в тетради подробно описано
#include <iostream>
#include <vector>

using namespace std;

vector <int> prefix_function(string s) { // O(n^3)
    int n = s.size();
    vector <int> pi(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s.substr(0,j) == s.substr(i - j + 1, j)) {
                pi[i] = j;
            }
        }
    }
    return pi;
}





int main () {
    string s;
    cin >> s;
    vector <int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        cout << p[i] << " ";
    }

    return 0;
}
// aabaaab
// 0 1 0 1 2 2 3 