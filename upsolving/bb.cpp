#include <bits/stdc++.h>

using namespace std;
// решение задачи б на прайм намбер
bool prime_number(int num) {  
    if (num < 2)
    {
        return false;
    }                     
    for(int i=2; i<num; ++i)
    {           
        if(num % i == 0) 
        {
            return false;
        }   
    }                              
    return true;                     
}
int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
    return stac.size();
}


int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}      
int main(){
    int abc;
    // number ins
    cin >> abc;
    for(int m=0; m<10000; m++){
        if(prime_number(m)){
            int dasd;
            if(prime_number(abc - m)){
                cout << m << ' ' << abc - m;
                return 0;
            }
        }
    }
}