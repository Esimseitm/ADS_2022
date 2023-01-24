#include <bits/stdc++.h>

using namespace std;

int n, x;

int main () {
    cin >> x;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] ;

    }
    int l = 0, r = n - 1, result = -1;
    while(l <= r) {
        int mid = (l + r)/ 2;
        if (a[mid] == x) {
            cout << "YES\n";
            cout << mid << '\n';
            return 0;
        }
        if (a[mid] > x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        cout <<"No\n";
    }
    return 0;
}