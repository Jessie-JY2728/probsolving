// Leetcode 1010, Pairs of Songs With Total Duration Divisible by 60
// Difficulty: Medium. Topic: array, math

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mod60(60);
        for (int t : time) {
            mod60[t % 60]++;
        }
        int ans = 0;
        for (int i = 1; i < 30; i++) {
            int a = mod60[i], b = mod60[60-i];
            ans += a * b;
        }
        
        ans += mod60[0] % 2 == 0 ? mod60[0] / 2 *  (mod60[0] - 1) : (mod60[0] - 1) / 2 * mod60[0];
        ans += mod60[30] % 2 == 0 ? mod60[30] / 2 * (mod60[30] - 1) : (mod60[30] - 1) / 2 * mod60[30];
        return ans;
    }
};
