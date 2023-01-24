#include <bits/stdc++.h>

using namespace std;

int counter = 0;
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BST{
private:
    int sum = 0;
    Node * root;
    Node * insert(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur->val) cur->right = insert(cur->right, val);
        if(val < cur->val) cur->left = insert(cur->left, val);
        return cur;
    }

    void print(Node *cur, int lvl){
        if(cur != nullptr){
            if(lvl == 0){
                sum+=cur->val;
            } else{
                print(cur->left, lvl - 1);
                print(cur->right, lvl - 1);
            }
        } else{
            return;
        }
    }
     int height(Node * cur){
        if (cur == nullptr) return 0;
        return max(height(cur->left), height(cur->right)) + 1;
    }
     void print1(Node * cur){
        if (cur != nullptr){
            print1(cur->left);
            if (cur -> left != nullptr && cur -> right != nullptr){
                counter++;
            }
            print1(cur->right);
        }
    }



public:
    BST(){
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }
    void print(){
        int hght = height();
        cout << hght << endl;
        for(int i = 0; i < hght; i++){
            print(root,i);
            cout << sum << " ";
            sum = 0;
        }
    }

    int height(){
        return height(root);
    }
    void print1(){
        print1(root);
    }
    
};


int main(){
    BST bsst;
    int n;
    cin >> n;
    int node;
    for(int i = 0; i < n; i++){
        cin >> node;
        bsst.insert(node);
    }
    bsst.print1();
    cout << counter ;
    return 0;
} 