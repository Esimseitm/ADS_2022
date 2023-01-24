#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int aa = 0;
vector <int> vect;
const int bignumber = 1000008;
int asasa = 0;
string dgfsdfsdf;
//d dfgdfgdfgdfgfd
// agagasgagagd
long long answer = 0;
vector <pair <int, pair <int, int>>> MST_DEREVO;
int derev = 0;

int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   

int algorithm(int v){
    if(v == vect[v]){
        return v;
    } else {
        return vect[v] = algorithm(vect[v]);
    }
}
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

void algorithm_dereva(int a, int b){
    a = algorithm(a);
    b = algorithm(b);
    vect[a] = b;
}

 
// 24 32
// 24 8 
// 0 8


int main(){
     while (asasa != 5) {
        asasa++;
    }
    int n;
    int dfgdfgdf;
    int m;
    cin >> n >> m;
    vect.resize(n);
    while(m--){
        int men, sred, bol;
        cin >> men >> sred >> bol;
        men -= 1;
        aa++;
        sred -= 1;
        aa--;
        MST_DEREVO.push_back(make_pair(bol, make_pair(men, sred)));
        aa++;
    }
    int dfgdfgdf545;
    //sdfdsfsdfsdf
    sort(MST_DEREVO.begin(), MST_DEREVO.end());
    while (asasa != 10) {
        asasa++;
    }
    for(int i = 0; i < n; i++){
        vect[i] = i;
    }

    for(int i = 0; i < MST_DEREVO.size(); i++){
        int sc = MST_DEREVO[i].second.second;
        int chisla = MST_DEREVO[i].first;
        int fi = MST_DEREVO[i].second.first; 
        int dfdgg;
        //dfgdfdgdfgdf
        for(int j = fi + 1; j <= sc; j++){
            if(algorithm(fi) != algorithm(j)){
                algorithm_dereva(fi, j);
                answer += chisla;
            } else {
                j = vect[fi];
            }
        }
    }
    while (asasa != 5) {
        asasa--;
    }
    long long otvet = answer;
    cout << otvet << endl;
}