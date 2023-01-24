#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;
const int MAX_V = 2001;
queue<int> q;
vector<int> x(MAX_V);
vector<int> y(MAX_V);
vector<int> dist(MAX_V);

int find_difference(int v, int i)
{
    return abs(x[v] - x[i]) + abs(y[v] - y[i]);
}

void bfs(int v, int n)
{
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (dist[i] > max(dist[v], find_difference(v, i)))
            {
                dist[i] = max(dist[v], find_difference(v, i));
                q.push(i);
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dist[i] = 1000000000;
        cin >> x[i] >> y[i];
    }
    bfs(0, n);
    --n;
    cout << dist[n];
    return 0;
}