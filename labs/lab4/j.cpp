#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        left = right = 0;
    }
};

class BST{
private:
    Node * root;
    Node * push(Node *cur, int val){
    if(cur == nullptr) return new Node(val);
    if(val > cur->val) cur->right = push(cur->right, val);
    if(val < cur->val) cur->left = push(cur->left, val);
    return cur;
}
    void push_(Node *cur, vector <Node*> &v){
        if(cur != 0){
            push_(cur->left, v);
            v.push_back(cur);
            push_(cur->right, v);
        }

    }

    Node* Balanced(vector <Node*> &v, int left, int right){
        if(left > right) 
            return 0;
        int mid = (left + right)/2;
        Node *temp = v[mid];
        temp->left = Balanced(v, left, mid-1);
        temp->right = Balanced(v, mid+1, right);
        return temp;
    }

    void print(Node *cur){
        if(cur != 0){
            cout << cur->val << " ";
            print(cur->left);
            print(cur->right);
        }
    }

public:
    BST(){
        root = 0;
    }
    void print(){
        vector <Node*> v;
        push_(root, v);
        root = Balanced(v, 0, v.size()-1);
        print(root);
    }
    void push_(){
        vector <Node*> v;
        push_(root,v);
    }
    
    void push(int val){
        root = push(root, val);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < pow(2, n)-1; i++){
        int t;
        cin >> t;
        tree.push(t);
    }
    tree.print();
    return 0;
} 