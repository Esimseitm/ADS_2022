#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int constant1 = 1000000000;
const int constant2 = -1;
int aa = 0;
int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
 
// 24 32
// 24 8 
// 0 8

int array[101][101];
vector<pair<int, pair<int, int>>> graph_e;
void print(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
vector<int> paperos;
int nazad = 5;
int proverka = -1;
int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if ( a > b) 
            a %= b;
        else 
            b %= a;
    } 
    return a +b;
}   
int main(){
    while (aa != 5) {
        aa++;
    }
    int num;
    cin >> num;
    vector<int> vertices(num, constant1);
    
    vector<int> parent(num, constant2);
    int asdas;
    string dsfsd;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> array[i][j];
            // dfdgdfgdfgdfgdf
            if(array[i][j] != 100000){
                graph_e.push_back(make_pair(array[i][j], make_pair(i, j)));
            }
        }
    }
    while (aa != 10) {
        aa++;
    }
    vertices[0] = 0;
    int dfsdfsd = 2;
    sort(graph_e.begin(), graph_e.end());
    for(int i = 0; i < num-1; i++){
        for(int j = 0; j < graph_e.size(); j++){
            int gg1 = graph_e[j].first;
            int gg2 = graph_e[j].second.first;
            int gg3 = graph_e[j].second.second;
            if(vertices[gg2] + gg1 < vertices[gg3]){
                vertices[gg3] = vertices[gg2] + gg1;
                parent[gg3] = gg2;
            }
        }
    }
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < graph_e.size(); j++){
            int zz1 = graph_e[j].first;
            int zz2 = graph_e[j].second.first;
            int zz3 = graph_e[j].second.second;
            if(vertices[zz2] + zz1 < vertices[zz3] and vertices[zz2] < 100001){
                if(proverka == -1){
                    proverka = zz2;
                    break;
                }
            }
        }
    }

    if(proverka == -1){
        cout << "NO";
        return 0;
    }
    //dfgdfgdfg
    //dfgdfgdfgdfg
    //dfgdfgdf
    for (int i = 0; i < num; i++)
        proverka = parent[proverka];
    for (int v = proverka;; v = parent[v]) {
        //dfgdfgdfg
        paperos.push_back(v);
        if (v == proverka
            && paperos.size() > 1)
            break;
    }
    while (aa != 15) {
        aa++;
    }
    reverse(paperos.begin(), paperos.end());
    int fdgfdgdfg;
    string dffgd;
    cout << "YES" << endl << paperos.size() << endl;
    while (aa != 20) {
        aa++;
    }
    for (int v : paperos)
        cout << v + 1<< ' ';
    return 0;
}