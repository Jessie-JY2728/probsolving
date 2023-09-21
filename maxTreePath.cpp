// Question: Given a tree, each node having positive or negative values,
// find a path (i.e. from one node to another) whose nodes give the max sum
// Tree inputed as two arrays: 1) parents[n], where node i's parent is parents[i];
// 2) values, node i's value is values[i];
// root's parent is always -1

class solution {
public:

map<int, vector<int>> tree;

void two_maxi(vector<int> &lst, vector<int> &vals, int &fst, int &snd){
    int first = INT_MIN, second = INT_MIN;
    int n = lst.size();
    for (int i = 0; i < n; i++) {
        if (vals[lst[i]] > first) {
            second = first;
            first = vals[lst[i]];
        } else if (vals[lst[i]] > second && vals[lst[i]] != first) {
            second = vals[lst[i]];
        }
    }
    if (first == INT_MIN) first = 0;
    if (second == INT_MIN) second = 0;
    fst = first;
    snd = second;
}

int maxPathSum(vector<int> &parent, vector<int> &values) {
    for (int i = 0; i < parent.size(); i++) {
        tree[parent[i]].push_back(i);
    }
    int root = tree[-1].front();    // assert root == 0
    
    stack<int> st;
    queue<int> lv;
    lv.push(root);
    while (!lv.empty()) {
        int cur = lv.front();
        lv.pop();
        st.push(cur);
        for (int x : tree[cur]) lv.push(x);
    }
    int ans = INT_MIN;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        int lc = 0, rc = 0;
        two_maxi(tree[cur], values, lc, rc);
        int bend = lc + rc + values[cur];
        values[cur] += max(0, lc);
        ans = max(bend, max(ans, values[cur]));
    }
    return ans;
}


int main() {
    vector<int> p{-1, 0, 1, 2, 0};
    vector<int> v{-2, 10, 10, -3, 10};
    int ans = maxPathSum(p, v);
    std::cout << "ans: "<< ans << endl;;
}
};
