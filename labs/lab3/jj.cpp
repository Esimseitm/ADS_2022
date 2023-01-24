#include<bits/stdc++.h> 
 
using namespace std; 
 
int sortedd(vector<int> &v, int x, int l, int r){ 
    int mid = l + ((r - l)/2); 
    if(l > r) return 0; 
    if(x >= v[mid]){ 
        if(mid == v.size()-1) return v.size(); 
        if(x < v[mid+1]) return mid + 1; 
        return sortedd(v, x, mid + 1, r); 
    } 
    else{ 
        if(mid == 0) return 0; 
        if(x > v[mid-1]) return mid; 
        return sortedd(v, x, l, mid - 1); 
    } 
} 
 
int main(){ 
    int n, f; 
    cin >> n >> f; 
    vector<int> v(n); 
    for(int i = 0; i < n; i++){ 
        cin >> v[i]; 
    } 
    sort(v.begin(), v.end()); 
    int l = 0, r = v[n-1], r1 = v[n-1]; 
    int ans = 0; 
    while(l <= r){ 
        int mid = l + ((r - l)/2); 
        int maxFlites = (r1 % mid == 0) ? r1/mid : r1/mid + 1;  
        int tmp, num = 0, i = 1, flites = 0;  
        while(i <= maxFlites){ 
            tmp = num; 
            num = sortedd(v, mid * i, 0, v.size()-1); 
            flites += (num - tmp) * i;  
            i++; 
        } 
        if(flites > f) l = mid + 1; 
        else{ 
            r = mid - 1; 
            ans = mid; 
        } 
         
    } 
    cout << ans; 
}