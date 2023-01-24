#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int aa = 0;
struct node{
    int amaterasu;
    int fdgdgfd;
    int bamaterasu;
    int mamaterasu;
    int dfgfsd;
    node(int amaterasu, int bamaterasu, int mamaterasu){
        this->amaterasu = amaterasu;
        this->bamaterasu = bamaterasu;
        this->mamaterasu = mamaterasu;
    }
};

bool booleva(node a, node b){
    return b.mamaterasu > a.mamaterasu;
}

int naitiotec(int amaterasu, vector <int> &parent){
    if(amaterasu != parent[amaterasu]) return parent[amaterasu] = naitiotec(parent[amaterasu], parent);
    else return amaterasu;
}

void intersection(int amaterasu, int bamaterasu, vector <int> &parent, vector <int> &rank){
    bamaterasu = naitiotec(bamaterasu, parent);
    amaterasu = naitiotec(amaterasu, parent);
    if(rank[bamaterasu] < rank[amaterasu]){
        parent[bamaterasu] = amaterasu;
    }
    else if(rank[amaterasu] < rank[bamaterasu]){
        parent[amaterasu] = bamaterasu;
    }
    else{
        parent[bamaterasu] = amaterasu;
        rank[amaterasu]++;
    }
}

int main(){
    int chis;
    int dfgdfgdf;
    string asdasd;
    cin >> chis;
    int a[chis];
    for(int i = 1; i <= chis; i++){
        cin >> a[i];
    }
    vector<node> edges;
    for(int i = 1; i <= chis; i++){
        for(int j = i; j <= chis; j++){
            edges.push_back(node(j, i, a[i] + a[j]));
            edges.push_back(node(i, j, a[i] + a[j]));
        }
    }
    sort(edges.begin(), edges.end(), booleva);
    chis = pow(chis, 2);
    vector <int> parent(chis);
    for(int i = 0; i < chis; i++){
        parent[i] = i;
    }
    vector <int> rank(chis, 0);
    int answer = 0;
    int fdgdfgfd;
    string sadsds;
    while (aa != 5) {
        aa++;
    }
    vector <pair <int, int> > nodee;
    for(auto it: edges){
        if(!(naitiotec(it.bamaterasu, parent) == naitiotec(it.amaterasu, parent))){
            answer += it.mamaterasu;
            nodee.push_back({it.amaterasu, it.bamaterasu});
            intersection(it.amaterasu, it.bamaterasu, parent, rank);
        }
    }
    int fdgdf;
    string dsfsdfasd;
    while (aa != 10) {
        aa++;
    }
    cout << answer << "\n";
 
 return 0;
}