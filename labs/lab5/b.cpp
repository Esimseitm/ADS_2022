#include<bits/stdc++.h>

using namespace std;

struct Heap_ {
	vector<int> heap;

	int hand(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(int value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[hand(i)] < this->heap[i]) {
			swap(this->heap[hand(i)], this->heap[i]);
			i = hand(i);
		}
	}
	int returning() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			int root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		int root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] > this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
    int getSize(){
        return heap.size();
    }
    void print(){
        for(int i = 0; i < heap.size(); i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
	Heap_ heap;
	int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        heap.insert(n);
    }
    while(heap.getSize() > 1){
        int x = heap.returning();
        int y = heap.returning();
        if(x > y){
            heap.insert(x - y);
        }
    }
    if(heap.getSize() == 0){
        cout << 0;
    } else{
        heap.print();
    }
    return 0;
}

