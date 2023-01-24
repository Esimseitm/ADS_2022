#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5;


struct node {
  int data;
  node* nxt;

  node() {
    this->data = 0;
    this->nxt = NULL;
  }
  node(int data) {
    this->data = data;
    this->nxt = NULL;
  }
  node(int data, node* nxt) {
    this->data = data;
    this->nxt = nxt;
  }
};

struct linked_list {
  node* head = NULL; // front
  // node* tail = NULL; // can be stored
  int front() {
    return head->data;
  }
  void push_front(int x) { // O(1)
    if (head == NULL) {
      head = new node(x);
      return;
    }
    node* v = new node(x, head);
    head = v;
  }
  
  void pop_front() { // O(1)
    if (head == NULL) {
      cerr << "Error: List is empty\n";
      exit(0);
    }
    node* newHead = head->nxt;
    delete head; // avoid memory leak
    head = newHead;
  }

  node* get_tail() { // O(n)
    node* tail = head;
    while (tail->nxt != NULL) {
      tail = tail->nxt;
    }
    return tail;
  }

  int back() { // O(n)
    return get_tail()->data;
  } 
  void push_back(int x) { // O(n)
    if (head == NULL) {
      head = new node(x);
      return;
    }
    node* tail = get_tail();
    node* v = new node(x);
    tail->nxt = v;
  }
  void pop_back() { // O(n)
    if (head == NULL) {
      cerr << "Error: List is empty\n";
      exit(0);
    }
    if (head->nxt == NULL) {
      // forget about head
      delete head;
      head = NULL;
      return;
    }
    // pick the element that preceeds tail
    node* pre_tail = head;
    while (pre_tail->nxt->nxt != NULL) {
      pre_tail = pre_tail->nxt;
    }
    node* tail = pre_tail->nxt;
    pre_tail->nxt = NULL;
    delete tail;
  }

  void print() {
    node* v = head;
    cout << "[";
    while (v != NULL) {
      cout << v->data;
      if (v->nxt != NULL)
        cout << " ";
      v = v->nxt;
    }
    cout << "]\n";
  }
};

int main () {
  int tests;
  cin >> tests;

  linked_list L;

  for (int i = 0; i < tests; i++) {
    
    string s;
    cin >> s;

    int x;
    if (s == "push_back") {
      cin >> x;
      L.push_back(x);
      cout << "OK\n";
    }
    if (s == "push_front") {
      cin >> x;
      L.push_front(x);
      cout << "OK\n";
    }
    if (s == "pop_front") {
      L.pop_front();
      cout << "OK\n"; 
    }
    if (s == "pop_back") {
      L.pop_back();
      cout << "OK\n"; 
    }
    L.print();
  }



  return 0;
}





