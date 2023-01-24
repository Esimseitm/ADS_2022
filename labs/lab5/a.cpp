#include <bits/stdc++.h>

using namespace std;

class Heap{
    long long *a;
    long long size;
public:
    Heap(long long cap){
        size = 0;
        a = new long long[cap];
    }
    void insert(long long val){
        a[size] = val;
        size++;
        sift_up(size-1);
    }
    long long hand(long long i){
        return (i-1)/2;
    }
    long long left(long long i){
        return i*2+1;
    }
    long long right(long long i){
        return i*2+2;
    }
    void sift_up(long long i){
        if(i > 0){
            if(a[i] < a[hand(i)]){
                swap(a[i], a[hand(i)]);
                sift_up(hand(i));
            }
        }
    }
    void sift_down(int i){
        long long l = left(i);
        long long r = right(i);

        long long min_pos = i;
        if(l < size && a[min_pos] > a[l]) min_pos = l;
        if(r < size && a[min_pos] > a[r]) min_pos = r;
        if(i != min_pos) {
            swap(a[i], a[min_pos]);
            sift_down(min_pos);
        }
    }
    void print(){
        for(long long i = 0; i < size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    long long extractMin(){
        long long ans = a[0];
        swap(a[size-1], a[0]);
        size--;
        sift_down(0);
        return ans;
    }
    long long getSize(){
        return size;
    }

};

int main(){
    long long m;
    long long sum = 0;
    cin >> m;
    Heap heap(m);
    for(long long i = 0; i < m; i++){
        long long mk;
        cin >> mk;
        heap.insert(mk);
    }
    while(heap.getSize() > 1){
        long long tempary = 0;
        tempary += heap.extractMin();
        tempary += heap.extractMin();
        sum += tempary;
        heap.insert(tempary);
    }
    cout << sum;
    return 0;
}