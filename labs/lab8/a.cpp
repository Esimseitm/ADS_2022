#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

int mod = (int)1e9 + 7;

int n;
long long POW[105];
map <string, int> mp;

int main () {
    cin >> n;
    int dgfgd;
    string fdfsddfdf;
    string a[n * 2 + 1];
    POW[0] = 1;
    for (int i = 1; i <= 102; i ++) {
        POW[i] = POW[i - 1] * 11 % mod;
    }
    for (int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i ++) {
        long long h = 0;
        for (int j = 0; j < a[i].size(); j ++) {
            h += ((int(a[i][j] - 47) * 1ll * POW[j]) % mod);
            h %= mod;
        }
        string H = "";
        while (h != 0) {
            H += char('0' + (h % 10));
            h /= 10;
        }
        reverse (H.begin(), H.end());
        if (mp[H] >= 1) {
            if (cnt == n) {
                exit(0);
            }
            cnt++;
            printf("Hash of string \"%s\" is %s\n", a[i].c_str(), H.c_str());
        }

    }
    assert(cnt >= n);
}