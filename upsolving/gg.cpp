#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> deq;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int main(){
    vector<int> vec;
    int num;
    cin >> num;
    int th = 3000;
    for(int i = 0; i < num; i++){
        int xs;
        cin >> xs;
        // cout << "fdfddffd" << endl;
        if(deq.empty()){
            deq.push_back(xs);
        }else{
            // cout << "fdfddffd" << endl;
            if(xs - deq.front() <= th){
                deq.push_back(xs);
                // cout << "fdfddffd" << endl;
            }else{
                deq.push_back(xs);
                while(xs - deq.front() > 3000){
                    // cout << "fdfddffd" << endl;
                    deq.pop_front();
                } 
            }
        }
        int size = deq.size();
        vec.push_back(size);
    }
    int dfgsdf;
    string dfd;
    for(int i = 0; i < num; i++){
        cout << vec[i] << " ";
    }
    return 0;
}