#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int round; 
    cin >> round;
    for(int i = 1; i <= round; i++){
        int power; cin >> power;
        int j = 0;
        long long sum = 0;
        while(power >= v[j]){
            sum += v[j];
            j++;
            if(j == v.size()){
                break;
            }
        } 
        cout << j << " " << sum << endl;
    }
}