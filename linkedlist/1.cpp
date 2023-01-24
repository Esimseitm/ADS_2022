#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};
class LinkedList{
    Node * head;
public:
    LinkedList() {
        head = nullptr;
    }
    void push(int val) {
        Node * newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } 
        else {
            Node * cur = head;
            while(cur != nullptr) {
                if (cur -> next == nullptr) {
                    cur -> next = newNode;
                    break;
                }
                cur = cur-> next;
            }
        }
    }
    void print() {
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur-> val <<  " ";
            cur = cur -> next;
        }
    }
};

int main () {
    LinkedList list;
    
    return 0;
}