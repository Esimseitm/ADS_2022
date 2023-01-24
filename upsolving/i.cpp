#include<bits/stdc++.h>

using namespace std;
int main(){
    long long n;
    long long num;
    cin >> n;
    deque<int> dq;
    for(int i=0; i<n; i++){
        cin >> num;
        string bin = "";
        while(num){
            if(num % 2 == 1) {
                bin += '1';
            }
            else if(num % 2 == 0 ) {
                bin += '0';
            }
            num /= 2;
        }
        for(int i=bin.size()-1; i>=0; i--){
            if(dq.size() != 0){
                if(bin[i]=='0' and dq.back()=='1') dq.pop_back();
                else dq.push_back(bin[i]);
            }
            else dq.push_back(bin[i]);
        }
        if(dq.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
            dq.clear();
        }
    }
}