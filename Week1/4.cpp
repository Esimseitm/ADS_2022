// Node (int data, Node *next)
#include <iostream>

using namespace std;

class Node {
    // Node *n1 = new Node(5);
    // n1.data =  5;
    // n1.next = NULL;
    public:
    int data;
    Node *next;

    Node( int data) {
        this->data = data;
        this->next = NULL;
    } 
};



int main () {
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    n1->next = n2;
    n2->next = n3;
    cout << "n1 = " <<  n1 << endl;
    cout << "n2 = " <<  n2 << endl;
    cout << "n3 = " <<  n3 << endl;
    cout << "n1->next = " << n1->next << endl;
    cout << "n2->next = " << n2->next << endl;
    cout << "n3->next = " << n3->next << endl;
    //      n1 -> n2 -> n3 -> 30
    cout << n1->next->next->data << endl;
    return 0;
}