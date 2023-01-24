#include <bits/stdc++.h>

using namespace std;

int bmn = 0;
struct Node{
    int val;
    Node *levo;
    Node *pravo;
    Node(int val){
        this->val = val;
        levo = nullptr;
        pravo = nullptr;
    }
};
struct BST{
    Node *base;
    BST(){
        base = nullptr;
    }
    Node *push_back(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(cur->val > val) cur->levo = push_back(cur->levo, val);
        if(cur->val < val) cur->pravo = push_back(cur->pravo, val);
        return cur;
    }
    void function(Node *temp){
        if(temp == nullptr) return;
        if(temp->levo == nullptr and temp->pravo == nullptr){
            bmn++;
        }
        function(temp->levo);
        function(temp->pravo);
    }
    void push_back(int val){
        base = push_back(base, val);
    }
    void function(){
        function(base);
        cout << bmn;
    }
};

int main(){
    BST derevo;
    int name;
    cin >> name;
    int x;
    while(name--){
        cin >> x;
        derevo.push_back(x);
    }
    derevo.function();
}