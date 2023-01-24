#include <iostream>
#include <cmath>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
\
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
			this->tail = temp;
		}
	}

    void check(int m){
        ListNode *cur = this->head;
        int index = 0;
        int f_index;
        int min = 2147483647;
        while(cur != nullptr){
            int ans = abs(m - cur->val);
            if(ans < min){
				min = ans;
				f_index = index;
            }
            index++;
            cur = cur->next;
        }
        cout << f_index;
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
        l->push_back(x);
    }
    int m;
    cin >> m;
    l->check(m);
	return 0;
}