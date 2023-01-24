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

	void _prord(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_prord(node->left);
		_prord(node->right);
	}

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

	Node* _search(Node* cur, int target) {
		if (!cur) return nullptr;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
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

	void solve(int target) {
		Node* targetNode = search(target);
		_prord(targetNode);
	}
};



int main() {
	BST bsst;
	int n; 
	int node;
	int target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node;
		bsst.insert(node);
	}
	cin >> target;
	bsst.solve(target);

	return 0;
}