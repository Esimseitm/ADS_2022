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
    Node * cur;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    // void push_back(int val) {
    //     Node * newNode = new Node(val);
    //     if (head == nullptr) {
    //         head = newNode;
    //     } 
    //     else {
    //         Node * cur = head;
    //         while(cur != nullptr) {
    //             if (cur -> next == nullptr) {
    //                 cur -> next = newNode;
    //                 break;
    //             }
    //             cur = cur-> next;
    //         }
    //     }
    //     size++;
    // }
    void push(int val) {
        Node * newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            cur = newNode;
            size = 1;
        } 
        else {
            cur -> next= newNode;
            cur = newNode;
            size++;
        }
    }
    void print() {
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur-> val <<  " ";
            cur = cur -> next;
        }
    }
    void sz() {
        int sz = size;
        cout << sz;
    }
    void push_front(int val) { // добавляет в начало
        Node * newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        size++;
    }
    void add(int pos, int val) { // добавляет элемент в позицию
        if ( pos > size) {
            cout << "error";
            return;
        }
        Node * newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;

        }
        else {
            Node * cur = head;
            int i = 1;
            while(cur != nullptr) {
                if ( i == pos) {
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
                i++;
            }       
        }
        size++;
    }
    
    void insert(int pos, int val) { // заменяет число в позиции
        if ( pos > size) {
            cout << "error";
            return;
        }
        Node * cur = head;
        int i = 1;
        while(cur != nullptr) {
            if ( i == pos) {
                cur -> val = val;
                break;
            }
            cur = cur -> next;
            i++;
        }
    }
};
int main () {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.print();
    cout << endl;
    list.push_front(10);
    list.print();
    cout << endl;
    list.sz();
    // cout << endl;
    // list.add(4, 15);
    // list.print();
    // cout << endl;
    // list.insert(2, 100);
    // list.print();
    return 0;
}