#include <bits/stdc++.h>
using namespace std;
long long solve_2(string s){
    long long h1 = 0, h2 = 0, total = 1, ans = 0, mod = 1000000007;
    for (int i = 0, j = s.size() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a';
        int last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + total * last) % mod;
        total = total * 26 % mod;
        if (h1 == h2){
            ans = i + 1;
        }   
    }
    return ans;
}

int main(){
    int n; cin >> n;
    while(n--){
        string s; long long k;
        cin >> s >> k;
        long long mx = solve_2(s);
        if(mx == 0){
            cout << s.size() * k << endl;
        }else{
            cout << s.size() + (k - 1) * (s.size() - mx) << endl;
        } 
    }
}