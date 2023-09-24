// Leetcode 1248, Count Number of Nice Subarrays
// Difficulty: Medium. Topic: sliding window

class Solution {
public:
    int atMost(vector<int> &arr, int k) {
        int ans = 0, i = 0, n = arr.size();
        for (int j = 0; j < n; j++) {
            k -= arr[j] % 2;
            while (k < 0) k += arr[i++] % 2;
            ans += j - i + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
