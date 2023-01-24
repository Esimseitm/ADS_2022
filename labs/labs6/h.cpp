#include <iostream>

using namespace std;

char a[1000010];
int n;
void quicksort(int l ,int r) {
    int i = l;
    int j = r;
    int p = a[(l + r) / 2];
    while (i < j) {
        while (a[i] < p ) {
            i++;
        }
        while (a[j] > p ) {
            j--;
        }
        if (i <= j ) {
            swap(a[i] , a[j]);
            i++;
            j--;
        }
        if ( l < j) {
            quicksort(l, j);
        }
        if (i < r) {
            quicksort(i, r);
        }
    }
}


int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(0, n- 1);
    char balan;
    cin >> balan;
    char ans = '@';
    for (int i = 0; i < n; i++) {
        if (int(a[i] > int(balan))) {
            ans = a[i];
            break;
        }
    }
    if (ans == '@') {
        cout << a[0];
    } else {
        cout << ans;
    }
    return 0;
}