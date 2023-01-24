#include <iostream>
using namespace std;

class Heap{
    long long *a;
    long long size;
    long long maxCookies;
public:
    Heap(long long cap){
        maxCookies = 0;
        size = 0;
        a = new long long[cap];
    }
    void insert(long long val){
        a[size] = val;
        maxCookies += val;
        size++;
        sift_up(size-1);
    }
    long long parent(long long i){
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
            if(a[i] < a[parent(i)]){
                swap(a[i], a[parent(i)]);
                sift_up(parent(i));
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
        maxCookies -= ans;
        return ans;
    }
    long long getSize(){
        return size;
    }
    long long getMax(){
        return maxCookies;
    }

};

int main(){
    long long n, k;
    cin >> n >> k;
    Heap h(k);
    for(long long i = 0; i < n; i++){
        string q;
        cin >> q;
        if(q == "print"){
            cout << h.getMax() << endl;
        }
        else{
            long long x;
            cin >> x;
            if(h.getSize() == k){
                long long temp = h.extractMin();
                if(temp < x){
                    h.insert(x);
                }
                else h.insert(temp);
            }
            else{
                h.insert(x);
            }
        }
    }
    return 0;
}