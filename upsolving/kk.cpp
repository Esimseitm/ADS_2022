#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> deq;
    int m = 0;
    bool naoborot = false;
    int numb;
    cin >> numb;
    for(int i = 0; i < numb; i++){
        int chislo;
        // patchddf
        cin >> chislo;
        if(chislo == 1){
            if(naoborot == false){
                int vtor;
                int mna;
                cin >> vtor;
                deq.push_back(vtor);
            }
            else{    
                int th;
                cin >> th;
                deq.push_front(th);
            }
        }else if(chislo == 2){
            naoborot = !naoborot;
        }
    }
    bool check = naoborot;
    if( check == false){
        while(!deq.empty()){
            cout << deq.front() << " ";
            deq.pop_front();
        }
    }else{
        while(!deq.empty()){
            cout << deq.back() << " ";
            deq.pop_back();
        }
    }
    return 0;
}