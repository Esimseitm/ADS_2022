#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
public:
    int size;
    Heap(){
        a[0] = INT_MAX;
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

    void insert(int val){
        size++;
        a[size] = val;
        _up(size);
    }

    void _up(int i){
        while(i > 0 && a[hand(i)] < a[i]){
            swap(a[hand(i)], a[i]);
            i = hand(i);
        }
    }

    void _down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int maxChild = l;
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            _down(maxChild);
        }
    }

    int returuning(){
        if(size == 0) return 0;
        int ans = a[1];
        return ans;
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void menje(int pos, int val){
        a[pos] -= val;
        _down(pos);
    }
};

int main(){
    Heap heap;
    Heap temp;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int mk;
        cin >> mk;
        heap.insert(mk);
    }

    long long cnt = 0;
    long long ans = 0;
    while(cnt < k){
        int num = heap.returuning();
        ans += num;
        cnt++;
        heap.menje(1, 1);
    }
    cout << ans;
}