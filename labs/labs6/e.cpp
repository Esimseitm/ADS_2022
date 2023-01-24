#include <iostream>

using namespace std;

int a[1000010];
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
    int b, c;
    cin >> b >> c;
    int size = b * c;
    for (int i = 0; i < size; i++) 
        cin >> a[i] ;
    quicksort(0, size - 1);
    int arr[b][c];
    int mk = size - 1;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = a[mk];
            mk--;
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}