#include <iostream>

using namespace std;


void prime(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if ( i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << i << " ";
    }
}


struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int x){
        val = x;
        right = NULL;
        left = NULL;
    }
};

class BST{
private:
    Node * base;
    int summa = 0;
    Node * push_back(Node* cur, int x){
        if(cur == NULL){
            return new Node(x);
        }else if(x < cur->val){
            cur->left = push_back(cur->left, x);
        }else if(x > cur->val){
            cur->right = push_back(cur->right, x);
        }
        return cur;
    }

    int howmuch(Node * cur, int level){
        if(cur == NULL){
            return summa; 
        }

        summa += cur->val - level;
        howmuch(cur->left, level + 1);
        howmuch(cur->right, level + 1);


    }

public:
    BST(){
        base = NULL;
        summa = 0;
    }


    void push_back(int x){
        base = push_back(base, x);
    }


    void howmuch(){
        cout << howmuch(base, 0);
    }
};

int main(){
    int num;
    cin >> num;
    BST derevo;
    for(int i = 0; i < num; i++){
        int abc;
        cin >> abc;
        derevo.push_back(abc);

    }
    derevo.howmuch();
    return 0;
}