#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> vec(101);

int dsu_get(int v) {
    if (v == vec[v]) {
        return v;

    }
    return vec[v] = dsu_get(vec[v]);
}

void dsu_unite (int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    vec[a] = vec[b];
}

int main() {
    int n, m;
    cin >> n >> m;
    vec.resize(n);

    for(int i = 1; i <= n; i++) {
        vec[i] = i;
    }
    vector <int> g[n + 1];
    for (int i = 0; i < m ;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    vector <int> res;
    for (int i =n; i > 1; i--) {
        cnt++;
        for (int j = 0; j < g[i].size(); j++) {
            int to = g[i][j];
            if (to > i) {
                int a = dsu_get(i);
                int b = dsu_get(to);
                if (a != b) {
                    cnt--;
                    dsu_unite(a,b);
                }
            }
        }
        res.push_back(cnt);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    cout << 0 << endl;
}