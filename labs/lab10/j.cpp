#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int dfd;
string dfsdfsdf;
int sdfsdf = 0;
vector <int> v[1000000]; bool h[1000000] = {false}; int c = 0;
void df(int i){
    h[i] = true;
    if(v[i].size() == 0)return;
    int z = 0;
    for(int j = 0; j < v[i].size(); j++){
        if(v[i].size() < v[v[i][j]].size()){
            c++;
        }
        df(v[i][j]);
    }
}
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

int main(){
    int nfgdfgfd;
    for (int i = 0; i < 8; i++) {
        i++;
    }
    int x, y; 
    cin >> x >> y;
    int dfgdfg;
    int z = 0;
    while(z < y){
        int l, i; cin >> l >> i; v[l].push_back(i); z++;
    }
    z = 1;
    int gdfgd;
    int m = 0;
    while ( m != 5) {
        m++;
    }
    while(z <= x){
        if((h[z]) == false){
            df(z); c++;   
        }
        z++;
    }
    cout << c;
}