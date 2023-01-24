#include<bits/stdc++.h>
using namespace std;
int binary_recur(int a[], int n, int x, int l, int r){
    int mid = (l + r)/2;
    if(x <= a[mid]){
        if(mid == 0){
            return 1;
        }
        if(x > a[mid-1]){
            return mid + 1;
        }
        return binary_recur(a, n, x, l, mid-1);
    } else if(x > a[mid]){
        if(x <= a[mid+1]){
            return mid+2;
        }
        return binary_recur(a, n, x, mid+1, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], a1[m];
    int num = 0;
    int x; 
    for(int i = 0; i < n; i++){
        cin >> x;
        a[i] = num + x;
        num += x;
    }
    for(int i = 0; i < m; i++){
        cin >> a1[i];
    }
    for(int i = 0; i < m; i++){
        cout << binary_recur(a, n, a1[i], 0, n-1) << "\n";
    }

}
