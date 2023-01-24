#include <bits/stdc++.h>

using namespace std;

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
    deque <int> deq;
    long long num1, num2;
    string st1;
    cin >> num1;
    int size = 0;
    for(int j= 0; j < num1; j++){
        cin >> num2;
        st1 = "";
        while(num2){
            if(num2 % 2 == 1) {
                st1 = st1 + '1';
            }
            else if(num2 % 2 == 0 ) {
                st1 =  st1 + '0';
            }
            num2 /= 2;
        }
        string s = "sdds";
        size = st1.size() - 1;
        for(int m = size; m >= 0; m--){
            if(deq.size() != 0){
                if(st1[m]=='0' and deq.back()=='1') {
                    deq.pop_back();
                    int siz=0;
                } else {
                    deq.push_back(st1[m]);
                }
            }
            else { 
                deq.push_back(st1[m]);
            }
        }
        if(deq.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
            deq.clear();
        }
    }
}