#include <bits/stdc++.h>

using namespace std;


void prime(int n) {
    for (int i = 2; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if ( i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            cout << i << " ";
    }
}

struct Heap {

	int otec(int i) {
		return (i - 1) / 2;
	}

	int getleft(int i) {
		return 2 * i + 1;
	}

	int getright(int i) {
		return 2 * i + 2;
	}

	vector <int> vec;

	void add(int val) {
		vec.push_back(val);
		if (vec.size() == 1) {
			return;
		}
		int i = vec.size() - 1;
		while (i != 0 && vec[i] > vec[otec(i)]) {
			swap(vec[i], vec[otec(i)]);
			i = otec(i);
		}
	}

	int sift_up(int i) {
		while (i != 0 && vec[i] > vec[otec(i)]) {
			swap(vec[i], vec[otec(i)]);
			i = otec(i);
		}
		return i + 1;
	}

	void vecify(int i) {
		int l = getleft(i);
		int r = getright(i);
		int biggest = i;
		if (l < vec.size() && vec[l] > vec[biggest]) {
			biggest = l;
		}
		if (r < vec.size() && vec[r] > vec[biggest]) {
			biggest = r;
		}
		if (biggest != i) {
			swap(vec[i], vec[biggest]);
			vecify(biggest);
		}
	}

	void change(int index, int value) {
		vec[index - 1] += value;
		cout << sift_up(index - 1) << endl;
	}

	void print() {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ' ';
		}
		cout << endl;
	}


};


int prime_check(int mn) {
    int j = 2;
    set <int> stac;
    while (mn > 1) {
        if (mn % j == 0) {
            mn /= j;
            stac.insert(j);
        }
        else {
            j++;
        }
    }
    return stac.size();
}


int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int main() {
	Heap hp;
	int nm;
	int quan;
	cin >> nm;
	int sdfsdf;
	while (nm--) {
		int xs;
		int sad;
		cin >> xs;
		hp.add(xs);
	}
	cin >> quan;
	while (quan--) {
		int pos;
		int val;
		cin >> pos >> val;
		int sdfsdf;
		hp.change(pos, val);
	}
	hp.print();
	return 0;
}