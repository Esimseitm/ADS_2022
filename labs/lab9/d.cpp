#include <iostream>
#include <vector>

using namespace std;
vector <string> parallel;

vector<int> prefix_function (string s){
	int size = s.size();
	vector<int> pi(size);
	for(int i = 1; i < size; i++){
		int j = pi[i-1];
		while(j > 0 and s[i] != s[j]){
			j = pi[j - 1];
        }
		if(s[i] == s[j]){
            j++;
        }
		pi[i] = j;
	}
	return pi;
}

int main()
{
    string p;
    cin >> p;
    int n;
    cin >> n;
    int ggwp = 0;
    int lanaya = 1;
    p[0] = tolower(p[0]);   
    for(int i = 0; i < n; i++){
        string gorod; cin >> gorod;
        gorod[0] = tolower(gorod[0]);
        string pat = gorod + "#" + p;
        vector <int> pi = prefix_function(pat);
        gorod[0] = toupper(gorod[0]);
        //dfvgdfgdfgdfgdfgdfg
        //dfgfdgdfgdfgdfg/dfgdf
        //dfgdfgdfgdfgdfgdfg
        if(pi.back() > lanaya){
            lanaya = pi.back();
            parallel.clear();
            parallel.push_back(gorod);
            ggwp = 1;
        }
        
        else if(pi.back() == lanaya){
            parallel.push_back(gorod);
            ggwp++;
        }
    }
    // cparallel << ggwp << endl;
    cout << parallel.size() << endl;
    for(string x : parallel)cout << x << endl;
    return 0;
}