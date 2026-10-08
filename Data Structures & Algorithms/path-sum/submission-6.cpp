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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, targetSum - root->val);

        while(!q.empty()){
            auto [node, sum] = q.front();
            q.pop();
            
            if(!node->left && !node->right && sum == 0) return true;

            if(node->right){
                q.emplace(node->right, sum - node->right->val);
            }

            if(node->left){
                q.emplace(node->left, sum - node->left->val);
            }
        }

        return false;
    }
};