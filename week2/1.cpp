// Linked list
#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node *next = 0;
    Node() {
        data = 0;
    }
    Node(int _data) {
        data = _data;
    }
    Node(int _data, Node *_next) {
        data = _data;
        next = _next;
    }
};

struct linked_list {
    Node *head = 0;

    Node* get_tail() {
        if(head == 0) 
            return 0;
        Node *cur = head;
        while (cur -> next != 0)
            cur =  cur-> next;
        return cur;
    }   
    Node *get(int i) {
        // return node at pos i or return NULL
        Node *cur = head;
        for (int j = 0; j < i ;j++ ) {
            if (cur == 0) 
                return 0;
            cur = cur->next;
        }
        return cur;
    }

    void insert_begin(int data) {
        Node *new_node = new Node(data, head);
        head = new_node;

    }
    void insert_tail (int data) {
        Node *tail = get_tail();
        Node *new_node = new Node(data);
        tail-> next = new_node;
    }

    void insert(int i, int data) {
        // insert at pos i means
        // put element with data at position i
        // moving everything to right
        // 
        if (i == 0) {
            insert_begin(data);
            return;
        }
        Node *A =get(i-1);
        if (A == 0) {
            insert_tail(data);
            return;
        }
        Node *B = A->next;
        Node *new_node = new Node(data, B);
        A->next = new_node; // A-> new 
    }
    void output() {
        cout << "[";
        Node *cur = head;
        while ( cur != 0) {
            cout << cur-> data;
            cur = cur -> next;
            if (cur == 0) 
                cout << "]";
            else 
                cout << ", ";
        }
        cout << endl;   
    }
    // delete
    void del_begin() { // oldhead -> newhead
        if (head == 0)
            return ;
        Node *old_head = head;
        head = head->next;
        delete old_head; // no memory;
    }
    void del_end() {
        if (head == 0) 
            return;
        if (head-> next == 0) {
            delete head;
            head = 0;
            return;
        }
        Node *cur = head;
        while (cur->next->next != 0) 
            cur = cur->next;
        delete cur->next;
        cur-> next = 0;
    }


};
int main () {
    linked_list L;
    L.insert(0, 10);
    L.insert(1, 20);
    L.insert(2, 30);
    L.insert(3, 40);

    L.insert(2, 50);
    L.output();
    L.del_begin();
    L.del_end();
    L.output();

 
    cout << endl;
    
    cout << L.get(2)->data << endl;

    return 0;
}