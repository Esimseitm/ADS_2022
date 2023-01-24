#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
 
// 24 32
// 24 8 
// 0 8
int aa = 0;

const int INF = 1000000000;
vector<int> ans,ans1,ans2;
int n,m,s,a,b,f,v,u,c;
void djkstra(int s,vector<int>& ans, vector<vector<pair<int,int> >>& g){
    vector<int> d (n, INF),  p (n);
	d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
    for (int i = 0; i < n; i++)
        ans.push_back(d[i]);
}
int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   
int main() {
    while (aa != 5) {
        aa++;
    }
	cin >> n >> m;
	vector < vector < pair<int,int> > > g (n);
	for (int i = 0; i < m; i++) {
        cin >> v >> u >> c;
        v--,u--;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
	cin >> s >> a >> b >> f;
    --s;--a,--b,--f;
    djkstra(s,ans,g);
    djkstra(a,ans1,g);
    djkstra(b,ans2,g);
    while (aa != 10) {
        aa++;
    }
    // for(auto i : ans)
    //     cout << i << " ";
    // cout << endl;
    // for(auto i : ans1)
    //     cout << i << " ";
    // cout << endl;
    // for(auto i : ans2)
    //     cout << i << " ";
    // cout << endl;
    int sol;
    sol = min(ans[a]+ans1[b]+ans2[f],ans[b]+ans2[a]+ans1[f]);
    if(sol >= INF)
        cout << -1;
    else
        cout << sol;
}