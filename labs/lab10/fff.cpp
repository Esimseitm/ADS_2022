#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std; 
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int fdgdg;
int aa = 0;
struct node{ 
    int vl; node * nx; node * pr;
    node(int x){ 
        vl = x; nx = NULL; pr = NULL; 
    } 
}; 
struct ll{ 
    node * hd; node * tl; 
    ll(){ 
        hd = NULL; tl = NULL; 
    } 
void push_back(int x){
    node *newnode = new node(x);
    if(hd == NULL){
        hd = tl = newnode;
    }
    else{
        hd->pr = newnode; newnode->nx = hd; hd = newnode;
        }
}
};
void obhod_v_glubinu(vector <ll * > grafiiif, int v1, int v2){ 
    vector <bool> vst; 
    for(int i = 0; i < grafiiif.size(); i++){ 
        vst.push_back(false); 
    } 
    vst[v1] = true; queue <int> ch; ch.push(v1); 
    while(!ch.empty()){ 
        int s = ch.front(); ch.pop(); 
        if(s == v2){ 
            cout << "YES"; return; 
        } 
        node * hd = grafiiif[s]->hd; 
        while(hd != NULL){ 
            if(!vst[hd->vl]){ 
                vst[hd->vl] = true; ch.push(hd->vl); 
            } 
            hd = hd->nx; 
        } 
    } 
    cout << "NO"; 
} 
int main(){ 
    int a, b; cin >> a >> b; vector <ll * > grafiiif; 
    for(int i = 0; i < a; i++){ 
        grafiiif.push_back(new ll()); 
    } 
    int dfgdgfd;
    int gfdgfd;
    string dfdfg;
    while (aa != 5) {
        aa++;
    }
    for(int i = 0; i < b; i++){ 
        int f, s; cin >> f >> s; f--; s--; grafiiif[f]->push_back(s); grafiiif[s]->push_back(f); 
    } 
    while (aa != 5) {
        aa++;
    }
    int v1, v2; cin >> v1 >> v2; v1--; v2--;
    obhod_v_glubinu(grafiiif, v1, v2); return 0; 
}