#include <iostream>
#include <set>
using namespace std;

int count(int n) {
    int i = 2;
    set <int> st;
    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            st.insert(i);
        }
        else {
            i++;
        }
    }
    return st.size();
}

int main() {
    int n; cin >> n;
    cout << count(n);

    return 0;
}