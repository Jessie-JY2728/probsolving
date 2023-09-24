// Leetcode 68, Minimum Window Substring
// Difficulty: Hard. Topic: two pointers

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tchars;
        for (char c : t) tchars[c]++;
        int count = 0, low = 0, minlen = INT_MAX, minstart = 0;
        int slen = s.length(), tlen = t.length();
        for (int high = 0; high < slen; high++) {
            if (tchars[s[high]] > 0) count++;
            tchars[s[high]]--;
            printf("%c: %d\n", s[high], tchars[s[high]]);
            if (count == tlen) {
                while (low < high && tchars[s[low]] < 0) tchars[s[low++]]++;
                if (minlen > high - low) {
                    minlen = high - low + 1;
                    minstart = low;
                }
                tchars[s[low++]]++;
                count--;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(minstart, minlen);
    }
};
