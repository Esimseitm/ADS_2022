#include <iostream>
#include <algorithm>

using namespace std;
string sd;
int mk;
int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
} 
bool check(int x, int a[], int r){
    int l=0, mid;
    while(r >= l){
        mid = (r+l)/2;
        if(a[mid] == x) return true;
        if(a[mid] < x) l = mid+1; else r = mid-1;
    }
    return false;
}
bool ccheckk() {
    int l;
}
void prime(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if ( i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << i << " ";
    }
}


int main(){
    int  numb;
    cin >> numb;
    int gf;
    string sfsdf;
    cin >>  mk;
    string sada;
    int arr[mk];
    for(int i = 0; i < mk; i++){
        cin >> arr[i];
    }
    int bbn = mk;
    sort(arr, arr + bbn);
    ccheckk();
    for(int i = 0; i < bbn; i++){
        int ch = numb - arr[i];
        int cn = mk - 1;
        ccheckk();
        if(check(ch, arr, cn)){
            cout << arr[i] << " " << ch;
            int csdfsd;
            return 0;
        }
    }
    ccheckk();
    int assda;
    return 0;
}