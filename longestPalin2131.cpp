// Leetcode 2131. Longset Palindrom by Concatenating Two Letter Words
// Difficulty: Medium. Topic: hashmap, string

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wanted;  // stores the reverse of encountered string
        int unpaired = 0, ans = 0;  // unpaired string with two same letters;
        for (string s : words) {
            char a = s[0], b = s[1];
            if (a == b) {
                if (wanted[s] > 0) {
                    wanted[s]--;
                    unpaired--;
                    ans += 4;
                } else {
                    wanted[s]++;
                    unpaired++;
                }
            } else {
                if (wanted[s] > 0) {
                    wanted[s]--;
                    ans += 4;
                } else {
                    string rev = "";
                    rev = rev + b + a;
                    wanted[rev]++;
                }
            }
        }
        if (unpaired > 0) ans += 2;
        return ans;

    }
};
