#include <iostream>
using namespace std;

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
 
Node* getMin(Node* root) { 
 while (root->left != NULL) { 
  root = root->left; 
 } 
 return root; 
} 
 
Node* add(Node* root, int data) { 
 if (root == NULL) { 
  return new Node(data); 
 } else if (root->data > data) { 
  if (root->left == NULL) { 
   root->left = new Node(data); 
  } else { 
   root->left = add(root->left, data); 
  } 
 } else if (root->data < data) { 
  if (root->right == NULL) { 
   root->right = new Node(data); 
  } else { 
   root->right = add(root->right, data); 
  } 
 } 
 return root; 
} 
 
Node* deleteNode(Node* root, int data) { 
 if (root == NULL) { 
  return NULL; 
 } else if (root->data > data) { 
  root->left = deleteNode(root->left, data); 
  return root; 
 } else if (root->data < data) { 
  root->right = deleteNode(root->right, data); 
  return root; 
 } else { 
  if (root->left == NULL && root->right == NULL) { 
   delete root; 
   return NULL; 
  } else if (root->right == NULL) { 
   Node* temp = root->left; 
   delete root; 
   return temp; 
  } else if (root->left == NULL) { 
   Node* temp = root->right; 
   delete root; 
   return temp; 
  } else { 
   Node* temp = getMin(root->right); 
   root->data = temp->data; 
   root->right = deleteNode(root->right, temp->data); 
   return root; 
  } 
 } 
} 
 
Node* find(Node* root, int x) { 
 if (root == NULL) { 
  return NULL; 
 } else if (root->data == x) { 
  return root; 
 } else if (root->data < x) { 
  return find(root->right, x); 
 } else { 
  return find(root->left, x); 
 } 
}
bool forLeft(Node* node, int i, int k){
    if(i >= k) return true;
    if(node == NULL) return false;
    return forLeft(node->left, i+1, k);
}
bool forRight(Node* node, int i, int k){
    if(i >= k) return true;
    if(node == NULL) return false;
    return forRight(node->right, i+1, k);
}

int count(Node* root,int k){
    int cnt = 0;
    if(root == NULL) return 0;
    if(forLeft(root,0,k) && forRight(root, 0 , k)){
        return count(root->left,k) + count(root->right, k) + 1;
    }
    return count(root->left,k) + count(root->right, k);
}

int main() {
    int n; cin >> n;
    int ans[n-1];
    Node* BST = NULL;
    for(int i = 0 ; i < n ;i++){
        int val; cin >> val;
        BST = add(BST, val);
    }
    for(int i = 2; i <= n; i++){
        ans[i-2] = count(BST,i);
    }
    for(int i = 0; i <n-1; i++){
        cout << ans[i] << " ";
    }

    return 0;
}