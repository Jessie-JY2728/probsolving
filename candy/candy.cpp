// Leetcode 135, Candy
// Difficulty: Hard. Topic: Greedy.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        int rv = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i+1] + 1 > candies[i])
                candies[i] = candies[i+1] + 1;
            rv += candies[i];
        }
        return rv + candies[n-1];
    }
};
