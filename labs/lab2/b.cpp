#include <iostream>
using namespace std;

struct ListNode
{
	string s;
	ListNode *next;
	ListNode *prev;

	ListNode(string s)
	{
		this->s = s;
		this->next = nullptr;
		this->prev = nullptr;
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

	void push_back(string s)
	{
		this->size++;
		ListNode *temp = new ListNode(s);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			this->tail = temp;
		}
	}

    void shiftleft(int k){
		tail->next = head;
		for (int i = 0; i < k; i++) {
			head = head->next;
			tail = tail->next;
		}
		tail->next = nullptr;
    }

	void print() {
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->s << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main()
{
	LinkedList *ll = new LinkedList();
    int n;
    cin >> n;
    string s;
    int k;
    cin >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        ll->push_back(s);
    }
    ll->shiftleft(k);
    ll->print();
	return 0;
}