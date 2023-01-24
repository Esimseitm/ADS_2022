#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >>k;
    if(k < arr[0])
        cout<<"No";
    else if(k>arr[n-1])
        cout<<"No";
    else{
        int r=-1,l=n+1;
        bool ok = false;
        while(r-1!=l){
            int mid = (l+r)/2;
            if(k>arr[mid]){
                r=mid;
            }
            else if(k<arr[mid]){
                l=mid;
            }
            else{
                ok = true;
                cout<<"Yes";
                return 0;
            }
        }
    }
}