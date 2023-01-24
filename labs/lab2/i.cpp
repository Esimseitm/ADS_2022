#include <iostream>
using namespace std;
struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
	Node *temp = new Node(s);
	if (head == nullptr){
		head = temp;
	}else{
		Node *cur = head;
		while(cur->next){
			cur = cur->next;
		}
		cur->next = temp;
	}
	cnt++;
}
void add_front(string s){
	Node *temp = new Node(s);
	temp->next = head;
	head = temp;
	cnt++;
}
bool empty(){
    return head == NULL;
}
void erase_front(){
	head = head->next;
	cnt--;
}
string front(){
	return head->val;
}
string back(){
	Node *cur = head;
    while(cur->next){
		cur = cur->next;
	}
	return cur->val;
}
void erase_back(){
	if(front() == back()){
		head = NULL;
	} else{
		Node *cur = head;
		while(cur->next->next){
			cur = cur->next;
		}
		cur->next = NULL;
	}
	cnt--;
}
void clear(){
	head = nullptr;
}
  
int main(){
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
		}
   	}
    return 0;
}