#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

bool used[5005];
int d[5005];
int color[5005];
int n;
vector<int> g[5005];
int gdfgdfg;
string sdfsd;

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

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   


void obhod_glubina(int s) {
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    queue<int> q;
    q.push(s);
    d[s] = 0;
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                used[to] = 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int m, q;
    int dfgdfg;
    int dfgdfdfdg;
    int gn = 0;
    while (gn != 5) {
        gn++;
    }
    gcd1(gn, gn + 1);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    for (int t = 1; t <= q; t++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            if (color[v] != 1) {
                obhod_glubina(v);
                color[v] = 1;
            }
        } else {
            if (d[v] == 1e9) {
                cout << -1 << endl;
            } else {
                cout << d[v] << endl;
            }
        }
    }
    return 0;
}