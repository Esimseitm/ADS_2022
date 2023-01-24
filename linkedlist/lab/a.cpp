#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};
class LinkedList{
    Node * head;
    Node *cur;
public:
    LinkedList() {
        head = nullptr;
    }
    void push(int val) {
        Node * newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            cur = newNode;
        } 
        else {
            cur -> next= newNode;
            cur = newNode;
        }
    }
    void print() {
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur-> val <<  " ";
            cur = cur -> next;
        }
    }
    void check(int m) {
        int min = 2147483647;
        int ans_index = 0;
        int index = 0;
        int ans;
        Node *cur = head;
        while (cur != nullptr) {
            ans = abs(m - cur->val);
            if (ans < min) {
                min = ans;
                ans_index = index;
            }
            index++;
            cur = cur-> next;
        }
        cout << ans_index;
    }

};

int main () {
    LinkedList list;
    int n; cin>> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        list.push(x);
    }
    int m; cin >> m;
    list.check(m);
    return 0;
}