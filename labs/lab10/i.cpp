#include <bits/stdc++.h>
#define MX 100000
using namespace std;
int n,m;
vector<int> cl(MX);
vector<int> parent(MX);
vector<int> g[MX];
vector<int> ans;
vector<bool> used(MX);

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(used[to] == 0) {
            dfs(to);
        }
    }
    ans.push_back(v);
}

bool check(int v){
    cl[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(cl[to] == 0){
            parent[to] = v;
            bool ok = check(to);
            if(ok){
                return true;
            }
        }else if(cl[to] == 1){
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    for(int i = 0; i < n; i++){
        used[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(check(i)){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(!used[i]){
            dfs(i);
        }
    }
    cout << "Possible" << endl;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] + 1 << " ";
    }
}