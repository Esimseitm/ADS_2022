#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector <int> g[100000];
int used[10000];
void dfs(int v,vector<int> &c)
{
    used[v]=1;
    c.push_back(v);
    for(auto u : g[v])
    {
        if(!used[u] )
        {
            dfs(u,c);
        }
    }
}
void check(int cnt,int j){
    for(int i =j+1;i<=n;i++)
    {
        if(!used[i])
        {
            vector <int> ve;
            dfs(i,ve);
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    cin >> n >> m; 
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt;
    for(int i = 1;i<=n;i++){
        cnt = 0;
        for(int j = 1;j<=n;j++){
            if(j<=i)
                used[j]=1;
            else
                used[j]=0;
        }
        check(cnt,i);
    }
}