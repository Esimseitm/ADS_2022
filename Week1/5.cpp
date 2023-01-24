#include <iostream>

using namespace std;


// b Node (20) top
// a Node (10) 
 
class Node{
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public :
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }
    // push
    void push(int data) {
        // node (20) 
        // node (10) top
        Node *node = new Node(data);
        node-> next = top;
        top = node;
        sz++;
    }
    void pop() {
        if (top != NULL) {
            top = top-> next;
            sz--;
        }
    }
    int size() {
        return this-> sz;
    }
    bool empty() {
        return (sz == 0); 
    }


};
    


int main () {
    Stack *st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    cout << st-> top-> data << endl;
    cout << st->top->next->data << endl;
    cout << st-> size() << endl;
    st->pop();
    st->pop();
    cout << st-> size();

    return 0;
}