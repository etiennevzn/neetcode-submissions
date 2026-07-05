/**
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
private:
    bool isBalancedTracker = true;

    int dfs(TreeNode* root){
        if(!root) return 0;
        int right = dfs(root->right);
        int left = dfs(root->left);
        if(isBalancedTracker){
            isBalancedTracker = abs(right - left) < 2;
        }
        return 1 + max(right,left);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        dfs(root);
        return isBalancedTracker;
    }
};
