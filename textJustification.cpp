// Question: Leetcode 68. Difficulty: Hard. Topic: Array/String

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int w) {
        vector<string> res, vs;
        string str;
        int len = 0;

        for (int i = 0; i < words.size(); i++) {
            if (len + vs.size() + words[i].size() <= w) {
                vs.push_back(words[i]);
                len += words[i].size();
            } else {
                if (vs.size() == 1) {
                    str = vs[0];
                    str.append(w - str.size(), ' ');
                    res.push_back(str);
                } else if (vs.size() > 1) {
                    int div = (w - len) / (vs.size() - 1);
                    int mod = (w - len) % (vs.size() - 1);
                    str = vs[0];
                    for (int j = 1; j < vs.size(); j++) {
                        if (j <= mod) str.append(div+1, ' ');
                        else str.append(div, ' ');
                        str += vs[j];
                    }
                    res.push_back(str);
                }
                vs.clear();
                vs.push_back(words[i]);
                len = words[i].size();
            }
        }
        str = vs[0];
        for (int j = 1; j < vs.size(); j++) str += (" " + vs[j]);
        str.append(w - str.size(), ' ');
        res.push_back(str);
        return res;
    }
};
