// Leetcode 2316, Count Unreachable Pairs of Nodes in an Undirected Graph
// Difficulty: Medium. Topic: DFS

class Solution {
public:

    void dfs(int root, vector<int> adj[], vector<bool> &visited, int &gc) {
            if (visited[root]) return;
            gc++;
            visited[root] = true;
            for (int child : adj[root]) {
                if (!visited[child])
                    dfs(child, adj, visited, gc);
            }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (vector<int> e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        vector<int> gcounts;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int gc = 0;
            dfs(i, adj, visited, gc);
            gcounts.push_back(gc);
        }

        long long res = 0;
        int seen = 0;
        for (int g : gcounts) {
            cout<< g << "  ";
            seen += g;
            res += (long)((long)g * (long)(n - seen));
        }
        return res;
        
    }
};
