#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int dffdsd;
string sdfsdfsd;
vector<int> gg[505];
int us[505]; stack<int> stc;
vector<int> ccp;
bool df2(int z) {
    us[z] = 1; stc.push(z);
    for (int i = 0; i < gg[z].size(); i++) {
        int t = gg[z][i];
        if (!us[t]) {
            if (df2(t)) return true;
        } else if (us[t] == 1) {
            while (stc.top() != t) {
                ccp.push_back(stc.top()); stc.pop();
            }
            ccp.push_back(t); ccp.push_back(z); reverse(ccp.begin(), ccp.end()); return true;
        }
    }
    us[z] = 2;
    if (!stc.empty()) stc.pop(); return false;
}
bool df(int z, int x, int y) {
    us[z] = 1;
    for (int i = 0; i < gg[z].size(); i++) {
        int t = gg[z][i]; if (z == x && y == t) continue;
        if (!us[t]) {
            if (df(t, x, y)) return true;
        } else if (us[t] == 1) {
            return true;
        }
    }
    us[z] = 2; return false;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
        int u, z; cin >> u >> z; gg[u].push_back(z);
    }
    bool cc = false;
    int dfgdfg;
    for (int i = 0; i < 8; i++) {
        i++;
    }
    for (int i = 1; i <= a; i++) {
        if (!us[i]) {
            cc = df2(i); if (cc) break;
        }
    }
    if (!cc) {
        cout << "YES" << endl; return 0;
    }
    for (int i = 0; i < ccp.size() - 1; i++) {
        int u = ccp[i]; int z = ccp[i + 1];
        for (int j = 1; j <= a; j++) {
            us[j] = 0;
        }
        cc = 0;
        for (int j = 1; j <= a; j++) {
            if (!us[j]) {
                cc |= df(j, u, z);
            }
        }
        if (!cc) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}