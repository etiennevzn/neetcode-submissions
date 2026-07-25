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
    unordered_map<TreeNode*, int> memo;
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(memo.count(root)) return memo[root];
        int rightRob = 0;
        int leftRob = 0;
        if(root->right) rightRob = dfs(root->right->right) + dfs(root->right->left);
        if(root->left) leftRob = dfs(root->left->right) + dfs(root->left->left);

        int rob = root->val + rightRob + leftRob;
        int noRob = dfs(root->left) + dfs(root->right);
        return memo[root] = max(rob, noRob);
    }
public:
    int rob(TreeNode* root) {
        return dfs(root);
    }
};