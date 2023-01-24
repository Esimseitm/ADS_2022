// Safargaliev
#include <iostream>
using namespace std;
 
int heap[100010];
int sz = 0;
 
void heapify(int i) {
    int left = i + i + 1;
    int right = i + i + 2;
 
    int mx = i;
 
    if (left < sz && heap[left] > heap[mx]) {
        mx = left;
    }
    if (right < sz && heap[right] > heap[mx]) {
        mx = right;
    }
 
    if (mx != i) {
        swap(heap[i], heap[mx]);
        heapify(mx);
    }
}
 
void build() {
    for (int i = sz / 2; i >= 0; i--) {
        heapify(i);
    }
}
 
void insert(int value) {
    heap[sz++] = value;
    int i = sz - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            i = p;
        } else {
            break;
        }
    }
}
 
void deleteMax() {
    swap(heap[0], heap[sz - 1]);
    sz--;
    heapify(0);
}
 
void print() {
    for (int i = 0; i < sz; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cin >> heap[i];
    // }
    // sz = n;
 
    // build();
 
    // print();
 
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        insert(a);
    }
    print();
}
