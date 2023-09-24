// Leetcode 1372: Longest ZigZag Path in a Binary Tree
// Difficulty: Medium. Topic: binary tree, dynamic programming

**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
   
class Solution {
public:
    int maxlen = 0;

    void dp(TreeNode* root, int dir, int curlen) {
        if (!root) return;
        maxlen = max(curlen, maxlen);
        dp(root->left, 0, dir ? curlen+1 : 1);
        dp(root->right, 1, dir ? 1 : curlen + 1); 
    }

    int longestZigZag(TreeNode* root) {
        dp(root, 0, 0);
        dp(root, 1, 0);
        return maxlen;
    }
};
