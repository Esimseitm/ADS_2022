#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = nullptr; // or type NUll instead of nullptr
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
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

	void addAtHead(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == nullptr)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			temp->next = this->head;
			this->head = temp;
		}
	}

	void addAtTail(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
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

	void addAtIndex(int val, int index)
	{
		if (index > this->size)
		{
			return;
		}
		else if (index == 0)
		{
			this->addAtHead(val);
		}
		else if (index == this->size)
		{
			this->addAtTail(val);
		}
		else
		{
			ListNode *temp = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp;
			this->size++;
		}
	}

	void printLL() {
		ListNode *cur = this->head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
		// while (cur->next) {

		// }
	}
};

int main()
{
	LinkedList *l = new LinkedList();
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        l->addAtTail(x);
    }
    int val, index;
    cin >> val;
    cin >> index;
    l->addAtIndex(val, index);
    l->printLL();
	return 0;
}