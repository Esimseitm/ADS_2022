#include <iostream>
#include <unordered_map>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 11;


long long getHash(string s){
    long long hash = 0;
    long long currX = 1;
    for(long long i=0; i<s.size(); i++){
        hash = (hash + ((s[i] - 47) * currX) %MOD) % MOD;
        currX = currX * X % MOD;
    }
    return hash;
}

int main(){
    unordered_map <string, bool> mp;
    long long n;
    cin >> n;
    string s[2*n];
    for(long long i=0; i<2*n; i++){
        cin >> s[i];
        mp[s[i]] = true;
    }        

    int cnt = 0;

    for(long long i=0; i<2*n; i++){
        long long hash = getHash(s[i]);
        string hashik = to_string(hash);
        if(mp[hashik] == true){
            cout << "Hash of string \"" << s[i] << "\" is " << hashik << endl;
            cnt++;
        }

        if(cnt == n) return 0;
    }
    
    return 0;
}