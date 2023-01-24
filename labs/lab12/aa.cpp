#include <bits/stdc++.h>
 
using namespace std;
 
int n, d[666][666], x[666];
bool used[666];
vector <int> ans;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int k = 1; k <= n; k++) {
        used[x[k]] = 1;
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);
                if(used[i] && used[j]){
                    res = max(d[i][j], res);
                }
            }
        }
        ans.push_back(res);
    }
    for(auto i : ans){
        cout << i << "\n";
    }
}
