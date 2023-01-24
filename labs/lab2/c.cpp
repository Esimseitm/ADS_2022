#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

struct DoublyLinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	DoublyLinkedList()
	{
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_front(int val)
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
			this->head->prev = temp;
			this->head = temp;
		}
	}

	void push_back(int val)
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
			temp->prev = this->tail;
			this->tail = temp;
		}
	}

	void removing()
	{
		ListNode *cur = head;
		int index = 1;
		while (cur != nullptr) {
			if (index % 2 == 0) {
				if (cur->next == nullptr) {
					ListNode *toDel = cur;
					cur->prev->next = nullptr;
					cur = cur->next;
					delete (toDel);
				} else {
					ListNode *toDel = cur;
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					cur = cur->next;
					delete (toDel);
				}
			} else {
				cur = cur->next;
			}
			index++;
		}
	}

	void print()
	{
		ListNode *cur = head;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << '\n';
	}
};

int main()
{
	int n, m;
	cin >> n ;
	DoublyLinkedList dll;
	while (n--) {
		cin >> m;
		dll.push_back(m);
	}
	dll.removing();
	dll.print();

	return 0;
}