#include <bits/stdc++.h>

using namespace std;

int bmn = 0;
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
struct BST{
    Node *root;
    BST(){
        root = nullptr;
    }
    Node *add(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(cur->val > val) cur->left = add(cur->left, val);
        if(cur->val < val) cur->right = add(cur->right, val);
        return cur;
    }
    void isLeaf(Node *temp){
        if(temp == nullptr) return;
        if(temp->left == nullptr and temp->right == nullptr){
            bmn++;
        }
        isLeaf(temp->left);
        isLeaf(temp->right);
    }
    void add(int val){
        root = add(root, val);
    }
    void isLeaf(){
        isLeaf(root);
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
        derevo.add(x);
    }
    derevo.isLeaf();
}