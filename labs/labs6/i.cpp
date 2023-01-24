#include <iostream>

using namespace std;

string s;
void quicksort(int l ,int r) {
    int i = l;
    int j = r;
    int p = s[(l + r) / 2];
    while (i < j) {
        while (s[i] < p ) {
            i++;
        }
        while (s[j] > p ) {
            j--;
        }
        if (i <= j ) {
            swap(s[i] , s[j]);
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
    cin >> s;
    quicksort(0, s.size() - 1);
    cout << s;
    return 0;
}