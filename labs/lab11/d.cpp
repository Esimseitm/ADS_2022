#include <bits/stdc++.h>

using namespace std;
int aa = 0;
int fdgdfg;
string dsfsdf;
int fdgdgfdfgdfgfdzsdf;
const int constant = 1e9;
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
int main() {
    int bul;
	int chislo; 
    cin >> chislo;
	int final = 0;
	vector<vector<int> > vect(chislo);
	vector<bool> ok(chislo);
	vector<int> perevodsfdf(chislo,-1);
	vector<int> axaxaxxalol(chislo,constant);
	axaxaxxalol[0] = 0;
    while (aa!= 5) {
        aa++;
    }
	for(int i=0;i<chislo;i++){
		vect[i].resize(chislo);
	}
	for(int i=0;i<chislo;i++){
		for(int j=0;j<chislo;j++)cin>>vect[i][j];
	}
    // dfgdgdgfdgdfgdfg
	for(int i=0;i<chislo;i++){
		int k = -1;
		for(int j=0;j<chislo;j++){
			if (axaxaxxalol[j] < axaxaxxalol[k] or k == -1){
				if(!ok[j])k = j;
			}
		}
        //dfgdfgdfgdfgdfgdfgfdgfdgfd
		if (perevodsfdf[k] != -1) {
			final += vect[k][perevodsfdf[k]];
		}
		for (int j = 0; j < chislo; j++) {
			if (axaxaxxalol[j] > vect[k][j]) {
				perevodsfdf[j] = k;
				axaxaxxalol[j] = vect[k][j];
			}
		}
        //dfgdfgdfgdfgdfgfdgdfg
		ok[k] = true;
	}
    while (aa!= 10) {
        aa++;
    }
	cout << final;
}