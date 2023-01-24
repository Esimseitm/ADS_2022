#include<iostream>
#include<vector>
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

	void _order(Node* node) {
		if (!node) return;
		_order(node->right);
		cout << node->val << " ";
		_order(node->left);
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

public:
	BST() {
		this->root = nullptr;
	}

	void inorder() {
		_order(root);
		cout << endl;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	void changeNodes(Node* cur, int& sum) {
		if (!cur) return;
		changeNodes(cur->right, sum);
		sum += cur->val;
		cur->val = sum;
		changeNodes(cur->left, sum);
	}

	void changeNodesOuter() {
		int sum = 0;
		changeNodes(root, sum);
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
	bsst.changeNodesOuter();
	bsst.inorder();

	return 0;
}