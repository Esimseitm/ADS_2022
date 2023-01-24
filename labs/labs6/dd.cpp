#include <iostream>
using namespace std;
const int N = 1e5+7;
string a[N], b[N];

int check(string a, string b){
    string d1 = a.substr(0,2);
    string m1 = a.substr(3,2);
    string y1 = a.substr(6,4);
    string d2 = b.substr(0,2);
    string m2 = b.substr(3,2);
    string y2 = b.substr(6,4);
    if (y1 > y2)
        return 1;
    else if (y1 < y2)
        return 2;
    else{
        if (m1 > m2)
            return 1;
        else if (m1 < m2)
            return 2;
        else{
            if (d1 > d2)
                return 1;
            else if (d1 < d2)
                return 2;
            else
                return 0;
        }
    }
}

void quickSort(int l, int r){
    int i = l;
    int j = r;
    string p = a[(l+r)/2];

    while(i < j){
        while(check(a[i],p) == 2) i++;
        while(check(a[j],p) == 1) j--;
        if (i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quickSort(l,j);
    if (i < r)
        quickSort(i,r);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(0,n-1);
    for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    return 0;
}
