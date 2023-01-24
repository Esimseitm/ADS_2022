# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
      val = 0;
      next = NULL;
  }

};

int findMaxSum(int n, Node *head) {
  bool is_pos = false;
	int max = -1e6;
  int max_end = 0;
  Node * cur = head;
  while(cur){
    max_end += cur->val;
    if(cur->val > 0){
      is_pos = true;
    }
    if(max < max_end){
      max = max_end;
    }
    if(max_end <0){
      max_end = 0;
    }
    cur = cur->next;
  }
  return max;

}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}