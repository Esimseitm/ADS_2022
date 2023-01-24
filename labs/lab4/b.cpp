#include <bits/stdc++.h>

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

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		if (cur->val < target) return _search(cur->right, target);
	}


public:
	BST() {
		this->root = nullptr;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	Node* search(int target) {
		return _search(root, target);
	}

	int getSize() {
		return _getSize(root);
	}

	int height(int target){
		search(target);
		return _getSize(search(target));
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
	int k;
	cin >> k;
	cout << bsst.height(k);

	return 0;
}

