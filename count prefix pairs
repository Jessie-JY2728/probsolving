// Question: given an array of strings, count the number of pairs, 
// such that one is the prefix of the other. 
// Eg. for ["ab", "ab", "abd"], "ab" is prefix of "ab" and "abd",
// so return 3 (each "ab" count for one).
// Idea: Trie

class solution {

struct Trie {
    Trie *children[27] = {};
    int count = 0;
};

Trie* getTrie(vector<string> &arr) {
    Trie *root = new Trie;
    for (string s : arr) {
        Trie *cur = root;
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new Trie;
            }
            (cur->children[index]->count)++;
            //printf("%c: %d\n", s[i], cur->children[index]->count);
            cur = cur->children[index];
        }
        if (!cur->children[26]) cur->children[26] = new Trie;
        (cur->children[26]->count)++;
    }
    return root;
}

int findPref(Trie* root) {
    int ans = 0;
    queue<Trie*> q;
    q.push(root);
    while(!q.empty()) {
        Trie* cur = q.front();
        q.pop();
        int test = cur->children[26] ? cur ->children[26]->count : 0;
        //printf("test: %d\n", test);
        int m1 = cur->count;
        int m2 = cur->children[26] ? cur->children[26]->count : 0;
        for (auto c : cur->children) {
            if (c) {
                q.push(c);
                //m2 += c->count;
            }
        }
        if (m1 == m2) ans = ans + m2;
        else ans = ans + (m1 - m2) * m2;
        printf("%d, %d, %d\n", m1, m2, ans);
    }
    return ans;
}


int prefPair(vector<string> &arr) {
    Trie* root = getTrie(arr);
    int ans = findPref(root);
    return ans;
}

// testing
int main() {
    vector<string> input{"an", "an", "an"};
    int n = prefPair(input);
    cout << n << endl;
    return 0;
}

};
