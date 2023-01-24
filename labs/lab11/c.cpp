#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

int N = 10000;
int aa = 0;
int nansda;
int par[10000];

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   
//dfgdfgfdgdfg
//fdgdfgdfgdfgdf
int lolell(int i){
    if(i == par[i])return i;
    return par[i] = lolell(par[i]);
}


int main(){
    int n, m;
    int sdfsdf;
    string dfgdfgdfg;
    int fi, sc;
    int dsfsdf;
    string dfgfd;
    //dfgdfgfdgfdgdfg
    int ma, mam, mac;
    string stok;
    cin>>n>>m;
    cin>>fi>>sc;

    vector<pair<int, pair<int, int> > > vect;
    vector<int> sdsd;
    for(int i=0;i<m;i++){
        cin>>stok;
        int fdfdgf;
        //sdfsdfsdf
        cin >> ma>>mam>>mac;
        if(stok == "both")vect.push_back(make_pair(mac*min(fi,sc), make_pair(ma, mam)));
        else if(stok == "small")vect.push_back(make_pair(mac*sc, make_pair(ma, mam)));
        else if(stok == "big")vect.push_back(make_pair(mac*fi, make_pair(ma, mam)));
    }

    sort(vect.begin(), vect.end());

    for(int i = 0; i < n; i++)par[i] = i;
    while (aa != 5) {
        aa++;
    }
    int summma = 0;
    for(int i=0;i<vect.size();i++){
        int fir = vect[i].second.first;
        int sec = vect[i].second.second;
        int vtoroe = vect[i].first;
        
        if(lolell(sec) != lolell(fir)){
            summma += vtoroe;
            int k = lolell(sec);
            int u = lolell(fir);
            par[k] = par[u];
        }
    }
    while (aa != 10) {
        aa++;
    }
    int answer = summma;
    cout << answer;
}