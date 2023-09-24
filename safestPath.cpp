// Leetcode 2812, Find the Safest Path in a Grid
// Difficulty: Medium. Topic: BFS, binary search

class Solution {
private:
    int n;
    int m;
    int dir[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
public:
    bool passPossible(vector<vector<int>> &grid, int &mid) {
        //int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        queue<int> q;
        if (grid[0][0] >= mid) q.push(0);
        while (q.size()) {
            int x = q.front() / 1000, y = q.front() % 1000;
            q.pop();
            if (x == n-1 && y == m - 1) return true;
            for (auto it : dir) {
                int dx = x + it[0], dy = y + it[1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    if (!visited[dx][dy] && grid[dx][dy] >= mid) {
                        visited[dx][dy] = true;
                        q.push(dx * 1000 + dy);
                    }
                }
            }
        }
        return false;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = INT_MAX, level = 2;
        if (m == 1 && n == 1) return !grid[0][0];
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) q.push(i * 1000 + j);
                else grid[i][j] = INT_MAX;
            }
        }
        while (q.size()) {
            int size = q.size();
            while (size--) {
                int x = q.front() / 1000, y = q.front() % 1000;
                q.pop();
                for (auto [dx, dy] : dir) {
                    if (x+dx < n && x+dx >= 0 && y+dy < m && y+dy >= 0) {
                        if (grid[x+dx][y+dy] > level) {
                            grid[x+dx][y+dy] = level;
                            q.push((x+dx) * 1000 + y + dy);
                        }
                    }
                }
            }
            level++;
        }
        int low = 0, high = level - 1, mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (passPossible(grid, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans - 1;
    }
};
