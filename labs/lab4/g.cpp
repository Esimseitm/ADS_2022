#include<bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct BST {
private:
	Node* root;

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	int _getSize(Node* node) {
		if (!node) return 0;
		return _getSize(node->left) + _getSize(node->right) + 1;
	}

public:
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	Node* getRoot() {
		return root;
	}

	int getHeight(Node* node, int &d) {
		if (!node) return 0;
		int left = getHeight(node->left, d);
		int right = getHeight(node->right, d);
		d = max(d, left + right + 1);
		return max(left, right) + 1;
	}

	int Diameter() {
		int d = 0;
		getHeight(root, d);
		return d;
	}

	
};

int main() {
	BST bsst;
	int n;
	cin >> n;
    int node;
	for(int i = 0; i < n; i++){
        cin >> node;
		bsst.insert(node);
	}
	cout << bsst.Diameter();
	return 0;
}