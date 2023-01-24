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
    // algorithm sort by bubble sort in LL list
    void sort() {
        Node *first = head;
        Node *sec = nullptr;
        if( head == nullptr)  
            return;
        while(first-> next != nullptr) {
            sec = first -> next;
            while(sec != nullptr) {
                if (first -> val  > sec -> val) { // чтобы сорт по убыванию надо поменять знак на <
                    swap(first->val, sec->val);
                }
                sec = sec-> next;
            }
            first = first -> next;
        }
    }
};

int main () {
    LinkedList list;
    int n ; cin >> n;
    for(int i=0; i < n; i++) {
        int x;
        cin >> x;
        list.push(x);
    }
    list.print();
    cout << endl;
    list.sort();
    list.print();
    return 0;
}