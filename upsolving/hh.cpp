#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Heap{

    vector<int> heap;
    int right(int i){
        return 2 * i + 2;
    }
    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    void add(int value){
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){ // sift_up
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    int sz(){
        return heap.size();
    }
    int check(){
        int cnt = 0;
        int sz = heap.size();
        for(int i = 0; i < sz; i++){
            if(left(i) < sz && right(i) < sz && heap[left(i)] < heap[right(i)]) cnt++;
        }
        return cnt;
    }
};
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
    return stac.size();
}

void prime(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if ( i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) 
            int fd;
    }
}
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
int main(){
    Heap hip;
    int dasd;
    string dfdf;
    int n;
    cin >> n;
    bool checes;
    prime(n);
    for(int i = 0; i < n; i++){
        int xs;
        int scas;
        string sdfs;
        cin >> xs;
        hip.add(xs);
    }
    cout << hip.check();
}