// Trie
#include <iostream>

using namespace std;


const int N = 26; 
class Node {
    public :
    char value;
    Node *ch[N];

    Node (char value) {
        this->value = value;
        for (int i = 0; i < N; i++) {
            this->ch[i] = NULL;

        }
    }

};

class Trie {
    public:
    Node *root;
    int cnt;
    Trie() {
        root = new Node('*');
        this->cnt = 0;

    }
    void insert (string s) {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if(cur -> ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
            }
            else {
                Node *node = new Node(s[i]);
                cur -> ch[s[i] - 'a'] = node;
                cur = node;
                this->cnt++;
            }
        }
    }

};

int main () {
    Trie *trie = new Trie();
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);

    }
    cout << trie->cnt;
    return 0;
}