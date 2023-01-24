#include <bits/stdc++.h>

using namespace std;

struct Nodejs {
	Nodejs *root;
	int data;
	Nodejs* left;
	Nodejs* right;
	int cnt;
	Nodejs(int data) {
		this->data = data;
		cnt = 1;
		left = NULL;
		right = NULL;
	} 
};
struct BST{
Nodejs* getMin(Nodejs* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Nodejs* add(Nodejs* root, int data) {
	if (root == NULL) {
		return new Nodejs(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Nodejs(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Nodejs(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	else if(root -> data == data){
		root->cnt+=1;
	}
	return root;
}

Nodejs* deleteNodejs(Nodejs* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNodejs(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNodejs(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Nodejs* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Nodejs* temp = root->right;
			delete root;
			return temp;
		} else {
			Nodejs* temp = getMin(root->right);
			root->data = temp->data;
			root->cnt = temp->cnt;
			root->right = deleteNodejs(root->right, temp->data);
			return root;
		}
	}
}

Nodejs* find(Nodejs* root, int x) {
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
};
int main(){
	BST tree;
	int n;
    cin >> n; 
	Nodejs *root = 0;
    for(int i = 0; i < n; i++){
        string s;
        int val;
        cin >> s >> val;
        if(s == "insert"){
            root = tree.add(root,val);
        }
        else if(s == "cnt"){
			Nodejs *tmp = tree.find(root,val);
			if(tmp == 0){
				cout << 0 << endl;
			}
			else{
			cout << tree.find(root,val)->cnt << endl;
        }   
		}
        else if(s == "delete"){
			Nodejs *tmp = tree.find(root,val);
			if(tmp!=0 && tmp->cnt == 1){
            root = tree.deleteNodejs(root,val);
			}
			else if(tmp != 0) tree.find(root,val)->cnt -=1;
        }
    }
}