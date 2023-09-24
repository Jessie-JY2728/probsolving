// Leetcode 799, Champagne Tower
// Difficulty: Medium. Topic: DP

class Solution {
public:
    double dp[101][101];
    double helper(int poured, int row, int glass) {
        if (row == 0 && glass == 0) return poured;
        if (row < 0 || glass > row || glass < 0) return 0.0;
        if (dp[row][glass] > -1) return dp[row][glass];

        double left = 0.5 * helper(poured, row-1, glass - 1) - 0.5;
        left = max(left, 0.0); 
        double right = 0.5 * helper(poured, row-1, glass) - 0.5;
        right = max(right, 0.0);

        double total = left + right;
        dp[row][glass] = total;
        return total;
    }

    double champagneTower(int poured, int row, int glass) {
        memset(dp, -1, sizeof(dp));
        double ans = helper(poured, row, glass);
        return min(1.0, ans);

    }
};
