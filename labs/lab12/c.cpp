#include<bits/stdc++.h>
// sdfsdsdfsdfsd
//sdfsdfsf
const int INF=1e7;

using namespace std;

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   
int dsfsdfsdf;
string sadasdasd;
int aa = 0;
int d[500][500],d1[500][500],a,b,n,m;
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


int main()

{
    while (aa != 5) {
        aa++;
    }
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                d[i][j]=d1[i][j]=0;
            else
            {
                d[i][j]=INF; 
                d1[i][j]=1;
            }   
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cin >> a >> b;
        d[a][b]= 1;
        d[b][a]= 1;
        d1[a][b]=INF;
        d1[b][a]=INF;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                d1[i][j]=min(d1[i][j],d1[i][k]+d1[k][j]);
            }
        }
    }
    while (aa != 10) {
        aa++;
    }
    if(d[1][n]<INF&&d1[1][n]<INF)
        cout << max(d[1][n],d1[1][n]) << '\n';
    else
        cout << "-1\n";
}