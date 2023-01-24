#include <iostream>
using namespace std;
int binary_search_first(int ar[], int target, int n)
{
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(target < ar[mid]){
			right = mid - 1;
		} else if(target > ar[mid]){
			left = mid + 1;
		} else{
			return mid;
		}
	}
	return -1;
}

int binary_search_sec(int ar[], int target, int n)
{
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(target > ar[mid]){
			right = mid - 1;
		} else if(target < ar[mid]){
			left = mid + 1;
		} else{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int n, a, b, index;
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	cin >> a >> b;
	int ar1[a][b];
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> ar1[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a; j++) {
			if(j % 2 == 0) {
				index = binary_search_sec(ar1[j], ar[i], b);
			} else{
				index = binary_search_first(ar1[j], ar[i], b);
			}
			if(index != -1){
				cout << j << " " << index << endl;
				break;
			} else if(index == -1 && j == a - 1){
				cout << -1 << endl;
				break;
			}
		}
	}
	return 0;
}