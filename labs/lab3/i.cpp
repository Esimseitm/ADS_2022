#include <iostream>
using namespace std;
bool binary_search(int a[], int target, int n){
	int left = 0;
	int right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if(a[mid] == target){
			return true;
		} else if(a[mid] > target){
			right = mid - 1;
		} else{
			left = mid + 1;
		}
	}
	return false;
}
int main(){
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    if(binary_search(a, k, n)){
        cout << "Yes" << endl; 
    } else{
        cout << "No" << endl;
    }
    return 0;
}