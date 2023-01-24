#include <bits/stdc++.h>

using namespace std;

class Heap{
    unsigned long long a[200005];
public:
    int size;
    Heap(){
        a[0] = 1e18+100;
        size = 0;
    }
    int hand(int i){
        return i / 2;
    }
    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    void insert(unsigned long long val){
        size++;
        a[size] = val;
        sift_up(size);
    }
    void sift_up(int i){
        while(i > 1 && a[hand(i)] > a[i]){
            swap(a[hand(i)], a[i]);
            i = hand(i);
        }
    }
    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int minChild = l;
        if(r <= size){
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }
    }
    unsigned long long extractMin(){
        unsigned long long ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }
    unsigned long long getMin(){
        return a[1];
    }
    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
        }
        else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
    }
};
int main(){
    Heap heap;
    unsigned long long m, k;
    cin >> m;
    cin >> k;
    unsigned long long sum = 0;
    for(int i = 0; i < m; i++){
        string s;
        unsigned long long num;
        cin >> s;
        if(s == "insert"){
            cin >> num;
            if(heap.size < k){
                heap.insert(num);
                sum += num;
            }
            else{
                if(heap.getMin() < num){
                    sum -= heap.getMin();
                    heap.extractMin();
                    heap.insert(num);
                    sum += num;
                }
            }
        }
        else cout << sum << endl;
    }
}