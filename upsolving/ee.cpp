#include <iostream>
#include <vector>
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
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

struct stackk{
    vector<int> stack;
    int nam = 0;
    void maxvalue(){
        if(!stack.empty()){
            for(int i = 0; i < stack.size(); i++){
                if(stack[i] > nam){
                    nam = stack[i];
                }
            }
            cout << nam << endl;
            nam = 0;
        }else{
            cout << "error"<< endl;
        }
    }
    void getpos(){
        if(!stack.empty()){
            cout << stack.back() << endl;
        }else{
            cout << "error"<< endl;
        }
    }
    void push_back(int x){
        stack.push_back(x);        
    }

    void pop_front(){
        if(!stack.empty())
            stack.pop_back();
    }

};



int main(){
    int abc;
    cin >> abc;
    stackk stak;
    for(int i = 0; i < abc; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int x; cin >> x;
            stak.push_back(x);
        }else if(s == "getmax"){
            stak.maxvalue();
        }else if(s == "getcur"){
            stak.getpos();
        }else if(s == "delete"){
            stak.pop_front();
        }
    }
    return 0;
}