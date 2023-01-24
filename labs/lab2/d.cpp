#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
	int val;
    int cnt;
	ListNode *next;
	ListNode *prev;

	ListNode(int val){
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
        this->cnt = 0;
	}
};

struct LinkedList{
	int size;
    int max;
	ListNode *head;
	ListNode *tail;

	LinkedList(){
		this->size = 0;
        this->max = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_back(int val){
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == NULL){
			this->head = temp;
			this->tail = temp;
		}
		else{
            ListNode *cur = this->head;
			while(cur != nullptr){
                if(cur->val == temp->val){
                    cur->cnt++;
                    break;
                }
                if(cur->next == NULL){
                    cur->next = temp;
                    break;
                }
                cur = cur->next;
            }
		}
	}

    void search(){
        ListNode *cur = this->head;
        while(cur != NULL){
            if(cur->cnt > max)
                max = cur->cnt;
            cur = cur->next;
        }
    }

    void print(){
        vector <int> v;
        ListNode* cur = this->head;
        while(cur != NULL){
            if(cur->cnt == max){
                v.push_back(cur->val);
            }
            cur = cur->next;
        }
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
    }
};
int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        l->push_back(x);
    }
    l->search();
    l->print();
}