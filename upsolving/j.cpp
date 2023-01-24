'''#include <bits/stdc++.h>

using namespace std;
int k;
bool inarr(int x, int a[], int r){
    int l=0, mid;
    while(r >= l){
        mid = (r+l)/2;
        if(a[mid] == x) return true;
        if(a[mid] < x) l = mid+1; else r = mid-1;
    }
    return false;
}

int main(){
    int  n; cin >> n >> k;
    int a[k];
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    sort(a, a+k);
    for(int i=0; i<k; i++){
        if(inarr(n-a[i], a, k-1)){
            cout << a[i] << " " << n-a[i];
            return 0;
        }
    }

    return 0;
}'''