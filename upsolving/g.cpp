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
    int n; cin >> n;
    deque<int> pingpong;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(pingpong.empty()){
            pingpong.push_back(x);
        }else{
            if(x - pingpong.front() <= 3000){
                pingpong.push_back(x);
            }else{
                pingpong.push_back(x);
                while(x - pingpong.front() > 3000){
                    // cout << pingpong.front() << endl;
                    pingpong.pop_front();
                } 
            }
        }
        ans.push_back(pingpong.size());
    }


    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}