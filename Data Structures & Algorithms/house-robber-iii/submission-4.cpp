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
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int rob = root->val + right.second + left.second;
        int noRob = max(left.first, left.second) + max(right.first, right.second);
        return {rob, noRob};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return max(res.first, res.second);
    }
};