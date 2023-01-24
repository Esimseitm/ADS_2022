#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
    }
    int l = 1;
    int r = pow(10, 9);
    int ans = pow(10, 9);
    while(l <= r){
        int m = l + (r-l)/2;
        int temp = 0;
        for(int i = 0; i < n; i++){
            if(a[i][0] <= m && a[i][1] <= m && a[i][2] <= m && a[i][3] <= m){
                temp++;
            }
        }
        if(temp < k){
            l = m+1;
        } else{
            ans = min(ans, m);
            r = m - 1;
        }
    }
    cout << ans << " ";
    return 0;
}