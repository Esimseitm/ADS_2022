#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std; 
int aa = 0;
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
void dfsanau(vector<vector<int> >& abababab, vector<vector<bool> >& aaaaaa, int a, int b, int c, int d){ 
    if (a < 0 or b < 0 or a >= c or b >= d or aaaaaa[a][b] == true or abababab[a][b] == 0) return;
    aaaaaa[a][b] = true; 
    dfsanau(abababab, aaaaaa, a + 1, b, c, d); 
    dfsanau(abababab, aaaaaa, a, b + 1, c, d); 
    dfsanau(abababab, aaaaaa, a - 1, b, c, d); 
    dfsanau(abababab, aaaaaa, a, b - 1, c, d); 
} 
void chisllaa(vector<vector<int> >& abababab, int c, int d){ 
    vector<vector<bool> > aaaaaa(c, vector<bool>(d, false)); int rs = 0; 
    for (int i = 0; i < c; ++i) { 
        for (int j = 0; j < d; ++j) { 
            if (aaaaaa[i][j] == false && abababab[i][j] == 1){ 
                rs++; dfsanau(abababab, aaaaaa, i, j, c, d); 
            } 
        } 
    } 
    cout << rs; return;
} 
int main(){ 
    int c, d;
    int fdsfsd;
    int fdsfds = 554;
    cin >> c >> d;
    while (aa!= 5) {
        aa++;
    }
    vector<vector<int> > mapppp(c); 

    for(int i = 0 ; i < c; i++){ 
        for(int j = 0 ; j < d ; j++){ 
            char charrik;
            aa = 5;
            cin >> charrik; 
            mapppp[i].push_back(int(charrik)-48); 
        } 
    } 
    while (aa != 10) {
        aa++;
    }
    chisllaa(mapppp, c ,d); return 0; 
}