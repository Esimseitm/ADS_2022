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
    bool contains(int val) { // есть ли данное число в массиве
        Node *cur = head;
        while(cur != nullptr) {
            if (cur -> val == val) {
                return true;
            }
            cur = cur -> next;
        }
        return false;
    }  
    // type function
    // type == type return 
    vector <int> search(int val) {
        vector <int> ans;
        Node *cur = head;
        int i = 1;
        while(cur != nullptr) {
            if (cur -> val == val) {
                ans.push_back(i);
            }
            cur = cur-> next;
            i++;
        }
        return ans;
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
    list.push(8);
    list.push(22);
    list.push(8);
    list.print();
    cout << endl << list.contains(30) << endl;
    vector<int> indexes = list.search(8);
    for (auto i : indexes) {
        cout << i << " ";
    }
    return 0;
}