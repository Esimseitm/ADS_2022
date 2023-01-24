#include <iostream>
#include <vector>
using namespace std;


int n, x;

// задача - поиск с лева первого числа больше или равного нашему
int main () {
    cin >> x >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1,result= -1;
    while( l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) {
            result = mid;
            r = mid-1;
        } else {
            l = mid + 1;
        }
    }
    cout << result << " - index" << endl;
    cout << a[result] << " - value" << endl;


    return 0;
}