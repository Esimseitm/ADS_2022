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

	int getHeight(Node *node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;
	}

	void getSumByLevels(Node* cur, int lvl, vector<int>& v) {
		if (!cur) return;
		v[lvl] += cur->val;
		getSumByLevels(cur->left, lvl + 1, v);
		getSumByLevels(cur->right, lvl + 1, v);
	}
};

int main() {
	BST bst;
	int n;
	cin >> n;
	while (n--) {
		int node;
		cin >> node;
		bst.insert(node);
	}
	vector<int> v(bst.getHeight(bst.getRoot()));
	bst.getSumByLevels(bst.getRoot(), 0, v);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}