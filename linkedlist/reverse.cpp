#include <iostream>
#include <vector>

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
    void reverse() {
        vector <int> rave;
        Node *cur = head;
        while(cur != nullptr) {
            rave.push_back(cur->val);
            cur = cur -> next;
        }
        for (int i = 0; i < rave.size(); i++) {
            cout << rave[i] << " ";
        }
        cur = head;
        int i = rave.size() -1;
        while(cur != nullptr) {
            cur -> val = rave[i];
            cur = cur -> next;
            i--;
        }
    }
    void reverse_h() {
        Node * cur = head;
        Node *next = nullptr;
        Node *prev = nullptr;
        while(cur != nullptr) {
            next = cur ->next;
            cur-> next = prev;
            prev = cur;
            cur = next; 
        }
        head = prev;
    }
};

int main () {
    LinkedList list;
    list.push(1);
    list.push(3);
    list.push(6);
    list.push(8);
    list.push(10);
    list.push(22);
    list.push(8);
    list.print();
    cout << endl;
    list.reverse_h();
    cout << endl;
    list.print();
    
    return 0;
}