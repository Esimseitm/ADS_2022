#include <bits/stdc++.h>

using namespace std;

int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
    return stac.size();
}

struct Node { 
 int data; 
 Node* left; 
 Node* right; 
 
 Node(int data) { 
  this->data = data; 
  left = NULL; 
  right = NULL; 
 }  
}; 

bool getleft(Node* node, int i, int k){
    if(i >= k) return true;
    if(node == NULL) return false;
    return getleft(node->left, i+1, k);
}
bool getright(Node* node, int i, int k){
    if(i >= k) return true;
    if(node == NULL) return false;
    return getright(node->right, i+1, k);
}

Node* push_back(Node* root, int data) { 
 if (root == NULL) { 
  return new Node(data); 
 } else if (root->data > data) { 
  if (root->left == NULL) { 
   root->left = new Node(data); 
  } else {
   root->left = push_back(root->left, data); 
  } 
 } else if (root->data < data) { 
  if (root->right == NULL) { 
   root->right = new Node(data); 
  } else { 
   root->right = push_back(root->right, data); 
  } 
 } 
 return root; 
} 

int check(Node* root,int k){
    int cnt = 0;
    if(root == NULL) return 0;
    if(getleft(root,0,k) && getright(root, 0 , k)){
        return check(root->left,k) + check(root->right, k) + 1;
    }
    return check(root->left,k) + check(root->right, k);
}


int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
int main() {
    Node* DEREVO = NULL;
    int numb;
    cin >> numb;
    string sssfda;
    int ch = numb - 1;
    int arr[ch];
    int dsfsdfsd;
    for(int i = 0 ; i < numb; i++){
        int value;
        cin >> value;
        DEREVO = push_back(DEREVO, value);
        int dfsdf;
    }
    for(int i = 2; i <= numb; i++){
        arr[i-2] = check(DEREVO,i);
        int dffvsdf;
    }
    for(int m = 0; m <ch; m++){
        cout << arr[m] << " ";
        int fdfg;
    }

    return 0;
}