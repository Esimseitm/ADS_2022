#include <bits/stdc++.h> 
using namespace std; 
int sizee = 0; 
 
struct Node{ 
    int val; 
    Node* next; 
    Node(): val(0), next(nullptr) {} 
    Node(int x): val(x), next(nullptr) {} 
    Node(Node* next): val(0), next(next) {} 
    Node(int x, Node* next): val(x), next(next) {} 
}; 
  
 
Node* insert(Node* head, Node* node, int p){ 
    /* write your code here */ 
    if(head == nullptr){ 
        head = node; 
    } 
    else if(p == 0){ 
        node->next = head; 
        head = node; 
    } 
    else{ 
        Node* cur = head; 
        int i = 0; 
        while(cur != nullptr){ 
            if(i+1 == p){ 
                node->next = cur->next; 
                cur->next = node; 
                break; 
            } 
            i++; 
            cur = cur->next; 
        }      
    } 
    sizee++; 
    return head; 
} 
  
Node* remove(Node* head, int p){ 
    /* write your code here */ 
    if(p == 0){ 
        head = head->next; 
    } 
    else{ 
        Node* cur = head; 
        for(int i = 0; i < p-1; i++){ 
            cur = cur->next; 
        } 
        cur->next = cur->next->next; 
    } 
    sizee--; 
    return head; 
} 
  
Node* replace(Node* head, int p1, int p2){ 
    /* write your code here */ 
    Node* cur = head; 
    for(int i = 0; i < p1; i++){ 
        cur = cur->next; 
    } 
    Node* temp = new Node(cur->val); 
    head = remove(head, p1); 
    head = insert(head, temp, p2); 
     
    return head; 
} 
  
Node* reverse(Node* head){ 
    /* write your code here */ 
    Node* cur =  head; 
    Node* prev = nullptr; 
    Node* next = nullptr; 
    while(cur != nullptr){ 
        next = cur->next; 
        cur->next = prev; 
        prev = cur; 
        cur = next; 
    } 
    head = prev; 
    return head; 
} 
  
void print(Node* head){ 
    /* write your code here */ 
    Node* cur = head; 
    while(cur != nullptr){ 
        cout << cur->val << ' '; 
        cur = cur->next; 
    } 
    cout << endl; 
} 
 
  
Node* cyclic_left(Node* head, int x){ 
    /* write your code here */ 
    if(x != 0){ 
        Node* cur = head; 
        while(cur->next){ 
            cur = cur->next; 
        } 
        Node* tail = cur; 
        cur = head; 
        for(int i = 0; i < x-1; i++){ 
            cur = cur->next; 
        } 
        tail->next = head; 
        head = cur->next; 
        cur->next = nullptr; 
    } 
    return head; 
} 
  
 
Node* cyclic_right(Node* head, int x){ 
    /* write your code here */ 
    if(x != 0){ 
        int temp = sizee-x; 
        head = cyclic_left(head, temp); 
    } 
    return head; 
} 
  
int main(){ 
    Node* head = nullptr; 
    while (true) 
    { 
        int command; cin >> command; 
        if (command == 0){ 
            break; 
        }else if(command == 1){ 
            int x, p; cin >> x >> p; 
            head = insert(head, new Node(x), p); 
        }else if (command == 2){ 
            int p; cin >> p; 
            head = remove(head, p); 
        }else if (command == 3){ 
            print(head); 
        }else if (command == 4){ 
            int p1, p2; cin >> p1 >> p2; 
            head = replace(head, p1, p2); 
        }else if (command == 5){ 
            head = reverse(head); 
        }else if (command == 6){ 
            int x; cin >> x; 
            head = cyclic_left(head, x); 
        }else if (command == 7){ 
            int x; cin >> x; 
            head = cyclic_right(head, x); 
        }    
    } 
    return 0; 
}