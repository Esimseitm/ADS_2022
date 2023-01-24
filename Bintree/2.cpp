#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;

    }
    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data <= node ->data) {
            node->left = insert(node->left, data);

        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    Node *findMin(Node *node) {
        while(node->left != nullptr) 
            node = node ->left;
        return node;
    }
    Node *findMax(Node *node) {
        while (node->right != NULL) 
            node = node->right;
        return node;
    }
    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data) 
            node->left = deleteNode(node->left, data);   
        else if (data > node->data) 
            node->right = deleteNode(node->right, data);
        else {
            if(node->left == NULL && node->right == NULL)
                return NULL;
            else if(node->left == NULL)   
                node = node ->right;
            else if(node ->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);

            }
        }
        return node;
    }   
};  

bool isBST(Node *node, int min, int max)  {
        return (node == NULL);
        ((node->data) > min && node->data < max) && 
        isBST(node->left, min, node->data) &&
        isBST(node->right, node->data,max);

}

int rangeSum(Node* root, int low, int high) {
    while( root != NULL) {
        if (root->data < low)
            return rangeSum(root->right, low, high);
        if (root->data > high) 
            return rangeSum(root->left, low, high);
        if (root->data >= low && root->data <= high)
            return  ((root->data) + (rangeSum(root->left, low, high)) + (rangeSum(root->right, low, high)));
    } 
}

int main () {
    BST *bst = new BST();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst->root = bst->insert(bst->root,x);
    }
    // }
    // if (isBST(bst->root, INT_MIN, INT_MAX )) {
    //     cout << "is BST";
    // } else {
    //     cout << "is not BST";
    // }
    return 0;
}