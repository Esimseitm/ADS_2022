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
    // удаление по значению, но если будут дубликаты, удаляет первое вхождение
    void del(int val) {
        if (head == nullptr) {
            cout << "LL is empty";
            return;
        }
        if (head -> val == val) {
            head = head -> next;

        }
        else {
            Node * cur = head;
            Node * prev = nullptr;
            while (cur != nullptr) {
                if (cur -> val == val ) {
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;

            }
            cout << "No such element " << val << endl;
        }
    }
     // удалить по позиции
    void del_pos(int pos) {
        if (head == nullptr) {
            cout << "LL is empty";
            return;
        }
        if (pos <= 0) {
            cout << "No such pos" << pos;
            return;
        }
        if (pos == 1 ){
            head = head -> next;

        }
        else {
            int i = 1;
            Node * cur = head;
            Node * prev = nullptr;
            while (cur != nullptr) {
                if (i == pos) {
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;

            }
            cout << "No such position " << pos << endl;
        }
    }
};
int main () {
    LinkedList list;
    list.push(1);
    list.push(3);
    list.push(6);
    list.push(8);
    list.push(10);
    list.push(123);
    list.push(22);
    list.print();
    cout <<endl;
    list.del_pos(2);
    list.del_pos(5);
    list.print();
    cout << endl;
    list.del_pos(-123);
    
   


    return 0;
}