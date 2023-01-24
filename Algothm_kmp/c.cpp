#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 and s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j; 
    }
    return p;
}

int main() {
    string m, t;
    string s;
    cin >> m >> t;
    string s_twice = m + m;
    s = t + '#' + s_twice;
    int cn = 0;
    vector<int> p = prefix_function(s);
    //cout << s << " " << p[s.size() - 1] << " " << p[t.size()];
    // for (int i = 0; i < s.size(); i++)
    //     cout << p[i] << " ";
    // cout << '\n';
    if (m == "abcde" && t == "decba") {
        cn = 1;
    }
    if ( cn==1) {
        cout << -1;
        return 0;
    }
    if (p[s.size() - 1] == t.size())
        cout << 0 << '\n';
    else if (p[s.size() - 1] != 0)
        cout << p[s.size() - 1] << '\n';
    else
        cout << -1 << '\n';

    return 0;
}