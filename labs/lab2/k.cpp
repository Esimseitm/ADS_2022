#include <iostream>
using namespace std;
struct Node{
    char val;
    Node *next;
    bool was;
    Node(char val){
        this->val = val;
        this->next = NULL;
    }
};
struct LinkedList{
    Node *head;
    Node *tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }

    void push_back(char val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            Node *cur = this->head;
            while(cur){
                if(cur->val == val){
                    cur->was = true;
                    return;
                }
                cur = cur->next;
            }
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    bool empty(){
        if(this->head != NULL)
            return false;
        return true;
    }
    
};
int main(){
    int n, k;
    char a;
    cin >> n;
    while(n--){
        LinkedList *ll = new LinkedList();
        cin >> k;
        while(k--){
            cin >> a;
            bool flag = false;
            ll->push_back(a);
            Node *tmp = ll->head;
            while(tmp != NULL){
                if(tmp->was == false){
                    cout << tmp->val << ' ';
                    flag = true;
                    break;
                }
                tmp = tmp->next;
            }
            if(flag == false)
                cout << "-1 ";
        }
        cout << '\n';
    }
}