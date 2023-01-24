#include <iostream>
using namespace std;

struct ListNode
{
	string s;
	ListNode *next;

	ListNode()
	{
		this->s = s;
		this->next = nullptr;
	}

	ListNode(string s)
	{
		this->s = s;
		this->next = nullptr;
	}

	ListNode(string s, ListNode *next)
	{
		this->s = s;
		this->next = next;
	}
};

struct LinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void push_back(ListNode **head, string s){
	ListNode *temp = new ListNode(s);
	temp->s = s;
	temp->next = (*head);
	(*head) = temp;
}
void removingDuplicates(ListNode *head){
    ListNode *cur = head;
    ListNode *nextt;
    if(!cur){
        return;
    }
    while(cur->next){
         if(cur->s == cur->next->s){
            nextt = cur->next->next;
            free(cur->next);
            cur->next = nextt;
        } else{
            cur= cur->next;
        }
    }
}
int cnt(ListNode *head){
    int cnt = 0;
    ListNode *cur = head;
    while(cur){
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

void print(ListNode *cur){
	while(cur != NULL){
		cout << cur->s << "\n";
		cur = cur->next;
	}
}

int main(){
    int n;
    cin >> n;
    string s;
	ListNode *head = NULL;
    for(int i = 0; i < n; i++){
        cin >> s;
        push_back(&head, s);
    }
    removingDuplicates(head);
    cout<< "All in all: " << cnt(head) << "\n";
    cout << "Students:" << endl;
    print(head);
	return 0;
}