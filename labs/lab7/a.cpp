#include <bits/stdc++.h>

using namespace std;

void Merge(vector <string> & v,int l1,int r1,int l2,int r2){
    int n1 = r1-l1+1;
    vector <string> L(n1);
    for(int i = 0;i<n1;i++){
        L[i] = v[l1+i];
    }
    int n2 = r2-l2+1;
    vector <string> R(n2);
    for(int i = 0;i<n2;i++){
        R[i] = v[l2+i];
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while (i1<n1 && i2<n2){
        if(L[i1].size()<R[i2].size()){
            v[i++] = L[i1++];
        }
        else if(L[i1].size()>R[i2].size()){
            v[i++] = R[i2++];
        }
        else{
            v[i++] = L[i1++];
        }
    }
    while (i1<n1){
        v[i++] = L[i1++];
    }
    while (i2<n2){
        v[i++] = R[i2++];
    }
}
void msort(vector <string> & v,int l,int r){
    if(l<r){
        int m = l + (r - l) / 2;
        msort(v,l,m);
        msort(v,m+1,r);
        Merge(v,l,m,m+1,r);
    }
}

int main(){
    int n;
    cin>>n;
    int fgfdf;
    string dfsdfsd;
    vector <string> v;
    cin>>ws;
    string s,str;
    for(int i=0;i<n;i++){
        v.clear();
        getline(cin, s);
        stringstream k(s);
        while (getline(k, str, ' ')) {    
            v.push_back(str);
        }
        msort(v,0,v.size()-1);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
