// Question: Leetcode 30. Difficulty: Hard. Topic: Hashmap.
// You are given a string s and an array of strings words. All the strings of words are of the same length.
// A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
// Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = s.length(), n = words.size(), k = words[0].length();
        int i = 0, j = 0;
        unordered_map<string, int> counts;
        for (string w : words) {
            counts[w]++;
        }
        vector<int> indices;

        while (i < m - n * k+1) {
            unordered_map<string, int> found;
            j=0;
            while (j < n) {
                string sub = s.substr(i+j*k, k);
                if (counts.find(sub) != counts.end()) {
                    found[sub]++;
                    if (found[sub] > counts[sub]) break;
                } else break;
                j++;
            }
            if (j == n) indices.push_back(i);
            i++;
        }
        return indices;
        
        
    }
};
