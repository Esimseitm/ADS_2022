#include <iostream>
#include <stack>

using namespace std;

int main () {
    stack<int> aa;
    int n;
    cin >> n;
    string comm;
    int numb;
    for (int i = 0; i < n; i++) {
        cin >> comm;
        if (comm == "add") {
            cin >> numb;
            aa.push(numb);
        }
        if (comm == "delete") {
            
        }
    }



    return 0;
}