// Leetcode Question 42. Difficulty: Hard. Topic: Two Pointers
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;
        int rv = 0;
        vector<int> maxleft(n, 0), maxright(n, 0);
        for (int i = 1; i < n; i++) {
            maxleft[i] = max(maxleft[i-1], height[i-1]);
            maxright[n-1-i] = max(maxright[n-i], height[n-i]);
        }
        for (int i = n - 2; i > 0; i--) {
            int level = min(maxright[i], maxleft[i]);
            if (level > height[i]) rv += (level - height[i]);
        }
        return rv;
    }
};
